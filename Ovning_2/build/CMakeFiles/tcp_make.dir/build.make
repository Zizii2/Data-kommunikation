# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Admin\.vscode\datakommunikation\Ovning_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Admin\.vscode\datakommunikation\Ovning_2\build

# Include any dependencies generated for this target.
include CMakeFiles/tcp_make.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tcp_make.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tcp_make.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tcp_make.dir/flags.make

CMakeFiles/tcp_make.dir/codegen:
.PHONY : CMakeFiles/tcp_make.dir/codegen

CMakeFiles/tcp_make.dir/client.cpp.obj: CMakeFiles/tcp_make.dir/flags.make
CMakeFiles/tcp_make.dir/client.cpp.obj: C:/Users/Admin/.vscode/datakommunikation/Ovning_2/client.cpp
CMakeFiles/tcp_make.dir/client.cpp.obj: CMakeFiles/tcp_make.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Admin\.vscode\datakommunikation\Ovning_2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tcp_make.dir/client.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\tcp_make.dir\client.cpp.obj.d --working-dir=C:\Users\Admin\.vscode\datakommunikation\Ovning_2\build --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2022\BUILDT~1\VC\Tools\MSVC\1441~1.341\bin\Hostx64\x64\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\tcp_make.dir\client.cpp.obj /FdCMakeFiles\tcp_make.dir/ /FS -c C:\Users\Admin\.vscode\datakommunikation\Ovning_2\client.cpp

CMakeFiles/tcp_make.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tcp_make.dir/client.cpp.i"
	C:\PROGRA~2\MICROS~2\2022\BUILDT~1\VC\Tools\MSVC\1441~1.341\bin\Hostx64\x64\cl.exe > CMakeFiles\tcp_make.dir\client.cpp.i  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Admin\.vscode\datakommunikation\Ovning_2\client.cpp

CMakeFiles/tcp_make.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tcp_make.dir/client.cpp.s"
	C:\PROGRA~2\MICROS~2\2022\BUILDT~1\VC\Tools\MSVC\1441~1.341\bin\Hostx64\x64\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\tcp_make.dir\client.cpp.s /c C:\Users\Admin\.vscode\datakommunikation\Ovning_2\client.cpp

# Object files for target tcp_make
tcp_make_OBJECTS = \
"CMakeFiles/tcp_make.dir/client.cpp.obj"

# External object files for target tcp_make
tcp_make_EXTERNAL_OBJECTS =

tcp_make.exe: CMakeFiles/tcp_make.dir/client.cpp.obj
tcp_make.exe: CMakeFiles/tcp_make.dir/build.make
tcp_make.exe: CMakeFiles/tcp_make.dir/objects1.rsp
tcp_make.exe: CMakeFiles/tcp_make.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Admin\.vscode\datakommunikation\Ovning_2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tcp_make.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tcp_make.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tcp_make.dir/build: tcp_make.exe
.PHONY : CMakeFiles/tcp_make.dir/build

CMakeFiles/tcp_make.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tcp_make.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tcp_make.dir/clean

CMakeFiles/tcp_make.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Admin\.vscode\datakommunikation\Ovning_2 C:\Users\Admin\.vscode\datakommunikation\Ovning_2 C:\Users\Admin\.vscode\datakommunikation\Ovning_2\build C:\Users\Admin\.vscode\datakommunikation\Ovning_2\build C:\Users\Admin\.vscode\datakommunikation\Ovning_2\build\CMakeFiles\tcp_make.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tcp_make.dir/depend

