vector<vector<pll>> graph;
// Return the vector of minimum distance between s to all other n nodes. inf means unrecheable.
// u = (cost, next node), graph[u] = vector of (next node, cost).
vll dijkstra(ll s) { // Negative edges NOT allowed.
    priority_queue<pll, vector<pll>, greater<pll>> p;
    vll dist(graph.size(), inf);
    pll u;
    p.push({0, s});
    while(p.empty() == false) {
        u = p.top(); p.pop();
        if(dist[u.se] != inf) continue;
        dist[u.se] = u.fi;
        for(auto const& el : graph[u.se]) {
            if(dist[el.fi] != inf) continue;
            p.push({ u.fi + el.se, el.fi });
        }
    }
    return dist;
}

