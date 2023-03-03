#ifndef LOGGING_EVENT_H
#define LOGGING_EVENT_H

#include <string>
#include <vector>
#include <ctime>
#define MAX_EV_NUM 256

namespace logdb {

using std::string;

enum LogLevel{
    DEBUG = 0,
    TRACE,
    INFO,
    WARNING,
    ERROR,
    DEFAULT,
};

typedef time_t TimeStamp_t;

class InternalEventManager;

typedef struct LoggingEvent {
    /* data */
    LogLevel ll;
    string msg;
    string file;
    int line;
    string func;
    TimeStamp_t rawtime;
    InternalEventManager *manager;
    bool inuse;
} LoggingEvent_t;

typedef LoggingEvent_t* LoggingEventPtr;

class InternalEventManager
{
public:
    static void doClearEv(LoggingEventPtr ev);
    InternalEventManager();
    ~InternalEventManager();
    LoggingEventPtr getEmptyEv(bool alloc);
    void putEv(LoggingEventPtr);
    /*
    * won't clear manager member
    */
    void clearEv(LoggingEventPtr);
private:
    LoggingEventPtr allocEv();
    std::vector<LoggingEventPtr> evList;
    int evNumMax;
};

}

#endif