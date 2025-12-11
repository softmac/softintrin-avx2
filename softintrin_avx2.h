//
//  SOFTINTRIN_AVX2.H
//
//  Copyright (c) 2025 Darek Mihocka
//
//  Enhancements to the existing "soft intrinsics" provided in the Windows 24H2 SDK (build 10.0.26100):
//
//  - this header file extends the functionality of SOFTINTRIN.H in the 24H2 SDK, it is not a replacement
//    and you must still have the 24H2 10.0.26100 (or higher) SDK installed
//
//  - optimizes common SSE soft intrinsics for both ARM64 and ARM64EC builds which results in a
//    15x speedup for ARM64/ARM64EC builds of ToyPathTracer ray tracing demo, on par with emulation
//
//  - adds dozens of new 256-bit AVX2 soft intrinsics to support using DVEC.H in ARM64/ARM64EC builds
//
//  - adds native twin functions (_nn_* _nn256_*) that mirror SSE/AVX naming convention and numeric behaviour
//
//  - smaller binary size due to linking less static code from SOFTINTRIN.LIB library from the SDK
//
//  - native ARM64 binaries produced by this implementation _are_ Windows 10 on ARM compatible and
//    compatible with Snapdragon 835 based devices such as ASUS Novago, HP Envy X2, and Lenovo Miix
//    (whereas ARM64EC has always required Windows 11 on ARM)
//
//  Implementation notes:
//
//  - this is _not_ an SSE/AVX-to-NEON mapping layer per se, although that technique is used
//
//  - each native twin is simply the original SSE/AVX name with 'mm' replaced by 'nn', e.g.:
//      __mm_add_ss() -> _nn_add_ss()
//
//  - Visual C++ ARM64 toolset does not recognize m128 _m256i etc. as native vector types so
//    the implementation relies of compiler auto-vectorization and lots of type casting
//
//  - ARM64 auto-vectorization arrived in Visual C/C++ 2022 17.6, using 17.12 or higher is recommended!
//

#ifndef SOFT_INTRINSICS_AVX2
#define SOFT_INTRINSICS_AVX2

#if defined _M_ARM64EC || defined _M_ARM64

#if !defined(USE_SOFT_INTRINSICS) || (USE_SOFT_INTRINSICS < 2)
#error Need to #include <use_soft_intrinsics.h> before including windows.h or intrin.h
#endif

#ifdef __cplusplus

#define SIMD_REINTERPRET_CAST(func, type_out, type_in) \
__forceinline type_out func(type_in a) { \
    return *reinterpret_cast<type_out *>(&a); } \
__forceinline type_out type_out ## _from_ ## type_in (type_in a) { \
    return *reinterpret_cast<type_out *>(&a); }

#else

#define SIMD_REINTERPRET_CAST(func, type_out, type_in) \
__forceinline type_out func(type_in a) { \
    return *(type_out *)(&a); } \
__forceinline type_out type_out ## _from_ ## type_in (type_in a) { \
    return *(type_out *)(&a); }

#endif

//
// Disable the /GS checks on soft intrinsics to avoid unnecessary cookie checks
//

#pragma strict_gs_check(push,off)

//
// __n128 is the twin of __m128, create the other two variants
//

typedef __n128   __n128d; // twin of __m128d
typedef __n128   __n128i; // twin of __m128i

//
// Faster 128-bit SSE soft intrinsics (replacing existing softintrin.h implementations)
//

#undef _mm_cvtss_f32

__forceinline
float _mm_cvtss_f32(__m128 a)
{
    return a.m128_f32[0];
}


#undef _mm_castpd_ps
#undef _mm_castps_pd
#undef _mm_castpd_si128
#undef _mm_castps_si128
#undef _mm_castsi128_pd
#undef _mm_castsi128_ps

//                    conversion-func         type_out  type_in

SIMD_REINTERPRET_CAST(_mm_castpd_ps,          __m128,   __m128d)
SIMD_REINTERPRET_CAST(_mm_castps_pd,          __m128d,  __m128)
SIMD_REINTERPRET_CAST(_mm_castpd_si128,       __m128i,  __m128d)
SIMD_REINTERPRET_CAST(_mm_castps_si128,       __m128i,  __m128)
SIMD_REINTERPRET_CAST(_mm_castsi128_pd,       __m128d,  __m128i)
SIMD_REINTERPRET_CAST(_mm_castsi128_ps,       __m128,   __m128i)

SIMD_REINTERPRET_CAST(_nn128_castn128_si128,  __m128i,  __n128)
SIMD_REINTERPRET_CAST(_nn128_castn128_pd,     __m128d,  __n128)
SIMD_REINTERPRET_CAST(_nn128_castn128_ps,     __m128,   __n128)

SIMD_REINTERPRET_CAST(_nn128_castsi128_n128,  __n128,   __m128i)
SIMD_REINTERPRET_CAST(_nn128_castpd_n128,     __n128,   __m128d)
SIMD_REINTERPRET_CAST(_nn128_castps_n128,     __n128,   __m128)

#undef _mm_set_epi32
#undef _mm_set_epi64x
#undef _mm_set_pd
#undef _mm_set_ps

__forceinline
__m128i _mm_set_epi32(int e3, int e2, int e1, int e0)
{
    __m128i T;

    T.m128i_i32[0] = e0;
    T.m128i_i32[1] = e1;
    T.m128i_i32[2] = e2;
    T.m128i_i32[3] = e3;

    return T;
}

__forceinline
__m128i _mm_set_epi64x(__int64 e1, __int64 e0)
{
    __m128i T;

    T.m128i_i64[0] = e0;
    T.m128i_i64[1] = e1;

    return T;
}

__forceinline
__m128 _mm_set_ps(float _F3, float _F2, float _F1, float _F0)
{
    __m128 T = { _F0, _F1, _F2, _F3 };

//  T.m128_f32[0] = _F0;
//  T.m128_f32[1] = _F1;
//  T.m128_f32[2] = _F2;
//  T.m128_f32[3] = _F3;

    return T;
}

__forceinline
__m128d _mm_set_pd(double _D1, double _D0)
{
    __m128d T = { _D0, _D1 };

//  T.m128d_f64[0] = _D0;
//  T.m128d_f64[1] = _D1;

    return T;
}

#undef _mm_setzero_epi32
#undef _mm_setzero_epix64
#undef _mm_setzero_ps
#undef _mm_setzero_pd

__forceinline
__m128i _mm_setzero_epi32(void)
{
    return _mm_set_epi32(0, 0, 0, 0);
}

__forceinline
__m128i _mm_setzero_epix64(void)
{
    return _mm_set_epi64x(0, 0);
}

__forceinline
__m128 _mm_setzero_ps(void)
{
    return _mm_set_ps(0.0f, 0.0f, 0.0f, 0.0f);
}

__forceinline
__m128d _mm_setzero_pd(void)
{
    return _mm_set_pd(0.0, 0.0);
}

#undef _mm_set1_epi32
#undef _mm_set1_epix64
#undef _mm_set1_ps
#undef _mm_set_ps1
#undef _mm_set1_pd
#undef _mm_set_pd1

__forceinline
__n128 _nn_set1_epi32(const int a)
{
    return neon_dupqr32(a);
}

__forceinline
__m128i _mm_set1_epi32(const int a)
{
//  return _nn128_castn128_si128(neon_dupqr32(a));
    return _mm_set_epi32(a, a, a, a);
}

__forceinline
__m128i _mm_set1_epix64(const int a)
{
    return _mm_set_epi64x(a, a);
}

__forceinline
__n128 _nn_set1_ps(const float a)
{
    return neon_dupqrf32(a);
}

__forceinline
__m128 _mm_set1_ps(const float a)
{
    return _nn128_castn128_ps(neon_dupqrf32(a));
//  return _mm_set_ps(a, a, a, a);
}

__forceinline
__n128d _nn_set1_pd(const double a)
{
    return neon_dupqrf64(a);
}

__forceinline
__m128d _mm_set1_pd(double a)
{
    return _mm_set_pd(a, a);
}

#define _mm_set_ps1 _mm_set1_ps
#define _mm_set_pd1 _mm_set1_pd

// MOVUPS MOVUPD MOVDQA

#undef _mm_loadu_pd
#undef _mm_loadu_ps
#undef _mm_loadu_si128
#undef _mm_load_pd
#undef _mm_load_ps
#undef _mm_load_si128

#undef _mm_storeu_pd
#undef _mm_storeu_ps
#undef _mm_store_pd
#undef _mm_store_ps

__forceinline
__n128d _nn128_loadu_pd(double const  * pa)
{
    __n128d T = vld1q_dup_f64(pa);

    return T;
}

__forceinline
__m128d _mm_loadu_pd(double const  * pa)
{
    __m128d T;

    T.m128d_f64[0] = pa[0];
    T.m128d_f64[1] = pa[1];

    return T;
}

__forceinline
__m128d _mm_load_pd(double const  * pa)
{
    // TODO: for now skip alignment check

    return _mm_loadu_pd(pa);
}

__forceinline
__n128 _nn128_loadu_ps(float const  * pa)
{
    __n128 T = vld1q_dup_f32(pa);

    return T;
}

__forceinline
__m128 _mm_loadu_ps(float const  * pa)
{
    __m128 T;

    T.m128_f32[0] = pa[0];
    T.m128_f32[1] = pa[1];
    T.m128_f32[2] = pa[2];
    T.m128_f32[3] = pa[3];

    return T;
}

__forceinline
__m128 _mm_load_ps(float const  * pa)
{
    // TODO: for now skip alignment check

    return _mm_loadu_ps(pa);
}

__forceinline
__m128i _mm_loadu_si128(__m128i const  * pa)
{
    __m128i T;

    T.m128i_u64[0] = pa[0].m128i_u64[0];
    T.m128i_u64[1] = pa[0].m128i_u64[1];

    return T;
}

__forceinline
__m128i _mm_load_si128(__m128i const  * pa)
{
    // TODO: for now skip alignment check

    return _mm_loadu_si128(pa);
}

__forceinline
void _nn128_storeu_pd(double * pa, __n128 a)
{
    pa; a; __debugbreak(); // NYI
}

__forceinline
void _mm_storeu_pd(double * pa, __m128d a)
{
    pa[0] = a.m128d_f64[0];
    pa[1] = a.m128d_f64[1];
}

__forceinline
void _mm_store_pd(double * pa, __m128d a)
{
    // TODO: for now skip alignment check

    _mm_storeu_pd(pa, a);
}

__forceinline
void _nn128_storeu_ps(float * pa, __n128 a)
{
    pa; a; __debugbreak(); // NYI
}

__forceinline
void _mm_storeu_ps(float * pa, __m128 a)
{
    pa[0] = a.m128_f32[0];
    pa[1] = a.m128_f32[1];
    pa[2] = a.m128_f32[2];
    pa[3] = a.m128_f32[3];
}

__forceinline
void _mm_store_ps(float * pa, __m128 a)
{
    // TODO: for now skip alignment check

    _mm_storeu_ps(pa, a);
}

//
// Flags to indicate special handling for certain operations
//

typedef enum  INTRIN_FLAGS
{
    _IF_NONE = 0,
    _IF_SQRT_F32 = (1 << 0),
    _IF_SQRT_F64 = (1 << 1),
    _IF_SCALAR_INSERT_F32 = (1 << 2),
    _IF_SCALAR_INSERT_F64 = (1 << 3),
    _IF_DIV_F32 = (1 << 4),
    _IF_DIV_F64 = (1 << 5),
    _IF_MINMAX_F32 = (1 << 6),
    _IF_MINMAX_F64 = (1 << 7),
    _IF_DUP_128 = (1 << 8),
} INTRIN_FLAGS;

