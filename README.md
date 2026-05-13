# tcxJuliaCxxWrap

TrussC Julia CxxWrap.jl binding generator

## About

This is not actual addon, but if you add this addon into empty project, `.dll`/`.so`/`.dylib` named JLTrussC (extension is depending on your platform) will be generated.

## Build Instruction

Please first add this addon into your `TrussC/addons` folder. Then select "Import Existing Project" from `trusscli` (TrussC Project Generator), and choose `buildJuliaProject` of this addon.

On cmake configure, you need to set `-DCMAKE_PREFIX_PATH` and `-DJulia_EXECUTABLE` in order to build `JlCxx`.

```bash
# for example, in buildJuliaProject (especially after project generator = trusscli )
# NOTE: ProjectGenerator (trusscli) cmake configure will fail without parameters below.
$ cmake -B build -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DCMAKE_PREFIX_PATH=C:/Users/fu/.julia/dev/libcxxwrap_julia_jll/override -DJulia_EXECUTABLE=C:/Users/fu/AppData/Local/Microsoft/WindowsApps/julia.exe
$ cmake --build build --parallel 8 -j 8 --config Release
```

After cmake build, `libJlTrussC.dll` / `libJlTrussc.so` / `libJlTrussC.dylib` will be generated in the folder (you can search by `fd` command etc, such as `fd -uu .dll$` or `fd -uu .so$` in your folder.)

More information about `JlCxx` build, please see https://github.com/funatsufumiya/CxxWrapTest.jl or https://github.com/JuliaInterop/CxxWrap.jl in detail.

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
