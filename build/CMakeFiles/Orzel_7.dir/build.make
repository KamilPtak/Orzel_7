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
CMAKE_SOURCE_DIR = /home/kamil/Desktop/Orzel_7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kamil/Desktop/Orzel_7/build

# Include any dependencies generated for this target.
include CMakeFiles/Orzel_7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Orzel_7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Orzel_7.dir/flags.make

CMakeFiles/Orzel_7.dir/src/main.cpp.o: CMakeFiles/Orzel_7.dir/flags.make
CMakeFiles/Orzel_7.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Desktop/Orzel_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Orzel_7.dir/src/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Orzel_7.dir/src/main.cpp.o -c /home/kamil/Desktop/Orzel_7/src/main.cpp

CMakeFiles/Orzel_7.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Orzel_7.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Desktop/Orzel_7/src/main.cpp > CMakeFiles/Orzel_7.dir/src/main.cpp.i

CMakeFiles/Orzel_7.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Orzel_7.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Desktop/Orzel_7/src/main.cpp -o CMakeFiles/Orzel_7.dir/src/main.cpp.s

CMakeFiles/Orzel_7.dir/src/kalman.cpp.o: CMakeFiles/Orzel_7.dir/flags.make
CMakeFiles/Orzel_7.dir/src/kalman.cpp.o: ../src/kalman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Desktop/Orzel_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Orzel_7.dir/src/kalman.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Orzel_7.dir/src/kalman.cpp.o -c /home/kamil/Desktop/Orzel_7/src/kalman.cpp

CMakeFiles/Orzel_7.dir/src/kalman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Orzel_7.dir/src/kalman.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Desktop/Orzel_7/src/kalman.cpp > CMakeFiles/Orzel_7.dir/src/kalman.cpp.i

CMakeFiles/Orzel_7.dir/src/kalman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Orzel_7.dir/src/kalman.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Desktop/Orzel_7/src/kalman.cpp -o CMakeFiles/Orzel_7.dir/src/kalman.cpp.s

CMakeFiles/Orzel_7.dir/src/motor.cpp.o: CMakeFiles/Orzel_7.dir/flags.make
CMakeFiles/Orzel_7.dir/src/motor.cpp.o: ../src/motor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Desktop/Orzel_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Orzel_7.dir/src/motor.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Orzel_7.dir/src/motor.cpp.o -c /home/kamil/Desktop/Orzel_7/src/motor.cpp

CMakeFiles/Orzel_7.dir/src/motor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Orzel_7.dir/src/motor.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Desktop/Orzel_7/src/motor.cpp > CMakeFiles/Orzel_7.dir/src/motor.cpp.i

CMakeFiles/Orzel_7.dir/src/motor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Orzel_7.dir/src/motor.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Desktop/Orzel_7/src/motor.cpp -o CMakeFiles/Orzel_7.dir/src/motor.cpp.s

CMakeFiles/Orzel_7.dir/src/vechicle.cpp.o: CMakeFiles/Orzel_7.dir/flags.make
CMakeFiles/Orzel_7.dir/src/vechicle.cpp.o: ../src/vechicle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Desktop/Orzel_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Orzel_7.dir/src/vechicle.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Orzel_7.dir/src/vechicle.cpp.o -c /home/kamil/Desktop/Orzel_7/src/vechicle.cpp

CMakeFiles/Orzel_7.dir/src/vechicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Orzel_7.dir/src/vechicle.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Desktop/Orzel_7/src/vechicle.cpp > CMakeFiles/Orzel_7.dir/src/vechicle.cpp.i

CMakeFiles/Orzel_7.dir/src/vechicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Orzel_7.dir/src/vechicle.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Desktop/Orzel_7/src/vechicle.cpp -o CMakeFiles/Orzel_7.dir/src/vechicle.cpp.s

CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.o: CMakeFiles/Orzel_7.dir/flags.make
CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.o: ../src/TCPconnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Desktop/Orzel_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.o -c /home/kamil/Desktop/Orzel_7/src/TCPconnection.cpp

CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Desktop/Orzel_7/src/TCPconnection.cpp > CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.i

CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Desktop/Orzel_7/src/TCPconnection.cpp -o CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.s

# Object files for target Orzel_7
Orzel_7_OBJECTS = \
"CMakeFiles/Orzel_7.dir/src/main.cpp.o" \
"CMakeFiles/Orzel_7.dir/src/kalman.cpp.o" \
"CMakeFiles/Orzel_7.dir/src/motor.cpp.o" \
"CMakeFiles/Orzel_7.dir/src/vechicle.cpp.o" \
"CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.o"

# External object files for target Orzel_7
Orzel_7_EXTERNAL_OBJECTS =

Orzel_7: CMakeFiles/Orzel_7.dir/src/main.cpp.o
Orzel_7: CMakeFiles/Orzel_7.dir/src/kalman.cpp.o
Orzel_7: CMakeFiles/Orzel_7.dir/src/motor.cpp.o
Orzel_7: CMakeFiles/Orzel_7.dir/src/vechicle.cpp.o
Orzel_7: CMakeFiles/Orzel_7.dir/src/TCPconnection.cpp.o
Orzel_7: CMakeFiles/Orzel_7.dir/build.make
Orzel_7: CMakeFiles/Orzel_7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kamil/Desktop/Orzel_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Orzel_7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Orzel_7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Orzel_7.dir/build: Orzel_7

.PHONY : CMakeFiles/Orzel_7.dir/build

CMakeFiles/Orzel_7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Orzel_7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Orzel_7.dir/clean

CMakeFiles/Orzel_7.dir/depend:
	cd /home/kamil/Desktop/Orzel_7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kamil/Desktop/Orzel_7 /home/kamil/Desktop/Orzel_7 /home/kamil/Desktop/Orzel_7/build /home/kamil/Desktop/Orzel_7/build /home/kamil/Desktop/Orzel_7/build/CMakeFiles/Orzel_7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Orzel_7.dir/depend