__forceinline
__n128 _nn_postprocess(__n128 T, __n128 a, const __n128 b, int flags)
{
    if (flags & _IF_SQRT_F32)
    {
        // Native ARM64 normally returns sign bit=0 for all inputs.  On x86/x64,
        // square root of negative must return Indefinite NaN which has sign bit=1.
        // Mask the input with 0x80000000`80000000`80000000`8000000 and use that
        // to propagate the original sign bits of the floats into the output.

        const __n128 SignMask = neon_dupqr32(0x80000000);
        T = neon_bitq(T, a, SignMask);
    }

    if (flags & _IF_SQRT_F64)
    {
        // Native ARM64 normally returns sign bit=0 for all inputs.  On x86/x64,
        // square root of negative must return Indefinite NaN which has sign bit=1.
        // Mask the input with 0x80000000`00000000`80000000`0000000 and use that
        // to propagate the original sign bits of the doubles into the output.

        const __n128 SignMask = neon_dupqr64(0x8000000000000000ull);
        T = neon_bitq(T, a, SignMask);
    }

    if (flags & _IF_DIV_F32)
    {
        // REVIEW: Prism currently does not correctly return -nan(ind)
        // this code adjusts the result to the correct x86/x64 result
        // using a similar sign propagation trick as SQRT_F32 above.

        const __n128 SignMask = neon_dupqr32(0x80000000);
        const __n128 LowxMask = neon_dupqr32(0x00400000);
        const __n128 Incremented = neon_addq64(T, LowxMask);
        const __n128 MaskedSigns = neon_andq(Incremented, SignMask);
        T = neon_orrq(T, MaskedSigns);
    }

    if (flags & _IF_DIV_F64)
    {
        // REVIEW: Prism currently does not correctly return -nan(ind)
        // this code adjusts the result to the correct x86/x64 result
        // using a similar sign propagation trick as SQRT_F64 above.

        const __n128 SignMask = neon_dupqr64(0x8000000000000000ull);
        const __n128 LowxMask = neon_dupqr64(0x0008000000000000ull);
        const __n128 Incremented = neon_addq64(T, LowxMask);
        const __n128 MaskedSigns = neon_andq(Incremented, SignMask);
        T = neon_orrq(T, MaskedSigns);
    }

    if (flags & _IF_MINMAX_F32)
    {
        // this code adjusts the result to the correct x86/x64 result
        // by selecting second source when either input is NaN
        // (which is true when neither a>b nor a<b)

        const __n128 GT = vcgtq_f32(a, b);
        const __n128 LT = vcgtq_f32(b, a);
        const __n128 IsOrdered = neon_orrq(GT, LT);
        T = vbslq_f32(IsOrdered, T, b);
    }

    if (flags & _IF_MINMAX_F64)
    {
        // this code adjusts the result to the correct x86/x64 result
        // by selecting second source when either input is NaN
        // (which is true when neither a>b nor a<b)

        const __n128 GT = vcgtq_f64(a, b);
        const __n128 LT = vcgtq_f64(b, a);
        const __n128 IsOrdered = neon_orrq(GT, LT);
        T = vbslq_f64(IsOrdered, T, b);
    }

    if (flags & _IF_DUP_128)
    {
        // nothing to do, dup to upper half is default behaviour for widening
    }

    // check these two last to insert any adjusted scalar result

    if (flags & _IF_SCALAR_INSERT_F32)
    {
        // scalar 32-bit SS/SI operations where result is inserted into low float/dword lane

        T = neon_insqe32q(a, 0, T, 0);
    }

    if (flags & _IF_SCALAR_INSERT_F64)
    {
        // scalar 64-bit SD/SQ operations where result is inserted into low double/qword lane

        T = neon_insqe64q(a, 0, T, 0);
    }

    return T;
}

__forceinline
__int16 _SaturateI16(__int32 a)
{
    return (__int16)((a < -32768) ? -32768 : (a > 32767) ? 32767 : a);
}

//
// Template for common 128-bit dest,source1 unary vector instructions
//

#define DEFINE_N128_OP_N128(rettype, name, intrin, arg1type, arg1, flags ) \
\
__forceinline __n128 _nn_ ## name (const __n128 a) \
{ \
    __n128 T = intrin (a); \
    T = _nn_postprocess(T, a, a, flags); \
    return T; \
} \
\
__forceinline rettype _mm_ ## name (arg1type arg1) \
{ \
    return rettype ## _from___n128 ( _nn_ ## name ( __n128_from_ ## arg1type (a) ) ); \
}

//
// Template for common 128-bit dest,source1,source2 vector instructions
//

#define DEFINE_N128_OP_N128_N128(rettype, name, intrin, arg1type, arg1, arg2type, arg2, flags ) \
\
__forceinline __n128 _nn_ ## name (__n128 a, const __n128 b) \
{ \
    __n128 T = intrin (a, b); \
    T = _nn_postprocess(T, a, b, flags); \
    return T; \
} \
\
__forceinline rettype _mm_ ## name (arg1type arg1, arg2type arg2) \
{ \
    return rettype ## _from___n128 ( _nn_ ## name ( __n128_from_ ## arg1type (a), __n128_from_ ## arg2type (b) ) ); \
}

//
// Template for spicy 128-bit dest,source1,source2,source3 vector instructions
//

#define DEFINE_N128_OP_N128_N128_N128(rettype, name, intrin, arg1type, arg1, arg2type, arg2, arg3type, arg3, flags ) \
\
__forceinline __n128 _nn_ ## name (__n128 a, const __n128 b, const __n128 c) \
{ \
    __n128 T = intrin (a, b, c); \
    T = _nn_postprocess(T, a, b, flags); \
    return T; \
} \
\
__forceinline rettype _mm_ ## name (arg1type arg1, arg2type arg2, arg3type arg3) \
{ \
    return rettype ## _from___n128 ( _nn_ ## name ( __n128_from_ ## arg1type (a), __n128_from_ ## arg2type (b), __n128_from_ ## arg3type (c) ) ); \
}

// PABS

#undef _mm_abs_epi8
#undef _mm_abs_epi16
#undef _mm_abs_epi32
#undef _mm_abs_epi64

DEFINE_N128_OP_N128(     __m128i, abs_epi8,     vabsq_s8,       __m128i, a,             0)
DEFINE_N128_OP_N128(     __m128i, abs_epi16,    vabsq_s16,      __m128i, a,             0)
DEFINE_N128_OP_N128(     __m128i, abs_epi32,    vabsq_s32,      __m128i, a,             0)
DEFINE_N128_OP_N128(     __m128i, abs_epi64,    vabsq_s64,      __m128i, a,             0)

// PAVG

#undef _mm_avg_epu8
#undef _mm_avg_epu16

DEFINE_N128_OP_N128_N128(__m128i, avg_epu8,     vrhaddq_u8,     __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, avg_epu16,    vrhaddq_u16,    __m128i, a, __m128i, b, 0)

// PADD PSUB

#undef _mm_add_epi8
#undef _mm_add_epi16
#undef _mm_add_epi32
#undef _mm_add_epi64

DEFINE_N128_OP_N128_N128(__m128i, add_epi8,     neon_addq8,     __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, add_epi16,    neon_addq16,    __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, add_epi32,    neon_addq32,    __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, add_epi64,    neon_addq64,    __m128i, a, __m128i, b, 0)

#undef _mm_sub_epi8
#undef _mm_sub_epi16
#undef _mm_sub_epi32
#undef _mm_sub_epi64

DEFINE_N128_OP_N128_N128(__m128i, sub_epi8,     neon_subq8,     __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, sub_epi16,    neon_subq16,    __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, sub_epi32,    neon_subq32,    __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, sub_epi64,    neon_subq64,    __m128i, a, __m128i, b, 0)

// PMADDWD PMADDUBSW

#undef _mm_madd_epi16
#undef _mm_maddubs_epi16

__forceinline
__n128 sw_madd_epi16(__n128 a, const __n128 b)
{
    __n128 T;

    // slower reference alternative

    T.n128_i32[0] = ((__int32)a.n128_i16[0] * (__int32)b.n128_i16[0]) +
                    ((__int32)a.n128_i16[1] * (__int32)b.n128_i16[1]);
    T.n128_i32[1] = ((__int32)a.n128_i16[2] * (__int32)b.n128_i16[2]) +
                    ((__int32)a.n128_i16[3] * (__int32)b.n128_i16[3]);
    T.n128_i32[2] = ((__int32)a.n128_i16[4] * (__int32)b.n128_i16[4]) +
                    ((__int32)a.n128_i16[5] * (__int32)b.n128_i16[5]);
    T.n128_i32[3] = ((__int32)a.n128_i16[6] * (__int32)b.n128_i16[6]) +
                    ((__int32)a.n128_i16[7] * (__int32)b.n128_i16[7]);

    return T;
}

__forceinline
__n128 sw_maddubs_epi16(__n128 a, const __n128 b)
{
    __n128 T;

    // slower reference alternative
    // A lanes are zero-extended
    // B lanes are sign-extended

    T.n128_i16[0] = _SaturateI16(((__int32)a.n128_u8[0] * (__int32)b.n128_i8[0]) +
                                 ((__int32)a.n128_u8[1] * (__int32)b.n128_i8[1]));
    T.n128_i16[1] = _SaturateI16(((__int32)a.n128_u8[2] * (__int32)b.n128_i8[2]) +
                                 ((__int32)a.n128_u8[3] * (__int32)b.n128_i8[3]));
    T.n128_i16[2] = _SaturateI16(((__int32)a.n128_u8[4] * (__int32)b.n128_i8[4]) +
                                 ((__int32)a.n128_u8[5] * (__int32)b.n128_i8[5]));
    T.n128_i16[3] = _SaturateI16(((__int32)a.n128_u8[6] * (__int32)b.n128_i8[6]) +
                                 ((__int32)a.n128_u8[7] * (__int32)b.n128_i8[7]));
    T.n128_i16[4] = _SaturateI16(((__int32)a.n128_u8[8] * (__int32)b.n128_i8[8]) +
                                 ((__int32)a.n128_u8[9] * (__int32)b.n128_i8[9]));
    T.n128_i16[5] = _SaturateI16(((__int32)a.n128_u8[10] * (__int32)b.n128_i8[10]) +
                                 ((__int32)a.n128_u8[11] * (__int32)b.n128_i8[11]));
    T.n128_i16[6] = _SaturateI16(((__int32)a.n128_u8[12] * (__int32)b.n128_i8[12]) +
                                 ((__int32)a.n128_u8[13] * (__int32)b.n128_i8[13]));
    T.n128_i16[7] = _SaturateI16(((__int32)a.n128_u8[14] * (__int32)b.n128_i8[14]) +
                                 ((__int32)a.n128_u8[15] * (__int32)b.n128_i8[15]));

    return T;
}

DEFINE_N128_OP_N128_N128(__m128i, madd_epi16,   sw_madd_epi16,  __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, maddubs_epi16,sw_maddubs_epi16, __m128i, a, __m128i, b, 0)

// PMULDQ PMULUDQ

#undef _mm_mul_epi32
#undef _mm_mul_epu32

__forceinline
__n128 sw_mulq_s32(__n128 a, const __n128 b)
{
    __n128 T;

    T.n128_u64[0] = (__int64)a.n128_i32[0] * (__int64)b.n128_i32[0];
    T.n128_u64[1] = (__int64)a.n128_i32[2] * (__int64)b.n128_i32[2];

    return T;
}

__forceinline
__n128 sw_mulq_u32(__n128 a, const __n128 b)
{
    __n128 T;

    T.n128_u64[0] = (unsigned __int64)a.n128_u32[0] * (unsigned __int64)b.n128_u32[0];
    T.n128_u64[1] = (unsigned __int64)a.n128_u32[2] * (unsigned __int64)b.n128_u32[2];

    return T;
}

DEFINE_N128_OP_N128_N128(__m128i, mul_epi32,    sw_mulq_s32,    __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, mul_epu32,    sw_mulq_u32,    __m128i, a, __m128i, b, 0)

// PMULLO

#undef _mm_mullo_epi16
#undef _mm_mullo_epi32

DEFINE_N128_OP_N128_N128(__m128i, mullo_epi16,  vmulq_s16,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, mullo_epi32,  vmulq_s32,      __m128i, a, __m128i, b, 0)

// PADDS PADDUS

#undef _mm_adds_epi8
#undef _mm_adds_epi16
#undef _mm_adds_epu8
#undef _mm_adds_epu16

DEFINE_N128_OP_N128_N128(__m128i, adds_epi8,    vqaddq_s8,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, adds_epi16,   vqaddq_s16,     __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, adds_epu8,    vqaddq_u8,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, adds_epu16,   vqaddq_u16,     __m128i, a, __m128i, b, 0)

// PHADDW PHADDD PHADDSW

#undef _mm_hadd_epi16
#undef _mm_hadd_epi32
#undef _mm_hadds_epi16

