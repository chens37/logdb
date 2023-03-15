#ifndef _LOGLOG_H_
#define _LOGLOG_H_

#define LOGLOG_ERR(msg) \
            logdb::helper::LogLog::getLoglog()->error(msg)
#define LOGLOG_WARN(msg) \
            logdb::helper::LogLog::getLoglog()->warn(msg)
#define LOGLOG_INFO(msg) \
            logdb::helper::LogLog::getLoglog()->info(msg)
#define LOGLOG_DEBUG(msg) \
            logdb::helper::LogLog::getLoglog()->debug(msg)

namespace logdb {
namespace helper {

static const std::string WARN_PREFIX = "WARN";
static const std::string DEBUG_PREFIX = "DEBUG";
static const std::string ERROR_PREFIX = "ERROR";
static const std::string INFO_PREFIX = "INFO";

class LogLog
{
public:
    static LogLog* getLoglog();

    void debug(std::string& msg);
    void debug(const char *msg);
    
    void warn(std::string& msg);
    void warn(const char *msg);
    
    void error(std::string& msg);
    void error(const char *msg);
    
    void info(std::string& msg);
    void info(const char *msg);

private:
    LogLog(/* args */);
    ~LogLog();
    
    template <typename StringType>
    void worker(std::ostream& out, const std::string& prefix, StringType const & msg);

    static LogLog *mLoglog;
};


} //namespace helper
} //namespace logdb

#endif
