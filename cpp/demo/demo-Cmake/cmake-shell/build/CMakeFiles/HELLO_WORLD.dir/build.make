# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/build

# Include any dependencies generated for this target.
include CMakeFiles/HELLO_WORLD.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HELLO_WORLD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HELLO_WORLD.dir/flags.make

CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.o: CMakeFiles/HELLO_WORLD.dir/flags.make
CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.o: ../src/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.o"
	/opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.o -c /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/src/hello.cpp

CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.i"
	/opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/src/hello.cpp > CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.i

CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.s"
	/opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/src/hello.cpp -o CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.s

# Object files for target HELLO_WORLD
HELLO_WORLD_OBJECTS = \
"CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.o"

# External object files for target HELLO_WORLD
HELLO_WORLD_EXTERNAL_OBJECTS =

HELLO_WORLD: CMakeFiles/HELLO_WORLD.dir/src/hello.cpp.o
HELLO_WORLD: CMakeFiles/HELLO_WORLD.dir/build.make
HELLO_WORLD: CMakeFiles/HELLO_WORLD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HELLO_WORLD"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HELLO_WORLD.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HELLO_WORLD.dir/build: HELLO_WORLD

.PHONY : CMakeFiles/HELLO_WORLD.dir/build

CMakeFiles/HELLO_WORLD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HELLO_WORLD.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HELLO_WORLD.dir/clean

CMakeFiles/HELLO_WORLD.dir/depend:
	cd /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/build /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/build /home/ahaoozhang/dev_code/demo-code/cpp/demo/demo-Cmake/cmake-shell/build/CMakeFiles/HELLO_WORLD.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HELLO_WORLD.dir/depend
