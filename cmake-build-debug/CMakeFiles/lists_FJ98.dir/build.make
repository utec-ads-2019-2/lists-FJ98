# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/83/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/83/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/felix/ADS-20192/lists-FJ98

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felix/ADS-20192/lists-FJ98/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lists_FJ98.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lists_FJ98.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lists_FJ98.dir/flags.make

CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.o: CMakeFiles/lists_FJ98.dir/flags.make
CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.o: ../mock/mocker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/ADS-20192/lists-FJ98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.o -c /home/felix/ADS-20192/lists-FJ98/mock/mocker.cpp

CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/ADS-20192/lists-FJ98/mock/mocker.cpp > CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.i

CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/ADS-20192/lists-FJ98/mock/mocker.cpp -o CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.s

CMakeFiles/lists_FJ98.dir/test/tester.cpp.o: CMakeFiles/lists_FJ98.dir/flags.make
CMakeFiles/lists_FJ98.dir/test/tester.cpp.o: ../test/tester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/ADS-20192/lists-FJ98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lists_FJ98.dir/test/tester.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lists_FJ98.dir/test/tester.cpp.o -c /home/felix/ADS-20192/lists-FJ98/test/tester.cpp

CMakeFiles/lists_FJ98.dir/test/tester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lists_FJ98.dir/test/tester.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/ADS-20192/lists-FJ98/test/tester.cpp > CMakeFiles/lists_FJ98.dir/test/tester.cpp.i

CMakeFiles/lists_FJ98.dir/test/tester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lists_FJ98.dir/test/tester.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/ADS-20192/lists-FJ98/test/tester.cpp -o CMakeFiles/lists_FJ98.dir/test/tester.cpp.s

CMakeFiles/lists_FJ98.dir/main.cpp.o: CMakeFiles/lists_FJ98.dir/flags.make
CMakeFiles/lists_FJ98.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/ADS-20192/lists-FJ98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lists_FJ98.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lists_FJ98.dir/main.cpp.o -c /home/felix/ADS-20192/lists-FJ98/main.cpp

CMakeFiles/lists_FJ98.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lists_FJ98.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/ADS-20192/lists-FJ98/main.cpp > CMakeFiles/lists_FJ98.dir/main.cpp.i

CMakeFiles/lists_FJ98.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lists_FJ98.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/ADS-20192/lists-FJ98/main.cpp -o CMakeFiles/lists_FJ98.dir/main.cpp.s

# Object files for target lists_FJ98
lists_FJ98_OBJECTS = \
"CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.o" \
"CMakeFiles/lists_FJ98.dir/test/tester.cpp.o" \
"CMakeFiles/lists_FJ98.dir/main.cpp.o"

# External object files for target lists_FJ98
lists_FJ98_EXTERNAL_OBJECTS =

lists_FJ98: CMakeFiles/lists_FJ98.dir/mock/mocker.cpp.o
lists_FJ98: CMakeFiles/lists_FJ98.dir/test/tester.cpp.o
lists_FJ98: CMakeFiles/lists_FJ98.dir/main.cpp.o
lists_FJ98: CMakeFiles/lists_FJ98.dir/build.make
lists_FJ98: CMakeFiles/lists_FJ98.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felix/ADS-20192/lists-FJ98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lists_FJ98"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lists_FJ98.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lists_FJ98.dir/build: lists_FJ98

.PHONY : CMakeFiles/lists_FJ98.dir/build

CMakeFiles/lists_FJ98.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lists_FJ98.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lists_FJ98.dir/clean

CMakeFiles/lists_FJ98.dir/depend:
	cd /home/felix/ADS-20192/lists-FJ98/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felix/ADS-20192/lists-FJ98 /home/felix/ADS-20192/lists-FJ98 /home/felix/ADS-20192/lists-FJ98/cmake-build-debug /home/felix/ADS-20192/lists-FJ98/cmake-build-debug /home/felix/ADS-20192/lists-FJ98/cmake-build-debug/CMakeFiles/lists_FJ98.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lists_FJ98.dir/depend

