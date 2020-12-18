#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) (((x)>>(i))&1)
#define set_bit(x, i) {(x) |= 1ll<<(i);}

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

class DSU{
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
DSU dsu(1);
// Minimum spanning tree in a bidirected graph.
// graph contains elements [0..n-1], no extra space.
ll kruskal(vector<vector<pii>> &graph) {
    int n = graph.size(), i;
    ll ans = 0;
    dsu = DSU(n);
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
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, n, m, a, c, y, x, i, zz;
    vector<vector<pii>> graph;
    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        cin >> n >> m >> a;
        graph.assign(n, vector<pii>());
        for(i = 0; i < m; i++) {
            cin >> x >> y >> c;
            if(c >= a) continue;
            x--;
            y--;
            graph[x].pb(mp(y, c));
            graph[y].pb(mp(x, c));
        }
        ll kk = kruskal(graph);
        ll num_c = dsu.number_components();
        cout << "Case #" << zz << ": " << kk + num_c*a << " " << num_c << "\n";
    }



    return 0;
}
