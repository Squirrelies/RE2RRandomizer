cmake_minimum_required(VERSION 3.11)
project (RE2RRandomizer)
#set(CMAKE_C_STANDARD 17) # 90, 99, 11, 17, 23
set(CMAKE_CXX_STANDARD 20)  # 98, 11, 14, 17, 20, 23, 26

# vcpkg dependencies.
find_package(minhook CONFIG REQUIRED)

add_compile_options(
    -Wall -Wextra -Wpedantic -Wno-overflow -Wno-unused-but-set-variable -Wno-unknown-pragmas
    $<$<CONFIG:RELEASE>:-O3> # Optimize.
    $<$<CONFIG:RELEASE>:-s> # Debug symbol stripping.
    $<$<CONFIG:DEBUG>:-O0> # No optimizations.
    $<$<CONFIG:DEBUG>:-ggdb3> # Set symbol type.
    )
add_compile_definitions(
    $<$<CONFIG:RELEASE>:RELEASE>
    $<$<CONFIG:DEBUG>:DEBUG>
    )

include_directories(include)

### Library
add_library(${PROJECT_NAME}Hook SHARED src/${PROJECT_NAME}Hook.cpp)
target_link_libraries(${PROJECT_NAME}Hook
PRIVATE minhook::minhook
)
add_custom_command(TARGET ${PROJECT_NAME}Hook POST_BUILD DEPENDS ${PROJECT_NAME}Hook COMMAND $<$<CONFIG:release>:${CMAKE_STRIP}> ARGS --strip-all ${PROJECT_NAME}Hook.dll)

### Executable
add_executable(${PROJECT_NAME}
src/${PROJECT_NAME}.cpp
)
target_link_libraries(${PROJECT_NAME}
PRIVATE minhook::minhook
)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD DEPENDS ${PROJECT_NAME} COMMAND $<$<CONFIG:release>:${CMAKE_STRIP}> ARGS --strip-all ${PROJECT_NAME}.exe)
