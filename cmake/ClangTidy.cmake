option(ENABLE_CLANG_TIDY "Enable clang-tidy checks during compilation" OFF)
if(ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
  if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    
    # Configuration for individual targets
    set(CMAKE_CXX_CLANG_TIDY 
        "${CLANG_TIDY_EXE}"
        "-p=${CMAKE_BINARY_DIR}"
        "-extra-arg=-Wno-unknown-warning-option")
    
    # Add a global target to run on all files
    find_program(RUN_CLANG_TIDY NAMES "run-clang-tidy")
    if(RUN_CLANG_TIDY)
      add_custom_target(tidy
        COMMAND ${RUN_CLANG_TIDY} -p ${CMAKE_BINARY_DIR} -header-filter='.*' ${PROJECT_SOURCE_DIR}/src/
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running clang-tidy on all source files"
      )
      
      # Also add a fix target to automatically apply fixes
      add_custom_target(tidy-fix
        COMMAND ${RUN_CLANG_TIDY} -p ${CMAKE_BINARY_DIR} -header-filter='.*' -fix ${PROJECT_SOURCE_DIR}/src/
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running clang-tidy with auto-fix on all source files"
      )
    else()
      message(WARNING "run-clang-tidy not found, 'tidy' target will not be available")
    endif()
  else()
    message(WARNING "clang-tidy requested but executable not found")
  endif()
else()
  message(STATUS "clang-tidy disabled")
endif()