__forceinline
__n128i sw_hadds_epi16(__n128i a, const __n128i b)
{
    __n128i T1 = neon_uzp2_q16(a, b);  // extract odd lanes  15 13 .. 7 5 3 1
    __n128i T2 = neon_uzp1_q16(a, b);  // extract even lanes 14 12 .. 6 4 2 0
    __n128i T  = vqaddq_s16(T1, T2);   // sum(15,14) sum(13,12) .. sum(1,0)

#if 0
    // slower reference alternative

    for (unsigned i = 0; i < 4; i++)
        T.n128_u16[i] = _SaturateI16((__int16)a.n128_i16[i+i] + (__int16)a.n128_i16[i+i+1]);

    for (unsigned i = 0; i < 4; i++)
        T.n128_u16[i+4] = _SaturateI16((__int16)b.n128_i16[i+i] + (__int16)b.n128_i16[i+i+1]);
#endif

    return T;
}

DEFINE_N128_OP_N128_N128(__m128i, hadd_epi16,   vpaddq_u16,     __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, hadd_epi32,   vpaddq_u32,     __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, hadds_epi16,  sw_hadds_epi16, __m128i, a, __m128i, b, 0);

// PSUBS PSUBUS

#undef _mm_subs_epi8
#undef _mm_subs_epi16
#undef _mm_subs_epu8
#undef _mm_subs_epu16

DEFINE_N128_OP_N128_N128(__m128i, subs_epi8,    vqsubq_s8,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, subs_epi16,   vqsubq_s16,     __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, subs_epu8,    vqsubq_u8,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, subs_epu16,   vqsubq_u16,     __m128i, a, __m128i, b, 0)

// PHSUBW PHSUBD PHSUBSW

#undef _mm_hsub_epi16
#undef _mm_hsub_epi32
#undef _mm_hsubs_epi16

__forceinline
__n128 sw_psubq_u16(__n128 a, const __n128 b)
{
    __n128i T1 = neon_uzp2_q16(a, b);  // extract odd lanes  15 13 .. 7 5 3 1
    __n128i T2 = neon_uzp1_q16(a, b);  // extract even lanes 14 12 .. 6 4 2 0
    __n128i T  = vsubq_s16(T2, T1);    // sub(even,odd)

#if 0
    // slower reference alternative

    T.n128_u16[0] = a.n128_u16[0] - a.n128_u16[1];
    T.n128_u16[1] = a.n128_u16[2] - a.n128_u16[3];
    T.n128_u16[2] = a.n128_u16[4] - a.n128_u16[5];
    T.n128_u16[3] = a.n128_u16[6] - a.n128_u16[7];
    T.n128_u16[4] = b.n128_u16[0] - b.n128_u16[1];
    T.n128_u16[5] = b.n128_u16[2] - b.n128_u16[3];
    T.n128_u16[6] = b.n128_u16[4] - b.n128_u16[5];
    T.n128_u16[7] = b.n128_u16[6] - b.n128_u16[7];
#endif

    return T;
}

__forceinline
__n128 sw_psubq_u32(__n128 a, const __n128 b)
{
    __n128i T1 = neon_uzp2_q32(a, b);  // extract odd lanes
    __n128i T2 = neon_uzp1_q32(a, b);  // extract even lanes
    __n128i T  = vsubq_s32(T2, T1);    // sub(even,odd)

#if 0
    // slower reference alternative

    T.n128_u32[0] = a.n128_u32[0] - a.n128_u32[1];
    T.n128_u32[1] = a.n128_u32[2] - a.n128_u32[3];
    T.n128_u32[2] = b.n128_u32[0] - b.n128_u32[1];
    T.n128_u32[3] = b.n128_u32[2] - b.n128_u32[3];
#endif

    return T;
}

__forceinline
__n128 sw_hsubs_epi16(__n128 a, const __n128 b)
{
    __n128i T1 = neon_uzp2_q16(a, b);  // extract odd lanes  15 13 .. 7 5 3 1
    __n128i T2 = neon_uzp1_q16(a, b);  // extract even lanes 14 12 .. 6 4 2 0
    __n128i T  = vqsubq_s16(T2, T1);   // subs(even,odd)

#if 0
    // slower reference alternative

    for (unsigned i = 0; i < 4; i++)
        T.n128_u16[i] = _SaturateI16((__int16)a.n128_i16[i+i] - (__int16)a.n128_i16[i+i+1]);

    for (unsigned i = 0; i < 4; i++)
        T.n128_u16[i+4] = _SaturateI16((__int16)b.n128_i16[i+i] - (__int16)b.n128_i16[i+i+1]);
#endif

    return T;
}

DEFINE_N128_OP_N128_N128(__m128i, hsub_epi16,   sw_psubq_u16,   __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, hsub_epi32,   sw_psubq_u32,   __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, hsubs_epi16,  sw_hsubs_epi16, __m128i, a, __m128i, b, 0)

// PAND PANDN POR PXOR

#undef _mm_and_si128
#undef _mm_andnot_si128
#undef _mm_or_si128
#undef _mm_xor_si128

DEFINE_N128_OP_N128_N128(__m128i, and_si128,    neon_andq,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, andnot_si128, neon_bicq,      __m128i, b, __m128i, a, 0) // swap arg order
DEFINE_N128_OP_N128_N128(__m128i,  or_si128,    neon_orrq,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, xor_si128,    neon_eorq,      __m128i, a, __m128i, b, 0)

// PMINS PMAXS

#undef _mm_min_epi8
#undef _mm_min_epi16
#undef _mm_min_epi32
#undef _mm_max_epi8
#undef _mm_max_epi16
#undef _mm_max_epi32

DEFINE_N128_OP_N128_N128(__m128i, min_epi8,     vminq_s8,       __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, min_epi16,    vminq_s16,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, min_epi32,    vminq_s32,      __m128i, a, __m128i, b, 0)

DEFINE_N128_OP_N128_N128(__m128i, max_epi8,     vmaxq_s8,       __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, max_epi16,    vmaxq_s16,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, max_epi32,    vmaxq_s32,      __m128i, a, __m128i, b, 0)

// PMINU PMINU

#undef _mm_min_epu8
#undef _mm_min_epu16
#undef _mm_min_epu32
#undef _mm_max_epu8
#undef _mm_max_epu16
#undef _mm_max_epu32

DEFINE_N128_OP_N128_N128(__m128i, min_epu8,     vminq_u8,       __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, min_epu16,    vminq_u16,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, min_epu32,    vminq_u32,      __m128i, a, __m128i, b, 0)

DEFINE_N128_OP_N128_N128(__m128i, max_epu8,     vmaxq_u8,       __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, max_epu16,    vmaxq_u16,      __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, max_epu32,    vmaxq_u32,      __m128i, a, __m128i, b, 0)

// MINPD MAXPD
// MINPS MAXPS

#undef _mm_min_pd
#undef _mm_max_pd
#undef _mm_min_ps
#undef _mm_max_ps

DEFINE_N128_OP_N128_N128(__m128d, min_pd,       vminq_f64,      __m128d, a, __m128d, b, _IF_MINMAX_F64)
DEFINE_N128_OP_N128_N128(__m128d, max_pd,       vmaxq_f64,      __m128d, a, __m128d, b, _IF_MINMAX_F64)
DEFINE_N128_OP_N128_N128(__m128,  min_ps,       vminq_f32,      __m128,  a, __m128,  b, _IF_MINMAX_F32)
DEFINE_N128_OP_N128_N128(__m128,  max_ps,       vmaxq_f32,      __m128,  a, __m128,  b, _IF_MINMAX_F32)

// MINSD MAXSD
// MINSS MAXSS

#undef _mm_min_sd
#undef _mm_max_sd
#undef _mm_min_ss
#undef _mm_max_ss

DEFINE_N128_OP_N128_N128(__m128d, min_sd,       vminq_f64,      __m128d, a, __m128d, b, _IF_SCALAR_INSERT_F64 | _IF_MINMAX_F64)
DEFINE_N128_OP_N128_N128(__m128d, max_sd,       vmaxq_f64,      __m128d, a, __m128d, b, _IF_SCALAR_INSERT_F64 | _IF_MINMAX_F64)
DEFINE_N128_OP_N128_N128(__m128,  min_ss,       vminq_f32,      __m128,  a, __m128,  b, _IF_SCALAR_INSERT_F32 | _IF_MINMAX_F32)
DEFINE_N128_OP_N128_N128(__m128,  max_ss,       vmaxq_f32,      __m128,  a, __m128,  b, _IF_SCALAR_INSERT_F32 | _IF_MINMAX_F32)

// ANDPD ORPD XORPD

#undef _mm_and_pd
#undef _mm_andnot_pd
#undef _mm_or_pd
#undef _mm_xor_pd

DEFINE_N128_OP_N128_N128(__m128d, and_pd,       vandq_s64,      __m128d, a, __m128d, b, 0)
DEFINE_N128_OP_N128_N128(__m128d, andnot_pd,    vbicq_s64,      __m128d, b, __m128d, a, 0) // swap arg order
DEFINE_N128_OP_N128_N128(__m128d, or_pd,        vorrq_s64,      __m128d, a, __m128d, b, 0)
DEFINE_N128_OP_N128_N128(__m128d, xor_pd,       veorq_s64,      __m128d, a, __m128d, b, 0)

// ANDPS ORPS XORPS

#undef _mm_and_ps
#undef _mm_andnot_ps
#undef _mm_or_ps
#undef _mm_xor_ps

DEFINE_N128_OP_N128_N128(__m128,  and_ps,       vandq_s32,      __m128,  a, __m128,  b, 0)
DEFINE_N128_OP_N128_N128(__m128,  andnot_ps,    vbicq_s32,      __m128,  b, __m128,  a, 0) // swap arg order
DEFINE_N128_OP_N128_N128(__m128,  or_ps,        vorrq_s32,      __m128,  a, __m128,  b, 0)
DEFINE_N128_OP_N128_N128(__m128,  xor_ps,       veorq_s32,      __m128,  a, __m128,  b, 0)

// ADDPD SUBPD MULPD DIVPD

#undef _mm_add_pd
#undef _mm_sub_pd
#undef _mm_mul_pd
#undef _mm_div_pd

DEFINE_N128_OP_N128_N128(__m128d, add_pd,       neon_faddq64,   __m128d, a, __m128d, b, 0)
DEFINE_N128_OP_N128_N128(__m128d, sub_pd,       neon_fsubq64,   __m128d, a, __m128d, b, 0)
DEFINE_N128_OP_N128_N128(__m128d, mul_pd,       neon_fmulq64,   __m128d, a, __m128d, b, 0)
DEFINE_N128_OP_N128_N128(__m128d, div_pd,       neon_fdivq64,   __m128d, a, __m128d, b, _IF_DIV_F64)

// ADDPS SUBPS MULPS DIVPS

#undef _mm_add_ps
#undef _mm_sub_ps
#undef _mm_mul_ps
#undef _mm_div_ps

DEFINE_N128_OP_N128_N128(__m128,  add_ps,       neon_faddq32,   __m128,  a, __m128,  b, 0)
DEFINE_N128_OP_N128_N128(__m128,  sub_ps,       neon_fsubq32,   __m128,  a, __m128,  b, 0)
DEFINE_N128_OP_N128_N128(__m128,  mul_ps,       neon_fmulq32,   __m128,  a, __m128,  b, 0)
DEFINE_N128_OP_N128_N128(__m128,  div_ps,       neon_fdivq32,   __m128,  a, __m128,  b, _IF_DIV_F32)

// ADDSD SUBSD MULSD DIVSD

#undef _mm_add_sd
#undef _mm_sub_sd
#undef _mm_mul_sd
#undef _mm_div_sd

DEFINE_N128_OP_N128_N128(__m128d, add_sd,       neon_faddq64,   __m128d, a, __m128d, b, _IF_SCALAR_INSERT_F64)
DEFINE_N128_OP_N128_N128(__m128d, sub_sd,       neon_fsubq64,   __m128d, a, __m128d, b, _IF_SCALAR_INSERT_F64)
DEFINE_N128_OP_N128_N128(__m128d, mul_sd,       neon_fmulq64,   __m128d, a, __m128d, b, _IF_SCALAR_INSERT_F64)
DEFINE_N128_OP_N128_N128(__m128d, div_sd,       neon_fdivq64,   __m128d, a, __m128d, b, _IF_SCALAR_INSERT_F64 | _IF_DIV_F64)

