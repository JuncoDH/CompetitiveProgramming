#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) ((x>>i)&1)

#ifdef GREMIO_DEBUG
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

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


vector<ld> p;
ll n;

ld h(ld x) {
    ll i;
    if(x < 0 || x > 1) return 0;
    ld ans = 0;
    for(i = 0; i < n; i++) {
        ans *= x;
        ans += p[i];
    }
    return ans;
}

ld f(ld x) { // h(x + h(x)) == h(x) we want.
    ld hx = h(x);
    return h(x+hx) - hx;
}

// Find the root of ld f(ld x){} in the interval [l..r] with precission of eps.
ld bisection_method(ld l, ld r) {
    ld fl = f(l), fr = f(r), mid, fmid;
    if(fl == 0) return l;
    if(fr == 0) return r;
    bool sgn1 = fl > 0, sgn2 = fr > 0;
    if(sgn1 == sgn2) echo("ERROR", sgn1);
    while(r-l > eps) {
        mid = (l+r)/2;
        fmid = f(mid);
        if(fmid == 0) return mid;
        if(fmid > 0) {
            if(sgn1) l = mid;
            else r = mid;
        } else {
            if(sgn1) r = mid;
            else l = mid;
        }
    }
    return (l+r)/2;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, i;

    cin >> tt;
    while(tt--) {
        cin >> n;
        n++;
        p.assign(n, 0);
        for(i = 0; i < n; i++) cin >> p[i];


        cout << setprecision(5) << fixed;
        //cout << h(0.01) << " " << h(0.99) << endl;
        cout << bisection_method(0.01, 0.99) << "\n";
    }




    return 0;
}
