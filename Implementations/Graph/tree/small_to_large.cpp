vector<vi> graph;
vll a; // Values of the nodes.
// O(n log n) insert small sets into bigger ones.
namespace small_to_large {
    ll ans = 0;
    vector<set<ll>> vs; // Assign size n. set adds another log n factor.
    void dfs_small_to_large(int u, int p) {
        bool ok_clear = false; // true if you dont want to upscale the node.
        vs[u].insert(xor_path::calculate_xor(u, 0)); // Change.
        for(auto v : graph[u]) {
            if(v == p) continue;
            dfs_small_to_large(v, u);
            if(ok_clear || vs[v].empty()) continue;
            if(vs[u].size() < vs[v].size()) swap(vs[u], vs[v]);
            for(auto el : vs[v]) {
                if(vs[u].count(el ^ a[u])) { // Change.
                    ok_clear = true;
                    break;
                }
            }
            if(ok_clear) continue;
            for(auto el : vs[v]) vs[u].insert(el); 
        }
        if(ok_clear) {
            ans++;
            vs[u].clear();
        }
    }
    void init(int n) {
        ans = 0;
        vs.assign(n, set<ll>());
        dfs_small_to_large(0, -1);
    }
}

