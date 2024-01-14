cmake_minimum_required(VERSION 3.11)
project (RE2RRandomizer)
#set(CMAKE_C_STANDARD 17) # 90, 99, 11, 17, 23
set(CMAKE_CXX_STANDARD 20)  # 98, 11, 14, 17, 20, 23, 26

# vcpkg dependencies.
find_package(minhook CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

# Required libraries we'll link for ImGUI.
find_library(D3D11_LIBRARY d3d11 REQUIRED)
find_library(D3DCOMPILER_LIBRARY d3dcompiler REQUIRED)
find_library(GDI32_LIBRARY Gdi32 REQUIRED)
find_library(DWMAPI_LIBRARY dwmapi REQUIRED)

# Required libraries we'll link.
find_library(DXGUID_LIBRARY dxguid REQUIRED)
find_library(DINPUT8_LIBRARY dinput8 REQUIRED)

include(CMakePrintHelpers)
cmake_print_variables(
    D3D11_LIBRARY,
    DXGUID_LIBRARY
    DINPUT8_LIBRARY,
    D3DCOMPILER_LIBRARY,
    GDI32_LIBRARY,
    DWMAPI_LIBRARY
)

add_compile_options(
    -Wall -Wextra -Wpedantic
    -m64
    $<$<CONFIG:RELEASE>:-O3> # Optimize.
    $<$<CONFIG:RELEASE>:-s> # Debug symbol stripping.
    $<$<CONFIG:DEBUG>:-O0> # No optimizations.
    $<$<CONFIG:DEBUG>:-ggdb3> # Set symbol type.
    #$<$<CONFIG:DEBUG>:-gcodeview> # Set symbol type.
    )
add_compile_definitions(
    $<$<CONFIG:RELEASE>:RELEASE>
    $<$<CONFIG:DEBUG>:DEBUG>
    UNICODE
    _UNICODE
    WIN32_LEAD_AND_MEAN
    )
add_link_options(
    -municode -static-libgcc -static-libstdc++ -static
)

target_link_libraries(imgui::imgui INTERFACE ${D3D11_LIBRARY} ${D3DCOMPILER_LIBRARY} ${GDI32_LIBRARY} ${DWMAPI_LIBRARY})
include_directories(include)

### Library
add_library(${PROJECT_NAME}Hook SHARED
src/${PROJECT_NAME}Hook.cpp
src/RE2RRUI.cpp
)
target_link_libraries(${PROJECT_NAME}Hook
PRIVATE minhook::minhook imgui::imgui ${DXGUID_LIBRARY} ${DINPUT8_LIBRARY}
)
add_custom_command(TARGET ${PROJECT_NAME}Hook POST_BUILD DEPENDS ${PROJECT_NAME}Hook COMMAND $<$<CONFIG:release>:${CMAKE_STRIP}> ARGS --strip-all lib${PROJECT_NAME}Hook.dll)

### Executable
add_executable(${PROJECT_NAME}
src/${PROJECT_NAME}.cpp
src/Strings.cpp
src/Process.cpp
)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD DEPENDS ${PROJECT_NAME} COMMAND $<$<CONFIG:release>:${CMAKE_STRIP}> ARGS --strip-all ${PROJECT_NAME}.exe)
