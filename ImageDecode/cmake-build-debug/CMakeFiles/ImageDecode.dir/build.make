# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/feidixie/CLionProjects/ImageDecode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/feidixie/CLionProjects/ImageDecode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ImageDecode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageDecode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageDecode.dir/flags.make

CMakeFiles/ImageDecode.dir/main.c.o: CMakeFiles/ImageDecode.dir/flags.make
CMakeFiles/ImageDecode.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/feidixie/CLionProjects/ImageDecode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ImageDecode.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ImageDecode.dir/main.c.o   -c /Users/feidixie/CLionProjects/ImageDecode/main.c

CMakeFiles/ImageDecode.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ImageDecode.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/feidixie/CLionProjects/ImageDecode/main.c > CMakeFiles/ImageDecode.dir/main.c.i

CMakeFiles/ImageDecode.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ImageDecode.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/feidixie/CLionProjects/ImageDecode/main.c -o CMakeFiles/ImageDecode.dir/main.c.s

# Object files for target ImageDecode
ImageDecode_OBJECTS = \
"CMakeFiles/ImageDecode.dir/main.c.o"

# External object files for target ImageDecode
ImageDecode_EXTERNAL_OBJECTS =

ImageDecode: CMakeFiles/ImageDecode.dir/main.c.o
ImageDecode: CMakeFiles/ImageDecode.dir/build.make
ImageDecode: CMakeFiles/ImageDecode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/feidixie/CLionProjects/ImageDecode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ImageDecode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageDecode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageDecode.dir/build: ImageDecode

.PHONY : CMakeFiles/ImageDecode.dir/build

CMakeFiles/ImageDecode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageDecode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageDecode.dir/clean

CMakeFiles/ImageDecode.dir/depend:
	cd /Users/feidixie/CLionProjects/ImageDecode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/feidixie/CLionProjects/ImageDecode /Users/feidixie/CLionProjects/ImageDecode /Users/feidixie/CLionProjects/ImageDecode/cmake-build-debug /Users/feidixie/CLionProjects/ImageDecode/cmake-build-debug /Users/feidixie/CLionProjects/ImageDecode/cmake-build-debug/CMakeFiles/ImageDecode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageDecode.dir/depend
