cmake_minimum_required(VERSION 3.23)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp ../../lib/safeInputFromFile.h ../../lib/exception.cpp ../../lib/exception.h ../../lib/checkingAccuracyOfTheInput.cpp ../../lib/checkingAccuracyOfTheInput.h ../../lib/safeInput.h main.cpp firstEx/train/Train.cpp firstEx/train/Train.h firstEx/list/Element.cpp firstEx/list/Element.h firstEx/list/List.cpp firstEx/list/List.h menu/MenuOfProgram.cpp menu/MenuOfProgram.h secondEx/TextAnalysis.cpp secondEx/TextAnalysis.h)