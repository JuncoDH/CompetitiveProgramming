// Num of numbers <= x with k bits set on.
map<pll, ll> m;
ll k_bits_on(ll x, ll k) {
    if(k == 0) return 1;
    if(x == 0) return 0;
    if(m.count({x, k})) return m[{x, k}];
    for(int i = 61; i >= 0; i--) {
        if(is_set(x, i)) {
            return m[{x, k}] = f(x - (1ll<<i), k - 1) + f((1ll<<i) - 1, k);
        }
    }
    return 0;
}

