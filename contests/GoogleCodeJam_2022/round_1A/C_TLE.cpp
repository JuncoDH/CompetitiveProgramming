#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) (((x)>>(i))&1)
#define set_bit(x, i) {(x) |= 1ll<<(i);}
#define unset_bit(x, i) {(x) = ((x) | (1ll<<(i))) ^ (1ll<<(i));}


#ifdef JUNCO_DEBUG
#define echoarr(x) {for(int _i=0,_n=min((size_t)15,sizeof(x)/sizeof(x[0]));_i<_n;_i++)\
 {cout << x[_i] << " ";} cout << endl;}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(x)
#define echo(...) 
#define echo2(x) 
#endif

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(long long unsigned _s) {cout<<_s;}
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout<<_s;}
void ECHO(long double _s){cout<<_s;}
void ECHO(bitset<8> b) {cout << b;}//resize bitset
template<typename T> void ECHO(set<T> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(map<T1, T2> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(pair<T1, T2> _s) {
    cout << "("; ECHO(_s.fi); cout << ","; ECHO(_s.se); cout << ")";
}
template<typename T> void ECHO(vector<T> v) {
    for(auto el : v) {ECHO(el); cout << "_";}
}
template<typename T> void ECHO(priority_queue<T> pq) {
    priority_queue<T> _pq = pq;
    while(!_pq.empty()) {ECHO(_pq.top()); cout << "->"; _pq.pop();}
}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i, c = 0;
    for(_i = 0; _i < (int)_s.size(); _i++) {
        if(c==0 && _s[_i]==',') break;
        if(_s[_i] == '(') c++;
        if(_s[_i] == ')') c--;
    }
    cout << " (" << _s.substr(0, _i) << "): "; ECHO(x);
    while(_i < (int)_s.size() && (_s[_i] == ',' || _s[_i] == ' ')) _i++;
    ECHO(_s.substr(_i), args...);
}

template<typename T> // Input vector<T>.
istream& operator >> (istream& is, vector<T>& v) {
    for(T& el : v) is >> el;
    return is;
}

template<typename T> // Output vector<T>.
ostream& operator << (ostream& os, const vector<T>& v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// https://www.browserling.com/tools/prime-numbers.
// s = a[i], hash = a[0] + b*a[1] + b^2*a[2] + b^n*a[n].
class HashStr {
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
            if(_b & 1) ans = ans * a % mod;
            _b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }
    // a^(mod - 1) = 1, Euler.
    ll inv(int i, int j){
        if(b_inv[i][j] != -1) return b_inv[i][j];
        return b_inv[i][j] = elevate(b[i][j], p[i] - 2, p[i]);
    }
    HashStr() = default; // Initialize later.
    HashStr(string &_s) { // not empty strings.
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
        char initial = 'A'; // change initial for range. 'a', 'A'.
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
    // O(1).
    bool equals(HashStr other, int l, int r) {
        for(int i = 0; i < n_p; i++) {
            if(getHash(l, r, i) != other.getHash(l, r, i)) return false;
        }
        return true;
    }
    // O(1).
    bool operator == (HashStr other) {
        if(n != other.n) return false;
        return equals(other, 0, n-1);
    }
    // return the index of the Longest Comon Prefix, -1 if no Common Prefix.
    // O(log n).
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
    bool operator < (const HashStr &other) const {
        for(int i = 0; i < min(10, min(n, other.n)); i++) {
            if(s[i] < other.s[i]) return true;
            if(s[i] > other.s[i]) return false;
        }
        return false;
    }
};

ll ans;
ll e, w;
vector<vll> v;
vll cnt;
vll s;
set<pair<pll, HashStr>> dp;

HashStr get_hash() {
    string s2;
    for(int i = 0; i < (int)s.size(); i++) {
        s2 += (char)(s[i]+'A');
    }
    return HashStr(s2);
}

void add_n(ll x) {
    s.pb(x);
    cnt[x]++;
}
ll del_n() {
    ll num = s.back();
    s.pop_back();
    cnt[num]--;
    return num;
}

void f(ll pos, ll t_ans) {
    ll i, j;
    if(t_ans + (ll)s.size() >= ans) return;
    if(pos == e) {
        ans = t_ans + (ll)s.size();
        return;
    }
    if((int) s.size() > 0) {
        HashStr hs = get_hash();
        if(dp.count(mp(mp(pos, t_ans), hs))) {
            return;
        }
        dp.insert(mp(mp(pos, t_ans), hs));
    }

    bool ok = true;
    for(i = 1; i <= w; i++) {
        if(cnt[i] != v[pos][i-1]) {
            ok = false;
            break;
        }
    }
    if(ok) {
        vll s2;
        s2 = s;
        j = 0;
        f(pos+1, t_ans);
        while((int) s.size() > 0) {
            del_n();
            j++;
            f(pos+1, t_ans+j);
        }
        for(i = 0; i < (int)s2.size(); i++) {
            add_n(s2[i]);
        }
        return;
    }
    for(i = 1; i <= w; i++) {
        if(cnt[i] > v[pos][i-1]) {
            return;
        }
    }
    for(i = 1; i <= w; i++) {
        if(cnt[i] < v[pos][i-1]) {
            add_n(i);
            f(pos, t_ans+1);
            del_n();
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll zz, tt, i, j;

    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        cin >> e >> w;
        if(e > 12) return 0; // SOLO VOY AL PEQUENIO.
        cnt.assign(w+1, 0);
        ans = inf;
        v.assign(e, vll(w, 0));
        for(i = 0; i < e; i++) {
            for(j = 0; j < w; j++) {
                cin >> v[i][j];
            }
        }
        s.clear();
        dp.clear();
        f(0, 0);

        cout << "Case #" << zz << ": " << ans << "\n";
    }


    return 0;
}


