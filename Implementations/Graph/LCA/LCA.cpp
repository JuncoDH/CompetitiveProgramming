const int MAX_N = 1e5+5;
const int MAX_LOG_N = 18;
int parent[MAX_N][MAX_LOG_N]; // Sparse table.
class LCA{ // LCA in O(log n), with O(n log n) preprocess.
    int n;
    vector<vi> graph;
    int lvl[MAX_N];
    void dfs_lvl(int u, int p) {
        parent[u][0] = p;
        lvl[u] = lvl[p] + 1;
        for(auto v : graph[u]) {
            if(v == p) continue;
            dfs_lvl(v, u);
        }
    }
    public:
    LCA(vector<vi> &_graph) {
        int i, j;
        graph = _graph;
        n = graph.size();
        lvl[0] = 0; // The root is 0.
        dfs_lvl(0, 0); // The parent of root is root.
        for(j = 1; j < MAX_LOG_N; j++) {
            for(i = 0; i < n; i++) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
    int lca(int u, int v) { // O(log n).
        if(lvl[u] > lvl[v]) swap(u, v);
        int i, d = lvl[v] - lvl[u];
        for(i = MAX_LOG_N - 1; i >= 0; i--) {
            if(is_set(d, i)) v = parent[v][i];
        }
        if(u == v) return u;
        for(i = MAX_LOG_N - 1; i >= 0; i--) {
            if(parent[u][i] != parent[v][i]) {
                u = parent[u][i], v = parent[v][i];
            }
        }
        return parent[u][0];
    }
    int dist(int u, int v) { // distance from u to v O(log n).
        return lvl[u] + lvl[v] - 2*lvl[lca(u, v)];
    }
};
