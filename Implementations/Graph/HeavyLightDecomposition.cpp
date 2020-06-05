const int MAX_N = 10005; // MAX number of nodes ~ edges
map<int, int> graph2[MAX_N]; // input bidirectional weighted graph
vector<pii> graph[MAX_N]; // graph built by dfs0, unidirectional
vll base_st; // the base of the segment tree
int n, cont_edge; // size of graph, and the number of edges

struct nodes {
    int level; // level of the dfs0
    int parent; // parent of the dfs0
    int subtree; // size of the subtree rooted at i
    int crawl_edge; // edge id, i -> dfs0 parent
    int chain_id; // id of the current edge
} node[MAX_N];

struct edges {
    ll value; // initial value of the edge
    int pos_st; // it's position in the base_st
} edge[MAX_N];

void add_edge(int u, int v, ll w) {
    graph2[u][v] = cont_edge;
    graph2[v][u] = cont_edge;
    edge[cont_edge].value = w;
    cont_edge++;
}

ll HLD_function(ll ans1, ll ans2) { // max of the edges in the path from u->v
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
        if(qr < l || r < ql) return -inf; // MAX segtree
        int mid = (l+r)>>1;
        ll a = query(k<<1, l, mid, ql, qr);
        ll b = query(k<<1|1, mid+1, r, ql, qr);
        return HLD_function(a, b);
    }
    void update(int k, int l, int r, int pos, ll dx) {
        if(pos < l || r < pos) return;
        if(l == r) {tree[k] = dx; return;} // set the weight of the edge
        int mid = (l+r)>>1;
        update(k<<1, l, mid, pos, dx);
        update(k<<1|1, mid+1, r, pos, dx);
        tree[k] = HLD_function(tree[k<<1], tree[k<<1|1]);
    }
    public:
    SegmentTree() {} // empty
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

void dfs0(int u, int p, int dep) { // create graph and fill node, call dfs(0, -1, 0)
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
void dfs1(int u, int id) { // call dfs1(0, 0), is the actual HLD. id is the current chain id
    int nu = graph[u].size(), i, imx = 0;
    if(!nu) return;
    for(i = 0; i < nu; i++) { // imx is the heavy son
        if(node[graph[u][i].fi].subtree > node[graph[u][imx].fi].subtree) imx = i;
    }
    edge[graph[u][imx].se].pos_st = base_st.size(); // continue chain
    base_st.pb(edge[graph[u][imx].se].value);
    node[graph[u][imx].fi].crawl_edge = graph[u][imx].se; 
    node[graph[u][imx].fi].chain_id = id;
    dfs1(graph[u][imx].fi, id);

    for(i = 0; i < nu; i++) {
        if(i == imx) continue;
        edge[graph[u][i].se].pos_st = base_st.size(); // new chain
        base_st.pb(edge[graph[u][i].se].value);
        node[graph[u][i].fi].crawl_edge = graph[u][i].se;
        node[graph[u][i].fi].chain_id = graph[u][i].fi;
        dfs1(graph[u][i].fi, graph[u][i].fi);
    }
}
void HLD_preprocess() { // call when graph2 is , before queries and updates
    dfs0(0, -1, 0);
    dfs1(0, 0);
    st = SegmentTree(base_st);
}
ll query_same_chain(int u, int v) { // don't call this query
    if(u == v) return -inf; // MAX QUERY
    if(node[u].level > node[v].level) swap(u, v); //lvl u higher than v
    int tmp = edge[node[v].crawl_edge].pos_st;
    return st.query(tmp - (node[v].level - node[u].level - 1), tmp);
}
ll query(int u, int v) { // HLD_function of edge in the path from u->v
    ll ans = -inf; 
    if(u == v) return ans;
    if(node[u].level > node[v].level) swap(u, v); 
    if(node[u].chain_id == node[v].chain_id) { // same chain
        return query_same_chain(u, v);
    } // go up one chain, the one that finish at lower level
    if(node[node[u].chain_id].level > node[node[v].chain_id].level) swap(u, v); // chain of v finish first
    ans = HLD_function(ans, query_same_chain(node[v].chain_id, v)); // v crawl
    int light = edge[node[node[v].chain_id].crawl_edge].pos_st;
    ans = HLD_function(ans, st.query(light, light)); // light edge
    ans = HLD_function(ans, query(u, node[node[v].chain_id].parent)); // the rest of the problem
    return ans;
}
void update(int u, int v, ll w) { // weight of edge u->v now is w
    int e = graph2[u][v];
    st.update(edge[e].pos_st, w);
}
void update(int e, ll w) { // weight of e edge (0-index) now is w
    st.update(edge[e].pos_st, w);
}
