ll mod = 1e9 + 7;
// Debug function, get the fraction p/q given x % mod.
void get_fraction(ll x) {
    x = (x%mod + mod) % mod;
    ll p, q;
    for(p = 0; p < 100; p++) {
        for(q = 1; q < 100; q++) {
            if(p == (x*q)%mod) {
                cout << x << " = " << p << "/" << q << endl;
                return;
            }
        }
    }
    cout << "ERROR " << x << " not found" << endl;
}

