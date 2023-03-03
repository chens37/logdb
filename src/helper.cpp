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

  }//namespace helper
} //namespace logdb