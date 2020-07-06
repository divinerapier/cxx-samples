cmake_minimum_required(VERSION 3.17)
project(samples)

set(CMAKE_CXX_STANDARD 14)

add_executable(samples main.cpp)

include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

target_link_libraries(samples PRIVATE nlohmann_json::nlohmann_json)