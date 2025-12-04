cmake_minimum_required(VERSION 3.10)
project(AlgoTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include 디렉토리 추가
include_directories(include)

# src 디렉토리 아래 모든 cpp 수집
file(GLOB_RECURSE ALL_SRC src/*.cpp)

# 이름에 'sovled' 가 포함된 파일을 제외
list(FILTER ALL_SRC EXCLUDE REGEX "src/.*/solved.*\\.cpp$")

add_executable(algomain ${ALL_SRC})