#include <iostream>

#include "log.h"
#include "layout.h"

using namespace logdb;

void layoutTest()
{
    string patternStr = "%d{%H:%M:%S} [%p] %n %m";
    Logger *pTestLogger = Logger::getInstance();
    Appender *appender = new ConsoleAppender;
    appender->setLayout(new PatternLayout(patternStr));
    pTestLogger->addAppender(appender);

    pTestLogger->log(INFO, "hello test layout");

}

int main(int argc, char** argv)
{
    Logger *pLogger = Logger::getInstance();

    pLogger->addAppender(new ConsoleAppender);

    pLogger->log(INFO, "hello world");
    pLogger->log(DEBUG, "hello world");
    pLogger->log(ERROR, "hello world");

    pLogger->setLogLevel(DEBUG);
    pLogger->log(DEBUG, "hello world");

    layoutTest();
    return 0;
}

