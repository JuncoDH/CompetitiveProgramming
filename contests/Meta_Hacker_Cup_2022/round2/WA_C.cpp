#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

#ifdef JUNCO_DEBUG
#define echoarr(_i, _v) {for(int _x=0;_x<_i;_x++){cout<<v[_x]<<" ";}cout<<endl;}
#define echoarr2(_i, _j, _v) {for(int _x=0;_x<_i;_x++){for(int _y=0;_y<_j;_y++) \
{cout<<_v[_x][_y]<<" ";}cout<<endl;}}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(_i, _v)
#define echoarr2(_i, _j, _v)
#define echo(...)
#define echo2(x)
#endif

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}
void ECHO(long long unsigned _s) {cout<<_s;}
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout.precision(7);cout<<fixed<<_s;}
void ECHO(long double _s){cout.precision(7);cout<<fixed<<_s;}
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
istream& operator >> (istream &is, vector<T> &v) {
    for(T &el : v) is >> el;
    return is;
}
template<typename T> // Output vector<T>.
ostream& operator << (ostream &os, const vector<T> &v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}
using ll = long long;
bool is_set(ll x, ll i) {return (x>>i)&1;}
void set_bit(ll &x, ll i) {x |= 1ll<<i;}
void unset_bit(ll &x, ll i) {x = (x | (1ll<<i)) ^ (1ll<<i);}
ll LSB(ll x) {return x & (-x);}
int LSB_idx(ll x) { // Number of starting zeros.
    for(int i = 0; i < 63; i++) if(is_set(x, i)) return i;
    return -1;
}
ll MSB(ll x) {
    for(int i = 63; i >= 0; i--) if(is_set(x, i)) return 1<<i;
    return 0;
}
using ld = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll mod = 1000000007;

// ONLY USE WHEN MOD IS PRIME, ELSE USE GCD.
ll elevate(ll a, ll b) { // b >= 0.
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
// a^(mod - 1) = 1, Euler.
ll inv(ll a) {
    return elevate(((a%mod) + mod)%mod, mod - 2);
}


ll mul(ll a, ll b, ll c) {
    a *= b;
    a %= mod;
    a *= c;
    return a%mod;
}

const ll MAX = 3001;
ll n, k, a;
map<pll, ll> dp[2][4][4];
// -1 no chip.
// 0 equal weight.
// 1 less weight.
// 2 is the chip.
ll p(ll x, ll b, ll c, ll l, ll r) {
    ll step = n-x-a-b-c;
    ll quedan = n-step;
    echo(step, quedan, x, b, c, l, r);
    if(x == 0 && l != 2 && r != 2) return 0;
    if(step-1 == k) {
        if(l == 2 || r == 2) return 1;
        else return 0;
    }
    if(dp[x][l+1][r+1].count(mp(b, c))) return dp[x][l+1][r+1][mp(b, c)]; 
    ll ans = 0;
    if(l == 0) {
        if(x > 0) ans += mul(x, inv(quedan), p(x-1, b, c, -1, 2));
        if(b > 0) ans += mul(b, inv(quedan), p(x, b-1, c, -1, 0));
        if(c > 0) ans += mul(c, inv(quedan), p(x, b, c-1, 0, -1));
    } else if(l == 1) {
        if(x > 0) ans += mul(x, inv(quedan), p(x-1, b, c, -1, 2));
        if(b > 0) ans += mul(b, inv(quedan), p(x, b-1, c, -1, 0));
        if(c > 0) ans += mul(c, inv(quedan), p(x, b, c-1, -1, 1));
    } else if(l == 2) {
        if(x > 0) ans += mul(x, inv(quedan), p(x-1, b, c, -1, 2));
        if(b > 0) ans += mul(b, inv(quedan), p(x, b-1, c, -1, 0));
        if(c > 0) ans += mul(c, inv(quedan), p(x, b, c-1, 2, -1));
    } 
    else if(r == 0) {
        if(x > 0) ans += mul(x, inv(quedan), p(x-1, b, c, -1, 0));
        if(b > 0) ans += mul(b, inv(quedan), p(x, b-1, c, -1, 0));
        if(c > 0) ans += mul(c, inv(quedan), p(x, b, c-1, -1, 0));
    } else if(r == 1) {
        if(x > 0) ans += mul(x, inv(quedan), p(x-1, b, c, 0, -1));
        if(b > 0) ans += mul(b, inv(quedan), p(x, b-1, c, 0, -1));
        if(c > 0) ans += mul(c, inv(quedan), p(x, b, c-1, -1, 1));
    } else if(r == 2) {
        if(x > 0) ans += mul(x, inv(quedan), p(x-1, b, c, -1, 2));
        if(b > 0) ans += mul(b, inv(quedan), p(x, b-1, c, -1, 2));
        if(c > 0) ans += mul(c, inv(quedan), p(x, b, c-1, -1, 2));
    }
    ans %= mod;
    ans += mod;
    ans %= mod;
    return dp[x][l+1][r+1][mp(b, c)] = ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, zz, d, xd, b, c, i, num, xnum, ans, j;
    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                dp[0][i][j].clear();
                dp[1][i][j].clear();
            }
        }
        cin >> n >> k;
        cin >> d >> xd;
        b = d-1;
        c = 0;
        a = 0;
        ll tot = d;
        for(i = 1; i < n; i++) {
            cin >> num >> xnum;
            tot += num;
            if(xnum == xd) b += num;
            else if(xnum < xd) c += num;
            else a += num;
        }
        n = tot;
        ans = 0;
        //echo(n, a, b, c);
        ans +=           mul(1, inv(n), p(1-1, b, c, 2, -1));
        // echo(ans);
        if(b > 0) ans += mul(b, inv(n), p(1, b-1, c, 0, -1));
        //echo(ans);
        if(c > 0) ans += mul(c, inv(n), p(1, b, c-1, 1, -1));
        //echo(ans);

        ans *= d;
        ans %= mod;
        ans += mod;
        ans %= mod;
        cout << "Case #" << zz << ": " << ans << "\n";
        echo("..");
    }


    return 0;
}


