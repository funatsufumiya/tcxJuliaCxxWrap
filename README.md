# tcxJuliaCxxWrap

TrussC Julia CxxWrap.jl binding generator

## About

This is not actual addon, but if you add this addon into empty project, `.dll`/`.so`/`.dylib` named JLTrussC (extension is depending on your platform) will be generated.

## Build Instruction

You need to set `-DCMAKE_PREFIX_PATH` and `-DJulia_EXECUTABLE` on cmake.

```bash
# for example
$ cmake -B build -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DCMAKE_PREFIX_PATH=C:/Users/fu/.julia/dev/libcxxwrap_julia_jll/override -DJulia_EXECUTABLE=C:/Users/fu/AppData/Local/Microsoft/WindowsApps/julia.exe
$ cmake --build build --parallel 8 -j 8 --config Release
```

Please see https://github.com/funatsufumiya/CxxWrapTest.jl in detail.

> [!NOTE]
> **TODO**: Write detailed build instructions here

### In case of Linux -fPIC error

You may need the line below after `add_library(TrussC STATIC ${TC_ALL_SOURCES})` on `TrussC/core/CMakeLists.txt` (maybe line at 120 around.)

```cmake
# Fix error of -fPIC linux dll
set_property(TARGET TrussC PROPERTY POSITION_INDEPENDENT_CODE TRUE)
```

## Usage from Julia

see https://github.com/funatsufumiya/JlTrussCTest.jl/

> [!NOTE]
> **TODO**: Write in detail

## Development

### Bindgen

Please read [tools/bindgen/README.md](tools/bindgen/README.md) in detail.

```bash
$ cd tools/bingen
# $ pip install uv # only at first time
# $ uv sync # only at first time
$ uv run main.py ../../../../core/include/TrussC.h
$ cp trussc_generated.cpp ../../src/generated
```