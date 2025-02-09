project(RE2RR_Common)

set(LOCAL_PROJECT_ALIAS RE2RR::Common)
set(LOCAL_PREFIX_NAME RE2RR_COMMON_)
set(LOCAL_EXPORT_NAME Common)
set(RC_INTERNALNAME "${PROJECT_NAME}")
set(RC_ORIGINALFILENAME "${PROJECT_NAME}.dll")
configure_file(${CMAKE_SOURCE_DIR}/src/VersionInfo.rc.in ${CMAKE_CURRENT_BINARY_DIR}/VersionInfoCommon.rc @ONLY)

add_library(${PROJECT_NAME} ${RE2RR_LIBRARY_TYPE})
add_library(${LOCAL_PROJECT_ALIAS} ALIAS ${PROJECT_NAME})

set_project_compile_options(${PROJECT_NAME})
set_project_compile_definitions(${PROJECT_NAME})
set_project_link_options(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/VersionInfoCommon.rc
        File.cpp
        Process.cpp
        Strings.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/internal
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
