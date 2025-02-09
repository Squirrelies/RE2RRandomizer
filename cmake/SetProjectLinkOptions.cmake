function(set_project_link_options project_name)
    set(CLANG_LINK_OPTIONS
    -municode
    -static
    -stdlib=libc++
    -lc++
    -lc++abi
    )

    target_link_options(${project_name} PRIVATE ${CLANG_LINK_OPTIONS})
endfunction()
