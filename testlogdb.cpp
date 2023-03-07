#include <iostream>

#include "log.h"
#include "layout.h"

using namespace logdb;

void layoutTest()
{
    string patternStr = "%d{%y/%m/%d %H:%M:%S} %b:%n [%p] %m";
    Logger *pTestLogger = Logger::getInstance();
    Appender *appender = new ConsoleAppender;
    appender->setLayout(new PatternLayout(patternStr));
    pTestLogger->addAppender(appender);

    pTestLogger->log(INFO, "hello test layout\n" );
    pTestLogger->log(ERROR, "hello test layout 2\n");
    pTestLogger->log(INFO, "hello test layout 3\n");

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

