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

struct l{
    ll a, b, c;
};


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, i, j, p, x, y, neg, pos;
    ll tt = 1;
    while(true) {
        cin >> n;   
        if(!n) return 0;

        vector<l> v(n);
        for(i = 0; i < n; i++) {
            cin >> v[i].a >> v[i].b >> v[i].c;
        }
        cin >> p;
        ll ans = 0;
        for(i = 0; i < p; i++) {
            cin >> x >> y;
            neg = pos = 0;
            for(j = 0; j < n; j++) {
                //echo(v[i].a, x, v[i].b, y, v[i].c, v[i].a * x + v[i].b * y + v[i].c);
                if(v[j].a * x + v[j].b * y + v[j].c > 0) pos++;
                else neg++;
            }
            //echo(neg, pos);
            //ans += neg*pos;
            ans += (neg*(neg-1))/2;
            ans += (pos*(pos-1))/2;
        }
        //cout << ans << "\n";
        //cout << "Roadmap " << (tt++) << ":\nNegative Builders Ltd.  will build "<< ans <<" New Roads.\n";
        cout << "Roadmap " << tt << ":\n";
        tt++;
        //if(ans == 1)
        //    cout << "Negative Builders Ltd. will build " << ans << " New Road.\n";
        //else
        cout << "Negative Builders Ltd. will build " << ans << " New Roads.\n";
    }




    return 0;
}


