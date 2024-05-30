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
CMAKE_SOURCE_DIR = /home/panic/Code/cs-projects/meshell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/panic/Code/cs-projects/meshell

# Include any dependencies generated for this target.
include include/custom_math/CMakeFiles/math.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/custom_math/CMakeFiles/math.dir/compiler_depend.make

# Include the progress variables for this target.
include include/custom_math/CMakeFiles/math.dir/progress.make

# Include the compile flags for this target's objects.
include include/custom_math/CMakeFiles/math.dir/flags.make

include/custom_math/CMakeFiles/math.dir/constants.c.o: include/custom_math/CMakeFiles/math.dir/flags.make
include/custom_math/CMakeFiles/math.dir/constants.c.o: include/custom_math/constants.c
include/custom_math/CMakeFiles/math.dir/constants.c.o: include/custom_math/CMakeFiles/math.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object include/custom_math/CMakeFiles/math.dir/constants.c.o"
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/custom_math/CMakeFiles/math.dir/constants.c.o -MF CMakeFiles/math.dir/constants.c.o.d -o CMakeFiles/math.dir/constants.c.o -c /home/panic/Code/cs-projects/meshell/include/custom_math/constants.c

include/custom_math/CMakeFiles/math.dir/constants.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/math.dir/constants.c.i"
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/panic/Code/cs-projects/meshell/include/custom_math/constants.c > CMakeFiles/math.dir/constants.c.i

include/custom_math/CMakeFiles/math.dir/constants.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/math.dir/constants.c.s"
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/panic/Code/cs-projects/meshell/include/custom_math/constants.c -o CMakeFiles/math.dir/constants.c.s

include/custom_math/CMakeFiles/math.dir/operations.c.o: include/custom_math/CMakeFiles/math.dir/flags.make
include/custom_math/CMakeFiles/math.dir/operations.c.o: include/custom_math/operations.c
include/custom_math/CMakeFiles/math.dir/operations.c.o: include/custom_math/CMakeFiles/math.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object include/custom_math/CMakeFiles/math.dir/operations.c.o"
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/custom_math/CMakeFiles/math.dir/operations.c.o -MF CMakeFiles/math.dir/operations.c.o.d -o CMakeFiles/math.dir/operations.c.o -c /home/panic/Code/cs-projects/meshell/include/custom_math/operations.c

include/custom_math/CMakeFiles/math.dir/operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/math.dir/operations.c.i"
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/panic/Code/cs-projects/meshell/include/custom_math/operations.c > CMakeFiles/math.dir/operations.c.i

include/custom_math/CMakeFiles/math.dir/operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/math.dir/operations.c.s"
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/panic/Code/cs-projects/meshell/include/custom_math/operations.c -o CMakeFiles/math.dir/operations.c.s

# Object files for target math
math_OBJECTS = \
"CMakeFiles/math.dir/constants.c.o" \
"CMakeFiles/math.dir/operations.c.o"

# External object files for target math
math_EXTERNAL_OBJECTS =

include/custom_math/libmath.a: include/custom_math/CMakeFiles/math.dir/constants.c.o
include/custom_math/libmath.a: include/custom_math/CMakeFiles/math.dir/operations.c.o
include/custom_math/libmath.a: include/custom_math/CMakeFiles/math.dir/build.make
include/custom_math/libmath.a: include/custom_math/CMakeFiles/math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libmath.a"
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && $(CMAKE_COMMAND) -P CMakeFiles/math.dir/cmake_clean_target.cmake
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/custom_math/CMakeFiles/math.dir/build: include/custom_math/libmath.a
.PHONY : include/custom_math/CMakeFiles/math.dir/build

include/custom_math/CMakeFiles/math.dir/clean:
	cd /home/panic/Code/cs-projects/meshell/include/custom_math && $(CMAKE_COMMAND) -P CMakeFiles/math.dir/cmake_clean.cmake
.PHONY : include/custom_math/CMakeFiles/math.dir/clean

include/custom_math/CMakeFiles/math.dir/depend:
	cd /home/panic/Code/cs-projects/meshell && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/panic/Code/cs-projects/meshell /home/panic/Code/cs-projects/meshell/include/custom_math /home/panic/Code/cs-projects/meshell /home/panic/Code/cs-projects/meshell/include/custom_math /home/panic/Code/cs-projects/meshell/include/custom_math/CMakeFiles/math.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/custom_math/CMakeFiles/math.dir/depend