// ADDSS SUBSS MULSS DIVSS

#undef _mm_add_ss
#undef _mm_sub_ss
#undef _mm_mul_ss
#undef _mm_div_ss

DEFINE_N128_OP_N128_N128(__m128,  add_ss,       neon_faddq32,   __m128,  a, __m128,  b, _IF_SCALAR_INSERT_F32)
DEFINE_N128_OP_N128_N128(__m128,  sub_ss,       neon_fsubq32,   __m128,  a, __m128,  b, _IF_SCALAR_INSERT_F32)
DEFINE_N128_OP_N128_N128(__m128,  mul_ss,       neon_fmulq32,   __m128,  a, __m128,  b, _IF_SCALAR_INSERT_F32)
DEFINE_N128_OP_N128_N128(__m128,  div_ss,       neon_fdivq32,   __m128,  a, __m128,  b, _IF_SCALAR_INSERT_F32 | _IF_DIV_F32)

// HADDPD HADDPS

#undef _mm_hadd_pd
#undef _mm_hadd_ps

DEFINE_N128_OP_N128_N128(__m128d, hadd_pd,      vpaddq_f64,     __m128d, a, __m128d, b, 0);
DEFINE_N128_OP_N128_N128(__m128,  hadd_ps,      vpaddq_f32,     __m128,  a, __m128,  b, 0);

// SQRTPD SQRTSD
// SQRTPS SQRTSS

#undef _mm_sqrt_pd
#undef _mm_sqrt_ps
#undef _mm_sqrt_sd
#undef _mm_sqrt_ss

__forceinline
__n128 _nn_sqrt_pd(__n128 a)
{
    __n128 T = neon_fsqrtq64(a);
    T = _nn_postprocess(T, a, a, _IF_SQRT_F64);

    return T;
}

__forceinline
__n128 _nn_sqrt_ps(__n128 a)
{
    __n128 T = neon_fsqrtq32(a);
    T = _nn_postprocess(T, a, a, _IF_SQRT_F32);

    return T;
}

__forceinline
__m128d _mm_sqrt_pd(__m128d a)
{
    return _nn128_castn128_pd( _nn_sqrt_pd(_nn128_castpd_n128(a)) );
}

__forceinline
__m128 _mm_sqrt_ps(__m128 a)
{
    return _nn128_castn128_ps( _nn_sqrt_ps(_nn128_castps_n128(a)) );
}

__forceinline
__n128 _nn_sqrt_sd(__n128 a, __n128 b) // not like the others!
{
    // SQRT(b) gets merged in to lower lane of a

    __n128 T = neon_fsqrtq64(b);
    T = _nn_postprocess(T, b, a /* unused */, _IF_SQRT_F64 | _IF_SCALAR_INSERT_F64); \

    return T;
}

__forceinline
__n128 _nn_sqrt_ss(__n128 a)
{
    // SQRT(a) gets merged in to lower lane of a

    __n128 T = neon_fsqrtq32(a);
    T = _nn_postprocess(T, a, a, _IF_SQRT_F32 | _IF_SCALAR_INSERT_F32); \

    return T;
}

__forceinline
__m128d _mm_sqrt_sd(__m128d a, __m128d b)
{
    return _nn128_castn128_pd( _nn_sqrt_sd(_nn128_castpd_n128(a),  _nn128_castpd_n128(b)) );
}

__forceinline
__m128 _mm_sqrt_ss(__m128 a)
{
    return _nn128_castn128_ps( _nn_sqrt_ss(_nn128_castps_n128(a)) );
}

// PSLLV PSRLV PSRARV

#undef _mm_sllv_epi32
#undef _mm_sllv_epi64
#undef _mm_srav_epi32
#undef _mm_srlv_epi32
#undef _mm_srlv_epi64

__forceinline
__n128i sw_sllv_epi32(__n128i a, const __n128i b)
{
    // Limit over-shifting to 32 bits to force zeroes in those slots

    __n128i Bounds = vmovq_n_u32(32);
    __n128i T = vminq_u32(Bounds, b);

    T = vshlq_u32(a, T);

    return T;
}

__forceinline
__n128i sw_sllv_epi64(__n128i a, const __n128i b)
{
    // There is no vminq_u64 intrinsic, so instead clip the shift count
    // using saturating addition followed by subtraction.  The original
    // shift count will result if it was in range to begin with.

    __n128i Bounds = vmovq_n_s64(-65);
    __n128i T = vsubq_u64(vqaddq_u64(Bounds, b), Bounds);

    T = vshlq_u64(a, T);

    return T;
}

__forceinline
__n128i sw_srav_epi32(__n128i a, const __n128i b)
{
    // Limit over-shifting to 32 bits to force zeroes in those slots

    __n128i Bounds = vmovq_n_u32(32);
    __n128i T = vminq_u32(Bounds, b);

    T = vshlq_s32(a, vnegq_s32(T)); // shift right = shift left by negative count

    return T;
}

__forceinline
__n128i sw_srlv_epi32(__n128i a, const __n128i b)
{
    // Limit over-shifting to 32 bits to force zeroes in those slots

    __n128i Bounds = vmovq_n_u32(32);
    __n128i T = vminq_u32(Bounds, b);

    T = vshlq_u32(a, vnegq_s32(T)); // shift right = shift left by negative count

    return T;
}

__forceinline
__n128i sw_srlv_epi64(__n128i a, const __n128i b)
{
    // There is no vminq_u64 intrinsic, so instead clip the shift count
    // using saturating addition followed by subtraction.  The original
    // shift count will result if it was in range to begin with.

    __n128i Bounds = vmovq_n_s64(-65);
    __n128i T = vsubq_u64(vqaddq_u64(Bounds, b), Bounds);

    T = vshlq_u64(a, vnegq_s64(T)); // shift right = shift left by negative count

    return T;
}

DEFINE_N128_OP_N128_N128(__m128i, sllv_epi32,   sw_sllv_epi32,  __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, sllv_epi64,   sw_sllv_epi64,  __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, srav_epi32,   sw_srav_epi32,  __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, srlv_epi32,   sw_srlv_epi32,  __m128i, a, __m128i, b, 0)
DEFINE_N128_OP_N128_N128(__m128i, srlv_epi64,   sw_srlv_epi64,  __m128i, a, __m128i, b, 0)

// PSHUFD

#undef _mm_shuffle_epi32

__forceinline
__m128i _mm_shuffle_epi32(__m128i a, const int imm8)
{
    __m128i T;

    // check for common cases of broadcasting a single lane

    if (imm8 == 0x00)
        return _mm_set1_epi32(a.m128i_i32[0]);

    if (imm8 == 0x55)
        return _mm_set1_epi32(a.m128i_i32[1]);

    if (imm8 == 0xAA)
        return _mm_set1_epi32(a.m128i_i32[2]);

    if (imm8 == 0xFF)
        return _mm_set1_epi32(a.m128i_i32[3]);

    // all other cases slow shuffle

    T.m128i_u32[0] = a.m128i_u32[(imm8 >> 0) & 0x03];
    T.m128i_u32[1] = a.m128i_u32[(imm8 >> 2) & 0x03];
    T.m128i_u32[2] = a.m128i_u32[(imm8 >> 4) & 0x03];
    T.m128i_u32[3] = a.m128i_u32[(imm8 >> 6) & 0x03];

    return T;
}

// SHUFPS

#undef _mm_shuffle_ps

__forceinline
__n128 _nn128_shuffle_ps(__n128 a, const __n128 b, const unsigned int imm8)
{
    __n128 T;

    T.n128_f32[0] = a.n128_f32[(imm8 >> 0) & 0x03];
    T.n128_f32[1] = a.n128_f32[(imm8 >> 2) & 0x03];
    T.n128_f32[2] = b.n128_f32[(imm8 >> 4) & 0x03];
    T.n128_f32[3] = b.n128_f32[(imm8 >> 6) & 0x03];

    return T;
}

__forceinline
__m128 _mm_shuffle_ps(__m128 a, __m128 b, const unsigned int imm8)
{
//  the NEON path is slower due to memory spill for the casts :-(
//  return _nn128_castn128_ps( _nn128_shuffle_ps(_nn128_castps_n128(a), _nn128_castps_n128(b), imm8) );

    __m128 T;

    // all other cases slow shuffle

    T.m128_f32[0] = a.m128_f32[(imm8 >> 0) & 0x03];
    T.m128_f32[1] = a.m128_f32[(imm8 >> 2) & 0x03];
    T.m128_f32[2] = b.m128_f32[(imm8 >> 4) & 0x03];
    T.m128_f32[3] = b.m128_f32[(imm8 >> 6) & 0x03];

    return T;
}

// CMPPS

#undef _mm_cmp_ps

__forceinline
__n128 _nn128_cmpord_ps(__n128 a, __n128 b)
{
    __n128 T1 = neon_fcmeqq32(a, a);
    __n128 T2 = neon_fcmeqq32(b, b);
    __n128 T3 = neon_andq(T1, T2);

    return T3;
}

__forceinline
__n128 _nn128_cmp_ps(__n128 a, __n128 b, const int imm8)
{
    __n128 T;

    switch (imm8 & 0x1F)
    {
        case _CMP_EQ_OQ:     T = neon_fcmeqq32(a, b); break;
        case _CMP_LT_OS:     T = neon_fcmgtq32(b, a); break;  // LT is GT swapped
        case _CMP_LE_OS:     T = neon_fcmgeq32(b, a); break;  // LE is GE swapped
        case _CMP_UNORD_Q:   T = neon_notq(_nn128_cmpord_ps(a, b)); break;
        case _CMP_NEQ_UQ:    T = neon_notq(neon_fcmeqq32(a, b)); break;
        case _CMP_NLT_US:    T = neon_notq(neon_fcmgtq32(b, a)); break;
        case _CMP_NLE_US:    T = neon_notq(neon_fcmgeq32(b, a)); break;
        case _CMP_ORD_Q:     T = _nn128_cmpord_ps(a, b); break;

        case _CMP_EQ_UQ:     T = neon_fcmeqq32(a, b); break;
        case _CMP_NGE_US:    T = neon_notq(neon_fcmgeq32(a, b)); break;
        case _CMP_NGT_US:    T = neon_notq(neon_fcmgtq32(a, b)); break;
        case _CMP_FALSE_OQ:  T = neon_moviqw(0); break;
        case _CMP_NEQ_OQ:    T = neon_notq(neon_fcmeqq32(b, a)); break;
        case _CMP_GE_OS:     T = neon_fcmgeq32(a, b); break;
        case _CMP_GT_OS:     T = neon_fcmgtq32(a, b); break;
        case _CMP_TRUE_UQ:   T = neon_mvniqw(0); break;

        case _CMP_EQ_OS:     T = neon_fcmeqq32(a, b); break;
        case _CMP_LT_OQ:     T = neon_fcmgtq32(b, a); break;
        case _CMP_LE_OQ:     T = neon_fcmgeq32(b, a); break;
        case _CMP_UNORD_S:   T = neon_notq(_nn128_cmpord_ps(a, b)); break;
        case _CMP_NEQ_US:    T = neon_notq(neon_fcmeqq32(a, b)); break;
        case _CMP_NLT_UQ:    T = neon_notq(neon_fcmgtq32(b, a)); break;
        case _CMP_NLE_UQ:    T = neon_notq(neon_fcmgeq32(b, a)); break;
        case _CMP_ORD_S:     T = _nn128_cmpord_ps(a, b); break;

        case _CMP_EQ_US:     T = neon_fcmeqq32(a, b); break;
        case _CMP_NGE_UQ:    T = neon_notq(neon_fcmgeq32(a, b)); break;
        case _CMP_NGT_UQ:    T = neon_notq(neon_fcmgtq32(a, b)); break;
        case _CMP_FALSE_OS:  T = neon_moviqw(0); break;
        case _CMP_NEQ_OS:    T = neon_notq(neon_fcmeqq32(b, a)); break;
        case _CMP_GE_OQ:     T = neon_fcmgeq32(a, b); break;
        case _CMP_GT_OQ:     T = neon_fcmgtq32(a, b); break;
        case _CMP_TRUE_US:   T = neon_mvniqw(0); break;
            break;

        default:
            __assume(0);
            break;
    }

    return T;
}

