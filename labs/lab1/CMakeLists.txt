cmake_minimum_required(VERSION 3.23)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1 main.cpp Ship/Submarine.cpp Ship/Submarine.h Ship/Sailboat.cpp Ship/Sailboat.h Ship/Speedboat.cpp Ship/Speedboat.h Ship/Ship.cpp Ship/Ship.h ../../lib/safeInputFromFile.h ../../lib/exception.cpp ../../lib/exception.h ../../lib/checkingAccuracyOfTheInput.cpp ../../lib/checkingAccuracyOfTheInput.h ../../lib/safeInput.h Keeper/Keeper.cpp Keeper/Keeper.h Menu/Menu.cpp Menu/Menu.h Ship/NameOfClass.h)