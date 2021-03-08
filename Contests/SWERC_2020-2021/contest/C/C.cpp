// Template from https://github.com/JuncoDH/CompetitiveProgramming/blob/master/Implementations/Template/template.cpp
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

// copied code from https://github.com/JuncoDH/CompetitiveProgramming/blob/master/Implementations/DataStructure/DSU_UFDS.cpp
class DSU {
    int n;
    vi parent;
    vi rank;
    int find_parent(int a){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    public:
    DSU(int _n) {
        n = _n;
        parent.assign(n, 0);
        rank.assign(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    bool is_connected(int a, int b){
        return find_parent(a) == find_parent(b);
    }
    void Union(int a, int b){
        a = find_parent(a);
        b = find_parent(b);
        
        if(a == b) return;

        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else {parent[a] = b; rank[b]++;}
    }
    // Return the number of components in [0..n-1]. Be careful with single components not used in [n..n+extra_space].
    int number_components() {
        int ans = 0, i;
        for(i = 0; i < n; i++) ans += find_parent(i) == i;
        return ans;
    }
};

ll n, nx, ny;
vector<pair<ld, ld>> v;

ld distance(pair<ld, ld> a, pair<ld, ld> b) {
    ld dx = a.fi - b.fi;
    ld dy = a.se - b.se;
    return sqrt(dx*dx + dy*dy);
}

bool f(ld x) {
    DSU dsu(n+5);
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(distance(v[i], v[j]) <= 2*x) dsu.Union(i, j);
        }
    }
    for(i = 0; i < n; i++) {
        if(ny - v[i].se <= x) dsu.Union(i, n);
        if(v[i].fi <= x) dsu.Union(i, n+1);
        if(v[i].se <= x) dsu.Union(i, n+2);
        if(nx - v[i].fi <= x) dsu.Union(i, n+3);
    }
    if(dsu.is_connected(n, n+3)) return false;
    if(dsu.is_connected(n, n+2)) return false;
    if(dsu.is_connected(n+1, n+3)) return false;
    if(dsu.is_connected(n+1, n+2)) return false;


    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll i;

    cin >> nx >> ny;
    cin >> n;
    v.assign(n, pair<ld, ld>());
    for(i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }

    //echo(f(2.2));
    //echo(f(2.3));
    ld l, r, mid;
    l = 0;
    r = 3*1'000'000;
    while(r-l > eps) {
        mid = (l+r)/2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout.precision(9);
    cout << fixed << l << "\n";

    return 0;
}
