
#ifndef _LOG_H_
#define _LOG_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "config.h"
#include "appender.h"
#include "loggingevent.h"

#define DEFAULT_LEVEL	INFO


namespace logdb {

using std::string;
class Appender;

    typedef struct LogMsg {
        string msgline;
        LogLevel level;
    }LogMsg_t;


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
        void callAppend(LoggingEvent_t *ev);
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
        void setLogLevel(LogLevel ll) { this->loglevel = ll; }

    private:
        Logger();
	    ~Logger();

        /**
         * Create instance of Logger,
         * which can only be called by GetInstance()
         */
	    static Logger* createInstance();
        bool isEnabledfor(LogLevel ll);

        static Logger *m_pLoggerInstance;
        
        std::vector<AppenderPtr> appenderList;
        InternalEventManager *evManager;
        LogLevel loglevel;
	    int Pid;
	    string ModuleName;
    };

}


#endif


