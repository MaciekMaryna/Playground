cmake_minimum_required(VERSION 3.10)
project(Playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(Playground   src/main.c
                            src/multable.c
                            src/ring.c
)