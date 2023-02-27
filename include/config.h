
#ifndef LOGDB_CONFIG_H
#define LOGDB_CONFIG_H

#if defined (__GNUC__) \
    && ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8))
#  define LOGDB_CALLER_FILE() __builtin_FILE()
#  define LOGDB_CALLER_LINE() __builtin_LINE()
#  define LOGDB_CALLER_FUNCTION() __builtin_FUNCTION()
#else
#  define LOGDB_CALLER_FILE() (nullptr)
#  define LOGDB_CALLER_LINE() (-1)
#  define LOGDB_CALLER_FUNCTION() (nullptr)    
#endif

#endif
