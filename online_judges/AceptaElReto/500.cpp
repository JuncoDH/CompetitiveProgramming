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

const ll MAX = 9999 + 10;

int vote(int n1, int n2) {
    string s1 = to_string(n1), s2 = to_string(n2);
    while(s1.length() != 4) {
        s1 = "0" + s1;
    }
    while(s2.length() != 4) {
        s2 = "0" + s2;
    }
    reverse(s2.begin(), s2.end());
    if(s1 == s2) return 1;
    return 0;
}

ll S[MAX], P[MAX];

int inverso(int a) {
    string s = to_string(a);
    while(s.length() != 4) {
        s = "0" + s;
    }
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main(){
    ios::sync_with_stdio(false);
    ll i, n, q, num;
    
    for(i = 0; i <= 9999; i++) {
        num = inverso(i);
        if((num + i) < MAX) S[num + i]++;
        //if(2000 < num && num < 2100) cout << i << " " << num << endl;
    }
    P[0] = S[0];
    for(i = 1; i <= 9999; i++) P[i] = P[i-1] + S[i];

    while(true) {
        cin >> n >> q;
        if(!n && !q) return 0;
        cout << n << " " << q << " " << P[n] - P[q-1] << "\n";
       /* for(i = q; i <= n; i++) {
            cout << S[i] << " ";
        }cout << endl;*/
    }
    
    return 0;
}
