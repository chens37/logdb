#include <ctime>
#include <string>
#include "helper.h"

namespace logdb{
  namespace helper{

using std::string;

string getFormatTime(string& format, time_t rawtime)
{
    char str[MAX_SIZE];
    tm *timeinfo = localtime(&rawtime);

    strftime(str, 80, format.c_str(), timeinfo);

    return str;
}

time_t now()
{
    return time(0);
}

string deletePath(string& fullpath)
{
    size_t start = fullpath.find_last_of('/', 0);
    
    return fullpath.substr(start+1);
}

  }//namespace helper
} //namespace logdb