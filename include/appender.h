
#ifndef APPENDER_H
#define APPENDER_H

#include <string>
#include <fstream>
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
    void formatEvent(string& str, LoggingEvent_t *ev);
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

class FileAppender:public Appender
{
public:
    FileAppender(string fileWithPath, 
                std::ios_base::openmode mode = std::ios_base::trunc,
                size_t maxsize = 1024*1024);
    ~FileAppender();
    void init();
    void deinit();
private:
    void open();
    void append(LoggingEvent_t *ev);
    string fileName;
    std::ios_base::openmode fileMode;
    size_t maxSize;
    std::ofstream out;
    
};


}

#endif