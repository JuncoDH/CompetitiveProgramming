// Minimum spanning tree in a bidirected graph.
// graph contains elements [0..n - 1], no extra space.
ll Kruskal(vector<vector<pii>> const& graph) {
    int n = graph.size();
    ll ans = 0;
    DSU dsu(n);
    vector<pair<ll, pii>> edge;
    for(int i = 0; i < n; ++i) {
        for(auto const& el : graph[i]) {
            if(i < el.fi) { // Only adds one edge.
                edge.pb({ el.se, { i, el.fi } });
            }
        }
    }
    sort(edge.begin(), edge.end());
    for(auto const& e : edge) {
        if(!dsu.is_connected(e.se.fi, e.se.se)) {
            dsu.merge(e.se.fi, e.se.se);
            ans += e.fi;
        }
    }
    if(dsu.number_components > 1) return -1;
    return ans;
}

