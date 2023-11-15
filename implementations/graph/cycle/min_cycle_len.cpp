constexpr int MAX = 502;
vector<int> graph[MAX];
int visited[MAX];
int parent[MAX];
ll n;
// bfs(u) returns min_cycle len going thorugh u. O(V + E).
ll bfs(int u) {
    int u_ori = u;
    ll ans = inf;
    for(int i = 0; i < n; ++i) visited[i] = -1, parent[i] = -1;
    visited[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        u = q.front(); q.pop();
        for(auto const& e : graph[u]) {
            if(visited[e] != -1 || parent[u] == e) continue;
            visited[e] = visited[u] + 1;
            parent[e] = u;
            q.push(e);
        }
    }
    for(int i = 0; i < n; ++i) {
        if(i == u_ori) continue;
        for(auto const& e : graph[i]) {
            if(e == parent[i] || i == parent[e]) continue;
            ans = min(ans, (ll)visited[i] + visited[e] + 1);
        }
    }
    return ans;
}
// Return the minimum cycle len in the graph,
// or -1 if no cycle found. O(V * (V + E)).
ll min_cycle_len() {
    ll ans = inf;
    for(int i = 0; i < n; ++i) {
        ans = min(ans, bfs(i));
    }
    if(ans == inf) return -1;
    return ans;
}

