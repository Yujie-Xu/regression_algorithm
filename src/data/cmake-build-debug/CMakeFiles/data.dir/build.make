# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/yujie/Downloads/clion-201.6487.17/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yujie/Downloads/clion-201.6487.17/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yujie/project/regression_algorithm/src/data

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yujie/project/regression_algorithm/src/data/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/data.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/data.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data.dir/flags.make

CMakeFiles/data.dir/make_dataset.cpp.o: CMakeFiles/data.dir/flags.make
CMakeFiles/data.dir/make_dataset.cpp.o: ../make_dataset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yujie/project/regression_algorithm/src/data/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/data.dir/make_dataset.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/data.dir/make_dataset.cpp.o -c /home/yujie/project/regression_algorithm/src/data/make_dataset.cpp

CMakeFiles/data.dir/make_dataset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data.dir/make_dataset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yujie/project/regression_algorithm/src/data/make_dataset.cpp > CMakeFiles/data.dir/make_dataset.cpp.i

CMakeFiles/data.dir/make_dataset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data.dir/make_dataset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yujie/project/regression_algorithm/src/data/make_dataset.cpp -o CMakeFiles/data.dir/make_dataset.cpp.s

# Object files for target data
data_OBJECTS = \
"CMakeFiles/data.dir/make_dataset.cpp.o"

# External object files for target data
data_EXTERNAL_OBJECTS =

data: CMakeFiles/data.dir/make_dataset.cpp.o
data: CMakeFiles/data.dir/build.make
data: CMakeFiles/data.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yujie/project/regression_algorithm/src/data/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable data"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data.dir/build: data

.PHONY : CMakeFiles/data.dir/build

CMakeFiles/data.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data.dir/clean

CMakeFiles/data.dir/depend:
	cd /home/yujie/project/regression_algorithm/src/data/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yujie/project/regression_algorithm/src/data /home/yujie/project/regression_algorithm/src/data /home/yujie/project/regression_algorithm/src/data/cmake-build-debug /home/yujie/project/regression_algorithm/src/data/cmake-build-debug /home/yujie/project/regression_algorithm/src/data/cmake-build-debug/CMakeFiles/data.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data.dir/depend
