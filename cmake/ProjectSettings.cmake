include(SetFromEnv)

if(BUILD_SHARED_LIBS)
    add_definitions(-DBUILD_SHARED_LIBS)
else()
    add_definitions(-DBUILD_STATIC_LIBS)
endif()

if(BUILD_RE2RR_SHARED_LIBS)
    set(RE2RR_LIBRARY_TYPE SHARED)
else()
    set(RE2RR_LIBRARY_TYPE STATIC)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".dll")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")
set(CMAKE_EXECUTABLE_ENABLE_EXPORTS TRUE)

string(ASCII 169 COPYRIGHT)

# VERSIONINFO properties (Ref: https://learn.microsoft.com/en-us/windows/win32/menurc/versioninfo-resource)
set(RC_PRODUCTNAME "Resident Evil 2 REmake Randomizer")
set(RC_FILEDESCRIPTION "A randomizer for Resident Evil 2 (2019).")
set(RC_COMPANYNAME "Travis J. Gutjahr")
set(RC_LEGALCOPYRIGHT "Copyright ${COPYRIGHT} 2025 Travis J. Gutjahr")

# Major.Minor.Patch.Rev
set_from_env(RC_VERSION_MAJOR 0 STRING "Version (major) of the product.")
set_from_env(RC_VERSION_MINOR 1 STRING "Version (minor) of the product.")
set_from_env(RC_VERSION_PATCH 0 STRING "Version (patch) of the product.")
set_from_env(RC_VERSION_BUILD 1 STRING "Version (build) of the product.") # Auto-increment in build CI/CD.

add_definitions("-DRE2RR_VERSION_MAJOR=${RC_VERSION_MAJOR}")
add_definitions("-DRE2RR_VERSION_MINOR=${RC_VERSION_MINOR}")
add_definitions("-DRE2RR_VERSION_PATCH=${RC_VERSION_PATCH}")
add_definitions("-DRE2RR_VERSION_BUILD=${RC_VERSION_BUILD}")
