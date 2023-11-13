vector<vi> graph;
class Toposort{
    vector<bool> visited;
    void topo_rec(int const u) {
        if(visited[u]) return;
        visited[u] = true;
        for(auto _v : graph[u]) topo_rec(_v);
        vSorted.pb(u);
    }
public:
    vi vSorted;
    Toposort(int const n) {
        visited.assign(n, false);
        for(int i = 0; i < n; i++) topo_rec(i);
        reverse(vSorted.begin(), vSorted.end());
    }
};

