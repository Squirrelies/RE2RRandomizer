cmake_minimum_required(VERSION 3.11)
project (RE2RRandomizer)
#set(CMAKE_C_STANDARD 17) # 90, 99, 11, 17, 23
set(CMAKE_CXX_STANDARD 20)  # 98, 11, 14, 17, 20, 23, 26

include(FetchContent)
set(FETCHCONTENT_QUIET off)

FetchContent_Declare(
    SHA-2
    GIT_REPOSITORY https://github.com/amosnier/sha-2.git
    GIT_TAG        b29613850d6e54e7159197ef42c7d22d012b6367 # origin/master
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/extern/amosnier/sha-2
)
FetchContent_MakeAvailable(SHA-2)

# vcpkg dependencies.
find_package(minhook CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

# Required libraries we'll link for ImGUI.
find_library(D3D11_LIBRARY d3d11 REQUIRED)
find_library(D3D12_LIBRARY d3d12 REQUIRED)
find_library(D3DCOMPILER_LIBRARY d3dcompiler REQUIRED)
find_library(GDI32_LIBRARY Gdi32 REQUIRED)
find_library(DWMAPI_LIBRARY dwmapi REQUIRED)
find_library(RPCRT4_LIBRARY Rpcrt4 REQUIRED)

# Required libraries we'll link.
find_library(DXGUID_LIBRARY dxguid REQUIRED)
find_library(DINPUT8_LIBRARY dinput8 REQUIRED)

include(CMakePrintHelpers)
cmake_print_variables(
    D3D11_LIBRARY,
    D3D12_LIBRARY,
    DXGUID_LIBRARY
    DINPUT8_LIBRARY,
    D3DCOMPILER_LIBRARY,
    GDI32_LIBRARY,
    DWMAPI_LIBRARY,
    RPCRT4_LIBRARY
)

add_compile_options(
    -Wall -Wextra -Wpedantic
    -m64 -masm=intel
    $<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>,$<CONFIG:RELWITHDEBINFO>>:-O3> # Optimize.
    $<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>>:-s> # Debug symbol stripping.
    $<$<OR:$<CONFIG:RELWITHDEBINFO>,$<CONFIG:DEBUG>>:-ggdb3> # Set symbol type. (GDB format)
    #$<$<OR:$<CONFIG:RELWITHDEBINFO>,$<CONFIG:DEBUG>>:-gcodeview> # Set symbol type. (MSVC++ format)
    $<$<CONFIG:DEBUG>:-O0> # No optimizations.
    )
add_compile_definitions(
    $<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>>:RELEASE>
    $<$<OR:$<CONFIG:RELWITHDEBINFO>,$<CONFIG:DEBUG>>:DEBUG>
    UNICODE
    _UNICODE
    WIN32_LEAD_AND_MEAN
    )
add_link_options(
    -municode -static-libgcc -static-libstdc++ -static
)

target_link_libraries(imgui::imgui INTERFACE ${D3D11_LIBRARY} ${D3D12_LIBRARY} ${D3DCOMPILER_LIBRARY} ${GDI32_LIBRARY} ${DWMAPI_LIBRARY} ${RPCRT4_LIBRARY})
include_directories(include extern/amosnier/sha-2)

### Library
add_library(${PROJECT_NAME}Hook SHARED
extern/amosnier/sha-2/sha-256.c
src/Types.cpp
src/File.cpp
src/Hashes.cpp
src/Process.cpp
src/UI.cpp
src/SeedGenerator.cpp
src/SeedShuffler.cpp
src/Randomizer.cpp
src/DllHook.cpp
)
target_link_libraries(${PROJECT_NAME}Hook
PRIVATE minhook::minhook imgui::imgui ${DXGUID_LIBRARY} ${DINPUT8_LIBRARY}
)
add_custom_command(TARGET ${PROJECT_NAME}Hook POST_BUILD DEPENDS ${PROJECT_NAME}Hook COMMAND $<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>>:${CMAKE_STRIP}> ARGS --strip-all lib${PROJECT_NAME}Hook.dll)

### Executable
add_executable(${PROJECT_NAME}
src/ExeInjector.cpp
src/Strings.cpp
src/Process.cpp
)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD DEPENDS ${PROJECT_NAME} COMMAND $<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>>:${CMAKE_STRIP}> ARGS --strip-all ${PROJECT_NAME}.exe)
