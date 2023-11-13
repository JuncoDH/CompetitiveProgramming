ll p_root = -1;
// Get x such that x^k == b % mod.
ll discrete_root(ll const k, ll const b, ll const mod) {
    // If you change the mod then calculate again the primitive root.
    if(p_root == -1) p_root = primitive_root(mod);
    if(p_root == -1) return -1;
    ll num = elevate(p_root, k, mod);
    ll y = discrete_logarithm(num, b, mod);
    return elevate(p_root, y, mod);
}

