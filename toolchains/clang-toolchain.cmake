set(CMAKE_C_COMPILER "C:/msys64/clang64/bin/clang.exe")
set(CMAKE_C_COMPILER_ID "clang")

set(CMAKE_CXX_COMPILER "C:/msys64/clang64/bin/clang++.exe")
set(CMAKE_CXX_COMPILER_ID "clang")

set(CMAKE_C_STANDARD 23) # 90, 99, 11, 17, 23
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 23)  # 98, 11, 14, 17, 20, 23, 26
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_FLAGS_INIT "-stdlib=libc++")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-lc++ -lc++abi")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "-lc++ -lc++abi")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "-lc++ -lc++abi")
set(CMAKE_STATIC_LINKER_FLAGS_INIT "-lc++ -lc++abi")