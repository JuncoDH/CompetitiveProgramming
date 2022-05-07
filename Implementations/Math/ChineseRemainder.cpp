class ChineseRemainder{
    ll mul(ll a, ll b) {
        ll ans = 0, neg = (a < 0) ^ (b < 0);
        a = abs(a); b = abs(b);
        while(b) {
            if(b & 1) ans = (ans + a)%modulo;
            b >>= 1;
            a = (a + a)%modulo;
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
    ll mod(ll x) {
        return ((x%modulo) + modulo)%modulo;
    }
    ll n = 0;
    vll c, m; // x == c[i] mod m[i], m[i] not need to be coprime.
    void solve_one() { // m[i] <= 1e9
        ll x, y, g;
        modulo = m[n-2]*(m[n-1]/__gcd(m[n-2], m[n-1]));
        g = gcdEx(m[n-1], m[n-2], &x, &y);
        if((c[n-1]-c[n-2])%g != 0) {n = -1; return;}
        x = c[n-1] + mul(m[n-1], mul(-x, (c[n-1]-c[n-2])/g));
        c.pop_back(); m.pop_back(); n--;
        c[n-1] = mod(x); m[n-1] = modulo;
    }
    public:
    ll modulo;
    void insert(ll _c, ll _m) { // _m > 0.
        n++;
        modulo = _m;
        m.pb(_m);
        c.pb(mod(_c));
    }
    ll solve() {
        while(n > 1) solve_one();
        return n <= 0? -1 : c[0];
    }
};
