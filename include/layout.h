#ifndef LOGDB_LAYOUT_H
#define LOGDB_LAYOUT_H

#include <string>
#include "loggingevent.h"

namespace logdb 
{

using std::string;

class Layout
{
public:
    Layout(/* args */){}
    ~Layout(){}
    virtual void formatAndAppend(std::ostream &, LoggingEvent_t *ev) = 0;
protected:
    const string& level2Str(const LogLevel ll);
};

typedef Layout* LayoutPtr;

class SampleLayout:public Layout
{
public:
    SampleLayout(/* args */){}
    ~SampleLayout(){}
    virtual void formatAndAppend(std::ostream &, LoggingEvent_t *ev);
};



} //namespace logdb

#endif