// Works for some naive short sols of n^2 and n up to 2 * 1e5.
// Use only when there is no more choice...
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimization ("O3")

// Vectors and floating point operations.
#pragma GCC target("avx,avx2,fma")

// Optimize float values, do not use, loses too much precision.
// #pragma GCC optimization ("Ofast")

