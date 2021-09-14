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

// Return the smallest x such as a^x == b % mod, or -1 if no answer exists.
// x = sqrt(mod)*p - q. Baby step - Giant step algorithm.
// Complexity O(sqrt(mod)).
ll discrete_logarithm(ll a, ll b, ll mod) {
    a = (a%mod + mod)%mod; b = (b%mod + mod)%mod;
    if(a == 0 && b == 0) return 1;
    if(a == 0) return -1; // 0^0 sometimes is 1.
    if(b == 1) return 0;
    ll k = 1, sq = sqrt(mod) + 1, q, p, g, asq = 1, aq = 1, ap = 1, add = 0;
    unordered_map<ll, ll> value;
    // if a is not coprime con mod then transform it to k*a^x == b%mod.
    while((g = __gcd(a, mod)) != 1) {
        if(b == k) return add; // Stop decreasing x.
        if(b%g) return -1;
        b /= g;
        mod /= g;
        add++;
        k = (k * (a / g))%mod;
    }
    // Meet in the middle, smallest x is high q and low p.
    for(q = 0; q <= sq; q++) {
        value[(b*aq)%mod] = q;
        aq = (aq*a)%mod;
    }
    for(p = 1; p <= sq; p++) asq = (asq*a)%mod;
    for(p = 1; p <= sq; p++) {
        ap = (ap*asq)%mod;
        if(value.count((k*ap)%mod))
            return sq*p - value[(k*ap)%mod] + add;
    }
    return -1;
}

ll p_root = -1;
// Get x such that x^k == b % mod.
ll discrete_root(ll k, ll b, ll mod) {
    // If you change the mod then calculate again the primitive root.
    if(p_root == -1) p_root = primitive_root(mod);
    if(p_root == -1) return -1;
    ll num = elevate(p_root, k, mod);
    ll y = discrete_logarithm(num, b, mod);
    return elevate(p_root, y, mod);
}
