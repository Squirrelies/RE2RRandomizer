project(RE2RR_App)

set(LOCAL_PROJECT_ALIAS RE2RR::App)
set(LOCAL_EXPORT_NAME App)
set(RC_INTERNALNAME "RE2RRandomizer")
set(RC_ORIGINALFILENAME "${RC_INTERNALNAME}.exe")
configure_file(${CMAKE_SOURCE_DIR}/src/VersionInfo.rc.in ${CMAKE_CURRENT_BINARY_DIR}/VersionInfoApp.rc @ONLY)

add_executable(${PROJECT_NAME})
add_executable(${LOCAL_PROJECT_ALIAS} ALIAS ${PROJECT_NAME})

set_project_compile_options(${PROJECT_NAME})
set_project_compile_definitions(${PROJECT_NAME})
set_project_link_options(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/VersionInfoApp.rc
        ExeInjector.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/internal
)

target_link_libraries(${PROJECT_NAME}
PRIVATE RE2RR::Common RE2RR::Hook
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${RC_INTERNALNAME}
    EXPORT_NAME ${LOCAL_EXPORT_NAME}
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
