// v is an AP if removing v from graph it split into more than one component.
// 1- v is the root and v has > 1 child in the DFS.
// 2- v is not the root and has one child u that dont have any back edge.
ll n;
vector<vll> graph;
vll low; // Minimum discover time using a back edge.
vll discover; // Discover DFS time.
vll parent;
vector<bool> AP; // True iff i is an Articulation Point.
void init() {
    graph.assign(n, vll());
    low.assign(n, -1);
    discover.assign(n, -1);
    parent.assign(n, -1);
    AP.assign(n, false);
}
void dfs(int u) { // Call dfs(root).
    static int Time = 0;
    if(discover[u] != -1) return;
    low[u] = discover[u] = Time++;
    int children = 0;
    for(auto v : graph[u]) {
        if(discover[v] == -1) {
            children++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            // Every time you set AP[u] = true, the number of components after
            // removing the nodes u or v from the graph increase.
            if(parent[u] == -1 && children > 1) AP[u] = true;
            if(parent[u] != -1 && low[v] >= discover[u]) AP[u] = true;
            //if(low[v] > discover[u]) {} // edge u->v is a bridge.
        }
        if(v != parent[u]) low[u] = min(low[u], discover[v]); // Back edge.
    }
}

