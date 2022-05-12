ll elevate(ll a, ll b) { // b >= 0.
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
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

