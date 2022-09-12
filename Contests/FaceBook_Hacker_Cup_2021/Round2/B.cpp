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
void ECHO(long long unsigned _s) {cout<<_s;}
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

const int MAX_N = 8e5 + 2;
const int MAX_LOG_N = 21;
int n;
vector<vi> graph; // Directed graph, allways reserve memory for it.
vector<vi> bigraph; // Undirected graph, reserve memory only if needed.

int level[MAX_N]; // level of the node rooted.
int parent[MAX_N][MAX_LOG_N]; // parent[i][j] is the parent 2^j of the node i.

vector<bool> visited_bigraph;
// root_graph(u, -1) roots the bigraph at node u.
void root_graph(int u, int p) {
    // echo(u, p);
    if(p == -1) visited_bigraph.assign(n, false);
    for(auto v : bigraph[u]) {
        if(v == p) continue;
        graph[u].pb(v);
        root_graph(v, u);
    }
}

// Calcule the level and parent 1. Don't call.
void dfs_level(int u, int p) {
    parent[u][0] = p;
    level[u] = level[p] + 1;
    for(auto v : graph[u]) {
        if(v == p) continue;
        dfs_level(v, u);
    }
}
// Builds the LCA.
void build_lca(int root) {
    int i, j;
    level[root] = -1;
    dfs_level(root, root); // The parent of the root is itself.
    for(j = 1; j < MAX_LOG_N; j++) {
        for(i = 0; i < MAX_N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}
// Calculates the LCA(u, v) in O(log n).
int lca(int u, int v) {
    if(level[u] > level[v]) swap(u, v);
    int i, d = level[v] - level[u];
    for(i = MAX_LOG_N - 1; i >= 0; i--) {
        if(is_set(d, i)) v = parent[v][i];
    }
    if(u == v) return u;
    for(i = MAX_LOG_N - 1; i >= 0; i--) {
        if(parent[u][i] != parent[v][i]) 
            u = parent[u][i], v = parent[v][i];
    }
    return parent[u][0];
}
// Calculates the distance(u, v) in a tree in O(log n).
int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u, v)];
}

set<pii> used;
vi highest; // el nodo mas alto.
pii get_edge(int u, int v) {
    if(u > v) swap(u, v);
    return mp(u, v);
}
int compress(int u) {
    u = highest[u];
    int e = parent[u][0];
    if(e == u) return u;
    if(used.count(get_edge(u, e))) {
        return highest[u] = compress(e);
    }
    return highest[u] = u;
}
// u is ancestor of v. u->...->v.
void count_color(int u, int v) {
    // echo(u, v);
    u = compress(u);
    while(level[u] > level[v]) {
        used.insert(get_edge(u, parent[u][0]));
        u = compress(u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, zz, i, u, v, ans;

    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        cin >> n;
        graph.assign(n, vi());
        bigraph.assign(n, vi());
        highest.assign(n, -1);
        used.clear();
        ans = 0;
        vector<vi> color(n+4, vi());
        for(i = 0; i < n-1; i++) {
            cin >> u >> v;
            u--; v--;
            bigraph[u].pb(v);
            bigraph[v].pb(u);
        }
        for(i = 0; i < n; i++) {
            cin >> u;
            color[u].pb(i);
        }
        root_graph(0, -1);
        build_lca(0);
        for(i = 0; i < n; i++) highest[i] = i;

        // echoarr(level);
        // echo2(graph);

        for(auto c : color) {
            if((int)c.size() <= 1) continue;
            u = -1;
            for(auto el : c) {
                if(u == -1) {u = el; continue;}
                int w = lca(u, el);
                count_color(u, w);
                count_color(el, w);
            }
        }
        // for(auto el : used) {
        //     echo("used", el);
        // }
        // ans = used.size();
        ans = n-1 - (int)used.size();
        cout << "Case #" << zz << ": " << ans << "\n";
    }


    return 0;
}

