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
CMAKE_SOURCE_DIR = "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Exo2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exo2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exo2.dir/flags.make

CMakeFiles/Exo2.dir/TP2/Exo2.cpp.obj: CMakeFiles/Exo2.dir/flags.make
CMakeFiles/Exo2.dir/TP2/Exo2.cpp.obj: ../TP2/Exo2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Exo2.dir/TP2/Exo2.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Exo2.dir\TP2\Exo2.cpp.obj -c "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\TP2\Exo2.cpp"

CMakeFiles/Exo2.dir/TP2/Exo2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exo2.dir/TP2/Exo2.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\TP2\Exo2.cpp" > CMakeFiles\Exo2.dir\TP2\Exo2.cpp.i

CMakeFiles/Exo2.dir/TP2/Exo2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exo2.dir/TP2/Exo2.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\TP2\Exo2.cpp" -o CMakeFiles\Exo2.dir\TP2\Exo2.cpp.s

# Object files for target Exo2
Exo2_OBJECTS = \
"CMakeFiles/Exo2.dir/TP2/Exo2.cpp.obj"

# External object files for target Exo2
Exo2_EXTERNAL_OBJECTS =

Exo2.exe: CMakeFiles/Exo2.dir/TP2/Exo2.cpp.obj
Exo2.exe: CMakeFiles/Exo2.dir/build.make
Exo2.exe: CMakeFiles/Exo2.dir/linklibs.rsp
Exo2.exe: CMakeFiles/Exo2.dir/objects1.rsp
Exo2.exe: CMakeFiles/Exo2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Exo2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Exo2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exo2.dir/build: Exo2.exe

.PHONY : CMakeFiles/Exo2.dir/build

CMakeFiles/Exo2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Exo2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Exo2.dir/clean

CMakeFiles/Exo2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\cmake-build-debug" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\cmake-build-debug" "C:\Users\eowal\Desktop\Cours\L2\Semestre 4\Info0402 - C++\TP\cmake-build-debug\CMakeFiles\Exo2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Exo2.dir/depend

