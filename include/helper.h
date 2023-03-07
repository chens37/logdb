#ifndef LOGDB_HELPER_H
#define LOGDB_HELPER_H

#include <string>

namespace logdb {
namespace helper{

#define MAX_SIZE 80

using std::string;

string getFormatTime(string &format, time_t rawtime);
time_t now();
string deletePath(string& fullpath);

} //namespace helper
} //namespace logdb


#endif