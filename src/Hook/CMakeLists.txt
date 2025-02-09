project(RE2RR_Hook)

set(LOCAL_PROJECT_ALIAS RE2RR::Hook)
set(LOCAL_PREFIX_NAME RE2RR_HOOK_)
set(LOCAL_EXPORT_NAME Hook)
set(RC_INTERNALNAME "${PROJECT_NAME}")
set(RC_ORIGINALFILENAME "${PROJECT_NAME}.dll")
configure_file(${CMAKE_SOURCE_DIR}/src/VersionInfo.rc.in ${CMAKE_CURRENT_BINARY_DIR}/VersionInfoHook.rc @ONLY)

include(FetchContent)
set(FETCHCONTENT_QUIET off)

FetchContent_Declare(
    minhook
    GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
    GIT_TAG        c1a7c3843bd1a5fe3eb779b64c0d823bca3dc339 # origin/master
    SOURCE_DIR extern/TsudaKageyu/minhook
)
FetchContent_MakeAvailable(minhook)
FetchContent_GetProperties(minhook)

# vcpkg dependencies.
find_package(imgui CONFIG REQUIRED)

# Required libraries we'll link for ImGUI.
find_library(D3D11_LIBRARY d3d11 REQUIRED)
find_library(D3D12_LIBRARY d3d12 REQUIRED)
find_library(D3DCOMPILER_LIBRARY d3dcompiler REQUIRED)
find_library(DWMAPI_LIBRARY dwmapi REQUIRED)
find_library(GDI32_LIBRARY Gdi32 REQUIRED)

# Required libraries we'll link.
find_library(DXGUID_LIBRARY dxguid REQUIRED)
find_library(DINPUT8_LIBRARY dinput8 REQUIRED)
find_library(RPCRT4_LIBRARY Rpcrt4 REQUIRED)

add_library(${PROJECT_NAME} ${RE2RR_LIBRARY_TYPE})
add_library(${LOCAL_PROJECT_ALIAS} ALIAS ${PROJECT_NAME})

set_project_compile_options(${PROJECT_NAME})
set_project_compile_definitions(${PROJECT_NAME})
set_project_link_options(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/VersionInfoHook.rc
        Types.cpp
        Hashes.cpp
        Database.cpp
        UI.cpp
        Randomizer.cpp
        DllHook.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/internal
        ${minhook_SOURCE_DIR}/include
)

target_link_libraries(imgui::imgui
INTERFACE ${D3D11_LIBRARY} ${D3D12_LIBRARY} ${D3DCOMPILER_LIBRARY} ${GDI32_LIBRARY} ${DWMAPI_LIBRARY} ${RPCRT4_LIBRARY}
)

target_link_libraries(${PROJECT_NAME}
PRIVATE RE2RR::Common minhook imgui::imgui ${DXGUID_LIBRARY} ${DINPUT8_LIBRARY}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
    EXPORT_NAME ${LOCAL_EXPORT_NAME}
)

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME}
    PREFIX_NAME ${LOCAL_PREFIX_NAME}
    EXPORT_FILE_NAME internal/Export.h
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND $<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>>:${CMAKE_STRIP}> ARGS --strip-all ${RC_ORIGINALFILENAME})

install(TARGETS ${PROJECT_NAME}
    EXPORT RE2RRTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
    DESTINATION include
)
