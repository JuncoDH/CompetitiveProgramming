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

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){cout<<_s;}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
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


ll ans, tot;

vll v, w;// v are values (+), w are weight (-) 
const int MAX_VALUE = 5005; //max size of the knapsack value
ll dp[MAX_VALUE];
void knapsack() {
    ll i, j, n = v.size();
    for(i = 0; i < MAX_VALUE; i++) dp[i] = inf;
    dp[0] = 0;
    for(i = 0; i < n; i++) {
        if(w[i] == inf) continue;
        for(j = MAX_VALUE-1; j >= 0; j--) {
            if(j + v[i] < MAX_VALUE && dp[j] != inf) dp[j+v[i]] = min(dp[j+v[i]], dp[j]+w[i]);
        }
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, p, n, m, neg;
    
    while(cin >> n) {
        
        v.assign(n, 0);
        w.assign(n, 0);
        ans = inf;
        tot = 0;
        for(i = 0; i < n; i++) {
            cin >> v[i] >> p >> neg >> m;
            tot += v[i];
            w[i] = (m+neg-p)/2 +1;
            if(w[i] > m) w[i] = inf;
            if(w[i] < 0) w[i] = 0;
            if(p > neg + m) w[i] = 0;
        }
        //echo(v, w, tot);
        knapsack();
        //for(i = 0; i < 10; i++) echo(dp[i]); cout << endl;
        for(i = tot/2 + 1; i < MAX_VALUE; i++) ans = min(ans, dp[i]);

        if(ans == inf) cout << "IMPOSIBLE\n";
        else cout << ans << "\n";

    }

    return 0;
}

