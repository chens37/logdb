#include <iostream>

#include "log.h"
#include "layout.h"

using namespace logdb;

int main(int argc, char** argv)
{
    Logger *pLogger = Logger::getInstance();

    pLogger->addAppender(new ConsoleAppender);

    pLogger->log(INFO, "hello world");
    pLogger->log(DEBUG, "hello world");
    pLogger->log(ERROR, "hello world");

    pLogger->setLogLevel(DEBUG);
    pLogger->log(DEBUG, "hello world");


    return 0;
}

