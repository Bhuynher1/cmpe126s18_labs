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
include lab4_lib/CMakeFiles/lab4_lib.dir/depend.make

# Include the progress variables for this target.
include lab4_lib/CMakeFiles/lab4_lib.dir/progress.make

# Include the compile flags for this target's objects.
include lab4_lib/CMakeFiles/lab4_lib.dir/flags.make

lab4_lib/CMakeFiles/lab4_lib.dir/src/calculator.cpp.o: lab4_lib/CMakeFiles/lab4_lib.dir/flags.make
lab4_lib/CMakeFiles/lab4_lib.dir/src/calculator.cpp.o: ../lib/lab04/src/calculator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lab4_lib/CMakeFiles/lab4_lib.dir/src/calculator.cpp.o"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab4_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4_lib.dir/src/calculator.cpp.o -c "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab04/src/calculator.cpp"

lab4_lib/CMakeFiles/lab4_lib.dir/src/calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_lib.dir/src/calculator.cpp.i"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab4_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab04/src/calculator.cpp" > CMakeFiles/lab4_lib.dir/src/calculator.cpp.i

lab4_lib/CMakeFiles/lab4_lib.dir/src/calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_lib.dir/src/calculator.cpp.s"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab4_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab04/src/calculator.cpp" -o CMakeFiles/lab4_lib.dir/src/calculator.cpp.s

# Object files for target lab4_lib
lab4_lib_OBJECTS = \
"CMakeFiles/lab4_lib.dir/src/calculator.cpp.o"

# External object files for target lab4_lib
lab4_lib_EXTERNAL_OBJECTS =

lab4_lib/liblab4_lib.a: lab4_lib/CMakeFiles/lab4_lib.dir/src/calculator.cpp.o
lab4_lib/liblab4_lib.a: lab4_lib/CMakeFiles/lab4_lib.dir/build.make
lab4_lib/liblab4_lib.a: lab4_lib/CMakeFiles/lab4_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblab4_lib.a"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab4_lib" && $(CMAKE_COMMAND) -P CMakeFiles/lab4_lib.dir/cmake_clean_target.cmake
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab4_lib" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab4_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lab4_lib/CMakeFiles/lab4_lib.dir/build: lab4_lib/liblab4_lib.a

.PHONY : lab4_lib/CMakeFiles/lab4_lib.dir/build

lab4_lib/CMakeFiles/lab4_lib.dir/clean:
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab4_lib" && $(CMAKE_COMMAND) -P CMakeFiles/lab4_lib.dir/cmake_clean.cmake
.PHONY : lab4_lib/CMakeFiles/lab4_lib.dir/clean

lab4_lib/CMakeFiles/lab4_lib.dir/depend:
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab04" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab4_lib" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab4_lib/CMakeFiles/lab4_lib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : lab4_lib/CMakeFiles/lab4_lib.dir/depend
