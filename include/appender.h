
#ifndef APPENDER_H
#define APPENDER_H

#include <string>

namespace logdb {

using std::string;

class Appender
{
public:
    Appender(/* args */);
    ~Appender();

    std::string getName();
    void setName(string& name);

private:
    string name;
};

typedef Appender* AppenderPtr; 

}

#endif