ll domod(ll a) {
    return ((a % mod) + mod) % mod;
}
ll add(ll a, ll b) {
    a = domod(a);
    b = domod(b);
    return domod(a + b);
}
ll mul(ll a, ll b) {
    ll ans = 0;
    a = domod(a);
    b = domod(b);
    while(b) {
        if(b & 1) ans = (ans + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return domod(ans);
}
ll elevate(ll a, ll b) { // b >= 0.
    a = domod(a);
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return domod(ans);
}
// ONLY USE WHEN MOD IS PRIME, ELSE USE GCD.
// a^(mod - 1) = 1, Euler.
ll inv(ll a) {
    return elevate(a, mod - 2);
}

