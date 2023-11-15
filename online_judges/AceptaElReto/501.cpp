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
    ll td, ta, dd, da, no, i, j, ma, md;
    
    while(cin >> td) {
        cin >> ta >> dd >> da >> no;
        for(i = 0; i < no; i++) {
            if(ta == 0 || td == 0) break;
            vi dadosd(min(td, dd));
            vi dadosa(min(ta, da));
            for(j = 0; j < min(td, dd); j++) cin >> dadosd[j];
            for(j = 0; j < min(ta, da); j++) cin >> dadosa[j];
            sort(dadosd.begin(), dadosd.end(), [](int a, int b) {return a > b;});
            sort(dadosa.begin(), dadosa.end(), [](int a, int b) {return a > b;});
            md = min(td, dd); ma = min(ta, da);
            for(j = 0; j < min(ma, md); j++) {
                /*cout << "comparo:" << dadosd[j] << " "<< dadosa[j]<<endl;*/
                if(dadosd[j] >= dadosa[j]) --ta;
                else --td;
            }
        }
        cout << td << " " << ta << "\n";
    
    }
    
    
    
    return 0;
}
