#ifndef LOGGING_EVENT_H
#define LOGGING_EVENT_H


namespace logdb {

using std::string;

enum LogLevel{
    DEBUG = 0,
    TRACE,
    INFO,
    WARNING,
    ERROR,
};

typedef string TimeStamp_t;

typedef struct LoggingEvent {
    /* data */
    LogLevel ll;
    string msg;
    string file;
    int line;
    string func;
    TimeStamp_t time;
} LoggingEvent_t;

}

#endif