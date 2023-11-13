// Return g such that for all x coprime with mod exists k : (g^k == x)% mod.
// g^k generate all the elements.
// If g is the primitive root of mod, you can take log_g{} in both sides.
// Exists iff mod is 1, 2, 4, (odd p)^k, 2*(odd p)^k.
// Complexity O(mod log(mod)).
ll primitive_root(ll const mod) {
    ll phi = get_phi(mod);
    vll factors; // Factorize phi.
    ll i, num = phi;
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
        bool ok = true;
        for(auto const& p : factors) {
            if(elevate(i, phi/p, mod) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return i;
    }
    return -1;
}

