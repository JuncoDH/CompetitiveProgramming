vector<vi> graph, tree;
void root_graph(int const root = 0, int const u = -1, int const p = -1) {
    if(u == -1) {
        tree.assign(graph.size(), vi());
        root_graph(root, root, -1);
        return;
    }
    for(auto const& v : graph[u]) {
        if(v == p) continue;
        tree[u].pb(v);
        root_graph(root, v, u);
    }
}

