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
include CMakeFiles/meshell.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/meshell.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/meshell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/meshell.dir/flags.make

CMakeFiles/meshell.dir/src/utils.c.o: CMakeFiles/meshell.dir/flags.make
CMakeFiles/meshell.dir/src/utils.c.o: src/utils.c
CMakeFiles/meshell.dir/src/utils.c.o: CMakeFiles/meshell.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/meshell.dir/src/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/meshell.dir/src/utils.c.o -MF CMakeFiles/meshell.dir/src/utils.c.o.d -o CMakeFiles/meshell.dir/src/utils.c.o -c /home/panic/Code/cs-projects/meshell/src/utils.c

CMakeFiles/meshell.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/meshell.dir/src/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/panic/Code/cs-projects/meshell/src/utils.c > CMakeFiles/meshell.dir/src/utils.c.i

CMakeFiles/meshell.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/meshell.dir/src/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/panic/Code/cs-projects/meshell/src/utils.c -o CMakeFiles/meshell.dir/src/utils.c.s

CMakeFiles/meshell.dir/src/parser.c.o: CMakeFiles/meshell.dir/flags.make
CMakeFiles/meshell.dir/src/parser.c.o: src/parser.c
CMakeFiles/meshell.dir/src/parser.c.o: CMakeFiles/meshell.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/meshell.dir/src/parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/meshell.dir/src/parser.c.o -MF CMakeFiles/meshell.dir/src/parser.c.o.d -o CMakeFiles/meshell.dir/src/parser.c.o -c /home/panic/Code/cs-projects/meshell/src/parser.c

CMakeFiles/meshell.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/meshell.dir/src/parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/panic/Code/cs-projects/meshell/src/parser.c > CMakeFiles/meshell.dir/src/parser.c.i

CMakeFiles/meshell.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/meshell.dir/src/parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/panic/Code/cs-projects/meshell/src/parser.c -o CMakeFiles/meshell.dir/src/parser.c.s

CMakeFiles/meshell.dir/src/meshellcfg.c.o: CMakeFiles/meshell.dir/flags.make
CMakeFiles/meshell.dir/src/meshellcfg.c.o: src/meshellcfg.c
CMakeFiles/meshell.dir/src/meshellcfg.c.o: CMakeFiles/meshell.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/meshell.dir/src/meshellcfg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/meshell.dir/src/meshellcfg.c.o -MF CMakeFiles/meshell.dir/src/meshellcfg.c.o.d -o CMakeFiles/meshell.dir/src/meshellcfg.c.o -c /home/panic/Code/cs-projects/meshell/src/meshellcfg.c

CMakeFiles/meshell.dir/src/meshellcfg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/meshell.dir/src/meshellcfg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/panic/Code/cs-projects/meshell/src/meshellcfg.c > CMakeFiles/meshell.dir/src/meshellcfg.c.i

CMakeFiles/meshell.dir/src/meshellcfg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/meshell.dir/src/meshellcfg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/panic/Code/cs-projects/meshell/src/meshellcfg.c -o CMakeFiles/meshell.dir/src/meshellcfg.c.s

CMakeFiles/meshell.dir/src/main.c.o: CMakeFiles/meshell.dir/flags.make
CMakeFiles/meshell.dir/src/main.c.o: src/main.c
CMakeFiles/meshell.dir/src/main.c.o: CMakeFiles/meshell.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/meshell.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/meshell.dir/src/main.c.o -MF CMakeFiles/meshell.dir/src/main.c.o.d -o CMakeFiles/meshell.dir/src/main.c.o -c /home/panic/Code/cs-projects/meshell/src/main.c

CMakeFiles/meshell.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/meshell.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/panic/Code/cs-projects/meshell/src/main.c > CMakeFiles/meshell.dir/src/main.c.i

CMakeFiles/meshell.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/meshell.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/panic/Code/cs-projects/meshell/src/main.c -o CMakeFiles/meshell.dir/src/main.c.s

CMakeFiles/meshell.dir/include/custom_math/operations.c.o: CMakeFiles/meshell.dir/flags.make
CMakeFiles/meshell.dir/include/custom_math/operations.c.o: include/custom_math/operations.c
CMakeFiles/meshell.dir/include/custom_math/operations.c.o: CMakeFiles/meshell.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/meshell.dir/include/custom_math/operations.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/meshell.dir/include/custom_math/operations.c.o -MF CMakeFiles/meshell.dir/include/custom_math/operations.c.o.d -o CMakeFiles/meshell.dir/include/custom_math/operations.c.o -c /home/panic/Code/cs-projects/meshell/include/custom_math/operations.c

CMakeFiles/meshell.dir/include/custom_math/operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/meshell.dir/include/custom_math/operations.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/panic/Code/cs-projects/meshell/include/custom_math/operations.c > CMakeFiles/meshell.dir/include/custom_math/operations.c.i

CMakeFiles/meshell.dir/include/custom_math/operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/meshell.dir/include/custom_math/operations.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/panic/Code/cs-projects/meshell/include/custom_math/operations.c -o CMakeFiles/meshell.dir/include/custom_math/operations.c.s

# Object files for target meshell
meshell_OBJECTS = \
"CMakeFiles/meshell.dir/src/utils.c.o" \
"CMakeFiles/meshell.dir/src/parser.c.o" \
"CMakeFiles/meshell.dir/src/meshellcfg.c.o" \
"CMakeFiles/meshell.dir/src/main.c.o" \
"CMakeFiles/meshell.dir/include/custom_math/operations.c.o"

# External object files for target meshell
meshell_EXTERNAL_OBJECTS =

meshell: CMakeFiles/meshell.dir/src/utils.c.o
meshell: CMakeFiles/meshell.dir/src/parser.c.o
meshell: CMakeFiles/meshell.dir/src/meshellcfg.c.o
meshell: CMakeFiles/meshell.dir/src/main.c.o
meshell: CMakeFiles/meshell.dir/include/custom_math/operations.c.o
meshell: CMakeFiles/meshell.dir/build.make
meshell: include/custom_math/libmath.a
meshell: CMakeFiles/meshell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/panic/Code/cs-projects/meshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable meshell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/meshell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/meshell.dir/build: meshell
.PHONY : CMakeFiles/meshell.dir/build

CMakeFiles/meshell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/meshell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/meshell.dir/clean

CMakeFiles/meshell.dir/depend:
	cd /home/panic/Code/cs-projects/meshell && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/panic/Code/cs-projects/meshell /home/panic/Code/cs-projects/meshell /home/panic/Code/cs-projects/meshell /home/panic/Code/cs-projects/meshell /home/panic/Code/cs-projects/meshell/CMakeFiles/meshell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/meshell.dir/depend

