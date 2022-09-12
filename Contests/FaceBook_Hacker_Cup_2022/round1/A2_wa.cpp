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

const int max_digits = 10; // Always numbers < 10^max_digits.
string to_str(ll x) {
    string s = to_string(x);
    while((int)s.length() < max_digits) s = "0" + s;
    return s;
}

// Search the ocurrences of t (pattern to search) in s (the text).
// O(n + m). It increases R at most 2n times and decreases at most n times. 
// z[i] is the longest string s[i..i+z[i]-1] that is a prefix = s[0..z[i]-1].
bool z_algorithm(string &s, string &t) {
    s = t + "$" + s; // "$" is a char not present in s nor t.
    int n = s.length(), m = t.length(), i, L = 0, R = 0;
    vi z(n, 0);
    // s[L..R] = s[0..R-L], [L, R] is the current window.
    for(i = 1; i < n; i++) {
        if(i > R) { // Old window, recalculate.
            L = R = i;
            while(R < n && s[R] == s[R-L]) R++;
            R--;
            z[i] = R - L + 1;
        } else {
            if(z[i-L] < R - i) z[i] = z[i-L]; // z[i] will fall in the window.
            else { // z[i] can fall outside the window, try to increase the window.
                L = i;
                while(R < n && s[R] == s[R-L]) R++;
                R--;
                z[i] = R - L + 1;
            }
        }
        if(z[i] == m) { // Match found.
            //echo("Pattern found at: ", i-m-1);
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, n, k, zz;
    bool ok;
    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        cin >> n >> k;
        vll a(n), b(n);
        cin >> a >> b;
        ok = true;
        // echo(a, b);
        if(k == 0) {
            if(a != b) ok = false;
        } else if(n == 2) {
            if(k%2 == 1) swap(a[0], a[1]);
            if(a == b) ok = true;
        } else {
            string s1, s2;
            for(auto el : a) s1 += to_str(el);
            for(auto el : b) s2 += to_str(el);
            s2 += s2;
            if(k == 1) {
                s2.pop_back();
                reverse(s2.begin(), s2.end());
                s2.pop_back();
                reverse(s2.begin(), s2.end());
            }
            if(!z_algorithm(s2, s1)) ok = false;
        }
        cout << "Case #" << zz << ": ";
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}



