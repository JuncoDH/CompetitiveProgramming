class ChineseRemainder {
    ll mod(ll const x) const {
        return ((x % modulo) + modulo) % modulo;
    }
    ll n = 0;
    vll c, m; // x == c[i] mod m[i], m[i] not need to be coprime.
    void solve_one() { // m[i] <= 1e9
        ll x, y;
        modulo = m[n - 2] * (m[n - 1] / __gcd(m[n - 2], m[n - 1]));
        ll g = gcdEx(m[n - 1], m[n - 2], &x, &y);
        if((c[n - 1] - c[n - 2]) % g != 0) { n = -1; return; }
        x = c[n - 1] + mul(m[n - 1], mul(-x, (c[n - 1] - c[n - 2]) / g));
        c.pop_back(); m.pop_back(); --n;
        c[n - 1] = mod(x); m[n - 1] = modulo;
    }
public:
    ll modulo;
    void insert(ll const _c, ll const _m) { // _m > 0.
        ++n;
        modulo = _m;
        m.pb(_m);
        c.pb(mod(_c));
    }
    ll solve() {
        while(n > 1) solve_one();
        return n <= 0? -1 : c[0];
    }
};

