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

const ll MAX = 1e5 + 5;
ll v[MAX], w[MAX];
ll n, k;
vector<ld> vs(MAX);

bool f(ld alpha) {
    ll i;
    for(i = 0; i < n; i++) {
        vs[i] = v[i] - alpha*w[i];
    }
    sort(vs.begin(), vs.begin() + n);
    ld sum = 0;
    for(i = 0; i < k; i++) {
        sum += vs[n-i-1];
    }
    return sum > 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i;
    ld l, r, mid;
    cin >> n >> k;
    for(i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }


    /*echo(f(0));
    echo(f(7));
    echo(f(2));
    echo(f(0.5));
    echo(f(0.7));*/

    //return 0;

    l = 0; r = 1e6*1e6;
    while(r - l >= eps) {
        mid = (r+l) / 2.0;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout.precision(6);
    cout << fixed << r << "\n";



    return 0;
}



