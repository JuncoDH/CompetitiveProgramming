vector<vector<pll>> graph;
// Minimum spanning tree in a bidirected graph.
// graph contains elements [0..n-1], no extra space.
ll Prim(int const n) {
    ll ans = 0;
    vector<bool> visited(n, false);
    priority_queue<pll> pq; // (-cost, next node).
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        pq.push({0, i});
        while(!pq.empty()) {
            auto u = pq.top(); pq.pop();
            if(visited[u.se]) continue;
            visited[u.se] = true;
            ans += u.fi;
            for(auto const& el : graph[u.se]) {
                if(!visited[el.fi]) {
                    pq.push({-el.se, el.fi});
                }
            }
        }
    }
    return -ans;
}

