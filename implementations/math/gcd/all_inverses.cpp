constexpr ll mod = 31;
ll inverse[mod];
// Calculates inverse for all i < mod.
void init() {
    inverse[1] = 1;
    for(ll i = 2; i < mod; ++i) {
        inverse[i] = -(mod / i) * inverse[mod % i];
        inverse[i] = (inverse[i] % mod + mod) % mod;
    }
}

