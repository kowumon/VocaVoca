# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kowum\CLionProjects\first

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kowum\CLionProjects\first\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/first.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/first.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/first.dir/flags.make

CMakeFiles/first.dir/main.c.obj: CMakeFiles/first.dir/flags.make
CMakeFiles/first.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kowum\CLionProjects\first\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/first.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\first.dir\main.c.obj   -c C:\Users\kowum\CLionProjects\first\main.c

CMakeFiles/first.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/first.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\kowum\CLionProjects\first\main.c > CMakeFiles\first.dir\main.c.i

CMakeFiles/first.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/first.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\kowum\CLionProjects\first\main.c -o CMakeFiles\first.dir\main.c.s

# Object files for target first
first_OBJECTS = \
"CMakeFiles/first.dir/main.c.obj"

# External object files for target first
first_EXTERNAL_OBJECTS =

../first.exe: CMakeFiles/first.dir/main.c.obj
../first.exe: CMakeFiles/first.dir/build.make
../first.exe: CMakeFiles/first.dir/linklibs.rsp
../first.exe: CMakeFiles/first.dir/objects1.rsp
../first.exe: CMakeFiles/first.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kowum\CLionProjects\first\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ..\first.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\first.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/first.dir/build: ../first.exe

.PHONY : CMakeFiles/first.dir/build

CMakeFiles/first.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\first.dir\cmake_clean.cmake
.PHONY : CMakeFiles/first.dir/clean

CMakeFiles/first.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kowum\CLionProjects\first C:\Users\kowum\CLionProjects\first C:\Users\kowum\CLionProjects\first\cmake-build-debug C:\Users\kowum\CLionProjects\first\cmake-build-debug C:\Users\kowum\CLionProjects\first\cmake-build-debug\CMakeFiles\first.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/first.dir/depend

