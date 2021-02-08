// Return the vector of minimum distance between s to all other n nodes. -1 = INF.
// u = (cost, next node), graph[u] = vector of (next node, cost).
vll dijkstra(ll s, ll n) {
    vll visited(n, -1);
    pll u;
    priority_queue<pll, vector<pll>, greater<pll>> p;
    p.push(mp(0, s));
    while(p.empty() == false) {
        u = p.top(); p.pop();
        if(visited[u.se] != -1) continue;
        visited[u.se] = u.fi;
        for(auto el : graph[u.se]) {
            if(visited[el.fi] != -1) continue; // Prune.
            p.push(mp(u.fi + el.se, el.fi));
        }
    }
    return visited;
}
