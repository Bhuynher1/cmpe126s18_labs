# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug"

# Include any dependencies generated for this target.
include test/gtest-1.7.0/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include test/gtest-1.7.0/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtest-1.7.0/CMakeFiles/gtest.dir/flags.make

test/gtest-1.7.0/CMakeFiles/gtest.dir/src/gtest-all.cc.o: test/gtest-1.7.0/CMakeFiles/gtest.dir/flags.make
test/gtest-1.7.0/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../test/gtest-1.7.0/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtest-1.7.0/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/test/gtest-1.7.0" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/test/gtest-1.7.0/src/gtest-all.cc"

test/gtest-1.7.0/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/test/gtest-1.7.0" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/test/gtest-1.7.0/src/gtest-all.cc" > CMakeFiles/gtest.dir/src/gtest-all.cc.i

test/gtest-1.7.0/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/test/gtest-1.7.0" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/test/gtest-1.7.0/src/gtest-all.cc" -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

test/gtest-1.7.0/libgtest.a: test/gtest-1.7.0/CMakeFiles/gtest.dir/src/gtest-all.cc.o
test/gtest-1.7.0/libgtest.a: test/gtest-1.7.0/CMakeFiles/gtest.dir/build.make
test/gtest-1.7.0/libgtest.a: test/gtest-1.7.0/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/test/gtest-1.7.0" && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/test/gtest-1.7.0" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtest-1.7.0/CMakeFiles/gtest.dir/build: test/gtest-1.7.0/libgtest.a

.PHONY : test/gtest-1.7.0/CMakeFiles/gtest.dir/build

test/gtest-1.7.0/CMakeFiles/gtest.dir/clean:
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/test/gtest-1.7.0" && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : test/gtest-1.7.0/CMakeFiles/gtest.dir/clean

test/gtest-1.7.0/CMakeFiles/gtest.dir/depend:
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/test/gtest-1.7.0" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/test/gtest-1.7.0" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/test/gtest-1.7.0/CMakeFiles/gtest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : test/gtest-1.7.0/CMakeFiles/gtest.dir/depend

