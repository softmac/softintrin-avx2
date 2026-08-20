@if "%1" == "-b" goto bench

@if not "%VSCMD_ARG_TGT_ARCH%" == "arm64" (
    echo Make sure to run vcvarsarm64.bat or vcvarsamd64_arm64.bat first!
    goto done
    )

@rem legacy ARM64EC build using stock SSE-only soft intrinsics from the Windows SDK
cl -FAsc -Zi -O2 -I../dvec_demo -I.. -arm64EC                             -Tc test-intrins.c -link -debug -release -incremental:no -out:test-intrins-aec-sse4.exe

@rem enhanced ARM64EC build overlaying new SSE/AVX soft intrinsics (build a C)
cl -FAsc -Zi -O2 -I../dvec_demo -I.. -arm64EC -FI../use_soft_intrinsics.h -Tc test-intrins.c -link -debug -release -incremental:no -out:test-intrins-eec-avx2.exe

@rem enhanced native ARM64 build overlaying new SSE/AVX soft intrinsics (build as C++)
cl -FAsc -Zi -O2 -I../dvec_demo -I..          -FI../use_soft_intrinsics.h -Tp test-intrins.c -link -debug -release -incremental:no -out:test-intrins-a64-avx2.exe

@rem Run both the correctness tests and micro-benchmarks (requires Windows on ARM, or Wine on aarch64)
@rem Optionally define LOADER with a debugger command line (e.g. "cdb -o -g -G") or TTD command line (e.g. "sudo ttd")

@if not "%PROCESSOR_ARCHITECTURE%" == "ARM64" (
    echo Skipping running the tests.  Windows on ARM not detected!
    goto done
    )

:bench

if exist test-intrins-aec-sse4.exe  (%LOADER% test-intrins-aec-sse4.exe    -o test-aec-sse4.txt)
if exist test-intrins-eec-avx2.exe  (%LOADER% test-intrins-eec-avx2.exe    -o test-eec-avx2.txt)
if exist test-intrins-a64-avx2.exe  (%LOADER% test-intrins-a64-avx2.exe    -o test-a64-avx2.txt)

if exist test-intrins-aec-sse4.exe  (%LOADER% test-intrins-aec-sse4.exe -b -o bench-aec-sse4.txt)
if exist test-intrins-eec-avx2.exe  (%LOADER% test-intrins-eec-avx2.exe -b -o bench-eec-avx2.txt)
if exist test-intrins-a64-avx2.exe  (%LOADER% test-intrins-a64-avx2.exe -b -o bench-a64-avx2.txt)

:done

