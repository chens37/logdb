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
    static PatternParser* getInstance();
    PatternListType parse(string pattern_);
private:
    PatternParser(){}
    ~PatternParser(){}

    static PatternParser *m_pInstance;

};

/* 
* Convert LoggingEvent to particular pattern format.
*/
class PatternConverter
{
public:
    PatternConverter(){}
    ~PatternConverter(){}
    void formatAndAppend(std::ostream &, LoggingEvent_t *ev);
protected:
    virtual void convert(string &s, LoggingEvent_t *ev) = 0;
};

/* 
* This PatternConverter return a constant string.
*/
class LiteralPatternConverter:public PatternConverter
{
public:
    LiteralPatternConverter(string &s):str(s){}
    ~LiteralPatternConverter();
protected:
    virtual void convert(string &s, LoggingEvent_t *ev);
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
    BasicPatternConverter(Type tp):type(tp){}
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
    DatePatternConverter(string& fmt):format(fmt){}
    ~DatePatternConverter();
protected:
    virtual void convert(string& s, LoggingEvent_t *ev);
    string format;
};



} //namespace logdb

#endif