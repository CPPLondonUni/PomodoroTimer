# Pomodoro Timer Workshop

## Introdution

This repository requires that you have installed Qt5 on your system.

For Linux, your distribution hopefully provides it - if not, get it from https://www.qt.io

For Windows, just go to https://www.qt.io and download the open-source installer. Depending on how you intend to build it, either install MSVC x64 or the MinGW pieces from the latest STABLE Qt. Installing all targets is *not recommended* because it will be an extremely large download.

For MacOS, use homebrew or grab it from the aforementioned links if you prefer.

There is a target called "pomodorosolved" which you can build if you'd like to see how the program is supposed to operate.

## SimplePomodoro

To complete this task, you need to implement a class called SimplePomodoro in the pre-provided header/cpp files in the root of this repository.

You are encouraged to also implement ITimeFormatter into a separate usable class as you will be able to reuse this code for tasks in a future workshop. This is not required, however.

Please see interface/IPomodoro.h for details on expected behaviour.

## ThreadedPomodoro

Follow the same process as SimplePomodoro, obviously this task requires you to take care of threading yourself. You are free to write an implementation from scratch, or you can wrap your SimplePomodoro class if you wish.
