
#include "log.h"
#include <unistd.h>
#include <time.h>
#include <string>
#include <algorithm>

namespace logdb {

void Logger::log(LogLevel ll, string str,
            const char *file, int line, const char *func)
{
    if(isEnabledfor(ll))
        forcedLog(ll, str, file, line, func);
}

void Logger::forcedLog(LogLevel ll, string str,
            const char *file, int line, const char *func)
{
    // TODO
}

Logger::~Logger(){

}
Logger::Logger()
{
}

void Logger::Init(string name)
{
    ModuleName = name;
    Pid = getpid();
}

Logger* Logger::m_pLoggerInstance = nullptr;

Logger* Logger::createInstance()
{
    return new Logger();
}

Logger* Logger::getInstance()
{
    if(m_pLoggerInstance == nullptr)
        m_pLoggerInstance = createInstance();
    return m_pLoggerInstance;
}

void Logger::destroyInstance()
{
    if(m_pLoggerInstance != nullptr) {
        delete m_pLoggerInstance;
        m_pLoggerInstance = nullptr;
    }
}

string Logger::level2str(const LogLevel levl)
{
    switch(levl){
    case DEBUG:
        return "DEBUG";
    case TRACE:
        return "TRACE";
    case INFO:
        return "INFO";
    case WARNING:
        return "WARNING";
    case ERROR:
        return "ERROR";
    default:
        return "INFO";
    }
}

FmtMsg_t Logger::Format(LogMsg_t& msg)
{
    time_t t = time(NULL);
    FmtMsg_t outmsg;
    string space = " ";
    
    string timestamp = ctime(&t);
    size_t pos = timestamp.find('\n');
    if(pos != std::string::npos) {
        timestamp.erase(pos, 1);
    }

    outmsg.msg = space + timestamp +
    		  space + std::__cxx11::to_string(Pid) + 
                   space + ModuleName +
		   space + level2str(msg.level) +
		   space + msg.msgline;

    return outmsg;
}


bool Logger::isEnabledfor(LogLevel ll)
{
    if (ll >= loglevel)
        return true;

    return false;
}

void Logger::addAppender(AppenderPtr newAppender)
{
    appenderList.push_back(newAppender);
}

AppenderPtr Logger::getAppender(string &name)
{
    for ( AppenderPtr& ptr : appenderList ) {
        if(ptr->getName() == name)
            return ptr;
    }
    
    return nullptr;
}

void Logger::removeAppender(AppenderPtr appender)
{
    auto iter = std::find(appenderList.begin(), appenderList.end(), appender);
    if (iter != appenderList.end())
        appenderList.erase(iter);
}

void Logger::removeAppender(string& name)
{ 
    removeAppender(getAppender(name));
}


void Logger::callAppend()
{
    //TODO
}

}//namespace logdb

