#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) (((x)>>(i))&1)
#define set_bit(x, i) {(x) |= 1ll<<(i);}
#define unset_bit(x, i) {(x) = ((x) | (1ll<<(i))) ^ (1ll<<(i));}


#ifdef JUNCO_DEBUG
#define echoarr(x) {for(int _i=0,_n=min((size_t)15,sizeof(x)/sizeof(x[0]));_i<_n;_i++)\
 {cout << x[_i] << " ";} cout << endl;}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(x)
#define echo(...) 
#define echo2(x) 
#endif

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout<<_s;}
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

template<typename T> // Input vector<T>.
istream& operator >> (istream& is, vector<T>& v) {
    for(T& el : v) is >> el;
    return is;
}

template<typename T> // Output vector<T>.
ostream& operator << (ostream& os, const vector<T>& v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAX = 52;
char c[MAX][MAX];

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, zz, n, i, j, tans, remember;
    bool ok;

    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        cin >> n;
        vll ans(n+1, 0);
        set<pii> ans1;
        // vector<set<pii>> ans(n+1);
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) cin >> c[i][j];
        }
        // rows.
        for(i = 0; i < n; i++) {
            ok = true;
            tans = 0;
            for(j = 0; j < n; j++) {
                if(c[i][j] == 'O') {ok = false; break;}
                else if(c[i][j] == '.') tans++, remember = j;
            }
            if(ok) ans[tans]++;
            if(ok && tans == 1) ans1.insert(mp(i, remember));
        }
        // cols.
        for(j = 0; j < n; j++) {
            ok = true;
            tans = 0;
            for(i = 0; i < n; i++) {
                if(c[i][j] == 'O') {ok = false; break;}
                else if(c[i][j] == '.') tans++, remember = i;
            }
            if(ok) ans[tans]++;
            if(ok  && tans == 1) ans1.insert(mp(remember, j));
        }
        ok = false;
        for(i = 0; i < n+1; i++) {
            if(ans[i] > 0) {
                if(i == 1)
                    cout << "Case #" << zz << ": " << i << " " << ans1.size() << "\n";
                else
                    cout << "Case #" << zz << ": " << i << " " << ans[i] << "\n";
    
                ok = true;
                break;
            }
        }
        if(!ok) {
            cout << "Case #" << zz << ": " << "Impossible" << "\n";
        }
    }



    return 0;
}
