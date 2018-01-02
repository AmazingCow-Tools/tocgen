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
)

add_executable(tocgen
    ./src/main.cpp

    ./libs/CoreAssert/CoreAssert/CoreAssert.h
    ./libs/CoreAssert/CoreAssert/include/Assert.h
    ./libs/CoreAssert/CoreAssert/include/Config.h
    ./libs/CoreAssert/CoreAssert/include/CoreAssert_Utils.h
    ./libs/CoreAssert/CoreAssert/include/Exception.h
    ./libs/CoreAssert/CoreAssert/include/OnlyInDebug.h
    ./libs/CoreAssert/CoreAssert/include/private/PrivateHelpers.h
    ./libs/CoreAssert/CoreAssert/include/Verify.h
    ./libs/CoreFile/CoreFile/CoreFile.h
    ./libs/CoreFile/CoreFile/include/Config.h
    ./libs/CoreFile/CoreFile/include/CoreFile.h
    ./libs/CoreFile/CoreFile/include/CoreFile_Utils.h
    ./libs/CoreFS/CoreFS/CoreFS.h
    ./libs/CoreFS/CoreFS/include/CoreFS.h
    ./libs/CoreFS/CoreFS/include/CoreFS_Utils.h
    ./libs/CoreFS/CoreFS/include/private/Macros.h
    ./libs/CoreLog/CoreLog/CoreLog.h
    ./libs/CoreLog/CoreLog/include/CoreLog_Utils.h
    ./libs/CoreLog/CoreLog/include/Logger.h
    ./libs/CoreLog/CoreLog/include/Log.h
    ./libs/CoreLog/CoreLog/src/private/os_functions.h
    ./libs/CoreString/CoreString/CoreString.h
    ./libs/CoreString/CoreString/include/CoreString.h
    ./libs/CoreString/CoreString/include/CoreString_Utils.h
    ./libs/libtermcolor/termcolor/include/Color.h
    ./libs/libtermcolor/termcolor/include/Config.h
    ./libs/libtermcolor/termcolor/include/Constants.h
    ./libs/libtermcolor/termcolor/include/Functions.h
    ./libs/libtermcolor/termcolor/include/termcolor_Utils.h
    ./libs/libtermcolor/termcolor/termcolor.h


    ./libs/CoreAssert/CoreAssert/src/private/PrivateHelpers.cpp
    ./libs/CoreFile/CoreFile/src/CoreFile.cpp
    ./libs/CoreFS/CoreFS/src/CoreFS.cpp
    ./libs/CoreFS/CoreFS/src/CoreFS_GNU_Linux.cpp
    ./libs/CoreFS/CoreFS/src/CoreFS_Win32.cpp

    ./libs/CoreLog/CoreLog/src/Log.cpp
    ./libs/CoreLog/CoreLog/src/Logger.cpp
    ./libs/CoreLog/CoreLog/src/private/os_functions_gnu_linux.cpp
    ./libs/libtermcolor/termcolor/src/Config.cpp
    ./libs/libtermcolor/termcolor/src/Functions.cpp

    ./libs/CoreString/CoreString/src/CoreString.cpp
)

INSTALL(TARGETS tocgen RUNTIME DESTINATION /usr/local/bin)
