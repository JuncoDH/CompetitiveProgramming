// Usually you are given a and b, then have to find a' and b',
// So that b' = z(a'), and usually b' size is 2^n.
// v[mask] = sum(v[submask]). O(n log n).
void zeta_transform(vll &v) {
    int i, n = v.size(), mask;
    for(i = 0; (1<<i) < n; i++)
        for(mask = 0; mask < n; mask++)
            if(is_set(mask, i))
                v[mask] ^= v[mask^(1<<i)]; // +=, ^=, gcd.
}
// v[mask] = sum(v[supermask]). O(n log n).
void zeta_transform_superset(vll &v) {
    int i, n = v.size(), mask;
    for(i = 0; (1<<i) < n; i++)
        for(mask = 0; mask < n; mask++)
            if(!is_set(mask, i) && (mask^(1<<i)) < n)
                v[mask] ^= v[mask^(1<<i)]; // +=, ^=, gcd.
}
// v[mask] = (-1)^(|mask|)*v[mask]. O(n).
void odd_negation(vll &v) {
    for(int i = 0; i < (int)v.size(); i++)
        if(__builtin_popcount(i)%2) v[i] = -v[i];
}
// v[mask] = sum((-1)^(|mask\submask|)*v[submask]), O(n log n).
// mobius and zeta are inverses of each other.
// With xor, mobius == zeta.
void mobius_transform(vll &v) {
    odd_negation(v);
    zeta_transform(v);
    odd_negation(v);
}

