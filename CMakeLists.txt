cmake_minimum_required(VERSION 3.2)
project(CppLondonUni_Pomodoro)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

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
