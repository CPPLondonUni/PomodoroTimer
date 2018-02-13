cmake_minimum_required(VERSION 3.2)
project(CppLondonUni_Pomodoro)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if (WIN32)
	message(NOTE "When building on Windows, You are expected to have QT installed to \\QT. Otherwise, you must set CMAKE_PREFIX_PATH manually")
	message(NOTE "Qt 5.10.1 is the default expected, please override this via QT_VERSION if you have a newer/older version of Qt5")
	set(QT_VERSION "5.10.1" CACHE PATH "Version of Qt5 you have installed")
	if (MSVC)
		message(NOTE "We currently only support MSVC2017. You will need to modify the CMakeLists.txt if you wish to use an older version.")
		set(CMAKE_PREFIX_PATH "C:\\Qt\\${QT_VERSION}\\msvc2017_64\\")
	else()
		set(CMAKE_PREFIX_PATH /Qt/${QT_VERSION}/mingw53_32/)
	endif()
	message(STATUS "Got Prefix path: ${CMAKE_PREFIX_PATH}")
endif()

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
include(FindThreads)

add_executable(pomodorosolved DO_NOT_READ/main.cpp
                              DO_NOT_READ/pomodoro.cpp
                              DO_NOT_READ/Solved/ThreadedPomodoro.cpp 
                              DO_NOT_READ/Solved/pomodorotimeformatter.cpp)
target_link_libraries(pomodorosolved Qt5::Core Qt5::Widgets Threads::Threads)
target_include_directories(pomodorosolved PRIVATE DO_NOT_READ/Solved
                                                  interface/
                                                  ${Qt5Core_INCLUDE_DIRS}
                                                  ${Qt5Widgets_INCLUDE_DIRS})
set_target_properties(pomodorosolved PROPERTIES CXX_STANDARD 14
                                                CXX_STANDARD_REQUIRED YES)

add_executable(pomodorosimple DO_NOT_READ/main.cpp
                              DO_NOT_READ/pomodoro.cpp
                              DO_NOT_READ/Simple/ThreadedPomodoro.cpp
                              SimplePomodoro.cpp)
target_link_libraries(pomodorosimple Qt5::Core
                                     Qt5::Widgets
                                     Threads::Threads)
target_include_directories(pomodorosimple PRIVATE DO_NOT_READ/Simple
                                                  interface/
                                                  .
                                                  ${Qt5Core_INCLUDE_DIRS}
                                                  ${Qt5Widgets_INCLUDE_DIRS})
set_target_properties(pomodorosimple PROPERTIES CXX_STANDARD 14
                                                CXX_STANDARD_REQUIRED YES)
                                                
add_executable(pomodorothreaded DO_NOT_READ/main.cpp
                                DO_NOT_READ/pomodoro.cpp
                                ThreadedPomodoro.cpp)
target_link_libraries(pomodorothreaded Qt5::Core
                                       Qt5::Widgets
                                       Threads::Threads)
target_include_directories(pomodorothreaded PRIVATE .
                                            interface/
                                            DO_NOT_READ/
                                            ${Qt5Core_INCLUDE_DIRS}
                                            ${Qt5Widgets_INCLUDE_DIRS})
set_target_properties(pomodorothreaded PROPERTIES CXX_STANDARD 14
                                                CXX_STANDARD_REQUIRED YES)
