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
CMAKE_COMMAND = "F:\Software\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Software\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\DragonSlayer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\DragonSlayer\cmake-build-release

# Include any dependencies generated for this target.
include unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/flags.make

unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/flags.make
unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/includes_CXX.rsp
unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: ../unit_testing/lib/googletest-master/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\DragonSlayer\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd /d D:\DragonSlayer\cmake-build-release\unit_testing\lib\googletest-master\googletest && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\src\gtest-all.cc.obj -c D:\DragonSlayer\unit_testing\lib\googletest-master\googletest\src\gtest-all.cc

unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /d D:\DragonSlayer\cmake-build-release\unit_testing\lib\googletest-master\googletest && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DragonSlayer\unit_testing\lib\googletest-master\googletest\src\gtest-all.cc > CMakeFiles\gtest.dir\src\gtest-all.cc.i

unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /d D:\DragonSlayer\cmake-build-release\unit_testing\lib\googletest-master\googletest && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\DragonSlayer\unit_testing\lib\googletest-master\googletest\src\gtest-all.cc -o CMakeFiles\gtest.dir\src\gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
lib/libgtest.a: unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\DragonSlayer\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\..\..\lib\libgtest.a"
	cd /d D:\DragonSlayer\cmake-build-release\unit_testing\lib\googletest-master\googletest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d D:\DragonSlayer\cmake-build-release\unit_testing\lib\googletest-master\googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/build

unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/clean:
	cd /d D:\DragonSlayer\cmake-build-release\unit_testing\lib\googletest-master\googletest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/clean

unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\DragonSlayer D:\DragonSlayer\unit_testing\lib\googletest-master\googletest D:\DragonSlayer\cmake-build-release D:\DragonSlayer\cmake-build-release\unit_testing\lib\googletest-master\googletest D:\DragonSlayer\cmake-build-release\unit_testing\lib\googletest-master\googletest\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : unit_testing/lib/googletest-master/googletest/CMakeFiles/gtest.dir/depend

