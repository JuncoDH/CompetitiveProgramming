#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))

#ifdef GREMIO_DEBUG
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
void ECHO(bool _s){cout<<_s;}
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

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 10005;
map<int, int> graph2[MAX_N];
vector<pii> graph[MAX_N];
vll base_st;
int n, cont_edge; // size of graph, and ith edge

struct nodes {
    int level;
    int parent;
    int subtree;
    int crawl_edge; //edge id to dfs0 parent
    int chain_id;
} node[MAX_N];

struct edges {
    ll value;
    int pos_st;
} edge[MAX_N];

void add_edge(int u, int v, ll w) {
    graph2[u][v] = cont_edge;
    graph2[v][u] = cont_edge;
    edge[cont_edge].value = w;
    cont_edge++;
}

ll HLD_function(ll ans1, ll ans2) {
    return max(ans1, ans2);
}

class SegmentTree {
    vll tree;
    vll v;
    int n;
    void build(int k, int l, int r) {
        if(l == r) {tree[k] = v[l]; return;}
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid+1, r);
        tree[k] = HLD_function(tree[k<<1], tree[k<<1|1]);
    }
    ll query(int k, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return tree[k];
        if(qr < l || r < ql) return -inf; //MAX segtree
        int mid = (l+r)>>1;
        ll a = query(k<<1, l, mid, ql, qr);
        ll b = query(k<<1|1, mid+1, r, ql, qr);
        return HLD_function(a, b);
    }
    void update(int k, int l, int r, int pos, ll dx) {
        if(pos < l || r < pos) return;
        if(l == r) {tree[k] = dx; return;} //set the weight of the edge
        int mid = (l+r)>>1;
        update(k<<1, l, mid, pos, dx);
        update(k<<1|1, mid+1, r, pos, dx);
        tree[k] = HLD_function(tree[k<<1], tree[k<<1|1]);
    }
    public:
    SegmentTree() {} //empty
    SegmentTree(vll &_v) {
        v = _v;
        n = v.size();
        tree.assign(4*n, 0);
        build(1, 0, n-1);
    }
    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    } 
    void update(int pos, ll dx) {
        update(1, 0, n-1, pos, dx);
    }
} st;

void dfs0(int u, int p, int dep) { //create graph and fill node, call dfs(0, -1, 0)
    node[u].level = dep;
    node[u].parent = p;
    node[u].subtree = 1;
    for(auto el : graph2[u]) {
        if(el.fi == p) continue;
        graph[u].pb(el); 
        dfs0(el.fi, u, dep+1);
        node[u].subtree += node[el.fi].subtree;
    }
}

void dfs1(int u, int id) { // call dfs1(0, 0)
    int nu = graph[u].size(), i, imx = 0;
    if(!nu) return;
    for(i = 0; i < nu; i++) {
        if(node[graph[u][i].fi].subtree > node[graph[u][imx].fi].subtree) imx = i;
    }
    edge[graph[u][imx].se].pos_st = base_st.size(); // continue chain
    base_st.pb(edge[graph[u][imx].se].value);
    node[graph[u][imx].fi].crawl_edge = graph[u][imx].se; 
    node[graph[u][imx].fi].chain_id = id;
    dfs1(graph[u][imx].fi, id);

    for(i = 0; i < nu; i++) {
        if(i == imx) continue;
        edge[graph[u][i].se].pos_st = base_st.size(); //new chain
        base_st.pb(edge[graph[u][i].se].value);
        node[graph[u][i].fi].crawl_edge = graph[u][i].se;
        node[graph[u][i].fi].chain_id = graph[u][i].fi;
        dfs1(graph[u][i].fi, graph[u][i].fi);

    }
}

void HLD_preprocess() {
    dfs0(0, -1, 0);
    dfs1(0, 0);
    st = SegmentTree(base_st);
}
ll query_same_chain(int u, int v) {
    if(u == v) return -inf; //MAX QUERY
    if(node[u].level > node[v].level) swap(u, v); //lvl u higher than v
    int tmp = edge[node[v].crawl_edge].pos_st;
    return st.query(tmp - (node[v].level - node[u].level - 1), tmp);
    //echo("q", u, v, tmp - (node[v].level - node[u].level - 1), tmp);
}
ll query(int u, int v) {
    ll ans = -inf; 
    if(u == v) return ans;
    //echo(u, v);
    if(node[u].level > node[v].level) swap(u, v); 
    if(node[u].chain_id == node[v].chain_id) {
        return query_same_chain(u, v);
    }
    if(node[node[u].chain_id].level > node[node[v].chain_id].level) swap(u, v); //chain of v finish first
    ans = HLD_function(ans, query_same_chain(node[v].chain_id, v)); // v crawl
    int light = edge[node[node[v].chain_id].crawl_edge].pos_st;
    ans = HLD_function(ans, st.query(light, light)); // light edge
    ans = HLD_function(ans, query(u, node[node[v].chain_id].parent)); // the rest of the problem
    return ans;
}

void update(int u, int v, ll w) {
    int e = graph2[u][v];
    st.update(edge[e].pos_st, w);
}
void update(int e, ll w) {
    st.update(edge[e].pos_st, w);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    /*n = 15;
    add_edge(0, 1, 0); //TO START AT 0
    add_edge(1, 2, 13);
    add_edge(1, 3, 9);
    add_edge(1, 4, 23);
    add_edge(2, 5, 4);
    add_edge(2, 6, 25);
    add_edge(6, 8, 5);
    add_edge(8, 10, 1);
    add_edge(8, 11, 6);
    add_edge(3, 7, 29);
    add_edge(7, 9, 30);


    preprocess_HLD();
    echo(base_st);

    update(6, 2, 33);
    update(7, 9, 21);
    update(9, 7, 20);
    update(10, 8, 3);

    echo(query(1, 5));
    echo(query(5, 5));
    echo(query(5, 5));
    echo(query(7, 4));
    echo(query(10, 7));
    echo(query(11, 1));
    echo(query(9, 7));*/
    //echo(query(9, 11));
    //query(9, 11);
    ll tt, i, u, v, w;
    string s;

    cin >> tt;
    while(tt--) {
        cin >> n;
        for(i = 0; i <= n; i++) {
            graph2[i].clear();
            graph[i].clear();
            node[i] = nodes();
            edge[i] = edges();
        }
        cont_edge = 0;
        base_st.clear();
        for(i = 0; i < n-1; i++) {
            cin >> u >> v >> w;
            u--; v--;
            add_edge(u, v, w);
        }
        HLD_preprocess();
        while(true) {
            cin >> s;
            if(s == "DONE") break;
            if(s == "QUERY") {
                cin >> u >> v;
                u--; v--;
                ll ans = query(u, v);
                if(ans == -inf) exit(-1);
                cout << ans << "\n";
            } else {
                cin >> u >> v;
                u--;
                update(u, v);
            }
        }
        if(tt > 0) cout << "\n";
    }


    return 0;
}
