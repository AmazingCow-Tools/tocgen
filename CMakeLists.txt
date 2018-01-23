cmake_minimum_required(VERSION 3.7)
project(tocgen)

set(CMAKE_CXX_STANDARD 11)

include_directories(
    ./libs/CoreAssert
    ./libs/CoreFile
    ./libs/CoreFS
    ./libs/CoreLog
    ./libs/CoreString
    ./libs/libtermcolor
	./libs/acow_cpp_goodies
	./libs/acow_nt_posix
)

add_executable(tocgen
        ./libs/CoreAssert/CoreAssert/src/private/PrivateHelpers.cpp
    ./libs/CoreFile/CoreFile/src/CoreFile.cpp
    ./libs/CoreFS/CoreFS/src/CoreFS.cpp
    ./libs/CoreFS/CoreFS/src/CoreFS_Unix.cpp
    ./libs/CoreFS/CoreFS/src/CoreFS_Win32.cpp
    ./libs/CoreFS/ide/clion/main.cpp
    ./libs/CoreLog/CoreLog/src/Log.cpp
    ./libs/CoreLog/CoreLog/src/Logger.cpp
    ./libs/CoreLog/CoreLog/src/private/os_functions.cpp
    ./libs/CoreString/CoreString/libs/asprintf/asprintf.cpp
    ./libs/CoreString/CoreString/libs/asprintf/vasprintf-c99.cpp
    ./libs/CoreString/CoreString/src/CoreString.cpp
    ./libs/CoreString/main.cpp
    ./libs/libtermcolor/termcolor/src/Config.cpp
    ./libs/libtermcolor/termcolor/src/Functions.cpp
    ./libs/libtermcolor/test/main.cpp
    ./src/main.cpp
)

INSTALL(TARGETS tocgen RUNTIME DESTINATION /usr/local/bin)
