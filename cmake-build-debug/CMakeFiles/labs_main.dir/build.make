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
include CMakeFiles/labs_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/labs_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/labs_main.dir/flags.make

CMakeFiles/labs_main.dir/main.cpp.o: CMakeFiles/labs_main.dir/flags.make
CMakeFiles/labs_main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/labs_main.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/labs_main.dir/main.cpp.o -c "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/main.cpp"

CMakeFiles/labs_main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/labs_main.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/main.cpp" > CMakeFiles/labs_main.dir/main.cpp.i

CMakeFiles/labs_main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/labs_main.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/main.cpp" -o CMakeFiles/labs_main.dir/main.cpp.s

# Object files for target labs_main
labs_main_OBJECTS = \
"CMakeFiles/labs_main.dir/main.cpp.o"

# External object files for target labs_main
labs_main_EXTERNAL_OBJECTS =

labs_main: CMakeFiles/labs_main.dir/main.cpp.o
labs_main: CMakeFiles/labs_main.dir/build.make
labs_main: lab1_lib/liblab1_lib.a
labs_main: lab2_lib/liblab2_lib.a
labs_main: lab3_lib/liblab3_lib.a
labs_main: lab4_lib/liblab4_lib.a
labs_main: lab5_lib/liblab5_lib.a
labs_main: lab6_lib/liblab6_lib.a
labs_main: lab3_lib/liblab3_lib.a
labs_main: lab2_lib/liblab2_lib.a
labs_main: lab1_lib/liblab1_lib.a
labs_main: CMakeFiles/labs_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable labs_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/labs_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/labs_main.dir/build: labs_main

.PHONY : CMakeFiles/labs_main.dir/build

CMakeFiles/labs_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/labs_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/labs_main.dir/clean

CMakeFiles/labs_main.dir/depend:
	cd "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug" "/Users/blakehuynh/Documents/SJSU SPRING 2021/CMPE 126/master/cmake-build-debug/CMakeFiles/labs_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/labs_main.dir/depend

