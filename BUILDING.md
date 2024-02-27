# Building

## To build this source code you'll need the following items

* [GCC](https://gcc.gnu.org/) (Tested with 13.2)
* [CMake](https://cmake.org/) (3.11+)
* [MinGW-w64 Headers](https://www.mingw-w64.org/)
* [VCPkg](https://vcpkg.io/)

On Windows, I used [MSYS2](https://www.msys2.org/) with the packages

* [mingw-w64-x86_64-toolchain](https://packages.msys2.org/groups/mingw-w64-x86_64-toolchain)
* [mingw-w64-x86_64-cmake](https://packages.msys2.org/package/mingw-w64-x86_64-cmake)

To build on Windows with VSCode, the following tutorial is useful.
[https://code.visualstudio.com/docs/cpp/config-mingw](https://code.visualstudio.com/docs/cpp/config-mingw).

Make sure to use the package referenced in the section [https://code.visualstudio.com/docs/cpp/config-mingw#_as-a-windows-user-running-the-pacman-command-gives-me-an-error](https://code.visualstudio.com/docs/cpp/config-mingw#_as-a-windows-user-running-the-pacman-command-gives-me-an-error) as UCRT is only available on Windows 10+ and may not be compatible with injecting into processes that support older than Windows 10.

As a result, we target the MSVCRT-style mingw-w64-x86_64 chain rather than the UCRT-style mingw-w64-ucrt-x86_64 chain.

So where it mentions `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain` you'll want to substitute that with `pacman -S --needed base-devel mingw-w64-x86_64-toolchain` and adjust pathing in the following steps accordingly.

## Example steps to build on a new Windows 11 installation w/o VSCode

Open Terminal as Admin and enter:

```bash
winget install MSYS2.MSYS2
```

open MSYS2 MINGW64 and enter:

```bash
pacman -S git mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake
git clone https://github.com/microsoft/vcpkg
./vcpkg/bootstrap-vcpkg.sh
git clone https://github.com/Squirrelies/RE2RRandomizer
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/home/<YOUR USERNAME>/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-mingw-static -DVCPKG_HOST_TRIPLET=x64-mingw-static -SRE2RRandomizer -BRE2RRandomizer/build
cmake --build RE2RRandomizer/build --parallel <Number of Threads> --target all
```
