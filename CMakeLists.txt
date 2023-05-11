cmake_minimum_required(VERSION 3.24)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Do not build in-source. Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source")
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(SPM VERSION 1.0.0.0 LANGUAGES CXX)
message(${PROJECT_NAME} ${SPM_VERSION})

include(FetchContent)

FetchContent_Declare(
                    cpr
                    GIT_REPOSITORY https://github.com/libcpr/cpr.git
                    GIT_TAG 32fd1453194c37d5136577ee55629b863a42333f
)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG        v3.3.0
)
FetchContent_MakeAvailable(tomlplusplus)


file(GLOB_RECURSE SRC
     "src/*.hpp"
     "src/*.cpp"
)
message(${SRC})
add_executable(${PROJECT_NAME}
	# src/main.cpp
	${SRC}
)
target_link_libraries(${PROJECT_NAME}
    PUBLIC cpr::cpr
    PUBLIC tomlplusplus::tomlplusplus
)
target_include_directories(${PROJECT_NAME} PRIVATE src)
