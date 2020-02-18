cmake_minimum_required(VERSION 2.8.0)

# your project name
set(project_name hope_you_love_coding)

# build option
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

# Export your compile_commands.json file to build directory
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++ standard
set(CMAKE_CXX_STANDARD 11)

# declare yor project
project(${project_name})

# global include path setting
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(include)

# output directory redirection
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# add libexample 
add_library(example SHARED src/package_name/module_name/example.cpp)

# add example_app
add_executable(example_app src/package_name/app_name/example_app.cpp)
target_link_libraries(example_app PUBLIC example)
add_dependencies(example_app example)
