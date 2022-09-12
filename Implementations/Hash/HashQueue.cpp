// https://www.browserling.com/tools/prime-numbers.
// s = a[i], hash = a[0] + b*a[1] + b^2*a[2] + b^n*a[n].
class HashString {
    char initial = '0'; // change initial for range. 'a', 'A', '0'.
    public:
    string s;
    int n, n_p;
    vector<vll> v; // contain the hash for [0..i].
    vll p = {16532849, 91638611, 83157709}; // prime numbers. // 15635513  77781229
    vll base = {37, 47, 53}; // base numbers: primes that > alphabet size. // 49 83
    vector<vll> b; // b[i][j] = (b_i^j) % p_i.
    vector<vll> b_inv; // b_inv[i][j] = (b_i^j)^-1 % p_i. 
    ll elevate(ll a, ll _b, ll mod){
        ll ans = 1;
        while(_b){
            if(_b & 1) ans = ans*a % mod;
            _b >>= 1;
            a = a*a % mod;
        }
        return ans;
    }
    // a^(mod - 1) = 1, Euler.
    ll inv(int i, int j){
        if(b_inv[i][j] != -1) return b_inv[i][j];
        return b_inv[i][j] = elevate(b[i][j], p[i] - 2, p[i]);
    }
    HashString() = default;
    HashString(string &_s) { // Not empty strings.
        s = _s;
        n = _s.length();
        n_p = (int)p.size();
        v.assign(n_p, vll(n, 0));
        b.assign(n_p, vll(n, 0));
        b_inv.assign(n_p, vll(n, -1));
        int i, j;
        for(i = 0; i < n_p; i++) {
            b[i][0] = 1;
            for(j = 1; j < n; j++) {
                b[i][j] = (b[i][j-1]*base[i]) % p[i];
            }
            v[i][0] = s[0]-initial+1;
            for(j = 1; j < n; j++) {
                v[i][j] = (b[i][j]*(s[j]-initial+1) + v[i][j-1]) % p[i];
            }
        }
    }
    void add(char c) { // Need something previously added.
        int i;
        s += c;
        n++;
        for(i = 0; i < n_p; i++) {
            b[i].pb((b[i][n-2]*base[i]) % p[i]);
            b_inv[i].pb(-1);
            v[i].pb((b[i][n-1]*(c-initial+1) + v[i][n-2]) % p[i]);
        }
    }
    void add(string &_s) {
        for(auto c : _s) add(c);
    }
    vll getHash(int l, int r) {
        ll i, ans;
        vll vans;
        for(i = 0; i < n_p; i++) {
            ans = v[i][r];
            if(l > 0) ans -= v[i][l-1];
            ans *= inv(i, l);
            ans = ((ans%p[i])+p[i])%p[i];
            vans.pb(ans);
        }
        return vans;
    }
    // O(1).
    bool operator == (HashString other) {
        if(n != other.n) return false;
        return getHash(0, n-1) == other.getHash(0, n-1);
    }
    // return the index of the Longest Comon Prefix, -1 if no Common Prefix.
    // O(log n).
    int LCP(HashString other) {
        int l = 0, r = min(n, other.n), mid;
        if(s[0] != other.s[0]) return -1;
        if(*this == other) return n-1;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            if(getHash(0, mid) == other.getHash(0, mid)) l = mid;
            else r = mid;
        }
        return l;
    }
    bool operator < (HashString other) {
        int id = LCP(other);
        if(id == -1) return s[0] < other.s[0];
        if(*this == other) return false;
        if(id == n) return true; // "ho" < "hol"
        if(id == other.n) return false;

        return s[id+1] < other.s[id+1];
    }
};
class HashQueue{
    const int max_digits = 10; // Always numbers < 10^max_digits.
    string to_str(ll x) {
        string s = to_string(x);
        while((int)s.length() < max_digits) s = "0" + s;
        return s;
    }
    public:
    HashQueue() {
        string dummy = "0";
        hs = HashString(dummy);
    }
    HashString hs;
    int id = 0;
    int l = 1, r = 0; // [l, r].
    deque<pll> d;
    void push_back(ll x) {
        string s = to_str(x);
        hs.add(s);
        r += max_digits;
    }
    void pop_front() {
        l += max_digits;
    }
    bool empty() {
        return l > r;
    }
    bool operator == (HashQueue other) {
        if(empty() && other.empty()) return true;
        if(empty() || other.empty()) return false;
        return hs.getHash(l, r) == other.hs.getHash(other.l, other.r);
    }
};

