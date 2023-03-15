#include <iostream>
#include "loglog.h"

namespace logdb {
    namespace helper {

LogLog* LogLog::getLoglog()
{
    if (!mLoglog)
    {
        mLoglog = new LogLog;
    }
    
    return mLoglog;
}

LogLog* LogLog::mLoglog = nullptr;

LogLog::LogLog(/* args */)
{

}

LogLog::~LogLog()
{

}

void LogLog::debug(std::string& msg)
{
    worker(std::cout, DEBUG_PREFIX, msg);
}

void LogLog::debug(const char *msg)
{
    worker(std::cout, DEBUG_PREFIX, msg);
}

    
void LogLog::warn(std::string& msg)
{
    worker(std::cout, WARN_PREFIX, msg);
}

void LogLog::warn(const char *msg)
{
    worker(std::cout, WARN_PREFIX, msg);
}
    
void LogLog::error(std::string& msg)
{
    worker(std::cout, ERROR_PREFIX, msg);
}

void LogLog::error(const char *msg)
{
    worker(std::cout, ERROR_PREFIX, msg);
}
    
void LogLog::info(std::string& msg)
{
    worker(std::cout, INFO_PREFIX, msg);
}

void LogLog::info(const char *msg)
{
    worker(std::cout, INFO_PREFIX, msg);
}


template <typename StringType>
void LogLog::worker(std::ostream& out, const std::string& prefix, StringType const & msg)
{
    out << prefix << " " << 
        msg <<std::endl;
}


} //namespace helper
} //namespace logdb