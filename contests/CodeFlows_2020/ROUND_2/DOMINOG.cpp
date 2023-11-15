#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) (((x)>>(i))&1)
#define set_bit(x, i) {(x) |= 1ll<<(i);}

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

ll ql, qr;
bool fin;
vector<vector<bool>> v;
void query(ll i, ll j) {
    if(fin) return;
    if(v[i][j]) return;
    cout << i << " " << j << endl;
    cin >> ql >> qr;
    if(ql == -1 && qr == -1) exit(-1);
    if(ql == 0 && qr == 0) fin = true;
    v[i][j] = true;
    v[ql][qr] = true;
}

void f(ll x1, ll y1, ll x2, ll y2) {
    if(x1 > x2 || y1 > y2 || fin) return;
    int i, j, mid;
    if(x2-x1+1 < y2-y1+1) { // Diff de x es menor.
        mid = (y1 + y2)/2;
        for(i = x1; i <= x2; i++) {
            query(i, mid);
        }
        int cont_l = 0, cont_r = 0;
        for(i = x1; i <= x2; i++) {
            for(j = y1; j <= y2; j++) {
                if(!v[i][j]) {
                    if(j < mid) cont_l++;
                    else cont_r++;
                }
            }
        }
        if(cont_l%2) f(x1, y1, x2, mid-1);
        else f(x1, mid+1, x2, y2);

        return;
    }
    mid = (x1 + x2)/2;
    for(j = y1; j <= y2; j++) {
        query(mid, j);
    }
    int cont_up = 0, cont_down = 0;
    for(i = x1; i <= x2; i++) {
        for(j = y1; j <= y2; j++) {
            if(!v[i][j]) {
                if(i < mid) cont_up++;
                else cont_down++;
            }
        }
    }
    if(cont_up%2) f(x1, y1, mid-1, y2);
    else f(mid+1, y1, x2, y2);    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, m;
    while(true) {
        cin >> n >> m;
        if(!n && !m) return 0;
        v.assign(n+1, vector<bool>(m+1, false));
        fin = false;
        f(1, 1, n, m);
    }



    return 0;
}
