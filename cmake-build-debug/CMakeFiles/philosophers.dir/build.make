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
CMAKE_SOURCE_DIR = /Users/aabet/projects/philosophers/philosophers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aabet/projects/philosophers/philosophers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philosophers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philosophers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philosophers.dir/flags.make

CMakeFiles/philosophers.dir/srcs/main.c.o: CMakeFiles/philosophers.dir/flags.make
CMakeFiles/philosophers.dir/srcs/main.c.o: ../srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aabet/projects/philosophers/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philosophers.dir/srcs/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philosophers.dir/srcs/main.c.o -c /Users/aabet/projects/philosophers/philosophers/srcs/main.c

CMakeFiles/philosophers.dir/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philosophers.dir/srcs/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aabet/projects/philosophers/philosophers/srcs/main.c > CMakeFiles/philosophers.dir/srcs/main.c.i

CMakeFiles/philosophers.dir/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philosophers.dir/srcs/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aabet/projects/philosophers/philosophers/srcs/main.c -o CMakeFiles/philosophers.dir/srcs/main.c.s

CMakeFiles/philosophers.dir/srcs/simple_func.c.o: CMakeFiles/philosophers.dir/flags.make
CMakeFiles/philosophers.dir/srcs/simple_func.c.o: ../srcs/simple_func.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aabet/projects/philosophers/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philosophers.dir/srcs/simple_func.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philosophers.dir/srcs/simple_func.c.o -c /Users/aabet/projects/philosophers/philosophers/srcs/simple_func.c

CMakeFiles/philosophers.dir/srcs/simple_func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philosophers.dir/srcs/simple_func.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aabet/projects/philosophers/philosophers/srcs/simple_func.c > CMakeFiles/philosophers.dir/srcs/simple_func.c.i

CMakeFiles/philosophers.dir/srcs/simple_func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philosophers.dir/srcs/simple_func.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aabet/projects/philosophers/philosophers/srcs/simple_func.c -o CMakeFiles/philosophers.dir/srcs/simple_func.c.s

CMakeFiles/philosophers.dir/srcs/data_func.c.o: CMakeFiles/philosophers.dir/flags.make
CMakeFiles/philosophers.dir/srcs/data_func.c.o: ../srcs/data_func.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aabet/projects/philosophers/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philosophers.dir/srcs/data_func.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philosophers.dir/srcs/data_func.c.o -c /Users/aabet/projects/philosophers/philosophers/srcs/data_func.c

CMakeFiles/philosophers.dir/srcs/data_func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philosophers.dir/srcs/data_func.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aabet/projects/philosophers/philosophers/srcs/data_func.c > CMakeFiles/philosophers.dir/srcs/data_func.c.i

CMakeFiles/philosophers.dir/srcs/data_func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philosophers.dir/srcs/data_func.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aabet/projects/philosophers/philosophers/srcs/data_func.c -o CMakeFiles/philosophers.dir/srcs/data_func.c.s

CMakeFiles/philosophers.dir/srcs/simple_func2.c.o: CMakeFiles/philosophers.dir/flags.make
CMakeFiles/philosophers.dir/srcs/simple_func2.c.o: ../srcs/simple_func2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aabet/projects/philosophers/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/philosophers.dir/srcs/simple_func2.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philosophers.dir/srcs/simple_func2.c.o -c /Users/aabet/projects/philosophers/philosophers/srcs/simple_func2.c

CMakeFiles/philosophers.dir/srcs/simple_func2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philosophers.dir/srcs/simple_func2.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aabet/projects/philosophers/philosophers/srcs/simple_func2.c > CMakeFiles/philosophers.dir/srcs/simple_func2.c.i

CMakeFiles/philosophers.dir/srcs/simple_func2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philosophers.dir/srcs/simple_func2.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aabet/projects/philosophers/philosophers/srcs/simple_func2.c -o CMakeFiles/philosophers.dir/srcs/simple_func2.c.s

CMakeFiles/philosophers.dir/srcs/routines.c.o: CMakeFiles/philosophers.dir/flags.make
CMakeFiles/philosophers.dir/srcs/routines.c.o: ../srcs/routines.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aabet/projects/philosophers/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/philosophers.dir/srcs/routines.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philosophers.dir/srcs/routines.c.o -c /Users/aabet/projects/philosophers/philosophers/srcs/routines.c

CMakeFiles/philosophers.dir/srcs/routines.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philosophers.dir/srcs/routines.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aabet/projects/philosophers/philosophers/srcs/routines.c > CMakeFiles/philosophers.dir/srcs/routines.c.i

CMakeFiles/philosophers.dir/srcs/routines.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philosophers.dir/srcs/routines.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aabet/projects/philosophers/philosophers/srcs/routines.c -o CMakeFiles/philosophers.dir/srcs/routines.c.s

CMakeFiles/philosophers.dir/srcs/simple_func3.c.o: CMakeFiles/philosophers.dir/flags.make
CMakeFiles/philosophers.dir/srcs/simple_func3.c.o: ../srcs/simple_func3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aabet/projects/philosophers/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/philosophers.dir/srcs/simple_func3.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philosophers.dir/srcs/simple_func3.c.o -c /Users/aabet/projects/philosophers/philosophers/srcs/simple_func3.c

CMakeFiles/philosophers.dir/srcs/simple_func3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philosophers.dir/srcs/simple_func3.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aabet/projects/philosophers/philosophers/srcs/simple_func3.c > CMakeFiles/philosophers.dir/srcs/simple_func3.c.i

CMakeFiles/philosophers.dir/srcs/simple_func3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philosophers.dir/srcs/simple_func3.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aabet/projects/philosophers/philosophers/srcs/simple_func3.c -o CMakeFiles/philosophers.dir/srcs/simple_func3.c.s

# Object files for target philosophers
philosophers_OBJECTS = \
"CMakeFiles/philosophers.dir/srcs/main.c.o" \
"CMakeFiles/philosophers.dir/srcs/simple_func.c.o" \
"CMakeFiles/philosophers.dir/srcs/data_func.c.o" \
"CMakeFiles/philosophers.dir/srcs/simple_func2.c.o" \
"CMakeFiles/philosophers.dir/srcs/routines.c.o" \
"CMakeFiles/philosophers.dir/srcs/simple_func3.c.o"

# External object files for target philosophers
philosophers_EXTERNAL_OBJECTS =

philosophers: CMakeFiles/philosophers.dir/srcs/main.c.o
philosophers: CMakeFiles/philosophers.dir/srcs/simple_func.c.o
philosophers: CMakeFiles/philosophers.dir/srcs/data_func.c.o
philosophers: CMakeFiles/philosophers.dir/srcs/simple_func2.c.o
philosophers: CMakeFiles/philosophers.dir/srcs/routines.c.o
philosophers: CMakeFiles/philosophers.dir/srcs/simple_func3.c.o
philosophers: CMakeFiles/philosophers.dir/build.make
philosophers: CMakeFiles/philosophers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aabet/projects/philosophers/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable philosophers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philosophers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philosophers.dir/build: philosophers

.PHONY : CMakeFiles/philosophers.dir/build

CMakeFiles/philosophers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philosophers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philosophers.dir/clean

CMakeFiles/philosophers.dir/depend:
	cd /Users/aabet/projects/philosophers/philosophers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aabet/projects/philosophers/philosophers /Users/aabet/projects/philosophers/philosophers /Users/aabet/projects/philosophers/philosophers/cmake-build-debug /Users/aabet/projects/philosophers/philosophers/cmake-build-debug /Users/aabet/projects/philosophers/philosophers/cmake-build-debug/CMakeFiles/philosophers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philosophers.dir/depend

