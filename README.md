# softintrin-avx2
Faster SSE/AVX/AVX2 software intrinsics for use with VS2022 and Windows SDK for even easier porting to Windows on ARM!

## Summary:

This project consists of two C/C++ header files which provide enhancements to the existing [ARM64EC](http://www.emulators.com/docs/abc_arm64ec_explained.htm) "soft intrinsics" provided in the Windows 24H2 SDK (build 10.0.26100).  The goal is to provide additional performance and functionality compared to what ships in the Windows SDK.  For Windows developers who are unfamiliar with ARM64 or NEON, to simplify porting existing Windows applications from Intel to ARM64 this project provides:

- over 100 new 256-bit AVX2 soft intrinsics for ARM64 and ARM64EC not implemented in the Windows SDK, more in progress

- optimizations to existing SSE soft intrinsics already in the SDK (for example, over 15x speedup for ToyPathTracer ray tracing demo just by adding and recompiling with these two .H files)

- test suite for over 320 SSE4 and AVX2 intrinsics, more in progress, very useful for validating the performance and correctness not only of these soft intrinsics but for emulators such as Prism, QEMU, and Rosetta

- native ARM64 support for soft intrinsics, including the ability to now use Visual Studio's `dvec.h` 128-bit SSE and 256-bit AVX2 vector classes

- work arounds for the "error C7302: AVX types (__m256) are not currently supported in ARM64EC code" compiler block in Visual Studio 2022

- faster link times and smaller compiled binary sizes for both ARM64EC and pure native ARM64 compared to what is currently generated by the SDK

- native ARM64 compatibility with Windows 10 on ARM and Snapdragon 835 based devices such as ASUS Novago, HP Envy X2, and Lenovo Miix (whereas ARM64EC has always required Windows 11 on ARM)

To help developers write *new* native ARM64 code without needing to learn NEON, *native twin* soft intrinsics are also provided which wrap native NEON intrinsics as familiar SSE/AVX names and execute with SSE/AVX behaviour.  For example, Intel and ARM implement different behaviour for computing floating point square roots on negative numbers.  The `_mm_sqrt_ps()` SSE soft intrinsic is thus paired with a twin `_nn_sqrt_ps()` soft intrinsic such that both provide the correct Intel behaviour.  In other words, you can write new ARM64 code using NEON directly but using the familiar Intel intrinsic names and behaviours that you already know.


## How to install:

Copy the two header files `use_soft_intrin.h` and `softintrin_avx2.h` to a path in your project's `INCLUDE` path or to the directory where the existing `softintrin.h` resides.  For example, if you have the latest official Windows SDK 10.0.26100 installed, that location is likely:

    c:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\

Then, add this line of code to each source file in your project where there is either an `#include <windows.h>` or `#include <intrin.h>`.  This line should be placed right _before_ those existing includes, not after, in order to work around the compiler's _m256 block.

    #include <use_soft_intrinsics.h>

Optionally you can do an in-place replace of `#include <intrin.h>` with `#include <use_soft_intrinsics.h>`, this will not break existing x86/x64 builds.  You can skip source files that are not performance critical or do no contain any Intel-specific intrinsics since at worse they will simply use the existing soft intrinsics.  Again, this project is an overlay on top of the SDK's existing reference implementation, not a full replacement, so just layer it on in source files where it matters.

If your project is already building as ARM64EC, then nothing else is required other than to rebuild your project and experience up to 15x faster performance!


## How about a demo?!?!

As a demo of ARM64EC soft intrinsics, our [fork of ToyPathTracer](https://github.com/softmac/ToyPathTracer) demonstrates in a handful of additional commits (on top of their tip of tree) how to add ARM64EC and ARM64 targets to an existing x86/x64 Visual Studio project and shows the minor source code edits to make the code compile using these new soft intrinsic.  The whole port from x64 to ARM64 only takes a few minutes!

Build all 4 Release targets - x86, x64, ARM64EC, and ARM64.  The x86 and x64 builds are exactly as-is as provided in the original [ToyPathTracer](https://github.com/aras-p/ToyPathTracer) project, the ARM64EC and ARM64 targets are what the fork branch adds.

You can see from the compiled binary sizes of each of the 4 targets that these new soft intrinsics combined with a native ARM64 build produce a binary size much smaller than either x64 or ARM64EC, and similar size as plain old 32-bit x86:

    167936    4/9/2025    9:09:59 AM  G:\BUILDS\ToyPathTracer.git\Cpp\Windows\ARM64\Release\ToyPathTracer.exe
    188416    4/9/2025    6:14:53 AM  G:\BUILDS\ToyPathTracer.git\Cpp\Windows\ARM64EC\Release\ToyPathTracer.exe
    163328    4/9/2025    6:14:47 AM  G:\BUILDS\ToyPathTracer.git\Cpp\Windows\Release\ToyPathTracer.exe
    185344    4/9/2025    6:14:50 AM  G:\BUILDS\ToyPathTracer.git\Cpp\Windows\x64\Release\ToyPathTracer.exe

For comparison, the unmodified ARM64EC-built binary using the SDK's reference implementation of soft intrinsics results in a considerably larger executable:

    206336   4/10/2025    6:50:38 AM  G:\BUILDS\ToyPathTracer.git\Cpp\Windows\ARM64EC\Release\ToyPathTracer.exe

On a Windows on ARM device - such as Surface Pro X, Surface Pro 9, Surface Pro 11 - run each of the 4 binaries produced (in theory you installed Visual Studio 2022 on your ARM device directly and can just press F5 on each).  What you should find, for example, on a Snapdragon X based Surface Pro 11, is that the 32-bit x86 binary renders at about 7 frames per second in CPU mode, the 64-bit x64 binary renders at about 9 frames per second in emulation (I'm testing on latest Windows Insider Canary 278xx builds), and both the ARM64EC and ARM64 builds render at about... wait for it... 0.5 frames per second, or 2 seconds per frame.  That is the reference implementation of soft intrinsics in the SDK.

So go ahead, make 2 minor edits to the fork (or be brave and even just make the edits to the original ToyPathTracer branch), go to each of these three source files in that project and add the magic #include to the top of each of these files:

    Cpp/Windows/TestWin.cpp
    Cpp/Source/MathSimd.h

and do a full rebuild of each of the ARM64EC and ARM64 targets.  Presto, the new builds run at 8 frames per second, faster than the x86 emulation and just a bit slower than the x64 emulation, but a full 15x faster or more than the reference implementation in the SDK.


## Tutorials:

There are subdirectories in this project (m256_demo, dvec_demo) which demonstrate existing ARM64EC compiler bugs and how they go away once your add the `#include <use_soft_intrinsics>`:

  - RUN_DEMO.BAT script in the m256_demo directory shows the bugs and how to add the new .H files to work around them.

  - MAKE64.BAT in the dvec_demo directory builds a runnable demo of the 256-bit C++ vector classes provided by `dvec.h` which can now run as native ARM64 and ARM64EC as well as legacy x86 and x64 builds.

  - MAKE64.BAT in the divss_demo directory builds a runnable unit test of SSE2 and AVX2 divisor intrinsics tests as native x64 binaries, stock SDK soft intrinsics binaries, or new soft intrinsics binaries.  You will see as you compare the outputs of each that soft intrinsics more correctly model the x86/x64 behaviour of real AMD and Intel hardware compared to various emulators.


## Implementation notes:

Thankfully, that reference implementation was specifically designed to be extensible, as most every soft intrinsic is implemented as a #define macro to re-map the intrinsic to a different function exported by `softintrin.lib`.  This is the key to how this new implementation layers on top, it simply uses an #undef to unmap each macro and replaces with a new faster implementation.

These header files extend the functionality of `softintrin.h` in the 24H2 SDK using this technique, so they are not a full replacement and you *must* have the 24H2 10.0.26100 (or higher) SDK installed as explained above.

This is not strictly an SSE/AVX-to-NEON mapping layer per se, although that technique is heavily used to replace the existing static library functions with inline functions that may contain NEON intrinscics or just operate directly on the _m128 and _m256 structures.  It is not stricly necessary to always try to map to NEON intrinsics, as in my testing I found that the Visual Studio C/C++ compiler vectorizer is quite good these days.

ARM64 auto-vectorization arrived in Visual C/C++ 2022 17.6, using 17.12 or higher is recommended since the compiler code quality been improving steadily since.

The file `use_soft_intrinsics.h` implements the wrapper around `intrin.h` and `windows.h` to make life easier:

  - it plays some macro voodoo to work around that _m256 compiler block, otherwise this project would be dead in the water until Microsoft fixes the [_m256 block](https://developercommunity.visualstudio.com/t/Arm64EC-Code-fails-to-compile/10838593).

  - it enables native ARM64 target by defining the `USE_SOFT_INTRINSICS` macro and adds `softintrin.lib` to the list of libraries.  This is what ARM64EC does automatically, but you have to do this manually for ARM64.  You can add these in the Visual Studio project itself, but by doing this in the header it makes it trivial to build from the command line using CL.EXE

  - it works around [another ARM64EC compiler bug](https://developercommunity.visualstudio.com/t/VC-176-preview-1-x86-compiler-bad-cod/10291481) which also causes the compiler to stop otherwise.

The file `softintrin_avx2.h` implements the actual soft intrisic overrides for SSE and the new soft intrinsics for AVX/AVX2.  It is #include-ed by the other header for convenience.  I'm keeping them as separate .H files since they serve entirely different purposes.  In theory once the Visual Studio compiler bugs are fixed most of `use_soft_intrinsics.h` will just go away and then you will just need `softintrin_avx2.h`.

This initial commit today (April 9 2025) is the bare bones to get things started and unblock `dvec.h` and speed up ToyPathTracer.  More demos and more new soft intrinsics will be added over time.

- Darek