__forceinline
__m128 _mm_cmp_ps(__m128 a, __m128 b, const int imm8)
{
    __m128 T = _nn128_castn128_ps( _nn128_cmp_ps(_nn128_castps_n128(a), _nn128_castps_n128(b), imm8 & 0x1F) );

    return T;
}

// PBLENDVB

#undef _mm_blendv_epi8
#undef _mm_blendv_ps
#undef _mm_blendv_pd

__forceinline
__n128i sw_blendv_epi8(__n128i a, __n128i b, __n128i mask)
{
    __n128i T = neon_bitq(a, b, neon_sshriq8(mask, 7));

    return T;
}

DEFINE_N128_OP_N128_N128_N128(__m128i, blendv_epi8,  sw_blendv_epi8, __m128i, a, __m128i, b, __m128i, c,    0)

__forceinline
__n128d sw_blendv_pd(__n128d a, __n128d b, __n128d mask)
{
    __n128d T = neon_bitq(a, b, neon_sshriq64(mask, 63));

    return T;
}

DEFINE_N128_OP_N128_N128_N128(__m128d, blendv_pd,    sw_blendv_pd,   __m128d, a, __m128d, b, __m128d, c,    0)


__forceinline
__n128 sw_blendv_ps(__n128 a, __n128 b, __n128 mask)
{
    __n128 T = neon_bitq(a, b, neon_sshriq32(mask, 32));

    return T;
}

DEFINE_N128_OP_N128_N128_N128(__m128,  blendv_ps,    sw_blendv_ps,   __m128,  a, __m128,  b, __m128,  c,    0)

// MOVEMSK

#undef _mm_movemask_epi8
#undef _mm_movemask_pd
#undef _mm_movemask_ps

__forceinline
int _mm_movemask_epi8(const __m128i a)
{
    int mask = 0;

    for (unsigned i = 0; i < 16; i++)
        mask |= (a.m128i_u8[i] >> 7) << i;

    return mask;
}


__forceinline
int _mm_movemask_pd(const __m128d a)
{
    __m128i T = _mm_castpd_si128(a);

    int mask = 0;

    mask |= (T.m128i_u64[1] >> 63) << 1;
    mask |= (T.m128i_u64[0] >> 63) << 0;

    return mask;
}


__forceinline
int _mm_movemask_ps(const __m128 a)
{
    __m128i T = _mm_castps_si128(a);

    int mask = 0;

    mask |= (T.m128i_u32[3] >> 31) << 3;
    mask |= (T.m128i_u32[2] >> 31) << 2;
    mask |= (T.m128i_u32[1] >> 31) << 1;
    mask |= (T.m128i_u32[0] >> 31) << 0;

    return mask;
}


//
// New 256-bit AVX2 soft intrinsics (not provided in softintrin.h)
//
// naming conventions as documented at https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
//

typedef __n128x2 __n256;  // twin of __m256
typedef __n128x2 __n256d; // twin of __m256d
typedef __n128x2 __n256i; // twin of __m256i

//                    conversion-func         type_out  type_in

SIMD_REINTERPRET_CAST(_mm256_castsi128_si256, __m256i,  __m128i)
SIMD_REINTERPRET_CAST(_mm256_castsi256_si128, __m128i,  __m256i)
SIMD_REINTERPRET_CAST(_mm256_castsi256_pd,    __m256d,  __m256i)
SIMD_REINTERPRET_CAST(_mm256_castsi256_ps,    __m256,   __m256i)
SIMD_REINTERPRET_CAST(_mm256_castpd_si256,    __m256i,  __m256d)
SIMD_REINTERPRET_CAST(_mm256_castps_si256,    __m256i,  __m256)

SIMD_REINTERPRET_CAST(_mm256_castpd128_pd256, __m256d,  __m128d)
SIMD_REINTERPRET_CAST(_mm256_castps128_ps256, __m256,   __m128)
SIMD_REINTERPRET_CAST(_mm256_castpd256_pd128, __m128d,  __m256d)
SIMD_REINTERPRET_CAST(_mm256_castps256_ps128, __m128,   __m256)

SIMD_REINTERPRET_CAST(_nn256_castn256_pd,     __m256d,  __n128x2)
SIMD_REINTERPRET_CAST(_nn256_castn256_ps,     __m256,   __n128x2)
SIMD_REINTERPRET_CAST(_nn256_castn256_si256,  __m256i,  __n128x2)
SIMD_REINTERPRET_CAST(_nn256_castn256_si128,  __m128i,  __n128x2)

SIMD_REINTERPRET_CAST(_nn256_castpd_n256,     __n128x2, __m256d)
SIMD_REINTERPRET_CAST(_nn256_castps_n256,     __n128x2, __m256)
SIMD_REINTERPRET_CAST(_nn256_castsi256_n256,  __n128x2, __m256i)
SIMD_REINTERPRET_CAST(_nn256_castsi256_n128,  __n128,   __m256i)

// initialization and broadcasts

__forceinline void _mm256_zeroall(void)
{
    // avoiding mode transitions is a no-op for us
}

__forceinline void _mm256_zeroupper(void)
{
    // avoiding mode transitions is a no-op for us
}

__forceinline
__m256d _mm256_set_pd(double _D3, double _D2, double _D1, double _D0)
{
    __m256d T;

    T.m256d_f64[0] = _D0;
    T.m256d_f64[1] = _D1;
    T.m256d_f64[2] = _D2;
    T.m256d_f64[3] = _D3;

    return T;
}

__forceinline
__m256d _mm256_setzero_pd(void)
{
    return _mm256_set_pd(0.0, 0.0, 0.0, 0.0);
}

__forceinline
__m256d _mm256_set1_pd(double _D0)
{
    return _mm256_set_pd(_D0, _D0, _D0, _D0);
}

__forceinline
__m256 _mm256_set_ps(float _F7, float _F6, float _F5, float _F4, float _F3, float _F2, float _F1, float _F0)
{
    __m256 T;

    T.m256_f32[0] = _F0;
    T.m256_f32[1] = _F1;
    T.m256_f32[2] = _F2;
    T.m256_f32[3] = _F3;
    T.m256_f32[4] = _F4;
    T.m256_f32[5] = _F5;
    T.m256_f32[6] = _F6;
    T.m256_f32[7] = _F7;

    return T;
}

__forceinline
__m256 _mm256_setzero_ps(void)
{
    return _mm256_set_ps(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
}

__forceinline
__m256 _mm256_set1_ps(float _F0)
{
    return _mm256_set_ps(_F0, _F0, _F0, _F0, _F0, _F0, _F0, _F0);
}

__forceinline
__m256i _mm256_set_epi32(int e7, int e6, int e5, int e4, int e3, int e2, int e1, int e0)
{
    __m256i T;

    T.m256i_u32[0] = e0;
    T.m256i_u32[1] = e1;
    T.m256i_u32[2] = e2;
    T.m256i_u32[3] = e3;
    T.m256i_u32[4] = e4;
    T.m256i_u32[5] = e5;
    T.m256i_u32[6] = e6;
    T.m256i_u32[7] = e7;

    return T;
}

__forceinline
__m256i _mm256_set1_epi32(const int a)
{
    return _mm256_set_epi32(a, a, a, a, a, a, a, a);
}

__forceinline
__m256i _mm256_setzero_si256(void)
{
    __m256i T = { 0, 0, 0, 0, 0, 0, 0, 0 };
    return T;
}

__forceinline
__m256d _mm256_broadcast_pd(__m128d const * pa)
{
    __m256d T;

    T.m256d_f64[0] = pa[0].m128d_f64[0];
    T.m256d_f64[1] = pa[0].m128d_f64[1];
    T.m256d_f64[2] = pa[0].m128d_f64[0];
    T.m256d_f64[3] = pa[0].m128d_f64[1];

    return T;
}

// VMOVUPS VMOVUPD VMOVDQA

__forceinline
__n256d _nn256_loadu_pd(double const  * pa)
{
    __n256d T = vld2q_f64(pa);

    return T;
}

__forceinline
__m256d _mm256_loadu_pd(double const  * pa)
{
    __m256d T;

    T.m256d_f64[0] = pa[0];
    T.m256d_f64[1] = pa[1];
    T.m256d_f64[2] = pa[2];
    T.m256d_f64[3] = pa[3];

    return T;
}

__forceinline
__m256d _mm256_load_pd(double const  * pa)
{
    // TODO: for now skip alignment check

    return _mm256_loadu_pd(pa);
}

__forceinline
__n256 _nn256_loadu_ps(float const  * pa)
{
    __n256 T = vld2q_f32(pa);

    return T;
}

__forceinline
__m256 _mm256_loadu_ps(float const  * pa)
{
    __m256 T;

    T.m256_f32[0] = pa[0];
    T.m256_f32[1] = pa[1];
    T.m256_f32[2] = pa[2];
    T.m256_f32[3] = pa[3];
    T.m256_f32[4] = pa[4];
    T.m256_f32[5] = pa[5];
    T.m256_f32[6] = pa[6];
    T.m256_f32[7] = pa[7];

    return T;
}

__forceinline
__m256 _mm256_load_ps(float const  * pa)
{
    // TODO: for now skip alignment check

    return _mm256_loadu_ps(pa);
}

__forceinline
void _nn256_storeu_pd(double * pa, __n256 a)
{
    vst2q_f64(pa, a);
}

__forceinline
void _mm256_storeu_pd(double * pa, __m256d a)
{
    pa[0] = a.m256d_f64[0];
    pa[1] = a.m256d_f64[1];
    pa[2] = a.m256d_f64[2];
    pa[3] = a.m256d_f64[3];
}

__forceinline
void _mm256_store_pd(double * pa, __m256d a)
{
    // TODO: for now skip alignment check

    _mm256_storeu_pd(pa, a);
}

__forceinline
void _nn256_storeu_ps(float * pa, __n256 a)
{
    vst2q_f32(pa, a);
}

__forceinline
void _mm256_storeu_ps(float * pa, __m256 a)
{
    pa[0] = a.m256_f32[0];
    pa[1] = a.m256_f32[1];
    pa[2] = a.m256_f32[2];
    pa[3] = a.m256_f32[3];
    pa[4] = a.m256_f32[4];
    pa[5] = a.m256_f32[5];
    pa[6] = a.m256_f32[6];
    pa[7] = a.m256_f32[7];
}

__forceinline
void _mm256_store_ps(float * pa, __m256 a)
{
    // TODO: for now skip alignment check

    _mm256_storeu_ps(pa, a);
}

//
// Template for 128-bit to 256-bit dest,source1 unary vector widening instructions
//

#define DEFINE_N256_OP_N128(rettype, name, intrin, arg1type, arg1, flags ) \
\
__forceinline __n128x2 _nn256_ ## name (const __n128 a) \
{ \
    __n128x2 T; \
    T.val[0] = intrin (a); \
    T.val[0] = _nn_postprocess(T.val[0], a, a, flags); \
    T.val[1] = intrin (a); \
    T.val[1] = _nn_postprocess(T.val[1], T.val[0], a, flags); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128_from_ ## arg1type (a) ) ); \
}

//
// Template for common 256-bit dest,source1 unary vector instructions
//

#define DEFINE_N256_OP_N256(rettype, name, intrin, arg1type, arg1, flags ) \
\
__forceinline __n128x2 _nn256_ ## name (const __n128x2 a) \
{ \
    __n128x2 T; \
    T.val[0] = intrin (a.val[0]); \
    T.val[0] = _nn_postprocess(T.val[0], a.val[0], a.val[0], flags); \
    T.val[1] = intrin (a.val[1]); \
    T.val[1] = _nn_postprocess(T.val[1], a.val[1], a.val[1], flags); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128x2_from_ ## arg1type (a) ) ); \
}

//
// Template for common 256-bit dest,source1,source2 vector instructions
//

#define DEFINE_N256_OP_N256_N256(rettype, name, intrin, arg1type, arg1, arg2type, arg2, flags ) \
\
__forceinline __n128x2 _nn256_ ## name (__n128x2 a, const __n128x2 b) \
{ \
    __n128x2 T; \
    T.val[0] = intrin (a.val[0], b.val[0]); \
    T.val[0] = _nn_postprocess(T.val[0], a.val[0], b.val[0], flags); \
    T.val[1] = intrin (a.val[1], b.val[1]); \
    T.val[1] = _nn_postprocess(T.val[1], a.val[1], b.val[1], flags); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1, arg2type arg2) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128x2_from_ ## arg1type (a), __n128x2_from_ ## arg2type (b) ) ); \
}

