vector<vi> graph;
namespace IsDag {
    vector<bool> visited;
    vi close_time; // Time when node is closed in dfs traversal.
    int tick; // Instead of time.
    void dfs(int const u) {
        visited[u] = true;
        for(auto const& v : graph[u])
            if(!visited[v]) dfs(v);
        close_time[u] = tick++;
    }
    // A graph is a DAG iff the graph don't have back edges.
    bool is_dag() { // Isolated points are a DAG.
        int u, n = graph.size();
        visited.assign(n, false);
        close_time.assign(n, 0);
        tick = 0;
        for(u = 0; u < n; u++)
            if(!visited[u]) dfs(u);
        for(u = 0; u < n; u++)
            for(auto const& v : graph[u])
                if(close_time[u] < close_time[v])
                    return false;
        return true;
    }
}

