//Return the vector of minimum distance between s to all other n nodes. -1 = INF
//u = (cost, next node), graph[u] = vector of (next node, cost)
vll dijkstra(ll s, ll n) {
    vll visited(n, -1);
    pll u;
    priority_queue<pll, vector<pll>, greater<pll>> p;
    p.push(mp(0, s));
    while(p.empty() == false) {
        u = p.top(); p.pop();
        if(visited[u.se] != -1) continue;
        visited[u.se] = u.fi;
        for(auto el : graph[u.se]) 
            p.push(mp(u.fi + el.se, el.fi));
    }
    return visited;
}

/* //Old implementation
vector<vector<pii>> graph; //graph[u] = mp(v, w) edge u -> v with weight w
int n;

void insert(int a, int b, int w) {
    graph[a].pb(mp(b, w));
}

vb visited;
//NO negative edges
int dijkstra(int s, int t) { //s = source != t = sink
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    priority_queue<pii> pq; // (- min cost, node)
    pii u;
    pq.push(mp(0, s));
    while(pq.empty() == false) {
        u = pq.top(); pq.pop();
        if(visited[u.se]) continue;
        visited[u.se] = true;
        if(u.se == t) return -u.fi;
        for(auto el : graph[u.se]) {
            pq.push(mp(u.fi - el.se, el.fi));
        }
    }
    return -1; //t not receable from s
}
*/
