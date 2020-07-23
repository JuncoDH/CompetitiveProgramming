// Optimize float values, don't use.
// #pragma GCC optimization ("Ofast")

// Hide warning m = s.length(), signed vs unsigned integer, don't use.
// #pragma GCC diagnostic ignored "-Wsign-compare"

// Works for naive short sols of n^2 and n up to 2*1e5.
// Use only when there is no more choice...
#pragma GCC optimization ("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