//
// Template for spicy 256-bit dest,source1,source2,source vector instructions
//

#define DEFINE_N256_OP_N256_N256_N256(rettype, name, intrin, arg1type, arg1, arg2type, arg2, arg3type, arg3, flags ) \
\
__forceinline __n128x2 _nn256_ ## name (__n128x2 a, const __n128x2 b, const __n128x2 c) \
{ \
    __n128x2 T; \
    T.val[0] = intrin (a.val[0], b.val[0], c.val[0]); \
    T.val[0] = _nn_postprocess(T.val[0], a.val[0], b.val[0], flags); \
    T.val[1] = intrin (a.val[1], b.val[1], c.val[1]); \
    T.val[1] = _nn_postprocess(T.val[1], a.val[1], b.val[1], flags); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1, arg2type arg2, arg3type arg3) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128x2_from_ ## arg1type (a), __n128x2_from_ ## arg2type (b), __n128x2_from_ ## arg3type (c) ) ); \
}

// VPABS

DEFINE_N256_OP_N256(     __m256i, abs_epi8,     vabsq_s8,       __m256i, a,             0)
DEFINE_N256_OP_N256(     __m256i, abs_epi16,    vabsq_s16,      __m256i, a,             0)
DEFINE_N256_OP_N256(     __m256i, abs_epi32,    vabsq_s32,      __m256i, a,             0)

// VPAVG

#undef _mm_avg_epu8
#undef _mm_avg_epu16

DEFINE_N256_OP_N256_N256(__m256i, avg_epu8,     vrhaddq_u8,     __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, avg_epu16,    vrhaddq_u16,    __m256i, a, __m256i, b, 0)

// VPADD VPSUB

DEFINE_N256_OP_N256_N256(__m256i, add_epi8,     neon_addq8,     __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, add_epi16,    neon_addq16,    __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, add_epi32,    neon_addq32,    __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, add_epi64,    neon_addq64,    __m256i, a, __m256i, b, 0)

DEFINE_N256_OP_N256_N256(__m256i, sub_epi8,     neon_subq8,     __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, sub_epi16,    neon_subq16,    __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, sub_epi32,    neon_subq32,    __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, sub_epi64,    neon_subq64,    __m256i, a, __m256i, b, 0)

// VPMADDWD VPMADDUBSW

// DEFINE_N256_OP_N256_N256(__m256i, madd_epi16,   sw_madd_epi16,  __m256i, a, __m256i, b, 0)
// DEFINE_N256_OP_N256_N256(__m256i, maddubs_epi16,sw_maddubs_epi16, __m256i, a, __m256i, b, 0)

// VPMULDQ VMULUDQ

DEFINE_N256_OP_N256_N256(__m256i, mul_epi32,    sw_mulq_s32,    __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, mul_epu32,    sw_mulq_u32,    __m256i, a, __m256i, b, 0)

// VPMULLO

DEFINE_N256_OP_N256_N256(__m256i, mullo_epi16,  vmulq_s16,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, mullo_epi32,  vmulq_s32,      __m256i, a, __m256i, b, 0)

// VPADDS VPADDUS

DEFINE_N256_OP_N256_N256(__m256i, adds_epi8,    vqaddq_s8,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, adds_epi16,   vqaddq_s16,     __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, adds_epu8,    vqaddq_u8,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, adds_epu16,   vqaddq_u16,     __m256i, a, __m256i, b, 0)

// VPHADDW VPHADDD VPHADDSW

DEFINE_N256_OP_N256_N256(__m256i, hadd_epi16,   vpaddq_u16,     __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, hadd_epi32,   vpaddq_u32,     __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, hadds_epi16,  sw_hadds_epi16, __m256i, a, __m256i, b, 0);

// VPSUBS VPSUBUS

DEFINE_N256_OP_N256_N256(__m256i, subs_epi8,    vqsubq_s8,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, subs_epi16,   vqsubq_s16,     __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, subs_epu8,    vqsubq_u8,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, subs_epu16,   vqsubq_u16,     __m256i, a, __m256i, b, 0)

// VPHSUBW VPHSUBD VPHSUBSW

DEFINE_N256_OP_N256_N256(__m256i, hsub_epi16,   sw_psubq_u16,   __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, hsub_epi32,   sw_psubq_u32,   __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, hsubs_epi16,  sw_hsubs_epi16, __m256i, a, __m256i, b, 0)

// VPAND  VPANDN  VPOR  VPXOR

DEFINE_N256_OP_N256_N256(__m256i, and_si256,    neon_andq,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, andnot_si256, neon_bicq,      __m256i, b, __m256i, a, 0) // swap arg order
DEFINE_N256_OP_N256_N256(__m256i, or_si256,     neon_orrq,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, xor_si256,    neon_eorq,      __m256i, a, __m256i, b, 0)

// VANDPD VORPD VXORPD

DEFINE_N256_OP_N256_N256(__m256d, and_pd,       vandq_s64,      __m256d, a, __m256d, b, 0)
DEFINE_N256_OP_N256_N256(__m256d, andnot_pd,    vbicq_s64,      __m256d, b, __m256d, a, 0) // swap arg order
DEFINE_N256_OP_N256_N256(__m256d, or_pd,        vorrq_s64,      __m256d, a, __m256d, b, 0)
DEFINE_N256_OP_N256_N256(__m256d, xor_pd,       veorq_s64,      __m256d, a, __m256d, b, 0)

// VANDPS VORPS VXORPS

DEFINE_N256_OP_N256_N256(__m256,  and_ps,       vandq_s32,      __m256,  a, __m256,  b, 0)
DEFINE_N256_OP_N256_N256(__m256,  andnot_ps,    vbicq_s32,      __m256,  b, __m256,  a, 0) // swap arg order
DEFINE_N256_OP_N256_N256(__m256,  or_ps,        vorrq_s32,      __m256,  a, __m256,  b, 0)
DEFINE_N256_OP_N256_N256(__m256,  xor_ps,       veorq_s32,      __m256,  a, __m256,  b, 0)

// VADDPD VSUBPD VMULPD VDIVPD

DEFINE_N256_OP_N256_N256(__m256d, add_pd,       neon_faddq64,   __m256d, a, __m256d, b, 0)
DEFINE_N256_OP_N256_N256(__m256d, sub_pd,       neon_fsubq64,   __m256d, a, __m256d, b, 0)
DEFINE_N256_OP_N256_N256(__m256d, mul_pd,       neon_fmulq64,   __m256d, a, __m256d, b, 0)
DEFINE_N256_OP_N256_N256(__m256d, div_pd,       neon_fdivq64,   __m256d, a, __m256d, b, _IF_DIV_F64)

// VADDPD VSUBPD VMULPD VDIVPD

DEFINE_N256_OP_N256_N256(__m256,  add_ps,       neon_faddq32,   __m256,  a, __m256,  b, 0)
DEFINE_N256_OP_N256_N256(__m256,  sub_ps,       neon_fsubq32,   __m256,  a, __m256,  b, 0)
DEFINE_N256_OP_N256_N256(__m256,  mul_ps,       neon_fmulq32,   __m256,  a, __m256,  b, 0)
DEFINE_N256_OP_N256_N256(__m256,  div_ps,       neon_fdivq32,   __m256,  a, __m256,  b, _IF_DIV_F32)

// VPMINS VPMAXS

DEFINE_N256_OP_N256_N256(__m256i, min_epi8,     vminq_s8,       __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, min_epi16,    vminq_s16,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, min_epi32,    vminq_s32,      __m256i, a, __m256i, b, 0)

DEFINE_N256_OP_N256_N256(__m256i, max_epi8,     vmaxq_s8,       __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, max_epi16,    vmaxq_s16,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, max_epi32,    vmaxq_s32,      __m256i, a, __m256i, b, 0)

// VPMINU VPMINU

DEFINE_N256_OP_N256_N256(__m256i, min_epu8,     vminq_u8,       __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, min_epu16,    vminq_u16,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, min_epu32,    vminq_u32,      __m256i, a, __m256i, b, 0)

DEFINE_N256_OP_N256_N256(__m256i, max_epu8,     vmaxq_u8,       __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, max_epu16,    vmaxq_u16,      __m256i, a, __m256i, b, 0)
DEFINE_N256_OP_N256_N256(__m256i, max_epu32,    vmaxq_u32,      __m256i, a, __m256i, b, 0)

// VMIN VMAX

DEFINE_N256_OP_N256_N256(__m256d, min_pd,       vminq_f64,      __m256d, a, __m256d, b, _IF_MINMAX_F64)
DEFINE_N256_OP_N256_N256(__m256d, max_pd,       vmaxq_f64,      __m256d, a, __m256d, b, _IF_MINMAX_F64)

DEFINE_N256_OP_N256_N256(__m256,  min_ps,       vminq_f32,      __m256,  a, __m256,  b, _IF_MINMAX_F32)
DEFINE_N256_OP_N256_N256(__m256,  max_ps,       vmaxq_f32,      __m256,  a, __m256,  b, _IF_MINMAX_F32)

// VHADDPD VHADDPS

DEFINE_N256_OP_N256_N256(__m256d, hadd_pd,      vpaddq_f64,     __m256d, a, __m256d, b, 0);
DEFINE_N256_OP_N256_N256(__m256,  hadd_ps,      vpaddq_f32,     __m256,  a, __m256,  b, 0);

// VSQRTPD VSQRTPS

__forceinline
__n128x2 _nn256_sqrt_pd(__n128x2 a)
{
    __n128x2 T;

    T.val[0] = neon_fsqrtq64(a.val[0]);
    T.val[1] = neon_fsqrtq64(a.val[1]);

    T.val[0] = _nn_postprocess(T.val[0], a.val[0], a.val[0], _IF_SQRT_F64);
    T.val[1] = _nn_postprocess(T.val[1], a.val[1], a.val[1], _IF_SQRT_F64);

    return T;
}

__forceinline
__n128x2 _nn256_sqrt_ps(__n128x2 a)
{
    __n128x2 T;

    T.val[0] = neon_fsqrtq32(a.val[0]);
    T.val[1] = neon_fsqrtq32(a.val[1]);

    T.val[0] = _nn_postprocess(T.val[0], a.val[0], a.val[0], _IF_SQRT_F32);
    T.val[1] = _nn_postprocess(T.val[1], a.val[1], a.val[1], _IF_SQRT_F32);

    return T;
}

__forceinline
__m256d _mm256_sqrt_pd(__m256d a)
{
    return _nn256_castn256_pd( _nn256_sqrt_pd(_nn256_castpd_n256(a)) );
}

__forceinline
__m256 _mm256_sqrt_ps(__m256 a)
{
    return _nn256_castn256_ps( _nn256_sqrt_ps(_nn256_castps_n256(a)) );
}

// VBLENDV

DEFINE_N256_OP_N256_N256_N256(__m256i, blendv_epi8,  sw_blendv_epi8, __m256i, a, __m256i, b, __m256i, c,    0)
DEFINE_N256_OP_N256_N256_N256(__m256d, blendv_pd,    sw_blendv_pd,   __m256d, a, __m256d, b, __m256d, c,    0)
DEFINE_N256_OP_N256_N256_N256(__m256,  blendv_ps,    sw_blendv_ps,   __m256,  a, __m256,  b, __m256,  c,    0)

// BROADCAST variants

__forceinline __n128 sw_broadcastb_epi8(__n128 const a)      { __n128 T = vdupq_laneq_u8 (a, 0); return T; }
__forceinline __n128 sw_broadcastw_epi16(__n128 const a)     { __n128 T = vdupq_laneq_u16(a, 0); return T; }
__forceinline __n128 sw_broadcastd_epi32(__n128 const a)     { __n128 T = vdupq_laneq_u32(a, 0); return T; }
__forceinline __n128 sw_broadcastq_epi64(__n128 const a)     { __n128 T = vdupq_laneq_u64(a, 0); return T; }
__forceinline __n128 sw_broadcastsd_pd(__n128 const a)       { __n128 T = vdupq_laneq_s64(a, 0); return T; }
__forceinline __n128 sw_broadcastss_ps(__n128 const a)       { __n128 T = vdupq_laneq_s32(a, 0); return T; }
__forceinline __n128 sw_broadcastsi128_si256(__n128 const a) { __n128 T = a;                     return T; }

