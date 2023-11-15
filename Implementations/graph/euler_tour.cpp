// Euler circuit, visit all edges once.
// Condition: for every node in-degree = out-degree.
// All edges are in the same SCC (connected).
// For a Euler path the condition is all nodes in-degree = out-degree,
// one out-degree + 1 = in-degree (start with this node) and one out-degree = in-degree + 1.
vi euler_tour;
void hierholzer(int const u) {
    while(!graph[u].empty()) {
        int v = graph[u].back();
        graph[u].pop_back(); // DESTROYS THE GRAPH.
        hierholzer(v);
    }
    euler_tour.pb(u);
}
void f_euler_tour() {
    hierholzer(0);
    reverse(euler_tour.begin(), euler_tour.end());
}

