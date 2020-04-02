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

bool colision(pll a, pll b) {
    if(a.se < b.fi || b.se < a.fi) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, i, j, res;
    bool flag, reduc;
    pll u;

    while(true) {
        cin >> n;
        if(!n) return 0;
        res = 0;
        vector<pll> v(n), ans;
        for(i = 0; i < n; i++) {
            cin >> v[i].fi >> v[i].se;
        }
        reduc = true;
        while(reduc) {
            reduc = false;
            ans.clear();

            while(v.empty() == false) {
                flag = true;
                ll si = (ll)v.size();
                
                for(j = 0; j < si-1; j++) {
                    if(colision(v[j], v.back())) {
                        flag = false;
                        u = v[j];
                        v[j].fi = min(u.fi, v.back().fi);
                        v[j].se = max(u.se, v.back().se);
                        v.pop_back();
                        reduc = true;
                        break;
                    }
                }
                if(flag) {
                    ans.pb(v.back());
                    v.pop_back();
                }
            }
            v = ans;
        }

        //echo(ans);
        j = (ll)ans.size();
        for(i = 0; i < j; i++) {
            res += ans[i].se - ans[i].fi + 1;
        }
        cout << res << "\n";
    }


    return 0;
}
