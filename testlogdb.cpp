#include <iostream>

#include "log.h"

using namespace logdb;

int main(int argc, char** argv)
{
    Logbase *pLogger = Logbase::CreateInstance();

    pLogger->Init("TestModule");

    pLogger->print(std::cout, INFO,"hello world");
    pLogger->print(std::cout, DEBUG,"hello world");
    pLogger->print(std::cout, ERROR,"hello world");

    return 0;
}

