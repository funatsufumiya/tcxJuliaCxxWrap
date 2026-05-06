# tcxJuliaCxxWrap

TrussC Julia CxxWrap.jl binding generator

## Usage

This is not actual addon, but if you add this addon into empty project, `.dll`/`.so`/`.dylib` named JLTrussC (extension is depending on your platform) will be generated.

## Build Instruction

You need to set `-DCMAKE_PREFIX_PATH` and `-DJulia_EXECUTABLE` on cmake.

Please see https://github.com/funatsufumiya/CxxWrapTest.jl in detail.

**TODO**: Write detailed build instructions here