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
    
    parsedPatternList = PatternParser::getInstance()->parse(pattern);

    //TODO check parsedPatternList empty
}

PatternLayout::~PatternLayout() = default;

void PatternLayout::formatAndAppend(std::ostream &stream, LoggingEvent_t *ev)
{
    for(auto & ptr : parsedPatternList)
        ptr->formatAndAppend(stream, ev); 
}

PatternParser* PatternParser::m_pInstance = nullptr;

PatternParser* PatternParser::getInstance()
{
    if(!m_pInstance)
        m_pInstance = new PatternParser;

    return m_pInstance;
}

PatternListType PatternParser::parse(string pattern_)
{
    //TODO
}

void PatternConverter::formatAndAppend(std::ostream &stream, LoggingEvent_t *ev)
{
    string s;
    convert(s, ev);

    stream << s;
}

void LiteralPatternConverter::convert(string &s, LoggingEvent_t *ev)
{
    s = str;
}

void DatePatternConverter::convert(string &s, LoggingEvent_t *ev)
{
    s = helper::getFormatTime(format, ev->rawtime);
}

void BasicPatternConverter::convert(string &s, LoggingEvent_t *ev)
{
    switch (type)
    {
    case FILE_CONVERTER:
        /* code */
        s = ev->file;
        break;
    case LINE_CONVERTER:
        s = ev->line;
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