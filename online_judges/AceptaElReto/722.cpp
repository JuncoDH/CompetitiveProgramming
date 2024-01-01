#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long double PI = acos(-1);
constexpr long double eps = 1e-9;
constexpr long long inf = LLONG_MAX / 10;

#ifdef JUNCO_DEBUG
#define echoarr(_i, _v) { for(int _x = 0; _x < _i; ++_x) { cout<< _v[_x] << " "; } cout << endl; }
#define echoarr2(_i, _j, _v) { for(int _x = 0; _x < _i; ++_x) { for(int _y = 0; _y < _j; ++_y) \
{ cout << _v[_x][_y] << " "; } cout << endl; } }
#define echo(...) { cout << "->"; ECHO(#__VA_ARGS__, __VA_ARGS__ ); cout << endl; }
#define echo2(x) { cout << #x << endl; for(auto const& el : x) { ECHO(el); cout << endl; } }
#else
#define echoarr(_i, _v)
#define echoarr2(_i, _j, _v)
#define echo(...)
#define echo2(x)
#endif

void ECHO(string const _s) { cout << _s; }
void ECHO(bool const _s) { if(_s) cout << "true" ; else cout << "false"; }
void ECHO(char const _s) { cout << _s; }
void ECHO(long unsigned const _s) { cout << _s; }
void ECHO(long long unsigned const _s) { cout << _s; }
void ECHO(int const _s){ cout << _s; }
void ECHO(long long const _s){ if(_s == inf) cout << "inf"; else cout<<_s; }
void ECHO(double const _s){ cout.precision(7); cout << fixed << _s; }
void ECHO(long double const _s){ cout.precision(7); cout << fixed <<_s; }
void ECHO(bitset<8> const b) { cout << b; } // Resize bitset.
template<typename T> void ECHO(set<T> const _s) {
    for(auto const& el : _s) { ECHO(el); cout << "_"; }
}
template<typename T1, typename T2> void ECHO(map<T1, T2> const _s) {
    for(auto const& el : _s) { ECHO(el); cout << "_"; }
}
template<typename T1, typename T2> void ECHO(pair<T1, T2> const _s) {
    cout << "("; ECHO(_s.fi); cout << ","; ECHO(_s.se); cout << ")";
}
template<typename T> void ECHO(vector<T> const v) {
    for(auto const& el : v) { ECHO(el); cout << "_"; }
}
template<typename T> void ECHO(priority_queue<T> const pq) {
    priority_queue<T> _pq = pq;
    while(!_pq.empty()) { ECHO(_pq.top()); cout << "->"; _pq.pop(); }
}
template<typename T, typename ...Args> void ECHO(string const _s, T const x, Args... args){
    int _i, c = 0;
    for(_i = 0; _i < (int)_s.size(); ++_i) {
        if(c == 0 && _s[_i]==',') break;
        if(_s[_i] == '(') ++c;
        if(_s[_i] == ')') --c;
    }
    cout << " (" << _s.substr(0, _i) << "): "; ECHO(x);
    while(_i < (int)_s.size() && (_s[_i] == ',' || _s[_i] == ' ')) ++_i;
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
using ll = long long;
bool is_set(ll const x, ll const i) { return (x >> i) & 1; }
void set_bit(ll& x, ll const i) { x |= 1ll<<i; }
void unset_bit(ll& x, ll const i) { x = (x | (1ll<<i)) ^ (1ll<<i); }
ll LSB(ll const x) { return x & (-x); }
int LSB_idx(ll const x) { // Number of starting zeros.
    for(int i = 0; i < 63; ++i) if(is_set(x, i)) return i;
    return -1;
}
ll MSB(ll const x) {
    for(int i = 63; i >= 0; --i) if(is_set(x, i)) return 1ll<<i;
    return 0;
}
using ld = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll a, b, c, d, k1, k2;
    while (true) {
        cin >> a >> b >> c >> d;
        if (!a && !b && !c && !d) return 0;
        if (a % c == 0 && b % d == 0 && a/c == b/d) {cout << "SI\n"; continue;}
        if (a % d == 0 && b % c == 0 && a/d == b/c) {cout << "SI\n"; continue;}
        if (c == d) {cout << "NO\n"; continue;}
        if ((a*d - b*c) % (d*d - c*c)) {cout << "NO\n"; continue;}
        k2 = (a*d - b*c) / (d*d - c*c);
        if ((a - k2*d) % c) {cout << "NO\n"; continue;}
        k1 = (a - k2*d) / c;
        if (k1 < 0 || k2 < 0) {cout << "NO\n"; continue;}
        cout << "SI\n";
    }


    return 0;
}


