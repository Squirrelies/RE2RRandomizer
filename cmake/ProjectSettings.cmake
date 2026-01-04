include(SetFromEnv)

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

# Major.Minor.Patch[-PreRel]+Build-Hash
# Example: 0.1.0-rc.1+1-abcdef12
set_from_env(RC_VERSION_MAJOR 0 STRING "Version (major) of the product.")
set_from_env(RC_VERSION_MINOR 1 STRING "Version (minor) of the product.")
set_from_env(RC_VERSION_PATCH 0 STRING "Version (patch) of the product.")
set_from_env(RC_VERSION_PRERELEASE_TAG "" STRING "Version (build) of the product.")
set_from_env(RC_VERSION_BUILD_HASH "" STRING "Version (build) of the product.")
set_from_env(RC_VERSION_BUILD 1 STRING "Version (build) of the product.") # Auto-increment in build CI/CD.

set(RC_VERSION_SEMVER "${RC_VERSION_MAJOR}.${RC_VERSION_MINOR}.${RC_VERSION_PATCH}")
if(DEFINED RC_VERSION_PRERELEASE_TAG AND NOT RC_VERSION_PRERELEASE_TAG STREQUAL "")
    string(APPEND RC_VERSION_SEMVER "-${RC_VERSION_PRERELEASE_TAG}")
endif()
string(APPEND RC_VERSION_SEMVER "+${RC_VERSION_BUILD}")
if(DEFINED RC_VERSION_BUILD_HASH AND NOT RC_VERSION_BUILD_HASH STREQUAL "")
    string(APPEND RC_VERSION_SEMVER ".${RC_VERSION_BUILD_HASH}")
endif()

add_definitions("-DRE2RR_VERSION_MAJOR=${RC_VERSION_MAJOR}")
add_definitions("-DRE2RR_VERSION_MINOR=${RC_VERSION_MINOR}")
add_definitions("-DRE2RR_VERSION_PATCH=${RC_VERSION_PATCH}")
add_definitions("-DRE2RR_VERSION_PRERELEASE_TAG=\"${RC_VERSION_PRERELEASE_TAG}\"")
add_definitions("-DRE2RR_VERSION_BUILD_HASH=\"${RC_VERSION_BUILD_HASH}\"")
add_definitions("-DRE2RR_VERSION_BUILD=${RC_VERSION_BUILD}")
add_definitions("-DRE2RR_VERSION_SEMVER=\"${RC_VERSION_SEMVER}\"")
