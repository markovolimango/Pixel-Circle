cmake_minimum_required(VERSION 3.28)
project(Pixel-Circle LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_SHARED_LIBS "Build the library as a shared libray" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_library(pixel-circle
        ${PROJECT_SOURCE_DIR}/include/pixel-circle.h
        ${PROJECT_SOURCE_DIR}/src/pixel-circle.cpp
)
target_include_directories(pixel-circle PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(pixel-circle PUBLIC SFML::Graphics)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET pixel-circle POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:pixel-circle>
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    )
endif ()

add_executable(generate app/generate.cpp)
target_compile_features(generate PRIVATE cxx_std_17)
target_link_libraries(generate PRIVATE pixel-circle)