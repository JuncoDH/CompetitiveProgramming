const int MAX_N = 1e5 + 5;
const int MAX_LOG_N = 18;
int n;
vector<vi> graph; // Directed graph, allways reserve memory for it.
vector<vi> bigraph; // Undirected graph, reserve memory only if needed.

int level[MAX_N]; // level of the node rooted.
int parent[MAX_N][MAX_LOG_N]; // parent[i][j] is the parent 2^j of the node i.

vector<bool> visited_bigraph;
// root_graph(u, -1) roots the bigraph at node u.
void root_graph(int u, int p) {
    if(p == -1) visited_bigraph.assign(n, false);
    for(auto v : bigraph[u]) {
        if(v == p) continue;
        graph[u].pb(v);
        root_graph(v, u);
    }
}

// Calcule the level and parent 1. Don't call.
void dfs_level(int u, int p) {
    parent[u][0] = p;
    level[u] = level[p] + 1;
    for(auto v : graph[u]) {
        if(v == p) continue;
        dfs_level(v, u);
    }
}
// Builds the LCA.
void build_lca(int root) {
    int i, j;
    level[root] = -1;
    dfs_level(root, root); // The parent of the root is itself.
    for(j = 1; j < MAX_LOG_N; j++) {
        for(i = 0; i < MAX_N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}
// Calculates the LCA(u, v) in O(log n).
int lca(int u, int v) {
    if(level[u] > level[v]) swap(u, v);
    int i, d = level[v] - level[u];
    for(i = MAX_LOG_N - 1; i >= 0; i--) {
        if(is_set(d, i)) v = parent[v][i];
    }
    if(u == v) return u;
    for(i = MAX_LOG_N - 1; i >= 0; i--) {
        if(parent[u][i] != parent[v][i]) 
            u = parent[u][i], v = parent[v][i];
    }
    return parent[u][0];
}
// Calculates the distance(u, v) in a tree in O(log n).
int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u, v)];
}
