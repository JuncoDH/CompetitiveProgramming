vector<vector<pll>> graph;
// Minimum spanning tree in a bidirected graph.
// graph contains elements [0..n-1], no extra space.
ll Prim(int n) {
    ll i, ans = 0;
    vector<bool> visited(n, false);
    priority_queue<pll> pq; // (-cost, next node).
    pll u;
    for(i = 0; i < n; i++) {
        if(visited[i]) continue;
        pq.push(mp(0, i));
        while(!pq.empty()) {
            u = pq.top(); pq.pop();
            if(visited[u.se]) continue;
            visited[u.se] = true;
            ans += u.fi;
            for(auto el : graph[u.se]) {
                if(!visited[el.fi]) {
                    pq.push(mp(-el.se, el.fi));
                }
            }
        }
    }
    return -ans;
}

