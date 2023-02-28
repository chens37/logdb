#include <iostream>
#include "layout.h"

namespace logdb {

using std::string;

static const string DEBUGSTRING("DEBUG");
static const string TRACESTRING("TRACE");
static const string INFOSTRING("INFO");
static const string WARNINGSTRING("WARNING");
static const string ERRORSTRING("ERROR");


void SampleLayout::formatAndAppend(std::ostream &stream, LoggingEvent_t *ev)
{
    stream << ev->file << " "
    << ev->func << " "
    << level2Str(ev->ll) << " - "
    << ev->line << " "
    << ev->msg << std::endl;
}

const string& Layout::level2Str(const LogLevel ll)
{
    switch(ll){
    case DEBUG:
        return DEBUGSTRING;
    case TRACE:
        return TRACESTRING;
    case INFO:
        return INFOSTRING;
    case WARNING:
        return WARNINGSTRING;
    case ERROR:
        return ERRORSTRING;
    default:
        return INFOSTRING;
    }
}

}//namespace logdb