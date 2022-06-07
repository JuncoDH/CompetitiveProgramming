class IsDag {
    vector<vi> graph;
    vector<bool> visited;
    vi close_time; // Time when node is closed in dfs traversal.
    int tick; // Instead of time.
    void dfs(int u) {
        visited[u] = true;
        for(auto v : graph[u]) 
            if(!visited[v]) dfs(v);
        close_time[u] = tick++;
    }
    public:
    IsDag(int n) {graph.assign(n, vi());};
    IsDag(vector<vi> &_graph) {graph = _graph;}
    void add_edge(int u, int v) {graph[u].pb(v);}
    // A graph is a DAG iff the graph don't have back edges.
    bool is_dag() { // Isolated points are a DAG.
        int u, n = graph.size();
        visited.assign(n, false);
        close_time.assign(n, 0);
        tick = 0;
        for(u = 0; u < n; u++)
            if(!visited[u]) dfs(u);
        for(u = 0; u < n; u++)
            for(auto v : graph[u])
                if(close_time[u] < close_time[v])
                    return false;
        return true;
    }
};

