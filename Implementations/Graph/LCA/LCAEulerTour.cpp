class EulerTour {
    vector<vi> graph;
    vi tour;
    vi lvl;
    vi first_ocurrence;
    SegmentTree<int> st;
    void dfs(int const u, int const p, int const _lvl) {
        first_ocurrence[u] = tour.size();
        tour.pb(u);
        lvl.pb(_lvl);
        for(auto v : graph[u]) {
            if(v == p) continue;
            dfs(v, u, _lvl + 1);
            tour.pb(u);
            lvl.pb(_lvl);
        }
    }
    public:
    EulerTour() = default;
    explicit EulerTour(vector<vi> const& _graph) {
        graph = _graph;
        first_ocurrence.assign(graph.size(), 0);
        dfs(0, -1, 0); // Rooted at 0.
        st = SegmentTree<int>(lvl);
    }
    int lca(int u, int v) const {
        u = first_ocurrence[u], v = first_ocurrence[v];
        if(u > v) swap(u, v);
        return tour[st.query(u, v).se.fi];
    }
    int dist(int u, int v) const {
        int w = first_ocurrence[lca(u, v)];
        u = first_ocurrence[u], v = first_ocurrence[v];
        return lvl[u] + lvl[v] - 2 * lvl[w];
    }
};

