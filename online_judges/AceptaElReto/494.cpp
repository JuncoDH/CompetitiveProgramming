#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}

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

/*mt19937 ran(time(0));*/
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
//typedef vector<bool> vb;


int main(){
    ios::sync_with_stdio(false);
    ll i, n, delta;
    bool flag;
    
    while(cin >> n) {
        if(!n)
            return 0;
            
        vi v(n), dif(n-1);
        for(i = 0; i < n; i++) cin >> v[i];
        for(i = 1; i < n; i++) dif[i - 1] = v[i] - v[i-1];
        //for(i = 0; i < n - 1; i++) cout << dif[i]<<" ";
        delta = 1;
        while(true) {
            flag = false;
            for(i = delta; i < n - 1; i++) {
                if(dif[i] != dif[i%delta]) {
                    flag = true;
                    break;
                }
            }
            if(flag==false) break;
            delta++;
        }
        //cout << "::" << delta<< endl;
        cout << v[n-1] + dif[(n-1)%delta] << "\n";
    }
    
    
    return 0;
}
