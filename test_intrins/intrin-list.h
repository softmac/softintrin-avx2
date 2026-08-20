//
// INTRIN-LIST.H
//
// This file must be #include-ed with the appropriate macros already defined!
//

// Arithmetic SSE/SSE2/SSE3/SSSE3/SSE4.1
// Compatible with all Intel Core i5/i7, AMD Zen, Prism, and Rosetta 2

// these frst two appear to be missing from the Windows SDK softintrin.h??
#if defined(MISSING_FROM_WINDOWS_SDK)
DEFINE_TEST_OP_RA  (_mm_cvtss_si64,         __int64,    __m128)
DEFINE_TEST_OP_RA  (_mm_cvttss_si64,        __int64,    __m128)
#endif

// these two are not 32-bit x86 compatible
#if !defined(_M_IX86)
DEFINE_TEST_OP_RAB (_mm_cvtsi64_sd,         __m128d,    __m128d,    __int64)
DEFINE_TEST_OP_RAB (_mm_cvtsi64x_sd,        __m128d,    __m128d,    __int64)
#endif

DEFINE_TEST_OP_RAB (_mm_cvt_si2ss,          __m128,     __m128,     __int32)
DEFINE_TEST_OP_RA  (_mm_cvt_ss2si,          __int32,    __m128)
DEFINE_TEST_OP_RA  (_mm_cvtt_ss2si,         __int32,    __m128)

DEFINE_TEST_OP_RAB (_mm_cvtsi32_sd,         __m128d,    __m128d,    __int32)

DEFINE_TEST_OP_RA  (_mm_cvtepi32_pd,        __m128d,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepi32_ps,        __m128,     __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtpd_epi32,        __m128i,    __m128d)
DEFINE_TEST_OP_RA  (_mm_cvtps_epi32,        __m128i,    __m128)
DEFINE_TEST_OP_RA  (_mm_cvtpd_ps,           __m128,     __m128d)
DEFINE_TEST_OP_RA  (_mm_cvtps_pd,           __m128d,    __m128)
DEFINE_TEST_OP_RA  (_mm_cvttpd_epi32,       __m128i,    __m128d)
DEFINE_TEST_OP_RA  (_mm_cvttps_epi32,       __m128i,    __m128)

DEFINE_TEST_OP_RA  (_mm_cvtepi8_epi16,      __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepi8_epi32,      __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepi8_epi64,      __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepi16_epi32,     __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepi16_epi64,     __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepi32_epi64,     __m128i,    __m128i)

DEFINE_TEST_OP_RA  (_mm_cvtepu8_epi16,      __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepu8_epi32,      __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepu8_epi64,      __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepu16_epi32,     __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepu16_epi64,     __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_cvtepu32_epi64,     __m128i,    __m128i)

DEFINE_TEST_OP_RA  (_mm_abs_epi8,           __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_abs_epi16,          __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_abs_epi32,          __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_avg_epu8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_avg_epu16,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_add_epi8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_add_epi16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_add_epi32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_add_epi64,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_adds_epi8,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_adds_epi16,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_adds_epu8,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_adds_epu16,         __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_hadd_epi16,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_hadd_epi32,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_hadds_epi16,        __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_hadd_pd,            __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_hadd_ps,            __m128,     __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_madd_epi16,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_maddubs_epi16,      __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_and_si128,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_and_pd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_and_ps,             __m128,     __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_andnot_si128,       __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_andnot_pd,          __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_andnot_ps,          __m128,     __m128,     __m128)

DEFINE_TEST_OP_RABI(_mm_blend_epi16,        __m128i,    __m128i,    __m128i,    0x0C)
DEFINE_TEST_OP_RABI(_mm_blend_epi16,        __m128i,    __m128i,    __m128i,    0xAA)
DEFINE_TEST_OP_RABI(_mm_blend_pd,           __m128d,    __m128d,    __m128d,    0)
DEFINE_TEST_OP_RABI(_mm_blend_ps,           __m128,     __m128,     __m128,     3)

