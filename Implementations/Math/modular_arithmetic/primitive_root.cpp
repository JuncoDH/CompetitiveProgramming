ll elevate(ll a, ll b, ll mod) { // b >= 0.
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

// phi of Euler. O(sqrt(n)).
ll get_phi(ll n) {
    ll ans = n, i;
    for(i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            while(n%i == 0) n /= i;
            ans -= ans/i;
        }
    }
    if(n > 1) ans -= ans/n;
    return ans;
}

// Return g such that for all x coprime with mod exists k : (g^k == x)% mod.
// g^k generate all the elements.
// If g is the primitive root of mod, you can take log_g{} in both sides.
// Exists iff mod is 1, 2, 4, (odd p)^k, 2*(odd p)^k.
// Complexity O(mod log(mod)).
ll primitive_root(ll mod) {
    ll phi = get_phi(mod);
    vll factors; // Factorize phi.
    ll i, num = phi;
    bool ok;
    if(mod == 1) return 0;
    if(mod == 2) return 1;
    for(i = 2; i*i <= num; i++) {
        if(num%i == 0) {
            factors.pb(i);
            while(num%i == 0) num /= i;
        }
    }
    if(num > 1) factors.pb(num);
    // Try every coprime number.
    for(i = 2; i < mod; i++) {
        if(__gcd(i, mod) != 1) continue;
        ok = true;
        for(auto p : factors) {
            if(elevate(i, phi/p, mod) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return i;
    }
    return -1;
}

