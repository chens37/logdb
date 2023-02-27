#include <iostream>
#include <string>
#include "log.h"
#include "appender.h"

namespace logdb {

void Appender::setName(string &n)
{
    name = n;
}

string Appender::getName()
{
    return name;
}



}