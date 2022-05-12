vector<pair<pii, ll>> edge; // ((u, v), w): u->v with cost w. Negative costs allowed.
ll n; // Number of nodes.
vll dist; // Min dist from s to all other nodes.
// O(V*E) return true iff there exists a negative cycle.
bool bellman_ford(int s) {
    ll i;
    dist.assign(n, inf);
    dist[s] = 0;
    for(i = 0; i < n - 1; i++) { // Iterate n - 1 times.
        for(auto e : edge) {
            if(dist[e.fi.fi] != inf)
                dist[e.fi.se] = min(dist[e.fi.se], dist[e.fi.fi] + e.se);
        }
    }
    for(auto e : edge) { // If you can relax one more time any node, there exists a negative cycle.
        if(dist[e.fi.fi] != inf)
            if(dist[e.fi.se] > dist[e.fi.fi] + e.se) return true;
    }
    return false;
}

