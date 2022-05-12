vector<vi> graph, rooted_graph;
void root_graph(int root, int u = -1, int p = -1) {
    if(u == -1) {
        rooted_graph.assign(graph.size(), vi());
        root_graph(root, root, -1);
        return;
    }
    for(auto v : graph[u]) {
        if(v == p) continue;
        rooted_graph[u].pb(v);
        root_graph(root, v, u);
    }
}

