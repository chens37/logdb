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
    printf("setlayout %p %p ", this, &layout);
}

LayoutPtr Appender::getLayout()
{
    return layout;
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
    printf("append %p %p ",this, &layout);
    layout->formatAndAppend(stream, ev);
    InternalEventManager::doClearEv(ev);
}

}