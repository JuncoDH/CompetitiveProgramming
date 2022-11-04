// Thue-Morse Sequence, Hash(S[0..2^k-1]) == Hash(S[2^k..2^(k-1)-1]), k >= 12,
// it does not depend on the base of the hash. It will give many, many collisions.
string generate(int n) {
    string s(n, '0');
    for(int i = 0; i < n; i++) 
        if(__builtin_popcount(i)%2) s[i] = '1';
    return s;
}
