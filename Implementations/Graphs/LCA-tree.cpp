const ll LOG_N = 20; //log2(MAX_N) + 4
const ll MAX_N = 1e5 + 3; //1e5, example
vector<vector<ll>> graph2, graph; //graph2 is the bidirectional and graph is the one you ask LCA
//---------------------------------------- LCA in a tree rooted at 0 ------------------------------------------------------------
int parent[LOG_N][MAX_N]; //parent[i][j] is the ancestor 2^i of node j. Is a sparse table
int level[MAX_N]; //depth of the node in the tree

//call dfs0(0, 0);
void dfs0(int u, int p) {
    parent[0][u] = p;
    for(auto v : graph[u]) {
        if(v == p) continue;
        level[v] = level[u] + 1;
        dfs0(v, u);
    }
}

//O(n log n)
void preprocess() {
    int i, j;
    dfs0(0, 0);
    for(i = 1; i < LOG_N; ++i) {
        for(j = 0; j < MAX_N; ++j) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
}

//rise b to the same level as a and continue moving up. O(log n)
int lca(int a, int b) {
    int i;

    if(level[a] > level[b]) swap(a, b);
    int d = level[b] - level[a];
    
    for(i = 0; i < LOG_N; ++i) {
        if((d >> i) & 1) b = parent[i][b];
    }
    if(a == b) return a;
    
    for(i = LOG_N - 1; i >= 0; --i) {
        if(parent[i][a] != parent[i][b])
            a = parent[i][a], b = parent[i][b];
    }
        
    return parent[0][a];
}

//distance between two nodes in a tree
int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u, v)];
}

//call dfs(0, -1) to root a tree at 0. the graph had to be bidirectional
vector<bool> visitedd;
void dfs(int x, int p) {
    if(visitedd[x]) return;
    visitedd[x] = true;
    if(p != -1) graph[p].pb(x);
    for(auto el : graph2[x]) {
        if(el == p) continue;
        dfs(el, x);
    }
}