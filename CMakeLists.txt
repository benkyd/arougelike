cmake_minimum_required(VERSION 3.7)
project(arougelike)

set(Executable output)
set(SourceDir src) # Change src/ to your source directory

set(IncludeDir include/) # Change include/ to your include directory
include_directories(${IncludeDir})

file(GLOB_RECURSE SourceFiles
    ${SourceDir}/*.cpp
)

set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)

find_package(OpenGL REQUIRED)

if (UNIX)
    find_package(X11 REQUIRED)
    find_package(PNG REQUIRED)
    include_directories(${PNG_INCLUDE_DIR})
endif (UNIX)

if (WIN32)
    include_directories(${WinSDK})
endif (WIN32)

add_executable(${Executable} 
    ${SourceFiles}
)

link_libraries(${Executable}
    Threads::Threads
    OpenGL::OpenGL
    OpenGL::GL
    OpenGL::GLX
)

if (UNIX) 
    target_link_libraries(${Executable} 
        ${X11_LIBRARIES}
        PNG::PNG
    )
endif (UNIX)
if (WIN32)
    target_link_libraries(${Executable} 
        ${WinSDK}
    )
endif (WIN32)
