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
* [mingw-w64-clang-x86_64-toolchain](https://packages.msys2.org/groups/mingw-w64-clang-x86_64-toolchain)
* [mingw-w64-clang-x86_64-cmake](https://packages.msys2.org/package/mingw-w64-clang-x86_64-cmake)

To build on Windows with VSCode, the following tutorial is useful.
[https://code.visualstudio.com/docs/cpp/config-mingw](https://code.visualstudio.com/docs/cpp/config-mingw).

## Example steps to build on a new Windows 11 installation w/o VSCode

Open Terminal as Admin and enter:

```bash
# Install MSYS2.
winget install MSYS2.MSYS2
```

open MSYS2 MINGW64 and enter:

```bash
# Install required packages.
pacman --needed -S git base-devel mingw-w64-clang-x86_64-toolchain mingw-w64-clang-x86_64-cmake
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
ctest --preset Release --output-on-failure
```

## Example steps to build on a new Debian-based Linux installation w/o VSCode

Note: Compiling MinGW-W64 manually because both Ubuntu 23.10 and Debian 13 contain older versions that are missing the typedef PFN_D3D12_SERIALIZE_ROOT_SIGNATURE in d3d12.h. We need MinGW-W64 newer than v11.x.

```bash
# Install required packages.
sudo apt-get install git clang clang++ cmake curl zip unzip tar flex bison texinfo m4
# Clone MinGW-W64
git clone https://git.code.sf.net/p/mingw-w64/mingw-w64
# Build MinGW-W64
# Follow steps at https://sourceforge.net/p/mingw-w64/wiki2/Build%20a%20native%20Windows%2064-bit%20gcc%20from%20Linux%20%28including%20cross-compiler%29/
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
ctest --preset Release --output-on-failure
```
