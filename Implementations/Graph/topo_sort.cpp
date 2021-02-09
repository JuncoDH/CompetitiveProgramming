vi vSorted;
vector<bool> visited;
void topo_rec(int u) {
    if(visited[u]) return;
    visited[u] = true;
    for(auto _v : graph[u]) topo_rec(_v);
    vSorted.pb(u);
}
// Topo sort the n_sz first values of graph.
void topo_sort(int n_sz) {
    vSorted.clear(); 
    visited.assign(n_sz, false);
    for(int i = 0; i < n_sz; i++) topo_rec(i);
    reverse(vSorted.begin(), vSorted.end());
}
