# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bobo/ros2_ws/eigen-3.4.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bobo/ros2_ws/build/Eigen3

# Include any dependencies generated for this target.
include doc/examples/CMakeFiles/function_taking_ref.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include doc/examples/CMakeFiles/function_taking_ref.dir/compiler_depend.make

# Include the progress variables for this target.
include doc/examples/CMakeFiles/function_taking_ref.dir/progress.make

# Include the compile flags for this target's objects.
include doc/examples/CMakeFiles/function_taking_ref.dir/flags.make

doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o: doc/examples/CMakeFiles/function_taking_ref.dir/flags.make
doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o: /home/bobo/ros2_ws/eigen-3.4.0/doc/examples/function_taking_ref.cpp
doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o: doc/examples/CMakeFiles/function_taking_ref.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bobo/ros2_ws/build/Eigen3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o"
	cd /home/bobo/ros2_ws/build/Eigen3/doc/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o -MF CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.d -o CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o -c /home/bobo/ros2_ws/eigen-3.4.0/doc/examples/function_taking_ref.cpp

doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.i"
	cd /home/bobo/ros2_ws/build/Eigen3/doc/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bobo/ros2_ws/eigen-3.4.0/doc/examples/function_taking_ref.cpp > CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.i

doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.s"
	cd /home/bobo/ros2_ws/build/Eigen3/doc/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bobo/ros2_ws/eigen-3.4.0/doc/examples/function_taking_ref.cpp -o CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.s

# Object files for target function_taking_ref
function_taking_ref_OBJECTS = \
"CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o"

# External object files for target function_taking_ref
function_taking_ref_EXTERNAL_OBJECTS =

doc/examples/function_taking_ref: doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o
doc/examples/function_taking_ref: doc/examples/CMakeFiles/function_taking_ref.dir/build.make
doc/examples/function_taking_ref: doc/examples/CMakeFiles/function_taking_ref.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bobo/ros2_ws/build/Eigen3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable function_taking_ref"
	cd /home/bobo/ros2_ws/build/Eigen3/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/function_taking_ref.dir/link.txt --verbose=$(VERBOSE)
	cd /home/bobo/ros2_ws/build/Eigen3/doc/examples && ./function_taking_ref >/home/bobo/ros2_ws/build/Eigen3/doc/examples/function_taking_ref.out

# Rule to build all files generated by this target.
doc/examples/CMakeFiles/function_taking_ref.dir/build: doc/examples/function_taking_ref
.PHONY : doc/examples/CMakeFiles/function_taking_ref.dir/build

doc/examples/CMakeFiles/function_taking_ref.dir/clean:
	cd /home/bobo/ros2_ws/build/Eigen3/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/function_taking_ref.dir/cmake_clean.cmake
.PHONY : doc/examples/CMakeFiles/function_taking_ref.dir/clean

doc/examples/CMakeFiles/function_taking_ref.dir/depend:
	cd /home/bobo/ros2_ws/build/Eigen3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bobo/ros2_ws/eigen-3.4.0 /home/bobo/ros2_ws/eigen-3.4.0/doc/examples /home/bobo/ros2_ws/build/Eigen3 /home/bobo/ros2_ws/build/Eigen3/doc/examples /home/bobo/ros2_ws/build/Eigen3/doc/examples/CMakeFiles/function_taking_ref.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc/examples/CMakeFiles/function_taking_ref.dir/depend
