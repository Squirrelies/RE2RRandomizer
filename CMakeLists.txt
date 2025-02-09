cmake_minimum_required(VERSION 3.25)
project (RE2RRandomizer)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_RE2RR_SHARED_LIBS "Build RE2RR using shared libraries" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(SetFromEnv)
include(SetProjectCompileOptions)
include(SetProjectCompileDefinitions)
include(SetProjectLinkOptions)
include(ProjectSettings)

add_subdirectory(src/Common)
add_subdirectory(src/Types)
add_subdirectory(src/Database)
add_subdirectory(src/Hook)
add_subdirectory(src/App)
