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
CMAKE_SOURCE_DIR = F:\DragonSlayer\unit_testing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\DragonSlayer\unit_testing\cmake-build-release

# Include any dependencies generated for this target.
include lib/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include lib/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googlemock/CMakeFiles/gmock.dir/flags.make

lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: lib/googlemock/CMakeFiles/gmock.dir/flags.make
lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: lib/googlemock/CMakeFiles/gmock.dir/includes_CXX.rsp
lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: ../lib/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\DragonSlayer\unit_testing\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj"
	cd /d F:\DragonSlayer\unit_testing\cmake-build-release\lib\googlemock && F:\Software\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gmock.dir\src\gmock-all.cc.obj -c F:\DragonSlayer\unit_testing\lib\googlemock\src\gmock-all.cc

lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /d F:\DragonSlayer\unit_testing\cmake-build-release\lib\googlemock && F:\Software\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\DragonSlayer\unit_testing\lib\googlemock\src\gmock-all.cc > CMakeFiles\gmock.dir\src\gmock-all.cc.i

lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /d F:\DragonSlayer\unit_testing\cmake-build-release\lib\googlemock && F:\Software\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\DragonSlayer\unit_testing\lib\googlemock\src\gmock-all.cc -o CMakeFiles\gmock.dir\src\gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.obj"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmock.a: lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj
lib/libgmock.a: lib/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmock.a: lib/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\DragonSlayer\unit_testing\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\libgmock.a"
	cd /d F:\DragonSlayer\unit_testing\cmake-build-release\lib\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean_target.cmake
	cd /d F:\DragonSlayer\unit_testing\cmake-build-release\lib\googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gmock.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googlemock/CMakeFiles/gmock.dir/build: lib/libgmock.a

.PHONY : lib/googlemock/CMakeFiles/gmock.dir/build

lib/googlemock/CMakeFiles/gmock.dir/clean:
	cd /d F:\DragonSlayer\unit_testing\cmake-build-release\lib\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean.cmake
.PHONY : lib/googlemock/CMakeFiles/gmock.dir/clean

lib/googlemock/CMakeFiles/gmock.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\DragonSlayer\unit_testing F:\DragonSlayer\unit_testing\lib\googlemock F:\DragonSlayer\unit_testing\cmake-build-release F:\DragonSlayer\unit_testing\cmake-build-release\lib\googlemock F:\DragonSlayer\unit_testing\cmake-build-release\lib\googlemock\CMakeFiles\gmock.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/googlemock/CMakeFiles/gmock.dir/depend
