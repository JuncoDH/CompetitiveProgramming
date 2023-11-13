vector<vll> graph; // TREE graph, with nodes [0..n-1].
vi dist;
// Fills dist vector.
void dfs_dist(int const u, int const p) {
    for(auto const& v : graph[u]) {
        if(v == p) continue;
        dist[v] = dist[u] + 1;
        dfs_dist(v, u);
    }
}
// Return the diameter and a pii of initial and end of the diameter path.
// One diameter path is the furthest node of the furthest node of node 0.
pair<int, pii> get_diameter() {
    int maxn = graph.size(), u;
    dist.assign(maxn, -1);
    dist[0] = 0;
    dfs_dist(0, -1);
    u = max_element(dist.begin(), dist.end()) - dist.begin();
    dist[u] = 0;
    dfs_dist(u, -1);
    auto it = max_element(dist.begin(), dist.end());
    return mp(*it, mp(u, it - dist.begin()));
}
vi parent;
// Fills parent vector.
void dfs_parent(int const u, int const p) {
    parent[u] = p;
    for(auto const& v : graph[u]) {
        if(v == p) continue;
        dfs_parent(v, u);
    }
}
// Return in a vector the diameter path.
vi get_diameter_vector() {
    int u, v, maxn = graph.size();
    pair<int, pii> diameter = get_diameter();
    vi ans;
    u = diameter.se.fi;
    v = diameter.se.se;
    parent.assign(maxn, 0);
    dfs_parent(u, -1);
    while(v != -1) {
        ans.pb(v);
        v = parent[v];
    }
    return ans;
}

