# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shichen/ssd/opensource/logdb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shichen/ssd/opensource/logdb

# Include any dependencies generated for this target.
include src/CMakeFiles/logdb.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/logdb.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/logdb.dir/flags.make

src/CMakeFiles/logdb.dir/appender.cpp.o: src/CMakeFiles/logdb.dir/flags.make
src/CMakeFiles/logdb.dir/appender.cpp.o: src/appender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shichen/ssd/opensource/logdb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/logdb.dir/appender.cpp.o"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logdb.dir/appender.cpp.o -c /home/shichen/ssd/opensource/logdb/src/appender.cpp

src/CMakeFiles/logdb.dir/appender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logdb.dir/appender.cpp.i"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shichen/ssd/opensource/logdb/src/appender.cpp > CMakeFiles/logdb.dir/appender.cpp.i

src/CMakeFiles/logdb.dir/appender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logdb.dir/appender.cpp.s"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shichen/ssd/opensource/logdb/src/appender.cpp -o CMakeFiles/logdb.dir/appender.cpp.s

src/CMakeFiles/logdb.dir/appender.cpp.o.requires:

.PHONY : src/CMakeFiles/logdb.dir/appender.cpp.o.requires

src/CMakeFiles/logdb.dir/appender.cpp.o.provides: src/CMakeFiles/logdb.dir/appender.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/logdb.dir/build.make src/CMakeFiles/logdb.dir/appender.cpp.o.provides.build
.PHONY : src/CMakeFiles/logdb.dir/appender.cpp.o.provides

src/CMakeFiles/logdb.dir/appender.cpp.o.provides.build: src/CMakeFiles/logdb.dir/appender.cpp.o


src/CMakeFiles/logdb.dir/layout.cpp.o: src/CMakeFiles/logdb.dir/flags.make
src/CMakeFiles/logdb.dir/layout.cpp.o: src/layout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shichen/ssd/opensource/logdb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/logdb.dir/layout.cpp.o"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logdb.dir/layout.cpp.o -c /home/shichen/ssd/opensource/logdb/src/layout.cpp

src/CMakeFiles/logdb.dir/layout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logdb.dir/layout.cpp.i"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shichen/ssd/opensource/logdb/src/layout.cpp > CMakeFiles/logdb.dir/layout.cpp.i

src/CMakeFiles/logdb.dir/layout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logdb.dir/layout.cpp.s"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shichen/ssd/opensource/logdb/src/layout.cpp -o CMakeFiles/logdb.dir/layout.cpp.s

src/CMakeFiles/logdb.dir/layout.cpp.o.requires:

.PHONY : src/CMakeFiles/logdb.dir/layout.cpp.o.requires

src/CMakeFiles/logdb.dir/layout.cpp.o.provides: src/CMakeFiles/logdb.dir/layout.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/logdb.dir/build.make src/CMakeFiles/logdb.dir/layout.cpp.o.provides.build
.PHONY : src/CMakeFiles/logdb.dir/layout.cpp.o.provides

src/CMakeFiles/logdb.dir/layout.cpp.o.provides.build: src/CMakeFiles/logdb.dir/layout.cpp.o


src/CMakeFiles/logdb.dir/log.cpp.o: src/CMakeFiles/logdb.dir/flags.make
src/CMakeFiles/logdb.dir/log.cpp.o: src/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shichen/ssd/opensource/logdb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/logdb.dir/log.cpp.o"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logdb.dir/log.cpp.o -c /home/shichen/ssd/opensource/logdb/src/log.cpp

src/CMakeFiles/logdb.dir/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logdb.dir/log.cpp.i"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shichen/ssd/opensource/logdb/src/log.cpp > CMakeFiles/logdb.dir/log.cpp.i

src/CMakeFiles/logdb.dir/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logdb.dir/log.cpp.s"
	cd /home/shichen/ssd/opensource/logdb/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shichen/ssd/opensource/logdb/src/log.cpp -o CMakeFiles/logdb.dir/log.cpp.s

src/CMakeFiles/logdb.dir/log.cpp.o.requires:

.PHONY : src/CMakeFiles/logdb.dir/log.cpp.o.requires

src/CMakeFiles/logdb.dir/log.cpp.o.provides: src/CMakeFiles/logdb.dir/log.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/logdb.dir/build.make src/CMakeFiles/logdb.dir/log.cpp.o.provides.build
.PHONY : src/CMakeFiles/logdb.dir/log.cpp.o.provides

src/CMakeFiles/logdb.dir/log.cpp.o.provides.build: src/CMakeFiles/logdb.dir/log.cpp.o


# Object files for target logdb
logdb_OBJECTS = \
"CMakeFiles/logdb.dir/appender.cpp.o" \
"CMakeFiles/logdb.dir/layout.cpp.o" \
"CMakeFiles/logdb.dir/log.cpp.o"

# External object files for target logdb
logdb_EXTERNAL_OBJECTS =

src/liblogdb.so: src/CMakeFiles/logdb.dir/appender.cpp.o
src/liblogdb.so: src/CMakeFiles/logdb.dir/layout.cpp.o
src/liblogdb.so: src/CMakeFiles/logdb.dir/log.cpp.o
src/liblogdb.so: src/CMakeFiles/logdb.dir/build.make
src/liblogdb.so: src/CMakeFiles/logdb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shichen/ssd/opensource/logdb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library liblogdb.so"
	cd /home/shichen/ssd/opensource/logdb/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logdb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/logdb.dir/build: src/liblogdb.so

.PHONY : src/CMakeFiles/logdb.dir/build

src/CMakeFiles/logdb.dir/requires: src/CMakeFiles/logdb.dir/appender.cpp.o.requires
src/CMakeFiles/logdb.dir/requires: src/CMakeFiles/logdb.dir/layout.cpp.o.requires
src/CMakeFiles/logdb.dir/requires: src/CMakeFiles/logdb.dir/log.cpp.o.requires

.PHONY : src/CMakeFiles/logdb.dir/requires

src/CMakeFiles/logdb.dir/clean:
	cd /home/shichen/ssd/opensource/logdb/src && $(CMAKE_COMMAND) -P CMakeFiles/logdb.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/logdb.dir/clean

src/CMakeFiles/logdb.dir/depend:
	cd /home/shichen/ssd/opensource/logdb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shichen/ssd/opensource/logdb /home/shichen/ssd/opensource/logdb/src /home/shichen/ssd/opensource/logdb /home/shichen/ssd/opensource/logdb/src /home/shichen/ssd/opensource/logdb/src/CMakeFiles/logdb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/logdb.dir/depend

