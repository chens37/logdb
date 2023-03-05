#ifndef LOGDB_LAYOUT_H
#define LOGDB_LAYOUT_H

#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include "loggingevent.h"

namespace logdb 
{

using std::string;

class PatternConverter;


struct FormatInfo
{
    int maxlen;
    int minlen;
    bool leftAlign;
    bool truncStart;
    
    FormatInfo(){ reset(); }
    void reset();
};


/*
* This class is used to layout strings sent to an Appender 
*/
class Layout
{
public:
    Layout(/* args */){}
    ~Layout(){}
    virtual void formatAndAppend(std::ostream &, LoggingEvent_t *ev) = 0;
    static const string& level2Str(const LogLevel ll);
protected:
};

typedef Layout* LayoutPtr;


/* 
* SampleLayout format output strings in a particular pattern, 
* which does not support specification.
*/
class SampleLayout:public Layout
{
public:
    SampleLayout(/* args */){}
    ~SampleLayout(){}
    virtual void formatAndAppend(std::ostream &, LoggingEvent_t *ev);
};

typedef std::vector< std::unique_ptr<logdb::PatternConverter> > PatternListType;

/* 
* a flexible layout configurable with pattern string.
* 
* The goal of this class is to format a LoggingEvent with the giving
* pattern and return the results as a string.
* 
* When it is instantiated, PatternLayout delegate the task of parsing 
* pattern to PatternParser which will return a vector of <PatternListType>.
* Each element of parsedPatternList is an instance of PatternConverter.
* the formatAndAppend acquirement will be forward to parsedPatternList in
* sequence.
*/
class PatternLayout:public Layout
{
public:
    PatternLayout(string &newPattern);
    ~PatternLayout();
    virtual void formatAndAppend(std::ostream &, LoggingEvent_t *ev);
private:
    string pattern;
    PatternListType parsedPatternList;

};

/* 
* a utility class providing the ability of parsing pattern and instantiate 
* PatternConverter.
*/
class PatternParser
{
public:
    enum STATE {
        LITERAL_STATE,
        CONVERT_STATE,
        DOT_STATE,
        MINC_STATE,
        MAXC_STATE
    };
    PatternParser(string &pattern_);
    ~PatternParser(){}
    PatternListType parse();
    void finalParse(char c);
private:
    size_t pos;
    STATE state;
    string pattern;
    string currentLiteral;
    FormatInfo formatInfo;
    PatternListType list;
};

/* 
* Convert LoggingEvent to particular pattern format.
*/
class PatternConverter
{
public:
    PatternConverter(const FormatInfo& fmtInfo_);
    ~PatternConverter(){}
    void formatAndAppend(std::ostream &, LoggingEvent_t *ev);

protected:
    virtual void convert(string &s, LoggingEvent_t *ev) = 0;

private:
    int maxlen;
    int minlen;
    bool leftAlign;
    bool truncStart;
};

/* 
* This PatternConverter return a constant string.
*/
class LiteralPatternConverter:public PatternConverter
{
public:
    LiteralPatternConverter(string& s):str(s),PatternConverter(FormatInfo()){}
    ~LiteralPatternConverter();
protected:
    virtual void convert(string& s, LoggingEvent_t *ev);
    string str;
};

/* 
* This PatternConverter is used to format most of the simple fields
* found in LoggingEvent objects.
*/
class BasicPatternConverter:public PatternConverter
{
public:
    enum Type{
        FILE_CONVERTER,
        LINE_CONVERTER,
        FUNC_CONVERTER,
        THREAD_CONVERTER,
        PROCESS_CONVERTER,
        MESSAGE_CONVERTER,
        LOGLEVEL_CONVERTER,

    };
    BasicPatternConverter(Type tp, FormatInfo& fmtInfo_);
    ~BasicPatternConverter();
protected:
    virtual void convert(string &s, LoggingEvent_t *ev);
    Type type;
};

/* 
* This PatternConverter is used to format the timestamp field found
* in LoggingEvent objects. It will be formatted according to the 
* specified "fmt" pattern
*/
class DatePatternConverter:public PatternConverter
{
public:
    DatePatternConverter(string& fmt, FormatInfo& i):format(fmt),PatternConverter(i){}
    ~DatePatternConverter();
protected:
    virtual void convert(string& s, LoggingEvent_t *ev);
    string format;
};



} //namespace logdb

#endif