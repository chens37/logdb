#include <iostream>
#include "layout.h"
#include "helper.h"

namespace logdb {

using std::string;

static const string DEBUGSTRING("DEBUG");
static const string TRACESTRING("TRACE");
static const string INFOSTRING("INFO");
static const string WARNINGSTRING("WARNING");
static const string ERRORSTRING("ERROR");

void FormatInfo::reset()
{
    maxlen = __INT_MAX__;
    minlen = 0;
    leftAlign = false;
    truncStart = true;
}

void SampleLayout::formatAndAppend(std::ostream &stream, LoggingEvent_t *ev)
{
    stream << ev->file << " "
    << ev->func << " "
    << Layout::level2Str(ev->ll) << " - "
    << ev->line << " "
    << ev->msg << std::endl;
}

const string& Layout::level2Str(const LogLevel ll)
{
    switch(ll){
    case DEBUG:
        return DEBUGSTRING;
    case TRACE:
        return TRACESTRING;
    case INFO:
        return INFOSTRING;
    case WARNING:
        return WARNINGSTRING;
    case ERROR:
        return ERRORSTRING;
    default:
        return INFOSTRING;
    }
}


PatternLayout::PatternLayout(string &newPattern)
:pattern(newPattern)
{
    parsedPatternList = PatternParser(pattern).parse();
    if (parsedPatternList.empty())
    {
        printf("parsedPatternList empty");
    }   
}

PatternLayout::~PatternLayout() = default;

void PatternLayout::formatAndAppend(std::ostream &stream, LoggingEvent_t *ev)
{
    for(auto & ptr : parsedPatternList)
        ptr->formatAndAppend(stream, ev);
    
}

PatternParser::PatternParser(string& pattern_)
:pos(0),state(LITERAL_STATE),pattern(pattern_)
{

}

PatternListType PatternParser::parse()
{
    char c;
    while (pos < pattern.length())
    {
        c = pattern[pos++];
        switch (state) {
        case LITERAL_STATE:
            if (pos == pattern.length())
            {
                currentLiteral += c;
                continue;
            }
            if (c == '%') 
            {
                switch (pattern[pos]) 
                {
                case '%':
                    currentLiteral += c;
                    pos++;
                    break;
                default:
                    if (!currentLiteral.empty())
                    {
                        list.push_back(std::unique_ptr<PatternConverter>(
                            new LiteralPatternConverter(currentLiteral)));
                    }
                    currentLiteral.resize(0);
                    formatInfo.reset();
                    currentLiteral += c;
                    state = CONVERT_STATE;
                    break;
                }
            } else 
            {
              currentLiteral += c;  
            }
            break;
        case CONVERT_STATE:
            currentLiteral += c;
            if (c == '-')
                formatInfo.leftAlign = true;
            else if (c >= '0' && c <= '9')
            {
                formatInfo.minlen = c - '0';
                state = MINC_STATE;
            }else if (c == '.')
            {
                state = DOT_STATE;
            }else
                finalParse(c);
            break;
        case DOT_STATE:
            currentLiteral += c;
            if (c >= '0' && c <= '9')
            {
                formatInfo.maxlen = c - '0';
                state = MAXC_STATE;
            }
            else if (c == '-') {
                formatInfo.truncStart = false;
            }else {
                //TODO error print;
                finalParse(c);
            }
            break;
        case MINC_STATE:
            currentLiteral += c;
            if (c >= '0' && c <= '9')
                formatInfo.minlen = formatInfo.minlen*10 + c-'0';
            else if (c == '.')
                state = DOT_STATE;
            else {           
                finalParse(c);
            }
            break;
        case MAXC_STATE:
            currentLiteral += c;
            if (c >= '0' && c <= '9')
                formatInfo.maxlen = formatInfo.maxlen*10 + c-'0';
            else {
                finalParse(c);
            }
            break;
        default:
            break;
        }
    }

    if (!currentLiteral.empty())
    {
        list.push_back(
            std::unique_ptr<PatternConverter>(
                new LiteralPatternConverter(currentLiteral)));
    }

    return std::move(list);
}

void PatternParser::finalParse(char c)
{
    PatternConverter* pc = nullptr;

    switch (c)
    {
    case 'b': 
        /* func */
        pc = new BasicPatternConverter(
            BasicPatternConverter::FUNC_CONVERTER, formatInfo);
        break;
    case 'c':
        /* logger name */
        break;
    case 'd':
    case 'D':
    {
        /* date */
        string fmt;
        size_t end;
        if (pattern[pos] == '{')
        {
            end = pattern.find_first_of('}', pos);
            if (end != string::npos)
            {
                fmt = pattern.substr(pos+1, end-pos-1);
                pos = end+1;
            } else
            {
                // TODO print error
                pos = pattern.length();
                break;
            }
        }else 
            fmt = "%y/%m/%d %H:%M:%S";
        pc = new DatePatternConverter(fmt, formatInfo);
    }
        break;
    case 'E':
        /* environment */
        break;
    case 'F':
        /* filename */
        pc = new BasicPatternConverter(
            BasicPatternConverter::FILE_CONVERTER, formatInfo);
        break;
    case 'm':
        /* message */
        pc = new BasicPatternConverter(
            BasicPatternConverter::MESSAGE_CONVERTER, formatInfo);
        break;
    case 'p':
        /* loglevel */
        pc = new BasicPatternConverter(
            BasicPatternConverter::LOGLEVEL_CONVERTER, formatInfo);
        break;
    case 'n':
        /* line */
        pc = new BasicPatternConverter(
            BasicPatternConverter::LINE_CONVERTER, formatInfo);
        break;
    case 'r':
        /* seconds */
        break;
    case 't':
        /* thread id */
        pc = new BasicPatternConverter(
            BasicPatternConverter::THREAD_CONVERTER, formatInfo);
        break;
    case 'T':
        /* thread name */
        break;
    case 'i':
        /* pid */
        break;
    default:
        if (!currentLiteral.empty())
            pc = new LiteralPatternConverter(currentLiteral);
        
        // TODO error print
        break;
    }

    if (pc)
        list.push_back(std::unique_ptr<PatternConverter>(pc));
    state = LITERAL_STATE;
    currentLiteral.resize(0);
    formatInfo.reset();
}

PatternConverter::PatternConverter(const FormatInfo& fmtInfo_)
{
    maxlen = fmtInfo_.maxlen;
    minlen = fmtInfo_.minlen;
    leftAlign = fmtInfo_.leftAlign;
    truncStart = fmtInfo_.truncStart;
}

void PatternConverter::formatAndAppend(std::ostream &output, LoggingEvent_t *ev)
{
    string s;
    convert(s, ev);
    int len = static_cast<int>(s.length());

    if (len > maxlen) 
    {
        if (truncStart)
        {
            output << s.substr(len - maxlen);
        } else 
            output << s.substr(0, maxlen);
    }
    else if (len < minlen)
    {
        int pad = minlen - len;
        if (leftAlign)
        {
            output << s;
            output << string(pad, ' ');
        } else {
            output << string(pad, ' ');
            output << s;
        }
    }
    else
        output << s;
}

void LiteralPatternConverter::convert(string &s, LoggingEvent_t *ev)
{
    s = str;
}

void DatePatternConverter::convert(string &s, LoggingEvent_t *ev)
{
    s = helper::getFormatTime(format, ev->rawtime);
}

BasicPatternConverter::BasicPatternConverter    (Type tp, FormatInfo& fmtInfo_)
:type(tp),PatternConverter(fmtInfo_)
{
}

void BasicPatternConverter::convert(string &s, LoggingEvent_t *ev)
{
    switch (type)
    {
    case FILE_CONVERTER:
        /* code */
        s = helper::deletePath(ev->file);
        break;
    case LINE_CONVERTER:
        s = std::to_string(ev->line);
        break;
    case FUNC_CONVERTER:
        s = ev->func;
        break;
    case THREAD_CONVERTER:
        //TODO
        break;
    case PROCESS_CONVERTER:
        //TODO
        break;
    case MESSAGE_CONVERTER:
        s = ev->msg;
        break;
    case LOGLEVEL_CONVERTER:
        s = Layout::level2Str(ev->ll);
        break;
    default:
        break;
    }
}


}//namespace logdb