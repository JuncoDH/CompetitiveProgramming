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
    void solve_one() {
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

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, a1, m1, a2, m2, ans;

    cin >> tt;
    while(tt--) {
        cin >> a1 >> m1 >> a2 >> m2;
        ChineseRemainder cr;
        cr.insert(a1, m1);
        cr.insert(a2, m2);
        ans = cr.solve();
        if(ans == -1) cout << "no solution\n";
        else cout << ans << " " << cr.modulo << "\n";
    }


    return 0;
}



