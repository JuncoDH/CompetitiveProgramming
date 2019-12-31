#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))

#ifdef _LOCAL_
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}
#else
#define echobin(x)
#define echo(...) 
#endif

void ECHO(string _s){cout<<endl;(void)_s;}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i; string _s2="";
    for(_i=0;_i<sz(_s);++_i){if(_s[_i]==',')break;if(_s[_i]!=' ')_s2+=_s[_i];}
    if(_i==sz(_s)){--_i;}cout<<"  ("<<_s2<<"):"<<x;
    ECHO(_s.substr(_i+1, sz(_s)-_i-1), args...);
} 


template<typename T0, typename T1>
inline ostream& operator << (ostream& os, pair<T0, T1>& p){
    return os << "(" << p.first << ", " << p.second <<")";
}

template <typename T>
inline ostream& operator << (ostream& os, vector<T>& v){
    for(int i = 0; i < sz(v); ++i) {if(i > 0) cout << "_"; cout << v[i];} cout << endl;
    return os;
} 

//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;
const int int_inf = INT_MAX / 10;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<pll, ll> m;

//num of numbers lower than x with k bits on
ll f(ll x, ll k) {
    ll i;
    if(k == 0) return 1;
    if(x == 0) return 0;

    if(m.count(mp(x, k))) return m[mp(x, k)];

    for(i = 61; i >= 0; i--) {
        if(x&(1ll<<i)) {
            return m[mp(x, k)] = f(x - (1ll<<i), k-1) + f((1ll<<i)-1, k);
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    ll a, b, c, s, i;


    while(true) {
        cin >> a >> b >> c;
        if(!a && !b && !c) return 0;
        //echo(a, b, c, f(c, a), f(b-1, a));
        s = 0;

        for(i = 0; i <= a; i++) s += f(c, i);
        if(b > 0)
            for(i = 0; i <= a; i++) s -= f(b-1, i);

        cout << s << "\n";
    }

    return 0;
}
