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


int main(){
    ios::sync_with_stdio(false);
    ll n, i, j, k1, ans, m;
    bool flag;
    vll a;
    while(true) {
        cin >> n;
        if(!n) return 0;

        vector<vll> v(n, vll(n));
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cin >> v[i][j];
                /*for(k1 = 0; k1 < 2; k1++) {
                    for(k2 = 0; k2 < 2; k2++) {
                        v[i+n*k1][j+n*k2] = v[i][j];
                    }
                }*/
            }
        }
        ans = inf;
        for(i = 0; i < n; i++) {
            m = 0;
            a.clear();
            for(j = 0; j < n; j++) {
                a.pb(v[(i+j)%n][j]);
            }
            for(j = 0; j < n; j++) {
                a.pb(v[(i+j)%n][j]);
                if(a.back() < a[m]) m = j;
            }
            flag = true;
            for(j = m+1; j < m+n; j++) {
                if(a[j-1] >= a[j]) flag = false;
            }
            //echo(a, m, flag);

            if(flag == true) {
                //echo("gano", i);
                k1 = (i+m)%n; j = m;
                //echo(k1, i, j, m, a);
                ans = min(ans, k1+j);
                ans = min(ans, (n-k1)+j);
                ans = min(ans, k1 + (n-j));
                ans = min(ans, (n-k1) + (n-j));
            }
        }
        //echo(v);
        /*ans = inf;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                flag = true;
                for(k = 1; k < n; k++) {
                    if(v[i+k][j+k] <= v[i-1+k][j-1+k]) {flag = false; break;}
                }
                if(flag) {
                    //ans = min(ans, abs(n-i)+abs(n-j));
                    ans = min(ans, i+j);
                    ans = min(ans, (n-i)+j);
                    ans = min(ans, i + (n-j));
                    ans = min(ans, (n-i) + (n-j));
                }
            }
        }*/
        if(ans == inf) {
            cout << "IMPOSIBLE\n";
        }
        else {
            cout << ans << "\n";
        }
    }
    return 0;
}
