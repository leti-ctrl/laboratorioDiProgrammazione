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
CMAKE_SOURCE_DIR = C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug

# Include any dependencies generated for this target.
include lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/includes_CXX.rsp
lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: ../lib/googletest-release-1.8.1/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\lib\googletest-release-1.8.1\googlemock\gtest && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\src\gtest-all.cc.obj -c C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\lib\googletest-release-1.8.1\googletest\src\gtest-all.cc

lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\lib\googletest-release-1.8.1\googlemock\gtest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\lib\googletest-release-1.8.1\googletest\src\gtest-all.cc > CMakeFiles\gtest.dir\src\gtest-all.cc.i

lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\lib\googletest-release-1.8.1\googlemock\gtest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\lib\googletest-release-1.8.1\googletest\src\gtest-all.cc -o CMakeFiles\gtest.dir\src\gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/googletest-release-1.8.1/googlemock/gtest/libgtestd.a: lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
lib/googletest-release-1.8.1/googlemock/gtest/libgtestd.a: lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/build.make
lib/googletest-release-1.8.1/googlemock/gtest/libgtestd.a: lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtestd.a"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\lib\googletest-release-1.8.1\googlemock\gtest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\lib\googletest-release-1.8.1\googlemock\gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/build: lib/googletest-release-1.8.1/googlemock/gtest/libgtestd.a

.PHONY : lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/build

lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\lib\googletest-release-1.8.1\googlemock\gtest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/clean

lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\lib\googletest-release-1.8.1\googletest C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\lib\googletest-release-1.8.1\googlemock\gtest C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\cmake-build-debug\lib\googletest-release-1.8.1\googlemock\gtest\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/googletest-release-1.8.1/googlemock/gtest/CMakeFiles/gtest.dir/depend

