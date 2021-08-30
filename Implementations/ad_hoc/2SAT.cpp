// 2-SAT. Check values (xi or xj) and ... and (xk or xz).
// xi will be element 2*i and not xi will be 2*i+1. Change them with xi xor 1.
vector<vi> graph; // size of graph will be 2*(the number of xi).

int get_element(int n) {return 2*n;} // Get pos of xi.
int get_not_element(int n) {return 2*n + 1;} // Get pos of not xi.
// Add (xi or xj), two edges: (not xj => xi) and (not xi => xj).
// inclusive or: 1 or 1 = 1. For exclusive use 2 clausules. (xi or xj) and (not xi or not xj).
void add_or_clausule(int i, int j) {
    int neg_i = i^1, neg_j = j^1;
    graph[neg_i].pb(j);
    graph[neg_j].pb(i);
}

// Use Kosaraju to find the SCCs.
vector<vi> graphRev;
stack<int> s;
vector<bool> visited; // It will be reutilized in SAT.
vector<vi> components;

void dfs1(ll u){
    visited[u] = true;
    for(auto v : graph[u]){
        if(!visited[v]) dfs1(v);
    }
    s.push(u);
}

void dfs2(ll u){
    visited[u] = true;
    for(auto v : graphRev[u]){
        if(!visited[v]) dfs2(v);
    }
    components.back().pb(u); // One element more to the current component.
}

void Kosaraju(){
    ll i, n = graph.size();
    graphRev.assign(n, vi());
    s = stack<int>();
    //transpose graph to graphRev
    for(i = 0; i < n; ++i){
        for(auto v : graph[i]){
            graphRev[v].pb(i);
        }
    }
    
    visited.assign(n, false);
    for(i = 0; i < n; i++)
        if(!visited[i])
            dfs1(i);
    visited.assign(n, false);
    components.pb(vi());
    while(true) {
        while(!s.empty() && visited[s.top()] == true) s.pop();
        if(s.empty()) break;

        dfs2(s.top());
        components.pb(vi()); // End of the current component.
    }
}
// Do a topoSort of the SCCs.
vector<vi> graph_topo;
vi vSorted;
void topo_rec(int u) {
    if(visited[u]) return;
    visited[u] = true;
    for(auto _v : graph_topo[u]) topo_rec(_v);
    vSorted.pb(u);
}
// Topo sort the n_sz first values of graph.
void topo_sort(int n_sz) {
    vSorted.clear(); 
    visited.assign(n_sz, false);
    for(int i = 0; i < n_sz; i++) topo_rec(i);
    reverse(vSorted.begin(), vSorted.end());
}
// xi_value[i] is 0 if xi is false, 1 if true. 
vi xi_value;
// If you know in advance elements of xi add a clausule (xi or xi).
// Return true if the base is satisfactible, false otherwise.
// All calls are O(n).
vi node2component; // Index of the component of the node.
vi component2order; // Order of the component in the topological sort.
bool SAT() {
    Kosaraju();
    int n_components = components.size(), i, n = graph.size();
    node2component.assign(n, 0);
    graph_topo.assign(n_components, vi());
    component2order.assign(n_components, 0);
    // All components in the same SCC will have the same truth value.
    for(i = 0; i < n_components; i++) {
        for(auto u : components[i]) node2component[u] = i;
    }
    // If xi and not xi are in the same component is UNSAT.
    for(i = 0; i < n; i += 2) {
        if(node2component[i] == node2component[i+1]) return false;
    }
    for(i = 0; i < n; i++) {
        for(auto u : graph[i]) {
            if(node2component[i] != node2component[u])
                graph_topo[node2component[i]].pb(node2component[u]);
        }
    }
    topo_sort(n_components);
    for(i = 0; i < n_components; i++) {
        component2order[vSorted[i]] = i;
    }
    xi_value.assign(n/2, -1);
    for(i = 0; i < n; i += 2) {
        if(component2order[node2component[i]] > component2order[node2component[i+1]]) xi_value[i/2] = true;
        else xi_value[i/2] = false;
    }
    return true;
}

