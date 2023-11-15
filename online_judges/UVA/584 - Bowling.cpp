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


ll read() {
    char c;
    cin >> c;
    if(c == 'X') return -1;
    if(c == '/') return -2;
    if(c == 'G') exit(0);
    return c-'0';
}
vi v;
ll getval(ll &i) {
    while(v[i] == -3) i++;
    if(v[i] == -2) return 10;
    if(v[i] == -1) return 10;
    return v[i];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll i, nxt;
    while(true) {
        v = vi(21, 0);
        for(i = 0; i < 20; i++) {
            v[i] = read();
            if(v[i] == -1) {
                v[i+1] = -3; // Hueco es -3.
                i++;
            }
        }
        if(v[18] == -1) {
            v[19] = read();
            v[20] = read();
        } else if(v[19] == -2) v[20] = read();
        // echo(v);
        ll ans = 0, mem;
        for(i = 0; i < 20; i++) {
            nxt = i;
            ans += getval(nxt);
            if(v[i] == -1) {
                nxt = i+1;
                ans += getval(nxt);
                mem = nxt;
                nxt++;
                ans += getval(nxt);
                if(v[mem] >= 0 && v[nxt] == -2) ans -= v[mem];
                i++;
            } else if(v[i] == -2) {
                ans -= v[i-1];
                nxt = i+1;
                ans += getval(nxt);
            }
            // echo(i, ans)
        }
        cout << ans << "\n";
    }


    return 0;
}



