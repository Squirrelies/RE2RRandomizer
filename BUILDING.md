# Building

## To build this source code you'll need the following items

* [Git](https://git-scm.com/)
* [GCC](https://gcc.gnu.org/) (Tested with 13.2)
* [CMake](https://cmake.org/) (3.11+)
* [MinGW-w64 Headers](https://www.mingw-w64.org/) (Must be newer than v11.x as that version and older lacks PFN_D3D12_SERIALIZE_ROOT_SIGNATURE needed for DirectX 12)
* [VCPkg](https://vcpkg.io/)

On Windows, I used [MSYS2](https://www.msys2.org/) with the packages

* [git](https://packages.msys2.org/package/git)
* [base-devel](https://packages.msys2.org/package/base-devel)
* [mingw-w64-x86_64-toolchain](https://packages.msys2.org/groups/mingw-w64-x86_64-toolchain)
* [mingw-w64-x86_64-cmake](https://packages.msys2.org/package/mingw-w64-x86_64-cmake)

To build on Windows with VSCode, the following tutorial is useful.
[https://code.visualstudio.com/docs/cpp/config-mingw](https://code.visualstudio.com/docs/cpp/config-mingw).

Make sure to use the package referenced in the section [https://code.visualstudio.com/docs/cpp/config-mingw#_as-a-windows-user-running-the-pacman-command-gives-me-an-error](https://code.visualstudio.com/docs/cpp/config-mingw#_as-a-windows-user-running-the-pacman-command-gives-me-an-error) as UCRT is only available on Windows 10+ and may not be compatible with injecting into processes that support older than Windows 10.

As a result, we target the MSVCRT-style mingw-w64-x86_64 chain rather than the UCRT-style mingw-w64-ucrt-x86_64 chain.

## Example steps to build on a new Windows 11 installation w/o VSCode

Open Terminal as Admin and enter:

```bash
# Install MSYS2.
winget install MSYS2.MSYS2
```

open MSYS2 MINGW64 and enter:

```bash
# Install required packages.
pacman --needed -S git base-devel mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake
# Clone vcpkg
git clone https://github.com/microsoft/vcpkg
# Setup vcpkg.
./vcpkg/bootstrap-vcpkg.sh
export VCPKG_ROOT=~/vcpkg
# Clone repo.
git clone https://github.com/Squirrelies/RE2RRandomizer
cd RE2RRandomizer
# Configure, build, test, package.
cmake --workflow --preset Release --fresh
```
