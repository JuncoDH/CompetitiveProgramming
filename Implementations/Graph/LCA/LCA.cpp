constexpr int MAX_N = 1e5+5;
constexpr int MAX_LOG_N = 18;
int parent[MAX_N][MAX_LOG_N]; // Sparse table.
class LCA{ // LCA in O(log n), with O(n log n) preprocess.
    int n = 0;
    vector<vi> graph;
    void dfs_lvl(int const u, int const p) {
        parent[u][0] = p;
        lvl[u] = lvl[p] + 1;
        for(auto const& v : graph[u]) {
            if(v == p) continue;
            dfs_lvl(v, u);
        }
    }
    public:
    int lvl[MAX_N] = { 0 };
    LCA() = default;
    explicit LCA(vector<vi> const& _graph) {
        graph = _graph;
        n = graph.size();
        lvl[0] = 0; // The root is 0.
        dfs_lvl(0, 0); // The parent of root is root.
        for(int j = 1; j < MAX_LOG_N; j++) {
            for(int i = 0; i < n; i++) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
    int lca(int u, int v) const { // O(log n).
        if(lvl[u] > lvl[v]) swap(u, v);
        int i, d = lvl[v] - lvl[u];
        v = get_parent(v, d);
        if(u == v) return u;
        for(i = MAX_LOG_N - 1; i >= 0; i--) {
            if(parent[u][i] != parent[v][i]) {
                u = parent[u][i], v = parent[v][i];
            }
        }
        return parent[u][0];
    }
    int dist(int const u, int const v) const { // Distance from u to v O(log n).
        return lvl[u] + lvl[v] - 2*lvl[lca(u, v)];
    }
    static int get_parent(int u, int dst) { // Calculate the dst parent of u.
        dst = max(dst, 0);
        for(int i = 0; i < MAX_LOG_N; i++) {
            if(is_set(dst, i)) u = parent[u][i];
        }
        return u;
    }
};

