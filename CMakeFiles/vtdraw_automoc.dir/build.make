# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sethbalodi/Desktop/project2-shashwb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sethbalodi/Desktop/project2-shashwb

# Utility rule file for vtdraw_automoc.

# Include the progress variables for this target.
include CMakeFiles/vtdraw_automoc.dir/progress.make

CMakeFiles/vtdraw_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/sethbalodi/Desktop/project2-shashwb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc for target vtdraw"
	/usr/local/Cellar/cmake/3.7.2/bin/cmake -E cmake_autogen /Users/sethbalodi/Desktop/project2-shashwb/CMakeFiles/vtdraw_automoc.dir/ ""

vtdraw_automoc: CMakeFiles/vtdraw_automoc
vtdraw_automoc: CMakeFiles/vtdraw_automoc.dir/build.make

.PHONY : vtdraw_automoc

# Rule to build all files generated by this target.
CMakeFiles/vtdraw_automoc.dir/build: vtdraw_automoc

.PHONY : CMakeFiles/vtdraw_automoc.dir/build

CMakeFiles/vtdraw_automoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vtdraw_automoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vtdraw_automoc.dir/clean

CMakeFiles/vtdraw_automoc.dir/depend:
	cd /Users/sethbalodi/Desktop/project2-shashwb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sethbalodi/Desktop/project2-shashwb /Users/sethbalodi/Desktop/project2-shashwb /Users/sethbalodi/Desktop/project2-shashwb /Users/sethbalodi/Desktop/project2-shashwb /Users/sethbalodi/Desktop/project2-shashwb/CMakeFiles/vtdraw_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vtdraw_automoc.dir/depend
