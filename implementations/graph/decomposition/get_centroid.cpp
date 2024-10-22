vector<vi> graph;
vi subtree;
void dfs_centroid_subtree(int const u, int const p) {
    subtree[u] = 1;
    for(auto const& v : graph[u]) {
        if(v == p) continue;
        dfs_centroid_subtree(v, u);
        subtree[u] += subtree[v];
    }
}
int dfs_centroid(int const u, int const p, int const n) {
    for(auto const& v : graph[u]) {
        if(v != p && subtree[v] > n / 2)
            return dfs_centroid(v, u, n);
    }
    return u;
} // Get one of the centroids of the tree in O(n).
int get_centroid() {
    int n = graph.size();
    subtree.assign(n, 0);
    dfs_centroid_subtree(0, -1);
    return dfs_centroid(0, -1, n);
}

