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
include test/CMakeFiles/runTests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runTests.dir/flags.make

test/CMakeFiles/runTests.dir/runAllTest.cpp.obj: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/runAllTest.cpp.obj: test/CMakeFiles/runTests.dir/includes_CXX.rsp
test/CMakeFiles/runTests.dir/runAllTest.cpp.obj: ../test/runAllTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runTests.dir/runAllTest.cpp.obj"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runTests.dir\runAllTest.cpp.obj -c C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\runAllTest.cpp

test/CMakeFiles/runTests.dir/runAllTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/runAllTest.cpp.i"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\runAllTest.cpp > CMakeFiles\runTests.dir\runAllTest.cpp.i

test/CMakeFiles/runTests.dir/runAllTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/runAllTest.cpp.s"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\runAllTest.cpp -o CMakeFiles\runTests.dir\runAllTest.cpp.s

test/CMakeFiles/runTests.dir/AccountTest.cpp.obj: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/AccountTest.cpp.obj: test/CMakeFiles/runTests.dir/includes_CXX.rsp
test/CMakeFiles/runTests.dir/AccountTest.cpp.obj: ../test/AccountTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/runTests.dir/AccountTest.cpp.obj"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runTests.dir\AccountTest.cpp.obj -c C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\AccountTest.cpp

test/CMakeFiles/runTests.dir/AccountTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/AccountTest.cpp.i"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\AccountTest.cpp > CMakeFiles\runTests.dir\AccountTest.cpp.i

test/CMakeFiles/runTests.dir/AccountTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/AccountTest.cpp.s"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\AccountTest.cpp -o CMakeFiles\runTests.dir\AccountTest.cpp.s

test/CMakeFiles/runTests.dir/AccountFixture.cpp.obj: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/AccountFixture.cpp.obj: test/CMakeFiles/runTests.dir/includes_CXX.rsp
test/CMakeFiles/runTests.dir/AccountFixture.cpp.obj: ../test/AccountFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/runTests.dir/AccountFixture.cpp.obj"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runTests.dir\AccountFixture.cpp.obj -c C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\AccountFixture.cpp

test/CMakeFiles/runTests.dir/AccountFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/AccountFixture.cpp.i"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\AccountFixture.cpp > CMakeFiles\runTests.dir\AccountFixture.cpp.i

test/CMakeFiles/runTests.dir/AccountFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/AccountFixture.cpp.s"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\AccountFixture.cpp -o CMakeFiles\runTests.dir\AccountFixture.cpp.s

test/CMakeFiles/runTests.dir/TransactionFixture.cpp.obj: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/TransactionFixture.cpp.obj: test/CMakeFiles/runTests.dir/includes_CXX.rsp
test/CMakeFiles/runTests.dir/TransactionFixture.cpp.obj: ../test/TransactionFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/runTests.dir/TransactionFixture.cpp.obj"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runTests.dir\TransactionFixture.cpp.obj -c C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\TransactionFixture.cpp

test/CMakeFiles/runTests.dir/TransactionFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/TransactionFixture.cpp.i"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\TransactionFixture.cpp > CMakeFiles\runTests.dir\TransactionFixture.cpp.i

test/CMakeFiles/runTests.dir/TransactionFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/TransactionFixture.cpp.s"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test\TransactionFixture.cpp -o CMakeFiles\runTests.dir\TransactionFixture.cpp.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/runAllTest.cpp.obj" \
"CMakeFiles/runTests.dir/AccountTest.cpp.obj" \
"CMakeFiles/runTests.dir/AccountFixture.cpp.obj" \
"CMakeFiles/runTests.dir/TransactionFixture.cpp.obj"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

test/runTests.exe: test/CMakeFiles/runTests.dir/runAllTest.cpp.obj
test/runTests.exe: test/CMakeFiles/runTests.dir/AccountTest.cpp.obj
test/runTests.exe: test/CMakeFiles/runTests.dir/AccountFixture.cpp.obj
test/runTests.exe: test/CMakeFiles/runTests.dir/TransactionFixture.cpp.obj
test/runTests.exe: test/CMakeFiles/runTests.dir/build.make
test/runTests.exe: test/lib/googletest/googlemock/gtest/libgtestd.a
test/runTests.exe: test/lib/googletest/googlemock/gtest/libgtest_maind.a
test/runTests.exe: libcore.a
test/runTests.exe: test/lib/googletest/googlemock/gtest/libgtestd.a
test/runTests.exe: test/CMakeFiles/runTests.dir/linklibs.rsp
test/runTests.exe: test/CMakeFiles/runTests.dir/objects1.rsp
test/runTests.exe: test/CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable runTests.exe"
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\runTests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runTests.dir/build: test/runTests.exe

.PHONY : test/CMakeFiles/runTests.dir/build

test/CMakeFiles/runTests.dir/clean:
	cd /d C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test && $(CMAKE_COMMAND) -P CMakeFiles\runTests.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/runTests.dir/clean

test/CMakeFiles/runTests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\letiz\Desktop\laboratorioDiProgrammazione C:\Users\letiz\Desktop\laboratorioDiProgrammazione\test C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test C:\Users\letiz\Desktop\laboratorioDiProgrammazione\cmake-build-debug\test\CMakeFiles\runTests.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runTests.dir/depend

