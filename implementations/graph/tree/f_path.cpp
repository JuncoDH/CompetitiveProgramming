vector<vi> graph;
vll a; // Values of the nodes.
// Calculate the xor of a path from u to v in a tree.
namespace xor_path {
    LCA lca;
    vll xor_root;
    void dfs_xor(int const u, int const p) {
        xor_root[u] = a[u];
        if(p != -1) xor_root[u] ^= xor_root[p];
        for(auto const& v : graph[u]) {
            if(v == p) continue;
            dfs_xor(v, u);
        }
    }
    void init(int const n) {
        lca = LCA(graph);
        xor_root.assign(n, 0);
        dfs_xor(0, -1); // Rooted at 0.
    }
    ll calculate_xor(int const u, int const v) {
        return xor_root[u] ^ xor_root[v] ^ a[lca.lca(u, v)];
    }
}
// Calculate the sum of a path from u to v in a tree.
namespace sum_path {
    LCA lca;
    vll sum_root;
    void dfs_sum(int const u, int const p) {
        sum_root[u] = a[u];
        if(p != -1) sum_root[u] ^= sum_root[p];
        for(auto const& v : graph[u]) {
            if(v == p) continue;
            dfs_sum(v, u);
        }
    }
    void init(int const n) {
        lca = LCA(graph);
        sum_root.assign(n, 0);
        dfs_sum(0, -1); // Rooted at 0.
    }
    ll calculate_sum(int const u, int const v) {
        int c = lca.lca(u, v);
        return sum_root[u] + sum_root[v] + a[c] - 2 * sum_root[c];
    }
}

