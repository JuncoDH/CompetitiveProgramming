constexpr ll mod = (ll)1e9 + 7;
constexpr int MAX = 1e5 + 10;
ll fact[MAX], inv_fact[MAX]; // inv_fact is fact^-1.
void init() {
    int i = 0;
    fact[0] = 1;
    inv_fact[0] = 1;
    for(i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        inv_fact[i] = inv(fact[i]);
    }
}
ll comb(ll const a, ll const b) { // O(1). // aCb = a! / (b! * (a - b)!.
    if(b > a) return 0;
    return ((fact[a] * inv_fact[b]) % mod) * inv_fact[a - b] % mod;
}

