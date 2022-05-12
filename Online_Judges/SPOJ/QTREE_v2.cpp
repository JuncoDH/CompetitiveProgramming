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


// Point update and Range query.
template<typename T>
class SegmentTree {
    vector<T> t, v;
    int n;
    T f(T a, T b) { // The function of the query. __gcd, +, |, &, max, min.
        return max(a, b);
    }
    void build(int k, int l, int r) {
        if(l == r) {t[k] = v[l]; return;}
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid + 1, r);
        t[k] = f(t[k<<1], t[k<<1|1]);
    }
    void update(int k, int l, int r, int p, T x) {
        if(l == r) {t[k] = x; return;}
        int mid = (l + r) >> 1;
        if(p <= mid) update(k<<1, l, mid, p, x);
        else update(k<<1|1, mid+1, r, p, x);
        t[k] = f(t[k<<1], t[k<<1|1]);
    }
    T query(int k, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return t[k];
        int mid = (l + r) >> 1;
        if(qr <= mid) return query(k<<1, l, mid, ql, qr);
        if(mid+1 <= ql) return query(k<<1|1, mid + 1, r, ql, qr);
        T qa = query(k<<1, l, mid, ql, qr);
        T qb = query(k<<1|1, mid + 1, r, ql, qr);
        return f(qa, qb);
    }
    public:
    SegmentTree() = default;
    SegmentTree(vector<T> &_v) {
        v = _v;
        n = v.size();
        t.assign(4*n, 0);
        build(1, 0, n-1);
    }
    void update(int p, T x) {
        update(1, 0, n-1, p, x);
    } // [ql, qr].
    T query(int ql, int qr) {
        return query(1, 0, n-1, ql, qr);
    }
};
class node{
    public:
    int lvl = 0;
    int parent = -1;
    int subtree = 1; // Number of nodes in its subtree.
    int crawl_edge = -1; // id of the edge this -> parent.
    int chain_id = -1; // The id is the highest node in the chain.
};
class edge{
    public:
    ll value = 0;
    int pos_st = -1; // Position in the base_st. 
};
class HeavyLightDecomposition{
    vector<vector<pll>> graph;
    vector<node> vn;
    vector<edge> ve;
    vll base_st; // Values of the edges, splitted into chains..
    int cont_edge = 0;
    SegmentTree<ll> st;
    void dfs0(int u, int p) {
        vn[u].lvl = vn[p].lvl + 1;
        vn[u].parent = p;
        for(auto el : graph[u]) {
            if(el.fi == p) continue;
            dfs0(el.fi, u);
            vn[u].subtree += vn[el.fi].subtree;
        }
    }
    void dfs1(int u, int p, int id) { // id of the chain.
        pll mx = mp(-1, -1);
        for(auto el : graph[u]) {
            if(el.fi == p) continue;
            if(mx.fi == -1 || vn[el.fi].subtree > vn[mx.fi].subtree)
                mx = el;
        }
        if(mx.fi == -1) return;
        ve[mx.se].pos_st = base_st.size(); // Continue chain.
        base_st.pb(ve[mx.se].value);
        vn[mx.fi].crawl_edge = mx.se;
        vn[mx.fi].chain_id = id;
        dfs1(mx.fi, u, id);
        for(auto el : graph[u]) {
            if(el.fi == p || el.fi == mx.fi) continue;
            ve[el.se].pos_st = base_st.size(); // New chain.
            base_st.pb(ve[el.se].value);
            vn[el.fi].crawl_edge = el.se;
            vn[el.fi].chain_id = el.fi;
            dfs1(el.fi, u, el.fi);
        }
    }
    ll query_same_chain(int u, int v) {
        if(u == v) return -inf; // MAX query.
        if(vn[u].lvl > vn[v].lvl) swap(u, v);
        int tmp = ve[vn[v].crawl_edge].pos_st;
        return st.query(tmp - (vn[v].lvl - vn[u].lvl - 1), tmp);
    }
    public:
    HeavyLightDecomposition(int n) {
        graph.assign(n, vector<pll>());
        vn.assign(n, node());
        ve.assign(n, edge());
    }
    void build() {
        dfs0(0, 0); // parent of root is root.
        vn[0].chain_id = 0;
        dfs1(0, 0, 0);
        st = SegmentTree<ll>(base_st);
    }
    void add_edge(int u, int v, ll w) {
        graph[u].pb(mp(v, cont_edge));
        graph[v].pb(mp(u, cont_edge));
        ve[cont_edge].value = w;
        cont_edge++;
    }
    ll query(int u, int v) { // Query in edges in path u -> v.
        ll ans = -inf; // MAX Query.
        if(u == v) return ans;
        if(vn[u].lvl > vn[v].lvl) swap(u, v);
        if(vn[u].chain_id == vn[v].chain_id)
            return query_same_chain(u, v);
        // Go up the lowest chain.
        if(vn[vn[u].chain_id].lvl > vn[vn[v].chain_id].lvl) swap(u, v);
        ans = max(ans, query_same_chain(vn[v].chain_id, v));
        int light = ve[vn[vn[v].chain_id].crawl_edge].pos_st;
        ans = max(ans, st.query(light, light)); // Light edge.
        ans = max(ans, query(u, vn[vn[v].chain_id].parent));
        return ans;
    }
    void update(int e, ll w) {
        ve[e].value = w;
        st.update(ve[e].pos_st, w);
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, n, i, u, v, w;
    string s;

    cin >> tt;
    while(tt--) {
        cin >> n;
        HeavyLightDecomposition hld(n);
        for(i = 0; i < n-1; i++) {
            cin >> u >> v >> w;
            u--; v--;
            hld.add_edge(u, v, w);
        }
        hld.build();
        while(true) {
            cin >> s;
            if(s == "DONE") break;
            cin >> u >> v;
            if(s == "QUERY") {
                u--; v--;
                cout << hld.query(u, v) << "\n";
            } else {
                u--;
                hld.update(u, v);
            }
        }
        if(tt > 0) cout << "\n";
    }


    return 0;
}



