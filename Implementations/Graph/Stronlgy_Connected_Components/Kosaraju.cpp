class Kosaraju{ // O(n). x2 times slower than Tarjan.
    vi s; // Stack.
    vector<vi> graph, graphT;
    vector<bool> visited;
    void dfs1(int u) {
        visited[u] = true;
        for(auto v : graph[u])
            if(!visited[v]) dfs1(v);
        s.pb(u);
    } // Add to the current component.
    void dfs2(int u) {
        visited[u] = true;
        for(auto v : graphT[u])
            if(!visited[v]) dfs2(v); 
        components.back().pb(u); 
    }
    public: // Strong Connected Components.
    vector<vi> components;
    Kosaraju(vector<vi> &_graph) {
        graph = _graph;
        int i, n = graph.size();
        visited.assign(n, false);
        for(i = 0; i < n; i++)
            if(!visited[i]) dfs1(i);
        graphT.assign(n, vi());
        for(i = 0; i < n; i++) 
            for(auto v : graph[i])
                graphT[v].pb(i);
        visited.assign(n, false);
        while(true) {
            while(!s.empty() && visited[s.back()]) s.pop_back();
            if(s.empty()) break;
            components.pb(vi());
            dfs2(s.back());
        }
    }
};

