# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /snap/cmake/1210/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1210/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wxing1/snakeGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wxing1/snakeGame/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/snakeGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/snakeGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/snakeGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snakeGame.dir/flags.make

CMakeFiles/snakeGame.dir/main.c.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/main.c.o: /home/wxing1/snakeGame/main.c
CMakeFiles/snakeGame.dir/main.c.o: CMakeFiles/snakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wxing1/snakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/snakeGame.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snakeGame.dir/main.c.o -MF CMakeFiles/snakeGame.dir/main.c.o.d -o CMakeFiles/snakeGame.dir/main.c.o -c /home/wxing1/snakeGame/main.c

CMakeFiles/snakeGame.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snakeGame.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wxing1/snakeGame/main.c > CMakeFiles/snakeGame.dir/main.c.i

CMakeFiles/snakeGame.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snakeGame.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wxing1/snakeGame/main.c -o CMakeFiles/snakeGame.dir/main.c.s

CMakeFiles/snakeGame.dir/snake.c.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/snake.c.o: /home/wxing1/snakeGame/snake.c
CMakeFiles/snakeGame.dir/snake.c.o: CMakeFiles/snakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wxing1/snakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/snakeGame.dir/snake.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snakeGame.dir/snake.c.o -MF CMakeFiles/snakeGame.dir/snake.c.o.d -o CMakeFiles/snakeGame.dir/snake.c.o -c /home/wxing1/snakeGame/snake.c

CMakeFiles/snakeGame.dir/snake.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snakeGame.dir/snake.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wxing1/snakeGame/snake.c > CMakeFiles/snakeGame.dir/snake.c.i

CMakeFiles/snakeGame.dir/snake.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snakeGame.dir/snake.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wxing1/snakeGame/snake.c -o CMakeFiles/snakeGame.dir/snake.c.s

CMakeFiles/snakeGame.dir/snake_ai.c.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/snake_ai.c.o: /home/wxing1/snakeGame/snake_ai.c
CMakeFiles/snakeGame.dir/snake_ai.c.o: CMakeFiles/snakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wxing1/snakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/snakeGame.dir/snake_ai.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snakeGame.dir/snake_ai.c.o -MF CMakeFiles/snakeGame.dir/snake_ai.c.o.d -o CMakeFiles/snakeGame.dir/snake_ai.c.o -c /home/wxing1/snakeGame/snake_ai.c

CMakeFiles/snakeGame.dir/snake_ai.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snakeGame.dir/snake_ai.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wxing1/snakeGame/snake_ai.c > CMakeFiles/snakeGame.dir/snake_ai.c.i

CMakeFiles/snakeGame.dir/snake_ai.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snakeGame.dir/snake_ai.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wxing1/snakeGame/snake_ai.c -o CMakeFiles/snakeGame.dir/snake_ai.c.s

CMakeFiles/snakeGame.dir/io.c.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/io.c.o: /home/wxing1/snakeGame/io.c
CMakeFiles/snakeGame.dir/io.c.o: CMakeFiles/snakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wxing1/snakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/snakeGame.dir/io.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snakeGame.dir/io.c.o -MF CMakeFiles/snakeGame.dir/io.c.o.d -o CMakeFiles/snakeGame.dir/io.c.o -c /home/wxing1/snakeGame/io.c

CMakeFiles/snakeGame.dir/io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snakeGame.dir/io.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wxing1/snakeGame/io.c > CMakeFiles/snakeGame.dir/io.c.i

CMakeFiles/snakeGame.dir/io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snakeGame.dir/io.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wxing1/snakeGame/io.c -o CMakeFiles/snakeGame.dir/io.c.s

# Object files for target snakeGame
snakeGame_OBJECTS = \
"CMakeFiles/snakeGame.dir/main.c.o" \
"CMakeFiles/snakeGame.dir/snake.c.o" \
"CMakeFiles/snakeGame.dir/snake_ai.c.o" \
"CMakeFiles/snakeGame.dir/io.c.o"

# External object files for target snakeGame
snakeGame_EXTERNAL_OBJECTS =

snakeGame: CMakeFiles/snakeGame.dir/main.c.o
snakeGame: CMakeFiles/snakeGame.dir/snake.c.o
snakeGame: CMakeFiles/snakeGame.dir/snake_ai.c.o
snakeGame: CMakeFiles/snakeGame.dir/io.c.o
snakeGame: CMakeFiles/snakeGame.dir/build.make
snakeGame: CMakeFiles/snakeGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wxing1/snakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable snakeGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snakeGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snakeGame.dir/build: snakeGame
.PHONY : CMakeFiles/snakeGame.dir/build

CMakeFiles/snakeGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snakeGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snakeGame.dir/clean

CMakeFiles/snakeGame.dir/depend:
	cd /home/wxing1/snakeGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wxing1/snakeGame /home/wxing1/snakeGame /home/wxing1/snakeGame/cmake-build-debug /home/wxing1/snakeGame/cmake-build-debug /home/wxing1/snakeGame/cmake-build-debug/CMakeFiles/snakeGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snakeGame.dir/depend

