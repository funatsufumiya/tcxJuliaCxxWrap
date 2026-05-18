# tcxZZJuliaCxxWrap

[TrussC](https://trussc.org/) Julia [CxxWrap.jl](https://github.com/JuliaInterop/CxxWrap.jl) binding generator

This addon is used to create [TrussC.jl](https://github.com/funatsufumiya/TrussC.jl) package.

## About

This is not actual addon, but if you add this addon into empty project, `.dll`/`.so`/`.dylib` named JLTrussC (extension is depending on your platform) will be generated.

## What's the name of `ZZ`

`ZZ` makes this addon at the last place in build order among other addons.
This makes build with other addons succeded (when referring other addons in addon `CMakeLists.txt`.)

This is just workaround, even if it seems weird. (Probably, there may be better ways such as use Project instead addon style.)

## Binding coverage

### Dones

- Basic trussc functions
- Vec, IVec, Mat, Quaternion
- Fbo, Texture, Image, Pixels, Shader
- Mesh, Light, Material, EasyCam
- Json, Xml
- Path, Font
- Tween (as TweeFloat, TweenVec2, TweenVec3, TweenColor)
- Sound

## Build Instruction

Please first add this addon into your `TrussC/addons` folder. Then select "Import Existing Project" from `trusscli` (TrussC Project Generator), and choose `buildJuliaProject` of this addon, then press `[Update]` to generate project `CMakeLists.txt`.

Project generate once fails on cmake configure, but it's OK at first.

Now, you need manually cmake configure, and please set `-DCMAKE_PREFIX_PATH` and `-DJulia_EXECUTABLE` in order to build `JlCxx` properly.

> [!Note]
> - `-DCMAKE_PREFIX_PATH`: This can be get by `julia --project=@. -e 'using CxxWrap; print(CxxWrap.prefix_path())'`. This command prints the `/path/to/libcxxwrap_julia_jll/override` (or just `~/.julia/artifacts/xxxxxx`). <br>
> - `-DJulia_EXECUTABLE`: Julia executable path can be get by `$(which julia)`

```bash
# for example, in buildJuliaProject (especially after project generator = trusscli )
# NOTE: ProjectGenerator (trusscli) cmake configure will fail without parameters below.
$ cmake -B build \
    -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
    -DCMAKE_PREFIX_PATH=C:/Users/fu/.julia/dev/libcxxwrap_julia_jll/override \
    -DJulia_EXECUTABLE=C:/Users/fu/AppData/Local/Microsoft/WindowsApps/julia.exe
$ cmake --build build --parallel 8 -j 8 --config Release
```

After cmake build, `libJlTrussC.dll` / `libJlTrussC.so` / `libJlTrussC.dylib` will be generated in the folder (you can search by `fd` command etc, such as `fd -uu .dll$` or `fd -uu .so$` in your folder.)

> [!Warning]
> ***Windows CxxWrap.jl issue***<br><br>
> If not working CxxWrap.jl on Windows, you need to try [Building libcxxwrap-julia](https://github.com/JuliaInterop/libcxxwrap-julia#building-libcxxwrap-julia) (Because prebuilt packaged dll for CxxWrap.jl is not compatible with MSVC).<br>
> Please see [Windows libcxxwrap_julia_jll build](https://github.com/funatsufumiya/CxxWrapTest.jl#windows-libcxxwrap_julia_jll-build) of https://github.com/funatsufumiya/CxxWrapTest.jl or https://github.com/JuliaInterop/libcxxwrap-julia in detail.<br>
>
> If it's too hard for you to manually build `libcxxwrap_julia_jll/override`, You can use [my prebuilt override.zip](https://github.com/funatsufumiya/TrussC.jl/releases/tag/libcxxwrap_julia_jll_override) (built for libcxxwrap_julia_jll 0.14.9+0, version at 2026/05/15.)

### In case of Linux -fPIC error

You may need the line below after `add_library(TrussC STATIC ${TC_ALL_SOURCES})` on `TrussC/core/CMakeLists.txt` (maybe [line at 120](https://github.com/TrussC-org/TrussC/blob/ca948f8cbb51b6de47adf61857cee2be6de0974e/core/CMakeLists.txt#L120) around.)

```cmake
# Fix error of -fPIC linux dll
set_property(TARGET TrussC PROPERTY POSITION_INDEPENDENT_CODE TRUE)
```

## Usage from Julia

see https://github.com/funatsufumiya/TrussC.jl/

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
