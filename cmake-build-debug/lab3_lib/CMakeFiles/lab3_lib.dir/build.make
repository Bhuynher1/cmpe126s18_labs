# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
include lab3_lib/CMakeFiles/lab3_lib.dir/depend.make

# Include the progress variables for this target.
include lab3_lib/CMakeFiles/lab3_lib.dir/progress.make

# Include the compile flags for this target's objects.
include lab3_lib/CMakeFiles/lab3_lib.dir/flags.make

lab3_lib/CMakeFiles/lab3_lib.dir/src/lifo.cpp.o: lab3_lib/CMakeFiles/lab3_lib.dir/flags.make
lab3_lib/CMakeFiles/lab3_lib.dir/src/lifo.cpp.o: ../lib/lab03/src/lifo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lab3_lib/CMakeFiles/lab3_lib.dir/src/lifo.cpp.o"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab3_lib.dir/src/lifo.cpp.o -c "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab03/src/lifo.cpp"

lab3_lib/CMakeFiles/lab3_lib.dir/src/lifo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_lib.dir/src/lifo.cpp.i"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab03/src/lifo.cpp" > CMakeFiles/lab3_lib.dir/src/lifo.cpp.i

lab3_lib/CMakeFiles/lab3_lib.dir/src/lifo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_lib.dir/src/lifo.cpp.s"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab03/src/lifo.cpp" -o CMakeFiles/lab3_lib.dir/src/lifo.cpp.s

lab3_lib/CMakeFiles/lab3_lib.dir/src/fifo.cpp.o: lab3_lib/CMakeFiles/lab3_lib.dir/flags.make
lab3_lib/CMakeFiles/lab3_lib.dir/src/fifo.cpp.o: ../lib/lab03/src/fifo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lab3_lib/CMakeFiles/lab3_lib.dir/src/fifo.cpp.o"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab3_lib.dir/src/fifo.cpp.o -c "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab03/src/fifo.cpp"

lab3_lib/CMakeFiles/lab3_lib.dir/src/fifo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_lib.dir/src/fifo.cpp.i"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab03/src/fifo.cpp" > CMakeFiles/lab3_lib.dir/src/fifo.cpp.i

lab3_lib/CMakeFiles/lab3_lib.dir/src/fifo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_lib.dir/src/fifo.cpp.s"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab03/src/fifo.cpp" -o CMakeFiles/lab3_lib.dir/src/fifo.cpp.s

# Object files for target lab3_lib
lab3_lib_OBJECTS = \
"CMakeFiles/lab3_lib.dir/src/lifo.cpp.o" \
"CMakeFiles/lab3_lib.dir/src/fifo.cpp.o"

# External object files for target lab3_lib
lab3_lib_EXTERNAL_OBJECTS =

lab3_lib/liblab3_lib.a: lab3_lib/CMakeFiles/lab3_lib.dir/src/lifo.cpp.o
lab3_lib/liblab3_lib.a: lab3_lib/CMakeFiles/lab3_lib.dir/src/fifo.cpp.o
lab3_lib/liblab3_lib.a: lab3_lib/CMakeFiles/lab3_lib.dir/build.make
lab3_lib/liblab3_lib.a: lab3_lib/CMakeFiles/lab3_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblab3_lib.a"
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && $(CMAKE_COMMAND) -P CMakeFiles/lab3_lib.dir/cmake_clean_target.cmake
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lab3_lib/CMakeFiles/lab3_lib.dir/build: lab3_lib/liblab3_lib.a

.PHONY : lab3_lib/CMakeFiles/lab3_lib.dir/build

lab3_lib/CMakeFiles/lab3_lib.dir/clean:
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" && $(CMAKE_COMMAND) -P CMakeFiles/lab3_lib.dir/cmake_clean.cmake
.PHONY : lab3_lib/CMakeFiles/lab3_lib.dir/clean

lab3_lib/CMakeFiles/lab3_lib.dir/depend:
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/lib/lab03" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/lab3_lib/CMakeFiles/lab3_lib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : lab3_lib/CMakeFiles/lab3_lib.dir/depend

