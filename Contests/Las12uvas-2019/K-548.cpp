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

vll v;
ll n, p, s;

int f(ll x) {
    ll i, sum = 0, p2 = p;
    if(v[0] > x) return 0;
    sum = v[0];
    for(i = 0; i < n; i++) {
        if(v[i + 1] + sum > x) {
            if(p2 == 0) return 0;
            p2--;
            sum = 0;
        }
        sum += v[i+1];
        if(sum > x) return 0;
        
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    ll i, l, mid, r;

    while(cin >> n) {
        cin >> p;
        v.resize(n);
        s = 0;
        for(i = 0; i < n; i++) {
            cin >> v[i];
            s += v[i];
        }
        v.pb(0);

        l = 0; r = s;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            if(f(mid) == 0) l = mid;
            else r = mid;
        }
        cout << r << "\n";
    }

    return 0;
}