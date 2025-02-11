function(set_project_compile_options project_name)
    set(CLANG_COMPILE_OPTIONS
    -Wall
    -Wextra
    -Wpedantic
    -m64
    -masm=intel
    $<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>,$<CONFIG:RELWITHDEBINFO>>:-O3> # Optimize.
    #$<$<OR:$<CONFIG:RELEASE>,$<CONFIG:MINSIZEREL>>:-s> # Debug symbol stripping. [Requires GCC]
    $<$<OR:$<CONFIG:RELWITHDEBINFO>,$<CONFIG:DEBUG>>:-g> # Set symbol type.
    #$<$<OR:$<CONFIG:RELWITHDEBINFO>,$<CONFIG:DEBUG>>:-gcodeview> # Set symbol type. (MSVC++ format) [Requires GCC 14+ or clang]
    $<$<CONFIG:DEBUG>:-O0> # No optimizations.
    )

    target_compile_options(${project_name} PRIVATE ${CLANG_COMPILE_OPTIONS} ${ARGN})
endfunction()
