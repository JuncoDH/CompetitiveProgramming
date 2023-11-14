// (m n) = prod_{i = 0, i <= k} (mi ni) % mod; m = sum_{i = 0, i <= k} mi * p^i.
ll lucas_theorem(ll m, ll n) {
    if(n > m) return 0;
    ll ans = 1;
    while(m || n) {
        ans *= comb(m % mod, n % mod);
        ans %= mod;
        m /= mod;
        n /= mod;
    }
    return ans;
}

