# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\eowal\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\eowal\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/Pile/main.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Pile/main.c.obj: ../Pile/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/Pile/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\main.dir\Pile\main.c.obj   -c "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\Pile\main.c"

CMakeFiles/main.dir/Pile/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Pile/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\Pile\main.c" > CMakeFiles\main.dir\Pile\main.c.i

CMakeFiles/main.dir/Pile/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Pile/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\Pile\main.c" -o CMakeFiles\main.dir\Pile\main.c.s

CMakeFiles/main.dir/Pile/pile.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Pile/pile.c.obj: ../Pile/pile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/Pile/pile.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\main.dir\Pile\pile.c.obj   -c "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\Pile\pile.c"

CMakeFiles/main.dir/Pile/pile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Pile/pile.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\Pile\pile.c" > CMakeFiles\main.dir\Pile\pile.c.i

CMakeFiles/main.dir/Pile/pile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Pile/pile.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\Pile\pile.c" -o CMakeFiles\main.dir\Pile\pile.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Pile/main.c.obj" \
"CMakeFiles/main.dir/Pile/pile.c.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/Pile/main.c.obj
main.exe: CMakeFiles/main.dir/Pile/pile.c.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: CMakeFiles/main.dir/linklibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\cmake-build-debug" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\cmake-build-debug" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0401 - Algorithmique\TP\cmake-build-debug\CMakeFiles\main.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

