project(RE2RR_Database)

set(LOCAL_PROJECT_ALIAS RE2RR::Database)
set(LOCAL_EXPORT_NAME Database)
set(RC_INTERNALNAME "${PROJECT_NAME}")
set(RC_ORIGINALFILENAME "${RC_INTERNALNAME}.dll")
configure_file(${CMAKE_SOURCE_DIR}/src/VersionInfo.rc.in ${PROJECT_BINARY_DIR}/VersionInfoDatabase.rc @ONLY)

add_library(${PROJECT_NAME} ${RE2RR_LIBRARY_TYPE})
add_library(${LOCAL_PROJECT_ALIAS} ALIAS ${PROJECT_NAME})

set_project_compile_options(${PROJECT_NAME})
set_project_compile_definitions(${PROJECT_NAME})
set_project_link_options(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_BINARY_DIR}/VersionInfoDatabase.rc
        Database.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${minhook_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
PRIVATE RE2RR::Common RE2RR::Types
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
