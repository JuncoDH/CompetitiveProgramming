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
    ll n, i, m, tt, num;

    cin >> tt;
    while(tt--) {
        cin >> n;
        set<ll> sn, sm;
        vll tn, tm, ansn2, ansm2;
        set<ll> ansn, ansm;
        for(i = 0; i < n; i++) {
            cin >> num;
            if(sn.count(num)) {
                tn.pb(num);
            }
            else {
                sn.insert(num);
            }
        }
        cin >> m;
        for(i = 0; i < m; i++) {
            cin >> num;
            if(sm.count(num)) {
                tm.pb(num);
            } else {
                sm.insert(num);
            }
        }
        for(auto el : tn) {
            if(sm.count(el) == 0) ansn.insert(el);
        }
        for(auto el : tm) {
            if(sn.count(el) == 0) ansm.insert(el);
        }
        if(ansn.empty() == true) {
            cout << "Nada que intercambiar";
        }
        else {
            n = ansn.size();
            for(auto el : ansn) ansn2.pb(el);
            sort(ansn2.begin(), ansn2.end());
            for(i = 0; i < n; i++) {
                if(i > 0) {
                    cout << " ";
                }
                cout << ansn2[i];
            }
        }
        cout << "\n";
        if(ansm.empty() == true) {
            cout << "Nada que intercambiar";
        }
        else {
            n = ansm.size();
            for(auto el : ansm) ansm2.pb(el);
            sort(ansm2.begin(), ansm2.end());
            for(i = 0; i < n; i++) {
                if(i > 0) {
                    cout << " ";
                }
                cout << ansm2[i];
            }
        }
        cout << "\n";
        ansn.clear();
        ansm.clear();
        ansn2.clear();
        ansm2.clear();
        tn.clear();
        tm.clear();
        sn.clear();
        sm.clear();


    }



    return 0;
}
