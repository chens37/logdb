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
include CMakeFiles/logdbtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/logdbtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/logdbtest.dir/flags.make

CMakeFiles/logdbtest.dir/testlogdb.cpp.o: CMakeFiles/logdbtest.dir/flags.make
CMakeFiles/logdbtest.dir/testlogdb.cpp.o: testlogdb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shichen/ssd/opensource/logdb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/logdbtest.dir/testlogdb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logdbtest.dir/testlogdb.cpp.o -c /home/shichen/ssd/opensource/logdb/testlogdb.cpp

CMakeFiles/logdbtest.dir/testlogdb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logdbtest.dir/testlogdb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shichen/ssd/opensource/logdb/testlogdb.cpp > CMakeFiles/logdbtest.dir/testlogdb.cpp.i

CMakeFiles/logdbtest.dir/testlogdb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logdbtest.dir/testlogdb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shichen/ssd/opensource/logdb/testlogdb.cpp -o CMakeFiles/logdbtest.dir/testlogdb.cpp.s

CMakeFiles/logdbtest.dir/testlogdb.cpp.o.requires:

.PHONY : CMakeFiles/logdbtest.dir/testlogdb.cpp.o.requires

CMakeFiles/logdbtest.dir/testlogdb.cpp.o.provides: CMakeFiles/logdbtest.dir/testlogdb.cpp.o.requires
	$(MAKE) -f CMakeFiles/logdbtest.dir/build.make CMakeFiles/logdbtest.dir/testlogdb.cpp.o.provides.build
.PHONY : CMakeFiles/logdbtest.dir/testlogdb.cpp.o.provides

CMakeFiles/logdbtest.dir/testlogdb.cpp.o.provides.build: CMakeFiles/logdbtest.dir/testlogdb.cpp.o


# Object files for target logdbtest
logdbtest_OBJECTS = \
"CMakeFiles/logdbtest.dir/testlogdb.cpp.o"

# External object files for target logdbtest
logdbtest_EXTERNAL_OBJECTS =

logdbtest: CMakeFiles/logdbtest.dir/testlogdb.cpp.o
logdbtest: CMakeFiles/logdbtest.dir/build.make
logdbtest: src/liblogdb.so
logdbtest: CMakeFiles/logdbtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shichen/ssd/opensource/logdb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable logdbtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logdbtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/logdbtest.dir/build: logdbtest

.PHONY : CMakeFiles/logdbtest.dir/build

CMakeFiles/logdbtest.dir/requires: CMakeFiles/logdbtest.dir/testlogdb.cpp.o.requires

.PHONY : CMakeFiles/logdbtest.dir/requires

CMakeFiles/logdbtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/logdbtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/logdbtest.dir/clean

CMakeFiles/logdbtest.dir/depend:
	cd /home/shichen/ssd/opensource/logdb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shichen/ssd/opensource/logdb /home/shichen/ssd/opensource/logdb /home/shichen/ssd/opensource/logdb /home/shichen/ssd/opensource/logdb /home/shichen/ssd/opensource/logdb/CMakeFiles/logdbtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/logdbtest.dir/depend
