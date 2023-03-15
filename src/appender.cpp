#include <iostream>
#include <string>
#include "log.h"
#include "appender.h"
#include "loggingevent.h"

namespace logdb {

Appender::Appender()
: name(""), layout(new SampleLayout)
{
}
Appender::~Appender()
{

}

void Appender::setName(string &n)
{
    name = n;
}

string Appender::getName()
{
    return name;
}

void Appender::setLayout(LayoutPtr newLayout)
{
    layout = newLayout;
}

LayoutPtr Appender::getLayout()
{
    return layout;
}

void formatEvent(string& str, LoggingEvent_t *ev)
{
    
}

ConsoleAppender::ConsoleAppender(/* args */)
{
}

ConsoleAppender::~ConsoleAppender()
{
}

void ConsoleAppender::doAppend(LoggingEvent_t *ev)
{
    append(ev);
}

void ConsoleAppender::append(LoggingEvent_t *ev)
{
    std::ostream& stream = std::cout;
    layout->formatAndAppend(stream, ev);
   // InternalEventManager::doClearEv(ev);
}

FileAppender::FileAppender(string fileWithPath,
                            std::ios_base::openmode mode,
                            size_t maxsize)
:maxSize(maxsize), fileMode(mode),fileName(fileWithPath)
{
    init();
}

FileAppender::~FileAppender()
{
    deinit();
}

void FileAppender::init()
{
    out.open(fileName, fileMode);
}

void FileAppender::deinit()
{
    out.close();
}

void FileAppender::doAppend(LoggingEvent_t *ev)
{
    append(ev);
}

void FileAppender::append(LoggingEvent_t *ev)
{
    layout->formatAndAppend(out, ev);
    out.flush();
}



}