class Node {
    public:
    int lvl = 0;
    int parent = -1;
    int subtree = 1; // Number of nodes in its subtree.
    int crawl_edge = -1; // id of the edge this -> parent.
    int chain_id = -1; // The id is the highest node in the chain.
};
class Edge {
    public:
    ll value = 0;
    int pos_st = -1; // Position in the base_st.
};
class HeavyLightDecomposition {
    vector<vector<pll>> graph;
    vector<Node> vn;
    vector<Edge> ve;
    vll base_st; // Values of the edges, splitted into chains..
    int cont_edge = 0;
    SegmentTree<ll> st;
    void dfs0(int const u, int const p) {
        vn[u].lvl = vn[p].lvl + 1;
        vn[u].parent = p;
        for(auto const& el : graph[u]) {
            if(el.fi == p) continue;
            dfs0(el.fi, u);
            vn[u].subtree += vn[el.fi].subtree;
        }
    }
    void dfs1(int const u, int const p, int const id) { // id of the chain.
        pll mx = {-1, -1};
        for(auto const& el : graph[u]) {
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
        for(auto const& el : graph[u]) {
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
        vn.assign(n, {});
        ve.assign(n, {});
    }
    void build() {
        dfs0(0, 0); // parent of root is root.
        vn[0].chain_id = 0;
        dfs1(0, 0, 0);
        st = SegmentTree<ll>(base_st);
    }
    void add_edge(int const u, int const v, ll const w) {
        graph[u].pb(mp(v, cont_edge));
        graph[v].pb(mp(u, cont_edge));
        ve[cont_edge].value = w;
        ++cont_edge;
    }
    ll query(int const u, int const v) { // Query in edges in path u -> v.
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
    void update(int const e, ll const w) {
        ve[e].value = w;
        st.update(ve[e].pos_st, w);
    }
};

