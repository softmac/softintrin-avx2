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

