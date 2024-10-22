#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))

#ifdef _LOCAL_
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echo(...) 
#define echo2(x) 
#endif

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){cout<<_s;}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){cout<<_s;}
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


const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;


typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll supermod = 1'000'000'007;

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

const ll MAX = 10;
ll a[MAX], p[MAX], n;

void solve() {
    ll i, x, y; //x is p[0]^-1 mod p[i]
    for(i = 1; i < n; i++) {
        gcdEx(p[0], p[i], &x, &y);
        //echo(a[0], p[0], (a[i] - a[0]), x);
        a[0] = a[0] + p[0]*(a[i] - a[0]) * x;
        p[0] = p[0]*p[i];
        a[0] = a[0] %p[0];

        a[0] %= supermod;
        p[0] %= supermod;
    }
    a[0] += p[0];
    a[0] %= p[0];

    a[0] %= supermod;
    p[0] %= supermod;
}


void check() {
    ll x = a[0], m = p[0], i;
    echo(x, m);
    for(i = 1; i < n; i++) {
        if(x%p[i] != a[i]) {
            echo("fail", a[i], p[i], x%p[i]);
            return;
        }
    }
    echo("AC");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, j, k, col;

    while(true) {
        cin >> n;
        if(!n) return 0;
        col = -1;
        set<ll> s;
        vector<vll> v(n, vll());
        for(i = 0; i < n; i++) {
            cin >> k;
            v[i].resize(k);
            for(j = 0; j < k; j++) {
                cin >> v[i][j];
                if(col != -1) continue;
                if(s.count(v[i][j])) {
                    col = v[i][j];
                    continue;
                } 
                s.insert(v[i][j]);
            }
        }


        for(i = 0; i < n; i++) {
            a[i] = p[i] = 0;
            for(j = 0; j < (ll)v[i].size(); j++) {
                if(p[i]) p[i]++;
                else if(v[i][j] == col) p[i]++;
                else a[i]++;
            }
            a[i] %= p[i];
        }

        //for(i = 0; i < n; i++) {cout << a[i] << " " << p[i] << endl;}

        solve();

        cout << a[0]%supermod << "\n";
    }


    return 0;
}



