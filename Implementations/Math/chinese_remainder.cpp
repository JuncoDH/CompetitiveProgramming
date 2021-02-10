ll mod;

ll mul(ll a, ll b) {
    ll ans = 0, neg = (a < 0) ^ (b < 0);
    a = abs(a); b = abs(b);
    while(b) {
        if(b & 1) ans = (ans + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    if(neg) return -ans;
    return ans;
}

ll gcdEx(ll a, ll b, ll *x1, ll *y1) {
    if(a == 0) {
        *x1 = 0;
        *y1 = 1;
        return b;
    }
    ll x0, y0, g;
    g = gcdEx(b%a, a, &x0, &y0);
    
    *x1 = y0 - (b/a)*x0;
    *y1 = x0;
    
    return g;
}

const ll MAX = 10;
ll a[MAX], p[MAX], n;
// Given n x == a[i] mod p[i], find x, or -1 if it doesn't exist.
// Let q[i] = (\prod_{i=0}^{n-1} p[j])/p[i].
// x will be = \sum_{i=0}^{n-1} a[i]*q[i]*inv(q[i], mod p[i])
ll chinese_remainder() {
    ll i, j, g, ans = 0, inv1, inv2;
    mod = 1;
    for(i = 0; i < n; i++) { // If the p[i] are not coprimes, do them coprimes.
        a[i] %= p[i]; a[i] += p[i]; a[i] %= p[i];
        for(j = 0; j < i; j++) {
            g = __gcd(p[i], p[j]);
            if((a[i]%g + g)%g != (a[j]%g + g)%g) return -1;
            // Delete the repeated factor at the correct side.
            if (__gcd(p[i]/g, p[j]) == 1) {p[i] /= g; a[i] %= p[i];}
            else {p[j] /= g; a[j] %= p[j];}
        }
    }
    // If you have a supermod, take P = min(P, supermod);
    for(i = 0; i < n; i++) {
        mod *= p[i];
    }
    for(i = 0; i < n; i++) {
        gcdEx(mod/p[i], p[i], &inv1, &inv2);
        ans += mul(a[i], mul(mod/p[i], inv1));
        ans %= mod;
    }
    return (ans%mod + mod) % mod;
}
