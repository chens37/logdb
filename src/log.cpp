
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
    LoggingEvent_t *ev = new LoggingEvent_t();

    ev->func = func;
    ev->file = file;
    ev->line = line;
    ev->ll = ll;
    ev->msg = str;

    callAppend(ev);

}

Logger::~Logger(){

}
Logger::Logger()
:loglevel(INFO)
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


void Logger::callAppend(LoggingEvent_t *ev)
{
    //TODO
    for ( AppenderPtr& ptr : appenderList ) {
        ptr->doAppend(ev);
    }
}

}//namespace logdb

