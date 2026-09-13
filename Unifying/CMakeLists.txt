cmake_minimum_required(VERSION 3.16)
project(Unifying LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

# 1. Encontra o Python e o pybind11 no sistema
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

# 2. Cria o módulo C++ exportável para Python (Gera o arquivo .so)
pybind11_add_module(example unifying.cpp)