DEFINE_TEST_OP_RABC(_mm_blendv_epi8,        __m128i,    __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RABC(_mm_blendv_pd,          __m128d,    __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RABC(_mm_blendv_ps,          __m128,     __m128,     __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_sad_epu8,           __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_sub_epi8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_sub_epi16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_sub_epi32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_sub_epi64,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_subs_epi8,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_subs_epi16,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_subs_epu8,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_subs_epu16,         __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_hsub_epi16,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_hsub_epi32,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_hsubs_epi16,        __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_hsub_pd,            __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_hsub_ps,            __m128,     __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_addsub_pd,          __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_addsub_ps,          __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_add_pd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_add_ps,             __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_sub_pd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_sub_ps,             __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_mul_pd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_mul_ps,             __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_div_pd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_div_ps,             __m128,     __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_add_sd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_add_ss,             __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_sub_sd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_sub_ss,             __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_mul_sd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_mul_ss,             __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_div_sd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_div_ss,             __m128,     __m128,     __m128)

#if 0
DEFINE_TEST_OP_RAB (_mm_div_epi8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_div_epi16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_div_epi32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_div_epi64,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_div_epu8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_div_epu16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_div_epu32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_div_epu64,          __m128i,    __m128i,    __m128i)
#endif

DEFINE_TEST_OP_RABI(_mm_dp_pd,              __m128d,    __m128d,    __m128d,    0x7F)
DEFINE_TEST_OP_RABI(_mm_dp_pd,              __m128d,    __m128d,    __m128d,    0xFF)
DEFINE_TEST_OP_RABI(_mm_dp_ps,              __m128,     __m128,     __m128,     0x7F)
DEFINE_TEST_OP_RABI(_mm_dp_ps,              __m128,     __m128,     __m128,     0xFF)

DEFINE_TEST_OP_RAB (_mm_min_epi8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_min_epi16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_min_epi32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_min_epu8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_min_epu16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_min_epu32,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_min_pd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_min_ps,             __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_min_sd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_min_ss,             __m128,     __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_max_epi8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_max_epi16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_max_epi32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_max_epu8,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_max_epu16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_max_epu32,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_max_pd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_max_ps,             __m128,     __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_max_sd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_max_ss,             __m128,     __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_mul_epi32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_mul_epu32,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_mulhi_epi16,        __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_mulhi_epu16,        __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_mulhrs_epi16,       __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_mullo_epi16,        __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_mullo_epi32,        __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RA  (_mm_movemask_epi8,      int,        __m128i)
DEFINE_TEST_OP_RA  (_mm_movemask_pd,        int,        __m128d)
DEFINE_TEST_OP_RA  (_mm_movemask_ps,        int,        __m128)

DEFINE_TEST_OP_RAB (_mm_or_si128,           __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_or_pd,              __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_or_ps,              __m128,     __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_xor_si128,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_xor_pd,             __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RAB (_mm_xor_ps,             __m128,     __m128,     __m128)

DEFINE_TEST_OP_RA  (_mm_rcp_ps,             __m128,     __m128)
DEFINE_TEST_OP_RA  (_mm_rcp_ss,             __m128,     __m128)

DEFINE_TEST_OP_RA  (_mm_rsqrt_ps,           __m128,     __m128)
DEFINE_TEST_OP_RA  (_mm_rsqrt_ss,           __m128,     __m128)

DEFINE_TEST_OP_RA  (_mm_sqrt_pd,            __m128d,    __m128d)
DEFINE_TEST_OP_RA  (_mm_sqrt_ps,            __m128,     __m128)
DEFINE_TEST_OP_RAB (_mm_sqrt_sd,            __m128d,    __m128d,    __m128d)
DEFINE_TEST_OP_RA  (_mm_sqrt_ss,            __m128,     __m128)

DEFINE_TEST_OP_RAB (_mm_sll_epi16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_srl_epi16,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_sra_epi16,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_sll_epi32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_srl_epi32,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_sra_epi32,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_sll_epi64,          __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_srl_epi64,          __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAI (_mm_slli_epi16,         __m128i,    __m128i,    1)
DEFINE_TEST_OP_RAI (_mm_slli_epi16,         __m128i,    __m128i,    7)
DEFINE_TEST_OP_RAI (_mm_slli_epi16,         __m128i,    __m128i,    20)
DEFINE_TEST_OP_RAI (_mm_srli_epi16,         __m128i,    __m128i,    1)
DEFINE_TEST_OP_RAI (_mm_srli_epi16,         __m128i,    __m128i,    11)
DEFINE_TEST_OP_RAI (_mm_srli_epi16,         __m128i,    __m128i,    20)
DEFINE_TEST_OP_RAI (_mm_srai_epi16,         __m128i,    __m128i,    1)
DEFINE_TEST_OP_RAI (_mm_srai_epi16,         __m128i,    __m128i,    15)
DEFINE_TEST_OP_RAI (_mm_srai_epi16,         __m128i,    __m128i,    20)

DEFINE_TEST_OP_RAI (_mm_slli_epi32,         __m128i,    __m128i,    1)
DEFINE_TEST_OP_RAI (_mm_slli_epi32,         __m128i,    __m128i,    7)
DEFINE_TEST_OP_RAI (_mm_slli_epi32,         __m128i,    __m128i,    40)
DEFINE_TEST_OP_RAI (_mm_srli_epi32,         __m128i,    __m128i,    1)
DEFINE_TEST_OP_RAI (_mm_srli_epi32,         __m128i,    __m128i,    15)
DEFINE_TEST_OP_RAI (_mm_srli_epi32,         __m128i,    __m128i,    40)
DEFINE_TEST_OP_RAI (_mm_srai_epi32,         __m128i,    __m128i,    1)
DEFINE_TEST_OP_RAI (_mm_srai_epi32,         __m128i,    __m128i,    31)
DEFINE_TEST_OP_RAI (_mm_srai_epi32,         __m128i,    __m128i,    40)

DEFINE_TEST_OP_RAI (_mm_slli_epi64,         __m128i,    __m128i,    14)
DEFINE_TEST_OP_RAI (_mm_slli_epi64,         __m128i,    __m128i,    74)
DEFINE_TEST_OP_RAI (_mm_srli_epi64,         __m128i,    __m128i,    28)
DEFINE_TEST_OP_RAI (_mm_srli_epi64,         __m128i,    __m128i,    78)

DEFINE_TEST_OP_RAI (_mm_slli_si128,         __m128i,    __m128i,    1)
DEFINE_TEST_OP_RAI (_mm_slli_si128,         __m128i,    __m128i,    15)
DEFINE_TEST_OP_RAI (_mm_srli_si128,         __m128i,    __m128i,    1)
DEFINE_TEST_OP_RAI (_mm_srli_si128,         __m128i,    __m128i,    15)

// SSE/SSE2/SSE3 data movement

DEFINE_TEST_OP_RA  (_mm_load_pd,            __m128d,    pdouble)
DEFINE_TEST_OP_RA  (_mm_load_ps,            __m128,     pfloat)
DEFINE_TEST_OP_RA  (_mm_loadu_pd,           __m128d,    pdouble)
DEFINE_TEST_OP_RA  (_mm_loadu_ps,           __m128,     pfloat)

DEFINE_TEST_OP_RAB (_mm_shuffle_epi8,       __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAI (_mm_shuffle_epi32,      __m128i,    __m128i,    0x00)               // 0 0 0 0
DEFINE_TEST_OP_RAI (_mm_shuffle_epi32,      __m128i,    __m128i,    0x36)               // 0 3 1 2
DEFINE_TEST_OP_RAI (_mm_shuffle_epi32,      __m128i,    __m128i,    0x5A)               // 1 1 2 2
DEFINE_TEST_OP_RAI (_mm_shuffle_epi32,      __m128i,    __m128i,    0x63)               // 1 2 0 3
DEFINE_TEST_OP_RAI (_mm_shuffle_epi32,      __m128i,    __m128i,    0xA5)               // 2 2 1 1
DEFINE_TEST_OP_RAI (_mm_shuffle_epi32,      __m128i,    __m128i,    0xFF)               // 3 3 3 3

DEFINE_TEST_OP_RABI(_mm_shuffle_pd,         __m128d,    __m128d,    __m128d,    0)
DEFINE_TEST_OP_RABI(_mm_shuffle_pd,         __m128d,    __m128d,    __m128d,    1)
DEFINE_TEST_OP_RABI(_mm_shuffle_pd,         __m128d,    __m128d,    __m128d,    2)
DEFINE_TEST_OP_RABI(_mm_shuffle_pd,         __m128d,    __m128d,    __m128d,    3)

DEFINE_TEST_OP_RABI(_mm_shuffle_ps,         __m128,     __m128,     __m128,     0x00)   // 0 0 0 0
DEFINE_TEST_OP_RABI(_mm_shuffle_ps,         __m128,     __m128,     __m128,     0x69)   // 1 2 2 1
DEFINE_TEST_OP_RABI(_mm_shuffle_ps,         __m128,     __m128,     __m128,     0x96)   // 2 1 1 2
DEFINE_TEST_OP_RABI(_mm_shuffle_ps,         __m128,     __m128,     __m128,     0xFF)   // 3 3 3 3

DEFINE_TEST_OP_VAB (_mm_store_pd,                       pdouble,    __m128d)
DEFINE_TEST_OP_VAB (_mm_store_ps,                       pfloat,     __m128)
DEFINE_TEST_OP_VAB (_mm_storeu_pd,                      pdouble,    __m128d)
DEFINE_TEST_OP_VAB (_mm_storeu_ps,                      pfloat,     __m128)

DEFINE_TEST_OP_R   (_mm_setzero_pd,         __m128d)
DEFINE_TEST_OP_R   (_mm_setzero_ps,         __m128)
DEFINE_TEST_OP_R   (_mm_setzero_si128,      __m128i)

#define SET_I8_0   0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8
#define SET_I8_1   127, -128, 0, 64, -64, 32, -32, 16, -16, 8, -8, 4, -4, 2, -2, 1
#define SET_I8_2   -11, 22, 0, -33, 44, -55, 66, -77, 88, -99, 110, -121, 12, -23, 34, -45
#define SET_I8_3   0, -127, 126, -125, 124, -123, 122, -121, 120, -119, 118, -117, 116, -115, 114, -113

#define SET_I16_0  0, 1, -1, 2, -2, 3, -3, 4
#define SET_I16_1  32767, -32768, 0, 16384, -16384, 8192, -8192, 1
#define SET_I16_2  -1234, 2345, 0, -3456, 4567, -5678, 6789, -7890
#define SET_I16_3  0, -30000, 29000, -28000, 27000, -26000, 25000, -24000

#define SET_I32_0  0, 1, -1, 2
#define SET_I32_1  2147483647, (-2147483647 - 1), 0, 1073741824
#define SET_I32_2  -123456789, 234567890, 0, -345678901
#define SET_I32_3  0, -2000000000, 1900000000, -1800000000

#define SET_I64_0  0LL, 1LL
#define SET_I64_1  -1LL, 0x7FFFFFFFFFFFFFFFLL
#define SET_I64_2  -123456789012345LL, 234567890123456LL
#define SET_I64_3  0LL, -345678901234567LL

#define SET_M64_0  literal_m64(0LL), literal_m64(1LL)
#define SET_M64_1  literal_m64(-1LL), literal_m64(0x7FFFFFFFFFFFFFFFLL)
#define SET_M64_2  literal_m64(-123456789012345LL), literal_m64(234567890123456LL)
#define SET_M64_3  literal_m64(0LL), literal_m64(-345678901234567LL)

#define SET_F32_0  0.0f, 1.0f, -1.0f, 2.5f
#define SET_F32_1  -0.0f, -2.5f, 0.0f, 3.25f
#define SET_F32_2  65536.0f, -65536.0f, 0.0f, 0.5f
#define SET_F32_3  -123.75f, 0.0f, 456.5f, -0.25f

#define SET_F64_0  0.0, 1.0
#define SET_F64_1  -1.0, 0.0
#define SET_F64_2  65536.5, -65536.25
#define SET_F64_3  -123456.75, 0.5

DEFINE_TEST_OP_RT  (_mm_set_epi8,           __m128i,    0, SET_I8_0)
DEFINE_TEST_OP_RT  (_mm_set_epi8,           __m128i,    1, SET_I8_1)
DEFINE_TEST_OP_RT  (_mm_set_epi8,           __m128i,    2, SET_I8_2)
DEFINE_TEST_OP_RT  (_mm_set_epi8,           __m128i,    3, SET_I8_3)

DEFINE_TEST_OP_RT  (_mm_set_epi16,          __m128i,    0, SET_I16_0)
DEFINE_TEST_OP_RT  (_mm_set_epi16,          __m128i,    1, SET_I16_1)
DEFINE_TEST_OP_RT  (_mm_set_epi16,          __m128i,    2, SET_I16_2)
DEFINE_TEST_OP_RT  (_mm_set_epi16,          __m128i,    3, SET_I16_3)

DEFINE_TEST_OP_RT  (_mm_set_epi32,          __m128i,    0, SET_I32_0)
DEFINE_TEST_OP_RT  (_mm_set_epi32,          __m128i,    1, SET_I32_1)
DEFINE_TEST_OP_RT  (_mm_set_epi32,          __m128i,    2, SET_I32_2)
DEFINE_TEST_OP_RT  (_mm_set_epi32,          __m128i,    3, SET_I32_3)

#if defined(_M_IX86) || defined(USE_SOFT_INTRINSICS)
DEFINE_TEST_OP_RT  (_mm_set_epi64,          __m128i,    0, SET_M64_0)
DEFINE_TEST_OP_RT  (_mm_set_epi64,          __m128i,    1, SET_M64_1)
DEFINE_TEST_OP_RT  (_mm_set_epi64,          __m128i,    2, SET_M64_2)
DEFINE_TEST_OP_RT  (_mm_set_epi64,          __m128i,    3, SET_M64_3)
#endif

DEFINE_TEST_OP_RT  (_mm_set_epi64x,         __m128i,    0, SET_I64_0)
DEFINE_TEST_OP_RT  (_mm_set_epi64x,         __m128i,    1, SET_I64_1)
DEFINE_TEST_OP_RT  (_mm_set_epi64x,         __m128i,    2, SET_I64_2)
DEFINE_TEST_OP_RT  (_mm_set_epi64x,         __m128i,    3, SET_I64_3)

DEFINE_TEST_OP_RT  (_mm_set_pd,             __m128d,    0, SET_F64_0)
DEFINE_TEST_OP_RT  (_mm_set_pd,             __m128d,    1, SET_F64_1)
DEFINE_TEST_OP_RT  (_mm_set_pd,             __m128d,    2, SET_F64_2)
DEFINE_TEST_OP_RT  (_mm_set_pd,             __m128d,    3, SET_F64_3)

DEFINE_TEST_OP_RV  (_mm_set_pd1,            __m128d,    0, 0.0)
DEFINE_TEST_OP_RV  (_mm_set_pd1,            __m128d,    1, 1.25)
DEFINE_TEST_OP_RV  (_mm_set_pd1,            __m128d,    2, -2.5)
DEFINE_TEST_OP_RV  (_mm_set_pd1,            __m128d,    3, -0.0)

DEFINE_TEST_OP_RT  (_mm_set_ps,             __m128,     0, SET_F32_0)
DEFINE_TEST_OP_RT  (_mm_set_ps,             __m128,     1, SET_F32_1)
DEFINE_TEST_OP_RT  (_mm_set_ps,             __m128,     2, SET_F32_2)
DEFINE_TEST_OP_RT  (_mm_set_ps,             __m128,     3, SET_F32_3)

DEFINE_TEST_OP_RV  (_mm_set_ps1,            __m128,     0, 0.0f)
DEFINE_TEST_OP_RV  (_mm_set_ps1,            __m128,     1, 1.25f)
DEFINE_TEST_OP_RV  (_mm_set_ps1,            __m128,     2, -2.5f)
DEFINE_TEST_OP_RV  (_mm_set_ps1,            __m128,     3, -0.0f)

DEFINE_TEST_OP_RV  (_mm_set_sd,             __m128d,    0, 0.0)
DEFINE_TEST_OP_RV  (_mm_set_sd,             __m128d,    1, 1.25)
DEFINE_TEST_OP_RV  (_mm_set_sd,             __m128d,    2, -2.5)
DEFINE_TEST_OP_RV  (_mm_set_sd,             __m128d,    3, -0.0)

DEFINE_TEST_OP_RV  (_mm_set_ss,             __m128,     0, 0.0f)
DEFINE_TEST_OP_RV  (_mm_set_ss,             __m128,     1, 1.25f)
DEFINE_TEST_OP_RV  (_mm_set_ss,             __m128,     2, -2.5f)
DEFINE_TEST_OP_RV  (_mm_set_ss,             __m128,     3, -0.0f)

DEFINE_TEST_OP_RV  (_mm_set1_epi8,          __m128i,    0, 0)
DEFINE_TEST_OP_RV  (_mm_set1_epi8,          __m128i,    1, 127)
DEFINE_TEST_OP_RV  (_mm_set1_epi8,          __m128i,    2, -1)
DEFINE_TEST_OP_RV  (_mm_set1_epi8,          __m128i,    3, -128)

DEFINE_TEST_OP_RV  (_mm_set1_epi16,         __m128i,    0, 0)
DEFINE_TEST_OP_RV  (_mm_set1_epi16,         __m128i,    1, 32767)
DEFINE_TEST_OP_RV  (_mm_set1_epi16,         __m128i,    2, -1)
DEFINE_TEST_OP_RV  (_mm_set1_epi16,         __m128i,    3, -32768)

DEFINE_TEST_OP_RV  (_mm_set1_epi32,         __m128i,    0, 0)
DEFINE_TEST_OP_RV  (_mm_set1_epi32,         __m128i,    1, 2147483647)
DEFINE_TEST_OP_RV  (_mm_set1_epi32,         __m128i,    2, -1)
DEFINE_TEST_OP_RV  (_mm_set1_epi32,         __m128i,    3, (-2147483647 - 1))

DEFINE_TEST_OP_RV  (_mm_set1_epi64x,        __m128i,    0, 0LL)
DEFINE_TEST_OP_RV  (_mm_set1_epi64x,        __m128i,    1, 0x7FFFFFFFFFFFFFFFLL)
DEFINE_TEST_OP_RV  (_mm_set1_epi64x,        __m128i,    2, -1LL)
DEFINE_TEST_OP_RV  (_mm_set1_epi64x,        __m128i,    3, -123456789012345LL)

DEFINE_TEST_OP_RV  (_mm_set1_pd,            __m128d,    0, 0.0)
DEFINE_TEST_OP_RV  (_mm_set1_pd,            __m128d,    1, 1.25)
DEFINE_TEST_OP_RV  (_mm_set1_pd,            __m128d,    2, -2.5)
DEFINE_TEST_OP_RV  (_mm_set1_pd,            __m128d,    3, -0.0)

DEFINE_TEST_OP_RV  (_mm_set1_ps,            __m128,     0, 0.0f)
DEFINE_TEST_OP_RV  (_mm_set1_ps,            __m128,     1, 1.25f)
DEFINE_TEST_OP_RV  (_mm_set1_ps,            __m128,     2, -2.5f)
DEFINE_TEST_OP_RV  (_mm_set1_ps,            __m128,     3, -0.0f)

DEFINE_TEST_OP_RT  (_mm_setr_epi8,          __m128i,    0, SET_I8_0)
DEFINE_TEST_OP_RT  (_mm_setr_epi8,          __m128i,    1, SET_I8_1)
DEFINE_TEST_OP_RT  (_mm_setr_epi8,          __m128i,    2, SET_I8_2)
DEFINE_TEST_OP_RT  (_mm_setr_epi8,          __m128i,    3, SET_I8_3)

DEFINE_TEST_OP_RT  (_mm_setr_epi16,         __m128i,    0, SET_I16_0)
DEFINE_TEST_OP_RT  (_mm_setr_epi16,         __m128i,    1, SET_I16_1)
DEFINE_TEST_OP_RT  (_mm_setr_epi16,         __m128i,    2, SET_I16_2)
DEFINE_TEST_OP_RT  (_mm_setr_epi16,         __m128i,    3, SET_I16_3)

DEFINE_TEST_OP_RT  (_mm_setr_epi32,         __m128i,    0, SET_I32_0)
DEFINE_TEST_OP_RT  (_mm_setr_epi32,         __m128i,    1, SET_I32_1)
DEFINE_TEST_OP_RT  (_mm_setr_epi32,         __m128i,    2, SET_I32_2)
DEFINE_TEST_OP_RT  (_mm_setr_epi32,         __m128i,    3, SET_I32_3)

#if defined(_M_IX86) || defined(USE_SOFT_INTRINSICS)
DEFINE_TEST_OP_RT  (_mm_setr_epi64,         __m128i,    0, SET_M64_0)
DEFINE_TEST_OP_RT  (_mm_setr_epi64,         __m128i,    1, SET_M64_1)
DEFINE_TEST_OP_RT  (_mm_setr_epi64,         __m128i,    2, SET_M64_2)
DEFINE_TEST_OP_RT  (_mm_setr_epi64,         __m128i,    3, SET_M64_3)
#endif

DEFINE_TEST_OP_RT  (_mm_setr_epi64x,        __m128i,    0, SET_I64_0)
DEFINE_TEST_OP_RT  (_mm_setr_epi64x,        __m128i,    1, SET_I64_1)
DEFINE_TEST_OP_RT  (_mm_setr_epi64x,        __m128i,    2, SET_I64_2)
DEFINE_TEST_OP_RT  (_mm_setr_epi64x,        __m128i,    3, SET_I64_3)

DEFINE_TEST_OP_RT  (_mm_setr_pd,            __m128d,    0, SET_F64_0)
DEFINE_TEST_OP_RT  (_mm_setr_pd,            __m128d,    1, SET_F64_1)
DEFINE_TEST_OP_RT  (_mm_setr_pd,            __m128d,    2, SET_F64_2)
DEFINE_TEST_OP_RT  (_mm_setr_pd,            __m128d,    3, SET_F64_3)

DEFINE_TEST_OP_RT  (_mm_setr_ps,            __m128,     0, SET_F32_0)
DEFINE_TEST_OP_RT  (_mm_setr_ps,            __m128,     1, SET_F32_1)
DEFINE_TEST_OP_RT  (_mm_setr_ps,            __m128,     2, SET_F32_2)
DEFINE_TEST_OP_RT  (_mm_setr_ps,            __m128,     3, SET_F32_3)

#undef SET_I8_0
#undef SET_I8_1
#undef SET_I8_2
#undef SET_I8_3
#undef SET_I16_0
#undef SET_I16_1
#undef SET_I16_2
#undef SET_I16_3
#undef SET_I32_0
#undef SET_I32_1
#undef SET_I32_2
#undef SET_I32_3
#undef SET_I64_0
#undef SET_I64_1
#undef SET_I64_2
#undef SET_I64_3
#undef SET_M64_0
#undef SET_M64_1
#undef SET_M64_2
#undef SET_M64_3
#undef SET_F32_0
#undef SET_F32_1
#undef SET_F32_2
#undef SET_F32_3
#undef SET_F64_0
#undef SET_F64_1
#undef SET_F64_2
#undef SET_F64_3

DEFINE_TEST_OP_R   (_mm_undefined_pd,       __m128d)
DEFINE_TEST_OP_R   (_mm_undefined_ps,       __m128)
DEFINE_TEST_OP_R   (_mm_undefined_si128,    __m128i)

// Westmere 128-bit AES

DEFINE_TEST_OP_RAB (_mm_aesdec_si128,       __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_aesdeclast_si128,   __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_aesenc_si128,       __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_aesenclast_si128,   __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RA  (_mm_aesimc_si128,       __m128i,    __m128i)
DEFINE_TEST_OP_RAI (_mm_aeskeygenassist_si128, __m128i,    __m128i,    0xFF)

DEFINE_TEST_OP_RABI(_mm_clmulepi64_si128,   __m128i,    __m128i,    __m128i,    0x00)
DEFINE_TEST_OP_RABI(_mm_clmulepi64_si128,   __m128i,    __m128i,    __m128i,    0x11)

#if defined(__AVX2__) || (defined(USE_SOFT_INTRINSICS) && (USE_SOFT_INTRINSICS >= 2))

// Arithmetic AVX/AVX2
// Requires Intel Core i5/i7 4th gen (Haswell) and up, AMD Zen,
// Prism in Windows Insider Canary build 27823 or higher (recommended),
// Rosetta 2 in macOS 15.4 or higher

DEFINE_TEST_OP_RA  (_mm256_cvtsd_f64,       double,     __m256d)
DEFINE_TEST_OP_RA  (_mm256_cvtss_f32,       float,      __m256)
DEFINE_TEST_OP_RA  (_mm256_cvtsi256_si32,   __int32,    __m256i)

DEFINE_TEST_OP_RA  (_mm256_cvtepi32_pd,     __m256d,    __m128i)
DEFINE_TEST_OP_RA  (_mm256_cvtepi32_ps,     __m256,     __m256i)
DEFINE_TEST_OP_RA  (_mm256_cvtpd_epi32,     __m128i,    __m256d)
DEFINE_TEST_OP_RA  (_mm256_cvtps_epi32,     __m256i,    __m256)
DEFINE_TEST_OP_RA  (_mm256_cvtpd_ps,        __m128,     __m256d)
DEFINE_TEST_OP_RA  (_mm256_cvtps_pd,        __m256d,    __m128)
DEFINE_TEST_OP_RA  (_mm256_cvttpd_epi32,    __m128i,    __m256d)
DEFINE_TEST_OP_RA  (_mm256_cvttps_epi32,    __m256i,    __m256)

DEFINE_TEST_OP_RA  (_mm256_abs_epi8,        __m256i,    __m256i)
DEFINE_TEST_OP_RA  (_mm256_abs_epi16,       __m256i,    __m256i)
DEFINE_TEST_OP_RA  (_mm256_abs_epi32,       __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_avg_epu8,        __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_avg_epu16,       __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_add_epi8,        __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_add_epi16,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_add_epi32,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_add_epi64,       __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_adds_epi8,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_adds_epi16,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_adds_epu8,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_adds_epu16,      __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_hadd_epi16,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_hadd_epi32,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_hadds_epi16,     __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_hadd_pd,         __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_hadd_ps,         __m256,     __m256,     __m256)

DEFINE_TEST_OP_RAB (_mm256_madd_epi16,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_maddubs_epi16,   __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_and_si256,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_and_pd,          __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_and_ps,          __m256,     __m256,     __m256)

DEFINE_TEST_OP_RAB (_mm256_andnot_si256,    __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_andnot_pd,       __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_andnot_ps,       __m256,     __m256,     __m256)

DEFINE_TEST_OP_RABI(_mm256_blend_epi16,     __m256i,    __m256i,    __m256i,    0x0C)
DEFINE_TEST_OP_RABI(_mm256_blend_epi16,     __m256i,    __m256i,    __m256i,    0xAA)
DEFINE_TEST_OP_RABI(_mm256_blend_pd,        __m256d,    __m256d,    __m256d,    0)
DEFINE_TEST_OP_RABI(_mm256_blend_ps,        __m256,     __m256,     __m256,     3)

DEFINE_TEST_OP_RABC(_mm256_blendv_epi8,     __m256i,    __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RABC(_mm256_blendv_pd,       __m256d,    __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RABC(_mm256_blendv_ps,       __m256,     __m256,     __m256,     __m256)

DEFINE_TEST_OP_RA  (_mm256_broadcastb_epi8, __m256i,    __m128i)
DEFINE_TEST_OP_RA  (_mm256_broadcastw_epi16,__m256i,    __m128i)
DEFINE_TEST_OP_RA  (_mm256_broadcastd_epi32,__m256i,    __m128i)
DEFINE_TEST_OP_RA  (_mm256_broadcastq_epi64,__m256i,    __m128i)
DEFINE_TEST_OP_RA  (_mm256_broadcastsi128_si256,__m256i,__m128i)
DEFINE_TEST_OP_RA  (_mm256_broadcastsd_pd,  __m256d,    __m128d)
DEFINE_TEST_OP_RA  (_mm256_broadcastss_ps,  __m256,     __m128)

DEFINE_TEST_OP_RAB (_mm256_sad_epu8,        __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_sub_epi8,        __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_sub_epi16,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_sub_epi32,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_sub_epi64,       __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_subs_epi8,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_subs_epi16,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_subs_epu8,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_subs_epu16,      __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_hsub_epi16,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_hsub_epi32,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_hsubs_epi16,     __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_hsub_pd,         __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_hsub_ps,         __m256,     __m256,     __m256)

DEFINE_TEST_OP_RAB (_mm256_addsub_pd,       __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_addsub_ps,       __m256,     __m256,     __m256)
DEFINE_TEST_OP_RAB (_mm256_add_pd,          __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_add_ps,          __m256,     __m256,     __m256)
DEFINE_TEST_OP_RAB (_mm256_sub_pd,          __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_sub_ps,          __m256,     __m256,     __m256)
DEFINE_TEST_OP_RAB (_mm256_mul_pd,          __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_mul_ps,          __m256,     __m256,     __m256)
DEFINE_TEST_OP_RAB (_mm256_div_pd,          __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_div_ps,          __m256,     __m256,     __m256)

DEFINE_TEST_OP_RABI(_mm256_dp_ps,           __m256,     __m256,     __m256,     0x7F)
DEFINE_TEST_OP_RABI(_mm256_dp_ps,           __m256,     __m256,     __m256,     0xFF)

DEFINE_TEST_OP_RAB (_mm256_min_epi8,        __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_min_epi16,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_min_epi32,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_min_epu8,        __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_min_epu16,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_min_epu32,       __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_min_pd,          __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_min_ps,          __m256,     __m256,     __m256)

DEFINE_TEST_OP_RAB (_mm256_max_epi8,        __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_max_epi16,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_max_epi32,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_max_epu8,        __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_max_epu16,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_max_epu32,       __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_max_pd,          __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_max_ps,          __m256,     __m256,     __m256)

DEFINE_TEST_OP_RAB (_mm256_mul_epi32,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_mul_epu32,       __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_mulhi_epi16,     __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_mulhi_epu16,     __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_mulhrs_epi16,    __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_mullo_epi16,     __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_mullo_epi32,     __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_or_si256,        __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_or_pd,           __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_or_ps,           __m256,     __m256,     __m256)

DEFINE_TEST_OP_RAB (_mm256_xor_si256,       __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_xor_pd,          __m256d,    __m256d,    __m256d)
DEFINE_TEST_OP_RAB (_mm256_xor_ps,          __m256,     __m256,     __m256)

DEFINE_TEST_OP_RA  (_mm256_rcp_ps,          __m256,     __m256)

DEFINE_TEST_OP_RA  (_mm256_rsqrt_ps,        __m256,     __m256)

DEFINE_TEST_OP_RA  (_mm256_sqrt_pd,         __m256d,    __m256d)
DEFINE_TEST_OP_RA  (_mm256_sqrt_ps,         __m256,     __m256)

DEFINE_TEST_OP_RAB (_mm256_sll_epi16,       __m256i,    __m256i,    __m128i)
DEFINE_TEST_OP_RAB (_mm256_srl_epi16,       __m256i,    __m256i,    __m128i)
DEFINE_TEST_OP_RAB (_mm256_sra_epi16,       __m256i,    __m256i,    __m128i)

DEFINE_TEST_OP_RAB (_mm256_sll_epi32,       __m256i,    __m256i,    __m128i)
DEFINE_TEST_OP_RAB (_mm256_srl_epi32,       __m256i,    __m256i,    __m128i)
DEFINE_TEST_OP_RAB (_mm256_sra_epi32,       __m256i,    __m256i,    __m128i)

DEFINE_TEST_OP_RAB (_mm256_sll_epi64,       __m256i,    __m256i,    __m128i)
DEFINE_TEST_OP_RAB (_mm256_srl_epi64,       __m256i,    __m256i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_sllv_epi32,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_srlv_epi32,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_srav_epi32,         __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm_sllv_epi64,         __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_srlv_epi64,         __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RAB (_mm256_sllv_epi32,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_srlv_epi32,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_srav_epi32,      __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAB (_mm256_sllv_epi64,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_srlv_epi64,      __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAI (_mm256_slli_epi16,      __m256i,    __m256i,    1)
DEFINE_TEST_OP_RAI (_mm256_slli_epi16,      __m256i,    __m256i,    7)
DEFINE_TEST_OP_RAI (_mm256_slli_epi16,      __m256i,    __m256i,    20)
DEFINE_TEST_OP_RAI (_mm256_srli_epi16,      __m256i,    __m256i,    1)
DEFINE_TEST_OP_RAI (_mm256_srli_epi16,      __m256i,    __m256i,    11)
DEFINE_TEST_OP_RAI (_mm256_srli_epi16,      __m256i,    __m256i,    20)
DEFINE_TEST_OP_RAI (_mm256_srai_epi16,      __m256i,    __m256i,    1)
DEFINE_TEST_OP_RAI (_mm256_srai_epi16,      __m256i,    __m256i,    15)
DEFINE_TEST_OP_RAI (_mm256_srai_epi16,      __m256i,    __m256i,    20)

DEFINE_TEST_OP_RAI (_mm256_slli_epi32,      __m256i,    __m256i,    1)
DEFINE_TEST_OP_RAI (_mm256_slli_epi32,      __m256i,    __m256i,    7)
DEFINE_TEST_OP_RAI (_mm256_slli_epi32,      __m256i,    __m256i,    40)
DEFINE_TEST_OP_RAI (_mm256_srli_epi32,      __m256i,    __m256i,    1)
DEFINE_TEST_OP_RAI (_mm256_srli_epi32,      __m256i,    __m256i,    15)
DEFINE_TEST_OP_RAI (_mm256_srli_epi32,      __m256i,    __m256i,    40)
DEFINE_TEST_OP_RAI (_mm256_srai_epi32,      __m256i,    __m256i,    1)
DEFINE_TEST_OP_RAI (_mm256_srai_epi32,      __m256i,    __m256i,    31)
DEFINE_TEST_OP_RAI (_mm256_srai_epi32,      __m256i,    __m256i,    40)

DEFINE_TEST_OP_RAI (_mm256_slli_epi64,      __m256i,    __m256i,    7)
DEFINE_TEST_OP_RAI (_mm256_slli_epi64,      __m256i,    __m256i,    67)
DEFINE_TEST_OP_RAI (_mm256_srli_epi64,      __m256i,    __m256i,    15)
DEFINE_TEST_OP_RAI (_mm256_srli_epi64,      __m256i,    __m256i,    75)

DEFINE_TEST_OP_RAI (_mm256_slli_si256,      __m256i,    __m256i,    1)
DEFINE_TEST_OP_RAI (_mm256_slli_si256,      __m256i,    __m256i,    31)
DEFINE_TEST_OP_RAI (_mm256_srli_si256,      __m256i,    __m256i,    1)
DEFINE_TEST_OP_RAI (_mm256_srli_si256,      __m256i,    __m256i,    31)

// AVX/AVX2 data movement

DEFINE_TEST_OP_RA  (_mm256_castsi256_si128, __m128i,    __m256i)

DEFINE_TEST_OP_RAI (_mm256_extractf128_pd,  __m128d,    __m256d,    0)
DEFINE_TEST_OP_RAI (_mm256_extractf128_pd,  __m128d,    __m256d,    1)
DEFINE_TEST_OP_RAI (_mm256_extractf128_ps,  __m128,     __m256,     0)
DEFINE_TEST_OP_RAI (_mm256_extractf128_ps,  __m128,     __m256,     1)
DEFINE_TEST_OP_RAI (_mm256_extracti128_si256, __m128i,  __m256i,    0)
DEFINE_TEST_OP_RAI (_mm256_extracti128_si256, __m128i,  __m256i,    1)

DEFINE_TEST_OP_RABI(_mm256_insertf128_pd,   __m256d,    __m256d,    __m128d,     0)
DEFINE_TEST_OP_RABI(_mm256_insertf128_pd,   __m256d,    __m256d,    __m128d,     1)
DEFINE_TEST_OP_RABI(_mm256_insertf128_ps,   __m256,     __m256,     __m128,      0)
DEFINE_TEST_OP_RABI(_mm256_insertf128_ps,   __m256,     __m256,     __m128,      1)
DEFINE_TEST_OP_RABI(_mm256_inserti128_si256, __m256i,   __m256i,    __m128i,     0)
DEFINE_TEST_OP_RABI(_mm256_inserti128_si256, __m256i,   __m256i,    __m128i,     1)

DEFINE_TEST_OP_RABI(_mm256_permute2f128_pd, __m256d,    __m256d,    __m256d,     0)
DEFINE_TEST_OP_RABI(_mm256_permute2f128_pd, __m256d,    __m256d,    __m256d,     1)

DEFINE_TEST_OP_RA  (_mm256_load_pd,         __m256d,    pdouble)
DEFINE_TEST_OP_RA  (_mm256_load_ps,         __m256,     pfloat)
DEFINE_TEST_OP_RA  (_mm256_loadu_pd,        __m256d,    pdouble)
DEFINE_TEST_OP_RA  (_mm256_loadu_ps,        __m256,     pfloat)

DEFINE_TEST_OP_RAB (_mm256_shuffle_epi8,    __m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RAI (_mm256_shuffle_epi32,   __m256i,    __m256i,    0x00)               // 0 0 0 0
DEFINE_TEST_OP_RAI (_mm256_shuffle_epi32,   __m256i,    __m256i,    0x36)               // 0 3 1 2
DEFINE_TEST_OP_RAI (_mm256_shuffle_epi32,   __m256i,    __m256i,    0x5A)               // 1 1 2 2
DEFINE_TEST_OP_RAI (_mm256_shuffle_epi32,   __m256i,    __m256i,    0x63)               // 1 2 0 3
DEFINE_TEST_OP_RAI (_mm256_shuffle_epi32,   __m256i,    __m256i,    0xA5)               // 2 2 1 1
DEFINE_TEST_OP_RAI (_mm256_shuffle_epi32,   __m256i,    __m256i,    0xFF)               // 3 3 3 3

DEFINE_TEST_OP_RABI(_mm256_shuffle_pd,      __m256d,    __m256d,    __m256d,    0)
DEFINE_TEST_OP_RABI(_mm256_shuffle_pd,      __m256d,    __m256d,    __m256d,    1)
DEFINE_TEST_OP_RABI(_mm256_shuffle_pd,      __m256d,    __m256d,    __m256d,    2)
DEFINE_TEST_OP_RABI(_mm256_shuffle_pd,      __m256d,    __m256d,    __m256d,    3)

DEFINE_TEST_OP_RABI(_mm256_shuffle_ps,      __m256,     __m256,     __m256,     0x00)   // 0 0 0 0
DEFINE_TEST_OP_RABI(_mm256_shuffle_ps,      __m256,     __m256,     __m256,     0x69)   // 1 2 2 1
DEFINE_TEST_OP_RABI(_mm256_shuffle_ps,      __m256,     __m256,     __m256,     0x96)   // 2 1 1 2
DEFINE_TEST_OP_RABI(_mm256_shuffle_ps,      __m256,     __m256,     __m256,     0xFF)   // 3 3 3 3

DEFINE_TEST_OP_R   (_mm256_setzero_pd,      __m256d)
DEFINE_TEST_OP_R   (_mm256_setzero_ps,      __m256)
DEFINE_TEST_OP_R   (_mm256_setzero_si256,   __m256i)

#define SET256_I8_0   0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9, 10, -10, 11, -11, 12, -12, 13, -13, 14, -14, 15, -15, 16
#define SET256_I8_1   127, -128, 0, 64, -64, 32, -32, 16, -16, 8, -8, 4, -4, 2, -2, 1, -1, 126, -127, 63, -63, 31, -31, 15, -15, 7, -7, 3, -3, 1, -1, 0
#define SET256_I8_2   -11, 22, 0, -33, 44, -55, 66, -77, 88, -99, 110, -121, 12, -23, 34, -45, 56, -67, 78, -89, 90, -101, 112, -123, 21, -32, 43, -54, 65, -76, 87, 0
#define SET256_I8_3   0, -127, 126, -125, 124, -123, 122, -121, 120, -119, 118, -117, 116, -115, 114, -113, 112, -111, 110, -109, 108, -107, 106, -105, 104, -103, 102, -101, 100, -99, 98, -97

#define SET256_I16_0  0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8
#define SET256_I16_1  32767, -32768, 0, 16384, -16384, 8192, -8192, 4096, -4096, 2048, -2048, 1024, -1024, 512, -512, 1
#define SET256_I16_2  -1234, 2345, 0, -3456, 4567, -5678, 6789, -7890, 8901, -9012, 10123, -11234, 12345, -13456, 14567, 0
#define SET256_I16_3  0, -30000, 29000, -28000, 27000, -26000, 25000, -24000, 23000, -22000, 21000, -20000, 19000, -18000, 17000, -16000

#define SET256_I32_0  0, 1, -1, 2, -2, 3, -3, 4
#define SET256_I32_1  2147483647, (-2147483647 - 1), 0, 1073741824, -1073741824, 536870912, -536870912, 1
#define SET256_I32_2  -123456789, 234567890, 0, -345678901, 456789012, -567890123, 678901234, -789012345
#define SET256_I32_3  0, -2000000000, 1900000000, -1800000000, 1700000000, -1600000000, 1500000000, -1400000000

#define SET256_I64_0  0LL, 1LL, -1LL, 2LL
#define SET256_I64_1  0x7FFFFFFFFFFFFFFFLL, -1LL, 0LL, 0x4000000000000000LL
#define SET256_I64_2  -123456789012345LL, 234567890123456LL, 0LL, -345678901234567LL
#define SET256_I64_3  0LL, -4000000000000000000LL, 3000000000000000000LL, -2000000000000000000LL

#define SET256_F32_0  0.0f, 1.0f, -1.0f, 2.5f, -2.5f, 3.25f, -3.25f, 4.5f
#define SET256_F32_1  -0.0f, -2.5f, 0.0f, 3.25f, -4.5f, 5.75f, -6.0f, 7.125f
#define SET256_F32_2  65536.0f, -65536.0f, 0.0f, 0.5f, -0.5f, 1024.25f, -2048.5f, 4096.75f
#define SET256_F32_3  -123.75f, 0.0f, 456.5f, -0.25f, 789.125f, -1011.5f, 1213.75f, -1415.0f

#define SET256_F64_0  0.0, 1.0, -1.0, 2.5
#define SET256_F64_1  -0.0, -2.5, 0.0, 3.25
#define SET256_F64_2  65536.5, -65536.25, 0.0, 0.5
#define SET256_F64_3  -123456.75, 0.5, 234567.25, -345678.125

DEFINE_TEST_OP_RT  (_mm256_set_epi8,        __m256i,    0, SET256_I8_0)
DEFINE_TEST_OP_RT  (_mm256_set_epi8,        __m256i,    1, SET256_I8_1)
DEFINE_TEST_OP_RT  (_mm256_set_epi8,        __m256i,    2, SET256_I8_2)
DEFINE_TEST_OP_RT  (_mm256_set_epi8,        __m256i,    3, SET256_I8_3)

DEFINE_TEST_OP_RT  (_mm256_set_epi16,       __m256i,    0, SET256_I16_0)
DEFINE_TEST_OP_RT  (_mm256_set_epi16,       __m256i,    1, SET256_I16_1)
DEFINE_TEST_OP_RT  (_mm256_set_epi16,       __m256i,    2, SET256_I16_2)
DEFINE_TEST_OP_RT  (_mm256_set_epi16,       __m256i,    3, SET256_I16_3)

DEFINE_TEST_OP_RT  (_mm256_set_epi32,       __m256i,    0, SET256_I32_0)
DEFINE_TEST_OP_RT  (_mm256_set_epi32,       __m256i,    1, SET256_I32_1)
DEFINE_TEST_OP_RT  (_mm256_set_epi32,       __m256i,    2, SET256_I32_2)
DEFINE_TEST_OP_RT  (_mm256_set_epi32,       __m256i,    3, SET256_I32_3)

DEFINE_TEST_OP_RT  (_mm256_set_epi64x,      __m256i,    0, SET256_I64_0)
DEFINE_TEST_OP_RT  (_mm256_set_epi64x,      __m256i,    1, SET256_I64_1)
DEFINE_TEST_OP_RT  (_mm256_set_epi64x,      __m256i,    2, SET256_I64_2)
DEFINE_TEST_OP_RT  (_mm256_set_epi64x,      __m256i,    3, SET256_I64_3)

DEFINE_TEST_OP_RT  (_mm256_set_pd,          __m256d,    0, SET256_F64_0)
DEFINE_TEST_OP_RT  (_mm256_set_pd,          __m256d,    1, SET256_F64_1)
DEFINE_TEST_OP_RT  (_mm256_set_pd,          __m256d,    2, SET256_F64_2)
DEFINE_TEST_OP_RT  (_mm256_set_pd,          __m256d,    3, SET256_F64_3)

DEFINE_TEST_OP_RT  (_mm256_set_ps,          __m256,     0, SET256_F32_0)
DEFINE_TEST_OP_RT  (_mm256_set_ps,          __m256,     1, SET256_F32_1)
DEFINE_TEST_OP_RT  (_mm256_set_ps,          __m256,     2, SET256_F32_2)
DEFINE_TEST_OP_RT  (_mm256_set_ps,          __m256,     3, SET256_F32_3)

DEFINE_TEST_OP_RV  (_mm256_set1_epi8,       __m256i,    0, 0)
DEFINE_TEST_OP_RV  (_mm256_set1_epi8,       __m256i,    1, 127)
DEFINE_TEST_OP_RV  (_mm256_set1_epi8,       __m256i,    2, -1)
DEFINE_TEST_OP_RV  (_mm256_set1_epi8,       __m256i,    3, -128)

DEFINE_TEST_OP_RV  (_mm256_set1_epi16,      __m256i,    0, 0)
DEFINE_TEST_OP_RV  (_mm256_set1_epi16,      __m256i,    1, 32767)
DEFINE_TEST_OP_RV  (_mm256_set1_epi16,      __m256i,    2, -1)
DEFINE_TEST_OP_RV  (_mm256_set1_epi16,      __m256i,    3, -32768)

DEFINE_TEST_OP_RV  (_mm256_set1_epi32,      __m256i,    0, 0)
DEFINE_TEST_OP_RV  (_mm256_set1_epi32,      __m256i,    1, 2147483647)
DEFINE_TEST_OP_RV  (_mm256_set1_epi32,      __m256i,    2, -1)
DEFINE_TEST_OP_RV  (_mm256_set1_epi32,      __m256i,    3, (-2147483647 - 1))

DEFINE_TEST_OP_RV  (_mm256_set1_epi64x,     __m256i,    0, 0LL)
DEFINE_TEST_OP_RV  (_mm256_set1_epi64x,     __m256i,    1, 0x7FFFFFFFFFFFFFFFLL)
DEFINE_TEST_OP_RV  (_mm256_set1_epi64x,     __m256i,    2, -1LL)
DEFINE_TEST_OP_RV  (_mm256_set1_epi64x,     __m256i,    3, -123456789012345LL)

DEFINE_TEST_OP_RV  (_mm256_set1_pd,         __m256d,    0, 0.0)
DEFINE_TEST_OP_RV  (_mm256_set1_pd,         __m256d,    1, 1.25)
DEFINE_TEST_OP_RV  (_mm256_set1_pd,         __m256d,    2, -2.5)
DEFINE_TEST_OP_RV  (_mm256_set1_pd,         __m256d,    3, -0.0)

DEFINE_TEST_OP_RV  (_mm256_set1_ps,         __m256,     0, 0.0f)
DEFINE_TEST_OP_RV  (_mm256_set1_ps,         __m256,     1, 1.25f)
DEFINE_TEST_OP_RV  (_mm256_set1_ps,         __m256,     2, -2.5f)
DEFINE_TEST_OP_RV  (_mm256_set1_ps,         __m256,     3, -0.0f)

DEFINE_TEST_OP_RT  (_mm256_setr_epi8,       __m256i,    0, SET256_I8_0)
DEFINE_TEST_OP_RT  (_mm256_setr_epi8,       __m256i,    1, SET256_I8_1)
DEFINE_TEST_OP_RT  (_mm256_setr_epi8,       __m256i,    2, SET256_I8_2)
DEFINE_TEST_OP_RT  (_mm256_setr_epi8,       __m256i,    3, SET256_I8_3)

DEFINE_TEST_OP_RT  (_mm256_setr_epi16,      __m256i,    0, SET256_I16_0)
DEFINE_TEST_OP_RT  (_mm256_setr_epi16,      __m256i,    1, SET256_I16_1)
DEFINE_TEST_OP_RT  (_mm256_setr_epi16,      __m256i,    2, SET256_I16_2)
DEFINE_TEST_OP_RT  (_mm256_setr_epi16,      __m256i,    3, SET256_I16_3)

DEFINE_TEST_OP_RT  (_mm256_setr_epi32,      __m256i,    0, SET256_I32_0)
DEFINE_TEST_OP_RT  (_mm256_setr_epi32,      __m256i,    1, SET256_I32_1)
DEFINE_TEST_OP_RT  (_mm256_setr_epi32,      __m256i,    2, SET256_I32_2)
DEFINE_TEST_OP_RT  (_mm256_setr_epi32,      __m256i,    3, SET256_I32_3)

DEFINE_TEST_OP_RT  (_mm256_setr_epi64x,     __m256i,    0, SET256_I64_0)
DEFINE_TEST_OP_RT  (_mm256_setr_epi64x,     __m256i,    1, SET256_I64_1)
DEFINE_TEST_OP_RT  (_mm256_setr_epi64x,     __m256i,    2, SET256_I64_2)
DEFINE_TEST_OP_RT  (_mm256_setr_epi64x,     __m256i,    3, SET256_I64_3)

DEFINE_TEST_OP_RT  (_mm256_setr_pd,         __m256d,    0, SET256_F64_0)
DEFINE_TEST_OP_RT  (_mm256_setr_pd,         __m256d,    1, SET256_F64_1)
DEFINE_TEST_OP_RT  (_mm256_setr_pd,         __m256d,    2, SET256_F64_2)
DEFINE_TEST_OP_RT  (_mm256_setr_pd,         __m256d,    3, SET256_F64_3)

DEFINE_TEST_OP_RT  (_mm256_setr_ps,         __m256,     0, SET256_F32_0)
DEFINE_TEST_OP_RT  (_mm256_setr_ps,         __m256,     1, SET256_F32_1)
DEFINE_TEST_OP_RT  (_mm256_setr_ps,         __m256,     2, SET256_F32_2)
DEFINE_TEST_OP_RT  (_mm256_setr_ps,         __m256,     3, SET256_F32_3)

#undef SET256_I8_0
#undef SET256_I8_1
#undef SET256_I8_2
#undef SET256_I8_3
#undef SET256_I16_0
#undef SET256_I16_1
#undef SET256_I16_2
#undef SET256_I16_3
#undef SET256_I32_0
#undef SET256_I32_1
#undef SET256_I32_2
#undef SET256_I32_3
#undef SET256_I64_0
#undef SET256_I64_1
#undef SET256_I64_2
#undef SET256_I64_3
#undef SET256_F32_0
#undef SET256_F32_1
#undef SET256_F32_2
#undef SET256_F32_3
#undef SET256_F64_0
#undef SET256_F64_1
#undef SET256_F64_2
#undef SET256_F64_3

DEFINE_TEST_OP_VAB (_mm256_store_pd,                    pdouble,    __m256d)
DEFINE_TEST_OP_VAB (_mm256_store_ps,                    pfloat,     __m256)
DEFINE_TEST_OP_VAB (_mm256_storeu_pd,                   pdouble,    __m256d)
DEFINE_TEST_OP_VAB (_mm256_storeu_ps,                   pfloat,     __m256)

#endif // AVX2 tests

//
// Post-AVX2 extensions to SSE and AVX since Haswell
//

#if (defined(__AVX2__) && defined(__VAES__)) || (defined(USE_SOFT_INTRINSICS) && (USE_SOFT_INTRINSICS >= 2))

// 256-bit AES (introduced in Zen2, Ice Lake?)

DEFINE_TEST_OP_RAB (_mm256_aesdec_epi128,    __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_aesdeclast_epi128,__m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_aesenc_epi128,    __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_aesenclast_epi128,__m256i,    __m256i,    __m256i)

DEFINE_TEST_OP_RABI(_mm256_clmulepi64_epi128,__m256i,    __m256i,    __m256i,   0x00)
DEFINE_TEST_OP_RABI(_mm256_clmulepi64_epi128,__m256i,    __m256i,    __m256i,   0x11)

#endif // AVX2 VAES tests

#if (defined(__AVX2__) && defined(__SHANI__)) || (defined(USE_SOFT_INTRINSICS) && (USE_SOFT_INTRINSICS >= 2))

// 128-bit SHA (introduced in Zen2, Pentium Silver)

DEFINE_TEST_OP_RAB (_mm_sha1msg1_epu32,     __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_sha1msg2_epu32,     __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_sha1nexte_epu32,    __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RABI(_mm_sha1rnds4_epu32,    __m128i,    __m128i,    __m128i,    0)
DEFINE_TEST_OP_RABI(_mm_sha1rnds4_epu32,    __m128i,    __m128i,    __m128i,    1)
DEFINE_TEST_OP_RABI(_mm_sha1rnds4_epu32,    __m128i,    __m128i,    __m128i,    2)
DEFINE_TEST_OP_RABI(_mm_sha1rnds4_epu32,    __m128i,    __m128i,    __m128i,    3)
DEFINE_TEST_OP_RAB (_mm_sha256msg1_epu32,   __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RAB (_mm_sha256msg2_epu32,   __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RABC(_mm_sha256rnds2_epu32,  __m128i,    __m128i,    __m128i,    __m128i)

#endif // SHANI tests

#if (defined(__AVX2__) && defined(__AVX_VNNI__)) || (defined(USE_SOFT_INTRINSICS) && (USE_SOFT_INTRINSICS >= 2))

// Alder Lake AVX-VNNI

DEFINE_TEST_OP_RABC(_mm_dpbusd_avx_epi32,   __m128i,    __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RABC(_mm_dpbusds_avx_epi32,  __m128i,    __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RABC(_mm_dpwssd_avx_epi32,   __m128i,    __m128i,    __m128i,    __m128i)
DEFINE_TEST_OP_RABC(_mm_dpwssds_avx_epi32,  __m128i,    __m128i,    __m128i,    __m128i)

DEFINE_TEST_OP_RABC(_mm256_dpbusd_avx_epi32, __m256i,   __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RABC(_mm256_dpbusds_avx_epi32,__m256i,   __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RABC(_mm256_dpwssd_avx_epi32, __m256i,   __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RABC(_mm256_dpwssds_avx_epi32,__m256i,   __m256i,    __m256i,    __m256i)

#endif

#if defined(__AVX512F__) || (defined(USE_SOFT_INTRINSICS) && (USE_SOFT_INTRINSICS >= 3))

// AVX-512 packed integer extensions which complete the original SSE2 and AVX2 opcodes

DEFINE_TEST_OP_RA  (_mm_abs_epi64,          __m128i,    __m128i)

DEFINE_TEST_OP_RAI (_mm_srai_epi64,         __m128i,    __m128i,    63)

DEFINE_TEST_OP_RAB (_mm256_sllv_epi16,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_srlv_epi16,      __m256i,    __m256i,    __m256i)
DEFINE_TEST_OP_RAB (_mm256_srav_epi16,      __m256i,    __m256i,    __m256i)

#endif // AVX-512 tests

