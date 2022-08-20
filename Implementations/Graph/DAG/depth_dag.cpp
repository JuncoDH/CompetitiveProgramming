vector<vi> graph;
namespace DepthDAG{ // Also longest path in a DAG.
    vi depth; // Depth from node to one leaf. Leafs are depth 0.
    void dfs_get_depth(int u) {
        if(depth[u] != -1) return;
        depth[u] = 0;
        for(auto v : graph[u]) {
            dfs_get_depth(v);
            depth[u] = max(depth[u], 1 + depth[v]);
        }
    }
    void get_depth() {
        int n = graph.size();
        depth.assign(n, -1);
        for(int i = 0; i < n; i++) 
            dfs_get_depth(i);
    }
};

