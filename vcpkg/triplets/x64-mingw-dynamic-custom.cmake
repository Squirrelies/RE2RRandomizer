# Determine VCPKG_ROOT
if (NOT DEFINED VCPKG_ROOT)
    message(STATUS "VCPKG_ROOT is not defined. Checking for environment variable...")
    if (DEFINED ENV{VCPKG_ROOT})
        set(VCPKG_ROOT $ENV{VCPKG_ROOT})
        message(STATUS "VCPKG_ROOT found in environment variables. VCPKG_ROOT is now set to ${VCPKG_ROOT}")
    else()
        set(VCPKG_ROOT "C:/vcpkg")    
        message(STATUS "VCPKG_ROOT not found in environment variables. VCPKG_ROOT is now set to ${VCPKG_ROOT}")
    endif()
endif()

include(${VCPKG_ROOT}/triplets/community/x64-mingw-dynamic.cmake)

set(VCPKG_C_FLAGS ${VCPKG_C_FLAGS} -DIM_ASSERT\(_EXPR\)=\(\(void\)\(_EXPR\)\))
set(VCPKG_CXX_FLAGS ${VCPKG_CXX_FLAGS} -DIM_ASSERT\(_EXPR\)=\(\(void\)\(_EXPR\)\))
