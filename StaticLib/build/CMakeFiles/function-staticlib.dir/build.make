# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/619/bin/cmake

# The command to remove a file.
RM = /snap/cmake/619/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marius/StaticLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marius/StaticLib/build

# Include any dependencies generated for this target.
include CMakeFiles/function-staticlib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/function-staticlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/function-staticlib.dir/flags.make

CMakeFiles/function-staticlib.dir/src/function.cpp.o: CMakeFiles/function-staticlib.dir/flags.make
CMakeFiles/function-staticlib.dir/src/function.cpp.o: ../src/function.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marius/StaticLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/function-staticlib.dir/src/function.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/function-staticlib.dir/src/function.cpp.o -c /home/marius/StaticLib/src/function.cpp

CMakeFiles/function-staticlib.dir/src/function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/function-staticlib.dir/src/function.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marius/StaticLib/src/function.cpp > CMakeFiles/function-staticlib.dir/src/function.cpp.i

CMakeFiles/function-staticlib.dir/src/function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/function-staticlib.dir/src/function.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marius/StaticLib/src/function.cpp -o CMakeFiles/function-staticlib.dir/src/function.cpp.s

# Object files for target function-staticlib
function__staticlib_OBJECTS = \
"CMakeFiles/function-staticlib.dir/src/function.cpp.o"

# External object files for target function-staticlib
function__staticlib_EXTERNAL_OBJECTS =

libfunction-staticlib.a: CMakeFiles/function-staticlib.dir/src/function.cpp.o
libfunction-staticlib.a: CMakeFiles/function-staticlib.dir/build.make
libfunction-staticlib.a: CMakeFiles/function-staticlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marius/StaticLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfunction-staticlib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/function-staticlib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/function-staticlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/function-staticlib.dir/build: libfunction-staticlib.a

.PHONY : CMakeFiles/function-staticlib.dir/build

CMakeFiles/function-staticlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/function-staticlib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/function-staticlib.dir/clean

CMakeFiles/function-staticlib.dir/depend:
	cd /home/marius/StaticLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marius/StaticLib /home/marius/StaticLib /home/marius/StaticLib/build /home/marius/StaticLib/build /home/marius/StaticLib/build/CMakeFiles/function-staticlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/function-staticlib.dir/depend
