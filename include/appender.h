
#ifndef APPENDER_H
#define APPENDER_H

#include <string>
#include "layout.h"
#include "loggingevent.h"

namespace logdb {

using std::string;

class Layout;

class Appender
{
public:
    Appender(/* args */);
    ~Appender();

    std::string getName();
    void setName(string& name);
    
    void setLayout(LayoutPtr newLayout);
    LayoutPtr getLayout();
    /*
    * core function, must be overloaded by subclass 
    */
    virtual void doAppend(LoggingEvent_t *ev) = 0;
protected:
    string name;
    LayoutPtr layout;
    virtual void append(LoggingEvent_t *ev) = 0;
};

typedef Appender* AppenderPtr; 

class ConsoleAppender:public Appender
{
public:
    ConsoleAppender(/* args */);
    ~ConsoleAppender();
    virtual void doAppend(LoggingEvent_t *ev);
private:
    virtual void append(LoggingEvent_t *ev);
};



}

#endif