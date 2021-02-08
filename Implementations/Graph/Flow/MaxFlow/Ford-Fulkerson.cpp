const int MAX = 40;
// RESET FOR EVERY TEST CASE. ALSO THE GRAPH WILL BE DESTROYED.
int graph[MAX][MAX];
set<int> ady_graph[MAX]; // Adjacency list (set) to reduce O(MAX_FLOW*V^2) -> O(MAX_FLOW*E).
int number_nodes = MAX; // Number of real nodes in the graph.
vi parent;

void reset() {
    int i, j;
    for(i = 0; i < MAX; i++) {
        ady_graph[i].clear();
        for(j = 0; j < MAX; j++) graph[i][j] = 0;
    }
}

void add_edge(int u, int v, int w) {
    graph[u][v] += w; // Accumulative edges.
    ady_graph[u].insert(v);
}

bool BFS(int s, int t) {
    vector<bool> visited(number_nodes, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto v : ady_graph[u]) {
            if(!visited[v] && graph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                if(v == t) return true;
                q.push(v);
            }
        }
    }    
    return false;
}
// Ford Fulkerson algorithm for the max flow. O(MAX_FLOW*E).
// source s to sink t.
int max_flow(int s, int t) {
    int ans = 0, v;
    int m; // The lowest edge founded in the BFS.
    parent.assign(number_nodes, -1);
    while(BFS(s, t)) {
        m = INT_MAX;
        for(v = t; v != s; v = parent[v]) {
            m = min(m, graph[parent[v]][v]);
        }
        ans += m;
        for(v = t; v != s; v = parent[v]) {
            if(graph[parent[v]][v] == m) ady_graph[parent[v]].erase(v); 
            graph[parent[v]][v] -= m;
            if(graph[v][parent[v]] == 0) ady_graph[v].insert(parent[v]);
            graph[v][parent[v]] += m;
        }
    }
    return ans;
}
