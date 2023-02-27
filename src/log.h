
#ifndef _LOG_H_
#define _LOG_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "config.h"
#include "appender.h"

enum LogLevel{
    DEBUG = 0,
    TRACE,
    INFO,
    WARNING,
    ERROR,
};

#define DEFAULT_LEVEL	INFO


namespace logdb {

using std::string;
class Appender;

    typedef struct LogMsg {
        string msgline;
        LogLevel level;
    }LogMsg_t;

    typedef struct FmtMsg {
        string msg;
    }FmtMsg_t;

    typedef struct TimeStamp {
        time_t time;
    }TimeStamp_t;

    class Filter;

    class Logger 
    {
    public:
      //Static Methods
        /**
         * Return the instance of Logger
         * if not exist, create a new instance
         */
	    static Logger* getInstance();
        
        /**
         * Destory the instance of Logger
         */
	    static void destroyInstance();

      //Non-Static Methods
        /**
         * Init Logger instance
         */
        void Init(string name);

        /**
         * attach a new appender to logger
         */
        void addAppender(AppenderPtr newAppender);
        void removeAppender(AppenderPtr appender);
        void removeAppender(string& name);
        AppenderPtr getAppender(string& name);
        void callAppend();
        /**
         * The user interface to stream log message
         * 
         */
        void log(LogLevel ll, string str,
            const char *file = LOGDB_CALLER_FILE(),
            int line = LOGDB_CALLER_LINE(),
            const char *func = LOGDB_CALLER_FUNCTION()
            );

        void forcedLog(LogLevel ll, string str,
            const char *file = LOGDB_CALLER_FILE(),
            int line = LOGDB_CALLER_LINE(),
            const char *func = LOGDB_CALLER_FUNCTION()
            );
        LogLevel getLogLevel() {return this->loglevel;}

    private:
        Logger();
	    ~Logger();

        /**
         * Create instance of Logger,
         * which can only be called by GetInstance()
         */
	    static Logger* createInstance();
        FmtMsg_t Format(LogMsg_t& msg);
	    string level2str(const LogLevel levl);
        bool isEnabledfor(LogLevel ll);

        static Logger *m_pLoggerInstance;
        
        std::vector<AppenderPtr> appenderList;
        LogLevel loglevel;
	    TimeStamp_t ts;
	    int Pid;
	    string ModuleName;
    };

}


#endif


