project(RE2RR_Common)

set(LOCAL_EXPORT_NAME Common)
set(RC_INTERNALNAME "RE2RR.Common")
set(RC_ORIGINALFILENAME "${RC_INTERNALNAME}.dll")
configure_file(${CMAKE_SOURCE_DIR}/src/VersionInfo.rc.in ${PROJECT_BINARY_DIR}/VersionInfoCommon.rc @ONLY)

include(FetchContent)
set(FETCHCONTENT_QUIET off)

FetchContent_Declare(
    SHA-2
    GIT_REPOSITORY https://github.com/amosnier/sha-2.git
    GIT_TAG        565f65009bdd98267361b17d50cddd7c9beb3e6c # origin/master
    SOURCE_DIR extern/amosnier/sha-2
)
FetchContent_MakeAvailable(SHA-2)
FetchContent_GetProperties(SHA-2)

set_property(TARGET Git::Git PROPERTY IMPORTED_IMPLIB "${GIT_EXECUTABLE}")

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

add_library(${PROJECT_NAME} SHARED)
add_library(RE2RR::Common ALIAS ${PROJECT_NAME})

set_project_compile_options(${PROJECT_NAME})
set_project_compile_definitions(${PROJECT_NAME})
set_project_link_options(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_BINARY_DIR}/VersionInfoCommon.rc
        extern/amosnier/sha-2/sha-256.c
        Common.cpp
        Collections.cpp
        File.cpp
        Logging.cpp
        Memory.cpp
        Process.cpp
        Strings.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${sha-2_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
PUBLIC imgui::imgui
INTERFACE ${D3D11_LIBRARY} ${D3D12_LIBRARY} ${D3DCOMPILER_LIBRARY} ${GDI32_LIBRARY} ${DWMAPI_LIBRARY} ${RPCRT4_LIBRARY} ${DXGUID_LIBRARY} ${DINPUT8_LIBRARY}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${RC_INTERNALNAME}
    EXPORT_NAME ${LOCAL_EXPORT_NAME}
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND $<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>>:${CMAKE_STRIP}> ARGS --strip-all $<TARGET_FILE:${PROJECT_NAME}>)

install(TARGETS ${PROJECT_NAME}
    EXPORT RE2RRTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
    DESTINATION include
)
