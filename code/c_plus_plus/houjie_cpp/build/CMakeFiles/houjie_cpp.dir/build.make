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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/snail/share/houjie_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/snail/share/houjie_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/houjie_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/houjie_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/houjie_cpp.dir/flags.make

CMakeFiles/houjie_cpp.dir/main.cpp.o: CMakeFiles/houjie_cpp.dir/flags.make
CMakeFiles/houjie_cpp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/snail/share/houjie_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/houjie_cpp.dir/main.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/houjie_cpp.dir/main.cpp.o -c /home/snail/share/houjie_cpp/main.cpp

CMakeFiles/houjie_cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/houjie_cpp.dir/main.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snail/share/houjie_cpp/main.cpp > CMakeFiles/houjie_cpp.dir/main.cpp.i

CMakeFiles/houjie_cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/houjie_cpp.dir/main.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snail/share/houjie_cpp/main.cpp -o CMakeFiles/houjie_cpp.dir/main.cpp.s

CMakeFiles/houjie_cpp.dir/my_complex.cpp.o: CMakeFiles/houjie_cpp.dir/flags.make
CMakeFiles/houjie_cpp.dir/my_complex.cpp.o: ../my_complex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/snail/share/houjie_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/houjie_cpp.dir/my_complex.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/houjie_cpp.dir/my_complex.cpp.o -c /home/snail/share/houjie_cpp/my_complex.cpp

CMakeFiles/houjie_cpp.dir/my_complex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/houjie_cpp.dir/my_complex.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snail/share/houjie_cpp/my_complex.cpp > CMakeFiles/houjie_cpp.dir/my_complex.cpp.i

CMakeFiles/houjie_cpp.dir/my_complex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/houjie_cpp.dir/my_complex.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snail/share/houjie_cpp/my_complex.cpp -o CMakeFiles/houjie_cpp.dir/my_complex.cpp.s

# Object files for target houjie_cpp
houjie_cpp_OBJECTS = \
"CMakeFiles/houjie_cpp.dir/main.cpp.o" \
"CMakeFiles/houjie_cpp.dir/my_complex.cpp.o"

# External object files for target houjie_cpp
houjie_cpp_EXTERNAL_OBJECTS =

houjie_cpp: CMakeFiles/houjie_cpp.dir/main.cpp.o
houjie_cpp: CMakeFiles/houjie_cpp.dir/my_complex.cpp.o
houjie_cpp: CMakeFiles/houjie_cpp.dir/build.make
houjie_cpp: CMakeFiles/houjie_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/snail/share/houjie_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable houjie_cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/houjie_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/houjie_cpp.dir/build: houjie_cpp

.PHONY : CMakeFiles/houjie_cpp.dir/build

CMakeFiles/houjie_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/houjie_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/houjie_cpp.dir/clean

CMakeFiles/houjie_cpp.dir/depend:
	cd /home/snail/share/houjie_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/snail/share/houjie_cpp /home/snail/share/houjie_cpp /home/snail/share/houjie_cpp/build /home/snail/share/houjie_cpp/build /home/snail/share/houjie_cpp/build/CMakeFiles/houjie_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/houjie_cpp.dir/depend

