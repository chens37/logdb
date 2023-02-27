aux_source_directory(. DIR_LOGDB_SRCS)
add_library(logdb SHARED  ${DIR_LOGDB_SRCS})
include_directories(${DIR_LOGDB_SRCS}/../include)
