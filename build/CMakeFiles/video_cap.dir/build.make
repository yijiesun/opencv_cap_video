# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/syj/work/vid_cap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/syj/work/vid_cap/build

# Include any dependencies generated for this target.
include CMakeFiles/video_cap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/video_cap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/video_cap.dir/flags.make

CMakeFiles/video_cap.dir/src/main.cpp.o: CMakeFiles/video_cap.dir/flags.make
CMakeFiles/video_cap.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syj/work/vid_cap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/video_cap.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/video_cap.dir/src/main.cpp.o -c /home/syj/work/vid_cap/src/main.cpp

CMakeFiles/video_cap.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/video_cap.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syj/work/vid_cap/src/main.cpp > CMakeFiles/video_cap.dir/src/main.cpp.i

CMakeFiles/video_cap.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/video_cap.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syj/work/vid_cap/src/main.cpp -o CMakeFiles/video_cap.dir/src/main.cpp.s

CMakeFiles/video_cap.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/video_cap.dir/src/main.cpp.o.requires

CMakeFiles/video_cap.dir/src/main.cpp.o.provides: CMakeFiles/video_cap.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/video_cap.dir/build.make CMakeFiles/video_cap.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/video_cap.dir/src/main.cpp.o.provides

CMakeFiles/video_cap.dir/src/main.cpp.o.provides.build: CMakeFiles/video_cap.dir/src/main.cpp.o


CMakeFiles/video_cap.dir/src/include/config.cpp.o: CMakeFiles/video_cap.dir/flags.make
CMakeFiles/video_cap.dir/src/include/config.cpp.o: ../src/include/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syj/work/vid_cap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/video_cap.dir/src/include/config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/video_cap.dir/src/include/config.cpp.o -c /home/syj/work/vid_cap/src/include/config.cpp

CMakeFiles/video_cap.dir/src/include/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/video_cap.dir/src/include/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syj/work/vid_cap/src/include/config.cpp > CMakeFiles/video_cap.dir/src/include/config.cpp.i

CMakeFiles/video_cap.dir/src/include/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/video_cap.dir/src/include/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syj/work/vid_cap/src/include/config.cpp -o CMakeFiles/video_cap.dir/src/include/config.cpp.s

CMakeFiles/video_cap.dir/src/include/config.cpp.o.requires:

.PHONY : CMakeFiles/video_cap.dir/src/include/config.cpp.o.requires

CMakeFiles/video_cap.dir/src/include/config.cpp.o.provides: CMakeFiles/video_cap.dir/src/include/config.cpp.o.requires
	$(MAKE) -f CMakeFiles/video_cap.dir/build.make CMakeFiles/video_cap.dir/src/include/config.cpp.o.provides.build
.PHONY : CMakeFiles/video_cap.dir/src/include/config.cpp.o.provides

CMakeFiles/video_cap.dir/src/include/config.cpp.o.provides.build: CMakeFiles/video_cap.dir/src/include/config.cpp.o


CMakeFiles/video_cap.dir/src/include/functions.cpp.o: CMakeFiles/video_cap.dir/flags.make
CMakeFiles/video_cap.dir/src/include/functions.cpp.o: ../src/include/functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syj/work/vid_cap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/video_cap.dir/src/include/functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/video_cap.dir/src/include/functions.cpp.o -c /home/syj/work/vid_cap/src/include/functions.cpp

CMakeFiles/video_cap.dir/src/include/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/video_cap.dir/src/include/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syj/work/vid_cap/src/include/functions.cpp > CMakeFiles/video_cap.dir/src/include/functions.cpp.i

CMakeFiles/video_cap.dir/src/include/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/video_cap.dir/src/include/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syj/work/vid_cap/src/include/functions.cpp -o CMakeFiles/video_cap.dir/src/include/functions.cpp.s

CMakeFiles/video_cap.dir/src/include/functions.cpp.o.requires:

.PHONY : CMakeFiles/video_cap.dir/src/include/functions.cpp.o.requires

CMakeFiles/video_cap.dir/src/include/functions.cpp.o.provides: CMakeFiles/video_cap.dir/src/include/functions.cpp.o.requires
	$(MAKE) -f CMakeFiles/video_cap.dir/build.make CMakeFiles/video_cap.dir/src/include/functions.cpp.o.provides.build
.PHONY : CMakeFiles/video_cap.dir/src/include/functions.cpp.o.provides

CMakeFiles/video_cap.dir/src/include/functions.cpp.o.provides.build: CMakeFiles/video_cap.dir/src/include/functions.cpp.o


# Object files for target video_cap
video_cap_OBJECTS = \
"CMakeFiles/video_cap.dir/src/main.cpp.o" \
"CMakeFiles/video_cap.dir/src/include/config.cpp.o" \
"CMakeFiles/video_cap.dir/src/include/functions.cpp.o"

# External object files for target video_cap
video_cap_EXTERNAL_OBJECTS =

video_cap: CMakeFiles/video_cap.dir/src/main.cpp.o
video_cap: CMakeFiles/video_cap.dir/src/include/config.cpp.o
video_cap: CMakeFiles/video_cap.dir/src/include/functions.cpp.o
video_cap: CMakeFiles/video_cap.dir/build.make
video_cap: /usr/local/lib/libopencv_dnn.so.4.1.0
video_cap: /usr/local/lib/libopencv_gapi.so.4.1.0
video_cap: /usr/local/lib/libopencv_ml.so.4.1.0
video_cap: /usr/local/lib/libopencv_objdetect.so.4.1.0
video_cap: /usr/local/lib/libopencv_photo.so.4.1.0
video_cap: /usr/local/lib/libopencv_stitching.so.4.1.0
video_cap: /usr/local/lib/libopencv_video.so.4.1.0
video_cap: /usr/local/lib/libopencv_calib3d.so.4.1.0
video_cap: /usr/local/lib/libopencv_features2d.so.4.1.0
video_cap: /usr/local/lib/libopencv_flann.so.4.1.0
video_cap: /usr/local/lib/libopencv_highgui.so.4.1.0
video_cap: /usr/local/lib/libopencv_videoio.so.4.1.0
video_cap: /usr/local/lib/libopencv_imgcodecs.so.4.1.0
video_cap: /usr/local/lib/libopencv_imgproc.so.4.1.0
video_cap: /usr/local/lib/libopencv_core.so.4.1.0
video_cap: CMakeFiles/video_cap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/syj/work/vid_cap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable video_cap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/video_cap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/video_cap.dir/build: video_cap

.PHONY : CMakeFiles/video_cap.dir/build

CMakeFiles/video_cap.dir/requires: CMakeFiles/video_cap.dir/src/main.cpp.o.requires
CMakeFiles/video_cap.dir/requires: CMakeFiles/video_cap.dir/src/include/config.cpp.o.requires
CMakeFiles/video_cap.dir/requires: CMakeFiles/video_cap.dir/src/include/functions.cpp.o.requires

.PHONY : CMakeFiles/video_cap.dir/requires

CMakeFiles/video_cap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/video_cap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/video_cap.dir/clean

CMakeFiles/video_cap.dir/depend:
	cd /home/syj/work/vid_cap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/syj/work/vid_cap /home/syj/work/vid_cap /home/syj/work/vid_cap/build /home/syj/work/vid_cap/build /home/syj/work/vid_cap/build/CMakeFiles/video_cap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/video_cap.dir/depend

