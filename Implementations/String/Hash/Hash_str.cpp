//https://www.browserling.com/tools/prime-numbers
//s = a[i], hash = a[0] + b*a[1] + b^2*a[2] + b^n*a[n]
class HashStr {
    public:
    string s;
    int n, n_p;
    vector<vll> v; //contain the hash for [0..i]
    vll p = {16532849, 91638611, 83157709}; //prime numbers//15635513  77781229
    vll base = {37, 47, 53}; //base numbers: primes that > alphabet size //49 83
    vector<vll> b; //b[i][j] = (b_i^j) % p_i 
    vector<vll> b_inv;//b_inv[i][j] = (b_i^j)^-1 % p_i 

    ll elevate(ll a, ll _b, ll mod){
        ll ans = 1;
        while(_b){
            if(_b & 1) ans = ans * a % mod;
            _b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }

    //a^(mod - 1) = 1, Euler
    ll inv(int i, int j){
        if(b_inv[i][j] != -1) return b_inv[i][j];
        return b_inv[i][j] = elevate(b[i][j], p[i] - 2, p[i]);
    }

    HashStr(string &_s) { //not empty strings
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
        }
        char initial = 'a'; //change initial for range
        for(i = 0; i < n_p; i++) {
            v[i][0] = s[0]-initial+1;
            for(j = 1; j < n; j++) {
                v[i][j] = (b[i][j]*(s[j]-initial+1) + v[i][j-1]) % p[i];
            }
        }
    }
    ll getHash(int l, int r, int imod) {
        ll ans = v[imod][r];
        if(l > 0) ans -= v[imod][l-1];
        ans *= inv(imod, l);
        ans = ((ans%p[imod])+p[imod])%p[imod];
        return ans;
    }
    //O(1)
    bool equals(HashStr other, int l, int r) {
        for(int i = 0; i < n_p; i++) {
            if(getHash(l, r, i) != other.getHash(l, r, i)) return false;
        }
        return true;
    }
    //O(1)
    bool operator == (HashStr other) {
        if(n != other.n) return false;
        return equals(other, 0, n-1);
    }
    //return the index of the Longest Comon Prefix, -1 if no Common Prefix
    //O(log n)
    int LCP(HashStr other) {
        int l = 0, r = min(n, other.n), mid;
        if(s[0] != other.s[0]) return -1;
        if(*this == other) return n-1;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            if(equals(other, 0, mid)) l = mid;
            else r = mid;
        }
        
        return l;
    }
    bool operator < (HashStr other) {
        int id = LCP(other);
        if(id == -1) return s[0] < other.s[0];
        if(*this == other) return false;
        if(id == n) return true; //"ho" < "hol"
        if(id == other.n) return false;

        return s[id+1] < other.s[id+1];
    }
};