DEFINE_N256_OP_N128(__m256i, broadcastb_epi8,      sw_broadcastb_epi8,      __m128i, a, _IF_DUP_128)
DEFINE_N256_OP_N128(__m256i, broadcastw_epi16,     sw_broadcastw_epi16,     __m128i, a, _IF_DUP_128)
DEFINE_N256_OP_N128(__m256i, broadcastd_epi32,     sw_broadcastd_epi32,     __m128i, a, _IF_DUP_128)
DEFINE_N256_OP_N128(__m256i, broadcastq_epi64,     sw_broadcastq_epi64,     __m128i, a, _IF_DUP_128)
DEFINE_N256_OP_N128(__m256d, broadcastsd_pd,       sw_broadcastsd_pd,       __m128d, a, _IF_DUP_128)
DEFINE_N256_OP_N128(__m256,  broadcastss_ps,       sw_broadcastss_ps,       __m128,  a, _IF_DUP_128)
DEFINE_N256_OP_N128(__m256i, broadcastsi128_si256, sw_broadcastsi128_si256, __m128i, a, _IF_DUP_128)

// VEXTRACTF128

__forceinline
__m128d _mm256_extractf128_pd(__m256d a, const int imm8)
{
    __m128d T = *(__m128d *)&a.m256d_f64[(imm8 & 1) << 1];
    return T;
}

__forceinline
__m128 _mm256_extractf128_ps(__m256 a, const int imm8)
{
    __m128 T = *(__m128 *)&a.m256_f32[(imm8 & 1) << 2];
    return T;
}

// VEXTRACTI128

__forceinline
__m128i _mm256_extracti128_si256(__m256i a, const int imm8)
{
    __m128i T = *(__m128i *)&a.m256i_u64[(imm8 & 1) << 1];
    return T;
}

// VINSERTF128

__forceinline
__m256d _mm256_insertf128_pd(__m256d a, __m128d b, const int imm8)
{
    __m256d T = a;
    *(__m128d *)&T.m256d_f64[(imm8 & 1) << 1] = b;
    return T;
}

__forceinline
__m256 _mm256_insertf128_ps(__m256 a, __m128 b, const int imm8)
{
    __m256 T = a;
    *(__m128 *)&T.m256_f32[(imm8 & 1) << 2] = b;
    return T;
}

// VINSERTI128

__forceinline
__m256i _mm256_inserti128_si256(__m256i a, __m128i b, const int imm8)
{
    __m256i T = a;
    *(__m128i *)&T.m256i_u64[(imm8 & 1) << 1] = b;
    return T;
}

// VPERF2F128

__forceinline
__n256i _nn256_permute2f128_si256 (__n256i a, __n256i b, const int imm8)
{
    __n256i T;

    T.val[0] = (imm8 & 0x08) ? _nn_set1_ps(0.0f) : ((imm8 & 0x02) ? b.val[(imm8 & 0x01) >> 0] : a.val[(imm8 & 0x01) >> 0]);
    T.val[1] = (imm8 & 0x80) ? _nn_set1_ps(0.0f) : ((imm8 & 0x20) ? b.val[(imm8 & 0x10) >> 4] : a.val[(imm8 & 0x10) >> 4]);

    return T;
}

__forceinline
__m256i _mm256_permute2x128_si256 (__m256i a, __m256i b, const int imm8)
{
    return _nn256_castn256_si256( _nn256_permute2f128_si256(_nn256_castsi256_n256(a), _nn256_castsi256_n256(b), imm8) );
}

__forceinline
__m256d _mm256_permute2f128_pd (__m256d a, __m256d b, const int imm8)
{
    return _nn256_castn256_pd( _nn256_permute2f128_si256(_nn256_castpd_n256(a), _nn256_castpd_n256(b), imm8) );
}

__forceinline
__m256 _mm256_permute2f128_ps (__m256 a, __m256 b, const int imm8)
{
    return _nn256_castn256_ps( _nn256_permute2f128_si256(_nn256_castps_n256(a), _nn256_castps_n256(b), imm8) );
}

// VPERMILPD VPERMILPS

__forceinline
__m256d _mm256_permute_pd(__m256d a, const int imm8)
{
    __m256d T =
    {
        a.m256d_f64[0 + ((imm8 >> 0) & 1)],
        a.m256d_f64[0 + ((imm8 >> 1) & 1)],
        a.m256d_f64[2 + ((imm8 >> 2) & 1)],
        a.m256d_f64[2 + ((imm8 >> 3) & 1)],
    };

    return T;
}

__forceinline
__m256 _mm256_permute_ps(__m256 a, const int imm8)
{
    __m256 T =
    {
        a.m256_f32[0 + ((imm8 >> 0) & 3)],
        a.m256_f32[0 + ((imm8 >> 2) & 3)],
        a.m256_f32[0 + ((imm8 >> 4) & 3)],
        a.m256_f32[0 + ((imm8 >> 6) & 3)],
        a.m256_f32[4 + ((imm8 >> 0) & 3)],
        a.m256_f32[4 + ((imm8 >> 2) & 3)],
        a.m256_f32[4 + ((imm8 >> 4) & 3)],
        a.m256_f32[4 + ((imm8 >> 6) & 3)],
    };

    return T;
}

// VMOVSHDUP VMOVSLDUP

__forceinline
__m256 _mm256_moveldup_ps(__m256 a)
{
    return _mm256_permute_ps(a, 0xA0); // A0 = 10'10'00'00
}

__forceinline
__m256 _mm256_movehdup_ps(__m256 a)
{
    return _mm256_permute_ps(a, 0xF5); // F5 = 11'11'01'01
}

// VCVT variants

// VCVTDQ2PD

__forceinline
__n128x2 _nn256_sw_cvtepi32_pd(__n128i a)
{
    __n128x2 T;

    T.val[0].n128_f64[0] = (int)a.n128_u32[0];
    T.val[0].n128_f64[1] = (int)a.n128_u32[1];
    T.val[1].n128_f64[0] = (int)a.n128_u32[2];
    T.val[1].n128_f64[1] = (int)a.n128_u32[3];

    return T;
}

#if 0
__forceinline
__n128x2 _nn256_cvtepi32_pd(__n128i a)
{
    __n128x2 T;

    T.val[0] = vcvt_f64_s32(a.DUMMYNEONSTRUCT.low64);
    T.val[1] = vcvt_high_f64_s32(a);

    return T;
}
#endif

// VCVTDQ2PS

__forceinline
__m256d _mm256_cvtepi32_pd(__m128i a)
{
    return _nn256_castn256_pd( _nn256_sw_cvtepi32_pd(_nn128_castsi128_n128(a)) );
}

__forceinline
__n256 _nn256_sw_cvtepi32_ps(__n256i a)
{
    __n256 T;

    T.val[0].n128_f32[0] = (float)a.val[0].n128_i32[0];
    T.val[0].n128_f32[1] = (float)a.val[0].n128_i32[1];
    T.val[0].n128_f32[2] = (float)a.val[0].n128_i32[2];
    T.val[0].n128_f32[3] = (float)a.val[0].n128_i32[3];
    T.val[1].n128_f32[0] = (float)a.val[1].n128_i32[0];
    T.val[1].n128_f32[1] = (float)a.val[1].n128_i32[1];
    T.val[1].n128_f32[2] = (float)a.val[1].n128_i32[2];
    T.val[1].n128_f32[3] = (float)a.val[1].n128_i32[3];

    return T;
}

__forceinline
__m256 _mm256_cvtepi32_ps(__m256i a)
{
    return _nn256_castn256_ps( _nn256_sw_cvtepi32_ps(_nn256_castsi256_n256(a)) );
}

// VCVTPS2PD

__forceinline
__n128x2 _nn256_sw_cvtps_pd(__n128 a)
{
    __n128x2 T;

    T.val[0].n128_f64[0] = a.n128_f32[0];
    T.val[0].n128_f64[1] = a.n128_f32[1];
    T.val[1].n128_f64[0] = a.n128_f32[2];
    T.val[1].n128_f64[1] = a.n128_f32[3];

    return T;
}

__forceinline
__n128x2 _nn256_cvtps_pd(__n128 a)
{
    __n128x2 T;

    T.val[0] = vcvt_f64_f32(a.DUMMYNEONSTRUCT.low64);
    T.val[1] = vcvt_high_f64_f32(a);

    return T;
}

__forceinline
__m256d _mm256_cvtps_pd(__m128 a)
{
    return _nn256_castn256_pd( _nn256_cvtps_pd(_nn128_castps_n128(a)) );
}

// VCVTPD2DQ

__forceinline
__n128i _nn256_sw_cvtpd_epi32(__n256d a)
{
    __n128 T;

    T.n128_u32[0] = (__int32)a.val[0].n128_f64[0];
    T.n128_u32[1] = (__int32)a.val[0].n128_f64[1];
    T.n128_u32[2] = (__int32)a.val[1].n128_f64[0];
    T.n128_u32[3] = (__int32)a.val[1].n128_f64[1];

    return T;
}

__forceinline
__m128i _mm256_cvtpd_epi32(__m256d a)
{
    return _nn128_castn128_si128( _nn256_sw_cvtpd_epi32(_nn256_castpd_n256(a)) );
}

// VCVTTPD2DQ

__forceinline
__n128i _nn256_sw_cvttpd_epi32(__n256d a)
{
    __n128 T;

    T.n128_u32[0] = (__int32)a.val[0].n128_f64[0];
    T.n128_u32[1] = (__int32)a.val[0].n128_f64[1];
    T.n128_u32[2] = (__int32)a.val[1].n128_f64[0];
    T.n128_u32[3] = (__int32)a.val[1].n128_f64[1];

    return T;
}

__forceinline
__m128i _mm256_cvttpd_epi32(__m256d a)
{
    return _nn128_castn128_si128( _nn256_sw_cvttpd_epi32(_nn256_castpd_n256(a)) );
}

// VCVTPD2PS

__forceinline
__n128 _nn256_sw_cvtpd_ps(__n128x2 a)
{
    __n128 T;

    T.n128_f32[0] = (float)a.val[0].n128_f64[0];
    T.n128_f32[1] = (float)a.val[0].n128_f64[1];
    T.n128_f32[2] = (float)a.val[1].n128_f64[0];
    T.n128_f32[3] = (float)a.val[1].n128_f64[1];

    return T;
}

__forceinline
__n128 _nn256_cvtpd_ps(__n256 a)
{
    __n128 T = vcvt_high_f32_f64(vcvt_f32_f64(a.val[0]), a.val[1]);

    return T;
}

__forceinline
__m128 _mm256_cvtpd_ps(__m256d a)
{
    return _nn128_castn128_ps( _nn256_cvtpd_ps(_nn256_castpd_n256(a)) );
}

// VPSLL VPSRL VPSRA

__forceinline
__n256i _nn256_sw_sli_si256(__n256i a, const int imm8)
{
    __n256 T;

    for (unsigned i = 0; i < 16; i++)
    {
        unsigned FromLane = (i + imm8);

        T.val[0].n128_i8[i] = (FromLane >= 16) ? 0 : a.val[0].n128_i8[FromLane];
        T.val[1].n128_i8[i] = (FromLane >= 16) ? 0 : a.val[1].n128_i8[FromLane];
    }

    return T;
}

__forceinline
__n256i _nn256_slli_si256(__n256i a, const int imm8)
{
    return _nn256_sw_sli_si256(a, -imm8);
}

__forceinline
__n256i _nn256_srli_si256(__n256i a, const int imm8)
{
    return _nn256_sw_sli_si256(a, +imm8);
}

__forceinline
__m256i _mm256_slli_si256(__m256i a, const int imm8)
{
    return _nn256_castn256_si256( _nn256_slli_si256(_nn256_castsi256_n256(a), imm8 ) );
}

__forceinline
__m256i _mm256_srli_si256(__m256i a, const int imm8)
{
    return _nn256_castn256_si256( _nn256_srli_si256(_nn256_castsi256_n256(a), imm8 ) );
}

//
// Double-wide AVX operations derived by doubling existing SSE operations
//

//
// Template for double-wide 256-bit dest,source1 vector instructions
//

#define DEFINE_M256_OP_M256(rettype, rettype128, name, arg1type, arg1type128) \
\
__forceinline __n128x2 _nn256_ ## name (__n128x2 a) \
{ \
    __n128x2 T; \
    T.val[0] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[0]) ) ); \
    T.val[1] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[1]) ) ); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128x2_from_ ## arg1type (arg1) ) ); \
}

