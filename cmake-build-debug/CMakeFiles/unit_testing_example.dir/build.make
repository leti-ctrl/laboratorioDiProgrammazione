# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\letiz\Desktop\laboratorioDiProgrammazione

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/unit_testing_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unit_testing_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit_testing_example.dir/flags.make

CMakeFiles/unit_testing_example.dir/main.cpp.obj: CMakeFiles/unit_testing_example.dir/flags.make
CMakeFiles/unit_testing_example.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unit_testing_example.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\unit_testing_example.dir\main.cpp.obj -c C:\Users\letiz\Desktop\laboratorioDiProgrammazione\main.cpp

CMakeFiles/unit_testing_example.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_testing_example.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\letiz\Desktop\laboratorioDiProgrammazione\main.cpp > CMakeFiles\unit_testing_example.dir\main.cpp.i

CMakeFiles/unit_testing_example.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_testing_example.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\letiz\Desktop\laboratorioDiProgrammazione\main.cpp -o CMakeFiles\unit_testing_example.dir\main.cpp.s

# Object files for target unit_testing_example
unit_testing_example_OBJECTS = \
"CMakeFiles/unit_testing_example.dir/main.cpp.obj"

# External object files for target unit_testing_example
unit_testing_example_EXTERNAL_OBJECTS =

unit_testing_example.exe: CMakeFiles/unit_testing_example.dir/main.cpp.obj
unit_testing_example.exe: CMakeFiles/unit_testing_example.dir/build.make
unit_testing_example.exe: libcore.a
unit_testing_example.exe: CMakeFiles/unit_testing_example.dir/linklibs.rsp
unit_testing_example.exe: CMakeFiles/unit_testing_example.dir/objects1.rsp
unit_testing_example.exe: CMakeFiles/unit_testing_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unit_testing_example.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\unit_testing_example.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit_testing_example.dir/build: unit_testing_example.exe

.PHONY : CMakeFiles/unit_testing_example.dir/build

CMakeFiles/unit_testing_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\unit_testing_example.dir\cmake_clean.cmake
.PHONY : CMakeFiles/unit_testing_example.dir/clean

CMakeFiles/unit_testing_example.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\letiz\Desktop\laboratorioDiProgrammazione C:\Users\letiz\Desktop\laboratorioDiProgrammazione C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\CMakeFiles\unit_testing_example.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit_testing_example.dir/depend

