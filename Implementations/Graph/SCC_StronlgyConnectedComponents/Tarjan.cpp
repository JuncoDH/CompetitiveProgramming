vector<vi> graph;
class Tarjan { // O(n) SCC.
    vi discover;
    vi low;
    vector<bool> onStack;
    vi s;
    int time = 0;
    void dfs(int const u) {
        low[u] = discover[u] = time++;
        onStack[u] = true;
        s.pb(u);
        for(auto const& v : graph[u]) {
            if(discover[v] == -1) dfs(v);
            if(onStack[v]) low[u] = min(low[u], low[v]);
        }
        if(low[u] == discover[u]) { // Head SCC node.
            while(true) {
                int v = s.back(); s.pop_back();
                components.back().pb(v);
                onStack[v] = false;
                if(u == v) break;
            }
            components.pb({});
        }
    }
    public:
    vector<vi> components;
    Tarjan() {
        int n = graph.size();
        discover.assign(n, -1);
        low.assign(n, -1);
        onStack.assign(n, false);
        components.pb({});
        for(int i = 0; i < n; ++i)
            if(discover[i] == -1) dfs(i);
        components.pop_back();
    }
};

