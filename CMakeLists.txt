cmake_minimum_required(VERSION 3.7)
project(arougelike)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)

# Find GL and GLX package
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# Adds RESOURCES constant in C++
add_definitions(-DRESOURCES="${CMAKE_SOURCE_DIR}/resources/")
message(${CMAKE_SOURCE_DIR}/resources)

if (UNIX)
    find_package(X11 REQUIRED)
    find_package(PNG REQUIRED)
    include_directories(${PNG_INCLUDE_DIR})
endif (UNIX)

set(arougelike arougelike)

file(GLOB Source
    src/*.cpp
    src/generation/*.cpp
)

include_directories(${arougelike}
    "include"
    ${WinSDK}
)

add_executable(${arougelike}
    ${Source} 
)

if (UNIX) 
    target_link_libraries(${arougelike} 
        ${X11_LIBRARIES}
        PNG::PNG
    )
endif (UNIX)

target_link_libraries(${arougelike}
    ${WinSDK}
    Threads::Threads
    OpenGL::GL
)

