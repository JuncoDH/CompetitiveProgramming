const int MAX_N = 2e5+5;
const int MAX_LOG_N = 19;
int parent[MAX_N][MAX_LOG_N]; // Sparse table.
class LCA{ // LCA in O(log n), with O(n log n) preprocess.
    int n;
    vector<vi> graph;
    void dfs_lvl(int u, int p) {
        parent[u][0] = p;
        lvl[u] = lvl[p] + 1;
        for(auto v : graph[u]) {
            if(v == p) continue;
            dfs_lvl(v, u);
        }
    }
    public:
    int lvl[MAX_N];
    LCA() = default;
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
        v = get_parent(v, d);
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
    int get_parent(int u, int dst) { // Calculate the dst parent of u.
        dst = max(dst, 0);
        for(int i = 0; i < MAX_LOG_N; i++) {
            if(is_set(dst, i)) u = parent[u][i];
        }
        return u;
    }
};
vector<vi> graph;
vll a; // Values of the nodes.
// Calculate the xor of a path from u to v in a tree.
namespace xor_path{
    LCA lca;
    vll xor_root;
    void dfs_xor(int u, int p) {
        xor_root[u] = a[u];
        if(p != -1) xor_root[u] ^= xor_root[p];
        for(auto v : graph[u]) {
            if(v == p) continue;
            dfs_xor(v, u);
        }
    }
    void init(int n) {
        lca = LCA(graph);
        xor_root.assign(n, 0);
        dfs_xor(0, -1); // Rooted at 0.
    }
    ll calculate_xor(int u, int v) {
        return xor_root[u] ^ xor_root[v] ^ a[lca.lca(u, v)];
    }
}
// Calculate the sum of a path from u to v in a tree.
namespace sum_path{
    LCA lca;
    vll sum_root;
    void dfs_sum(int u, int p) {
        sum_root[u] = a[u];
        if(p != -1) sum_root[u] ^= sum_root[p];
        for(auto v : graph[u]) {
            if(v == p) continue;
            dfs_sum(v, u);
        }
    }
    void init(int n) {
        lca = LCA(graph);
        sum_root.assign(n, 0);
        dfs_sum(0, -1); // Rooted at 0.
    }
    ll calculate_sum(int u, int v) {
        int c = lca.lca(u, v);
        return sum_root[u] + sum_root[v] + a[c] - 2*sum_root[c];
    }
}

