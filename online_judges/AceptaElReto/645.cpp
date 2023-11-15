#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

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

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}
void ECHO(long long unsigned _s) {cout<<_s;}
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout.precision(7);cout<<fixed<<_s;}
void ECHO(long double _s){cout.precision(7);cout<<fixed<<_s;}
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
template<typename T> void ECHO(priority_queue<T> pq) {
    priority_queue<T> _pq = pq;
    while(!_pq.empty()) {ECHO(_pq.top()); cout << "->"; _pq.pop();}
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
istream& operator >> (istream &is, vector<T> &v) {
    for(T &el : v) is >> el;
    return is;
}
template<typename T> // Output vector<T>.
ostream& operator << (ostream &os, const vector<T> &v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}
using ll = long long;
bool is_set(ll x, ll i) {return (x>>i)&1;}
void set_bit(ll &x, ll i) {x |= 1ll<<i;}
void unset_bit(ll &x, ll i) {x = (x | (1ll<<i)) ^ (1ll<<i);}
ll LSB(ll x) {return x & (-x);}
int LSB_idx(ll x) { // Number of starting zeros.
    for(int i = 0; i < 63; i++) if(is_set(x, i)) return i;
    return -1;
}
ll MSB(ll x) {
    for(int i = 63; i >= 0; i--) if(is_set(x, i)) return 1<<i;
    return 0;
}
using ld = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

class DSU {
    int n;
    vi parent;
    vi rank;
    int find_parent(int a){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    public:
    int number_components;
    DSU() = default;
    DSU(int _n) {
        n = _n;
        number_components = n;
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
        number_components--;
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else {parent[a] = b; rank[b]++;}
    }
};
// Minimum spanning tree in a bidirected graph.
// graph contains elements [0..n-1], no extra space.
ll Kruskal(vector<vector<pii>> &graph) {
    int n = graph.size(), i;
    ll ans = 0;
    DSU dsu(n);
    vector<pair<ll, pii>> edge;
    for(i = 0; i < n; i++) {
        for(auto el : graph[i]) {
            if(i < el.fi) { // Only adds one edge.
                edge.pb(mp(el.se, mp(i, el.fi)));
            }
        }
    }
    sort(edge.begin(), edge.end());
    for(auto e : edge) {
        if(!dsu.is_connected(e.se.fi, e.se.se)) {
            dsu.Union(e.se.fi, e.se.se);
            ans += e.fi;
        }
    }
    if(dsu.number_components > 1) return -1;
    return ans;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, m, i, u, v, w, ans;
    while(cin >> n >> m) {
        vector<vector<pii>> graph(n, vector<pii>());
        for(i = 0; i < m; i++) {
            cin >> u >> v >> w;
            u--; v--;
            graph[u].pb(mp(v, w));
            graph[v].pb(mp(u, w));
        }
        ans = Kruskal(graph);
        if(ans == -1) cout << "No hay puentes suficientes\n";
        else cout << ans << "\n";
    }

    return 0;
}
