cmake_minimum_required(VERSION 3.10)
project(AlgoTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include 디렉토리 추가
include_directories(include)

# src 디렉토리 아래 모든 cpp 수집
file(GLOB SRC_FILES ./*.cpp)

add_executable(algomain ${SRC_FILES})