// VCVTPS2DQ
// VCVTTPS2DQ

DEFINE_M256_OP_M256(__m256i, __m128i, cvtps_epi32,   __m256 , __m128 )
DEFINE_M256_OP_M256(__m256i, __m128i, cvttps_epi32,  __m256 , __m128 )

// VRCPPS
// VRSQRTPS

DEFINE_M256_OP_M256(__m256 , __m128 , rcp_ps,        __m256 , __m128 )
DEFINE_M256_OP_M256(__m256 , __m128 , rsqrt_ps,      __m256 , __m128 )

//
// Template for double-wide 256-bit dest,source1,imm8 vector instructions
//

#define DEFINE_M256_OP_M256_IMM8(rettype, rettype128, name, arg1type, arg1type128) \
\
__forceinline __n128x2 _nn256_ ## name (__n128x2 a, const int imm8) \
{ \
    __n128x2 T; \
    T.val[0] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[0]), imm8 ) ); \
    T.val[1] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[1]), imm8 ) ); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1, const int imm8) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128x2_from_ ## arg1type (arg1), imm8 ) ); \
}

DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, shuffle_epi32, __m256i, __m128i)

DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, slli_epi16,    __m256i, __m128i)
DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, slli_epi32,    __m256i, __m128i)
DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, slli_epi64,    __m256i, __m128i)

DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, srai_epi16,    __m256i, __m128i)
DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, srai_epi32,    __m256i, __m128i)

DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, srli_epi16,    __m256i, __m128i)
DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, srli_epi32,    __m256i, __m128i)
DEFINE_M256_OP_M256_IMM8(__m256i, __m128i, srli_epi64,    __m256i, __m128i)

//
// Template for double-wide 256-bit dest,source1,source2 vector instructions
// Variants for source2 is 128-bit and 256-bit
//

#define DEFINE_M256_OP_M256_M128(rettype, rettype128, name, arg1type, arg1type128, arg2type, arg2type128) \
\
__forceinline __n128x2 _nn256_ ## name (__n128x2 a, const __n128 b) \
{ \
    __n128x2 T; \
    T.val[0] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[0]), arg2type128 ## _from___n128(b) ) ); \
    T.val[1] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[1]), arg2type128 ## _from___n128(b) ) ); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1, arg2type arg2) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128x2_from_ ## arg1type (arg1), __n128_from_ ## arg2type (arg2) ) ); \
}

DEFINE_M256_OP_M256_M128(__m256i, __m128i, sll_epi16,     __m256i, __m128i, __m128i, __m128i)
DEFINE_M256_OP_M256_M128(__m256i, __m128i, sll_epi32,     __m256i, __m128i, __m128i, __m128i)
DEFINE_M256_OP_M256_M128(__m256i, __m128i, sll_epi64,     __m256i, __m128i, __m128i, __m128i)

DEFINE_M256_OP_M256_M128(__m256i, __m128i, sra_epi16,     __m256i, __m128i, __m128i, __m128i)
DEFINE_M256_OP_M256_M128(__m256i, __m128i, sra_epi32,     __m256i, __m128i, __m128i, __m128i)

DEFINE_M256_OP_M256_M128(__m256i, __m128i, srl_epi16,     __m256i, __m128i, __m128i, __m128i)
DEFINE_M256_OP_M256_M128(__m256i, __m128i, srl_epi32,     __m256i, __m128i, __m128i, __m128i)
DEFINE_M256_OP_M256_M128(__m256i, __m128i, srl_epi64,     __m256i, __m128i, __m128i, __m128i)

#define DEFINE_M256_OP_M256_M256(rettype, rettype128, name, arg1type, arg1type128, arg2type, arg2type128) \
\
__forceinline __n128x2 _nn256_ ## name (__n128x2 a, const __n128x2 b) \
{ \
    __n128x2 T; \
    T.val[0] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[0]), arg2type128 ## _from___n128(b.val[0]) ) ); \
    T.val[1] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[1]), arg2type128 ## _from___n128(b.val[1]) ) ); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1, arg2type arg2) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128x2_from_ ## arg1type (arg1), __n128x2_from_ ## arg2type (arg2) ) ); \
}

DEFINE_M256_OP_M256_M256(__m256i, __m128i, mulhi_epi16,   __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, mulhi_epu16,   __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, mulhrs_epi16,  __m256i, __m128i, __m256i, __m128i)

DEFINE_M256_OP_M256_M256(__m256i, __m128i, sad_epu8,      __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, shuffle_epi8,  __m256i, __m128i, __m256i, __m128i)

DEFINE_M256_OP_M256_M256(__m256i, __m128i, sllv_epi32,    __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, sllv_epi64,    __m256i, __m128i, __m256i, __m128i)

DEFINE_M256_OP_M256_M256(__m256i, __m128i, srav_epi32,    __m256i, __m128i, __m256i, __m128i)

DEFINE_M256_OP_M256_M256(__m256i, __m128i, srlv_epi32,    __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, srlv_epi64,    __m256i, __m128i, __m256i, __m128i)

DEFINE_M256_OP_M256_M256(__m256d, __m128d, addsub_pd,     __m256d, __m128d, __m256d, __m128d)
DEFINE_M256_OP_M256_M256(__m256 , __m128 , addsub_ps,     __m256 , __m128 , __m256 , __m128 )
DEFINE_M256_OP_M256_M256(__m256d, __m128d, hsub_pd,       __m256d, __m128d, __m256d, __m128d)
DEFINE_M256_OP_M256_M256(__m256 , __m128 , hsub_ps,       __m256 , __m128 , __m256 , __m128 )

DEFINE_M256_OP_M256_M256(__m256i, __m128i, madd_epi16,    __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, maddubs_epi16, __m256i, __m128i, __m256i, __m128i)

// AES uses different data types for SSE and AVX variants

#define _mm_aesdec_epi128      _mm_aesdec_si128
#define _mm_aesdeclast_epi128  _mm_aesdeclast_si128
#define _mm_aesenc_epi128      _mm_aesenc_si128
#define _mm_aesenclast_epi128  _mm_aesenclast_si128

DEFINE_M256_OP_M256_M256(__m256i, __m128i, aesdec_epi128, __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, aesenc_epi128, __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, aesdeclast_epi128, __m256i, __m128i, __m256i, __m128i)
DEFINE_M256_OP_M256_M256(__m256i, __m128i, aesenclast_epi128, __m256i, __m128i, __m256i, __m128i)

#define __VAES__

//
// Template for double-wide 256-bit dest,source1,source2,imm8 vector instructions
//

#define DEFINE_M256_OP_M256_M256_IMM8(rettype, rettype128, name, arg1type, arg1type128, arg2type, arg2type128, hish) \
\
__forceinline __n128x2 _nn256_ ## name (__n128x2 a, const __n128x2 b, const int imm8) \
{ \
    __n128x2 T; \
    T.val[0] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[0]), arg2type128 ## _from___n128(b.val[0]), imm8 ) ); \
    T.val[1] = __n128_from_ ## rettype128 ( _mm_ ## name( arg1type128 ## _from___n128(a.val[1]), arg2type128 ## _from___n128(b.val[1]), imm8 >> hish ) ); \
    return T; \
} \
\
__forceinline rettype _mm256_ ## name (arg1type arg1, arg2type arg2, const int imm8) \
{ \
    return rettype ## _from___n128x2 ( _nn256_ ## name ( __n128x2_from_ ## arg1type (arg1), __n128x2_from_ ## arg2type (arg2), imm8 ) ); \
}

DEFINE_M256_OP_M256_M256_IMM8(__m256d, __m128d, blend_pd,      __m256d, __m128d, __m256d, __m128d, 2)
DEFINE_M256_OP_M256_M256_IMM8(__m256 , __m128 , blend_ps,      __m256 , __m128 , __m256 , __m128 , 4)
DEFINE_M256_OP_M256_M256_IMM8(__m256i, __m128i, blend_epi16,   __m256i, __m128i, __m256i, __m128i, 0)
// DEFINE_M256_OP_M256_M256_IMM8(__m256i, __m128i, blend_epi32,   __m256i, __m128i, __m256i, __m128i, 4)

DEFINE_M256_OP_M256_M256_IMM8(__m256 , __m128 , dp_ps,         __m256 , __m128 , __m256 , __m128 , 0)

DEFINE_M256_OP_M256_M256_IMM8(__m256d, __m128d, shuffle_pd,    __m256d, __m128d, __m256d, __m128d, 2)
DEFINE_M256_OP_M256_M256_IMM8(__m256 , __m128 , shuffle_ps,    __m256 , __m128 , __m256 , __m128 , 0)

// PCLMUL uses different data types for SSE and AVX variants

#define _mm_clmulepi64_epi128  _mm_clmulepi64_si128

DEFINE_M256_OP_M256_M256_IMM8(__m256i, __m128i, clmulepi64_epi128, __m256i, __m128i, __m256i, __m128i, 0)

//
// AVX-VNNI
//

// VPDPBUSD VPDPBUSDS

#if _M_ARM64_EXTENSION >= 86
__declspec(selectany) int Has_I8MM = 1;
#else
__declspec(selectany) int Has_I8MM = 0;
#endif


__forceinline
__n128 sw_dpbusd_epi32(__n128 c, __n128 a, __n128 b)
{
    __n128 T;

    if (Has_I8MM)
    {
        // FEAT_I8MM is ARMv8.6, found on Snapdragon X and Apple M3

        T = vusdotq_s32(c, a, b);
    }
    else
    {
        // Legacy ARMv8.0 NEON implementation

        T = _nn_maddubs_epi16(a, b);
        T = _nn_madd_epi16(T, _nn_set1_epi32(0x00010001));
        T = neon_addq32(c, T);
    }

    return T;
}

__forceinline
__n128 sw_dpbusds_epi32(__n128 c, __n128 a, __n128 b)
{
    // This is a saturating version of VPDPBUS,
    // compute dot-product separately then saturate the sum

    __n128 T = neon_moviqw(0);

    T = sw_dpbusd_epi32(T, a, b);
    T = neon_sqaddq32(c, T);

    return T;
}

// VPDPWSSD VPDPWSSDS

__forceinline
__n128 sw_dpwssd_epi32(__n128 c, __n128 a, __n128 b)
{
    __n128 T;

    T = sw_madd_epi16(a, b);
    T = neon_addq32(c, T);

    return T;
}

__forceinline
__n128 sw_dpwssds_epi32(__n128 c, __n128 a, __n128 b)
{
    __n128 T;

    T = sw_madd_epi16(a, b);
    T = neon_sqaddq32(c, T);

    return T;
}

DEFINE_N128_OP_N128_N128_N128(__m128i, dpbusd_avx_epi32,  sw_dpbusd_epi32,  __m128i, a, __m128i, b, __m128i, c,    0)
DEFINE_N128_OP_N128_N128_N128(__m128i, dpbusds_avx_epi32, sw_dpbusds_epi32, __m128i, a, __m128i, b, __m128i, c,    0)
DEFINE_N128_OP_N128_N128_N128(__m128i, dpwssd_avx_epi32,  sw_dpwssd_epi32,  __m128i, a, __m128i, b, __m128i, c,    0)
DEFINE_N128_OP_N128_N128_N128(__m128i, dpwssds_avx_epi32, sw_dpwssds_epi32, __m128i, a, __m128i, b, __m128i, c,    0)

DEFINE_N256_OP_N256_N256_N256(__m256i, dpbusd_avx_epi32,  sw_dpbusd_epi32,  __m256i, a, __m256i, b, __m256i, c,    0)
DEFINE_N256_OP_N256_N256_N256(__m256i, dpbusds_avx_epi32, sw_dpbusds_epi32, __m256i, a, __m256i, b, __m256i, c,    0)
DEFINE_N256_OP_N256_N256_N256(__m256i, dpwssd_avx_epi32,  sw_dpwssd_epi32,  __m256i, a, __m256i, b, __m256i, c,    0)
DEFINE_N256_OP_N256_N256_N256(__m256i, dpwssds_avx_epi32, sw_dpwssds_epi32, __m256i, a, __m256i, b, __m256i, c,    0)

#define __AVX_VNNI__

#pragma strict_gs_check(pop)

#endif  // ARM64/ARM64EC

#endif  // SOFT_INTRINSICS_AVX2

