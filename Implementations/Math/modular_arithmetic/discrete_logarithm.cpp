// Return the smallest x such as a^x == b % mod, or -1 if no answer exists.
// x = sqrt(mod) * p - q. Baby step - Giant step algorithm.
// Complexity O(sqrt(mod)).
ll discrete_logarithm(ll a, ll b, ll mod) {
    a = (a % mod + mod) % mod; b = (b % mod + mod) % mod;
    if(a == 0 && b == 0) return 1;
    if(a == 0) return -1; // 0^0 sometimes is 1.
    if(b == 1) return 0;
    ll k = 1, sq = sqrt(mod) + 1, q, p, g, asq = 1, aq = 1, ap = 1, add = 0;
    unordered_map<ll, ll> value;
    // If a is not coprime con mod then transform it to k * a^x == b % mod.
    while((g = __gcd(a, mod)) != 1) {
        if(b == k) return add; // Stop decreasing x.
        if(b % g) return -1;
        b /= g;
        mod /= g;
        add++;
        k = (k * (a / g)) % mod;
    }
    // Meet in the middle, smallest x is high q and low p.
    for(q = 0; q <= sq; q++) {
        value[(b * aq) % mod] = q;
        aq = (aq * a) % mod;
    }
    for(p = 1; p <= sq; p++) asq = (asq * a) % mod;
    for(p = 1; p <= sq; p++) {
        ap = (ap * asq) % mod;
        if(value.count((k * ap) % mod))
            return sq*p - value[(k * ap) % mod] + add;
    }
    return -1;
}

