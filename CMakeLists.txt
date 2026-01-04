cmake_minimum_required(VERSION 3.31)
project (RE2RRandomizer)

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

#set(VCPKG_C_FLAGS ${VCPKG_C_FLAGS} -DIM_ASSERT\(_EXPR\)=\(\(void\)\(_EXPR\)\))
#set(VCPKG_CXX_FLAGS ${VCPKG_CXX_FLAGS} -DIM_ASSERT\(_EXPR\)=\(\(void\)\(_EXPR\)\))
