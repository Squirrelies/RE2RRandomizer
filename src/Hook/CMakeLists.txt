project(RE2RR_Hook)

set(LOCAL_EXPORT_NAME Hook)
set(RC_INTERNALNAME "RE2RR.Hook")
set(RC_ORIGINALFILENAME "${RC_INTERNALNAME}.dll")
configure_file(${CMAKE_SOURCE_DIR}/src/VersionInfo.rc.in ${PROJECT_BINARY_DIR}/VersionInfoHook.rc @ONLY)

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

add_library(${PROJECT_NAME} ${RE2RR_LIBRARY_TYPE})
add_library(RE2RR::Hook ALIAS ${PROJECT_NAME})

set_project_compile_options(${PROJECT_NAME})
set_project_compile_definitions(${PROJECT_NAME})
set_project_link_options(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_BINARY_DIR}/VersionInfoHook.rc
        Hashes.cpp
        UI.cpp
        Randomizer.cpp
        DllHook.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${minhook_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
PRIVATE RE2RR::Common RE2RR::Types RE2RR::Database minhook
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
