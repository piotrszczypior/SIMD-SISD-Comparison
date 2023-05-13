cmake_minimum_required(VERSION 3.25)
project(comparison)

set(CMAKE_CXX_STANDARD 20)

add_executable(comparison main.cpp CalculatorSISD.h TimeTesterSISD.h Timer.cpp Timer.h Vector4f.h RandomGenerator.h Vector4l.h CalculatorSIMD.h TimeTesterSIMD.h RandomGenerator.cpp FileWriter.cpp FileWriter.h)
