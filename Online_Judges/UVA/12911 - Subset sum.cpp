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

// Sum Over Subsets. f[mask] = Sum_{s in mask} v[s].
// dp[mask][i] = Sum of submasks of masks having only the i+1 last bits different.
// if(is_set(mask, i)) dp[mask][i] = dp[mask][i-1] + dp[mask ^ (1ll << i)][i-1]
// else dp[mask][i] = dp[mask][i-1]. With base case dp[mask][-1] = v[mask].
vll SOS(vll &v) {
    int n_original = v.size();
    // Make v size power of two.
    while((int)v.size() != LSB((int)v.size())) v.pb(0); // 0 neutral sum element.
    int n = v.size(), i, mask;
    vll f(n, 0);
    for(mask = 0; mask < n; mask++) f[mask] = v[mask];
    for(i = 0; (1ll << i) < n; i++) {
        for(mask = 0; mask < n; mask++)
            if(is_set(mask, i))
                f[mask] += f[mask ^ (1ll << i)];
    }
    // Restore original v and f size.
    while((int) v.size() > n_original) v.pop_back(), f.pop_back();
    return f;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, k, i, n1, n2;

    while(cin >> n >> k) {
        vll v(n), v1, v2;
        cin >> v;
        if(n == 1) { // Base case.
            if(v[0] == k) cout << "1\n";
            else cout << "0\n";
            continue;
        }
        n1 = n/2;
        n2 = (n+1)/2;
        for(i = 0; i < n1; i++) v1.pb(v[i]);
        for(; i < n; i++) v2.pb(v[i]);

        vll v3(1ll << n1), v4(1ll << n2);
        for(i = 0; i < n1; i++) v3[1ll << i] = v1[i];
        for(i = 0; i < n2; i++) v4[1ll << i] = v2[i];
        // echo(v3);
        // echo(v4);

        // echo(v, v1, v2);
        auto ans1 = SOS(v3);
        auto ans2 = SOS(v4);

        // echo(ans1);
        // echo(ans2);

        map<ll, ll> m1;
        for(auto el : ans1) m1[el]++;
        ll ans = 0;
        for(auto el : ans2) {
            if(m1.count(k - el)) ans += m1[k - el];
        }
        if(k == 0) ans--;
        cout << ans << "\n";
    }

    return 0;
}

