// Tarjan algorithm use 1 DFS while this use 2 (x2 slower).
// shows in O(n) SCC Strongly Connected Components. 
// first dfs1 when node is processed is added to the stack, then the graph is transposed, then dfs2 when node is processed is showed in its component.
vector<vi> graph, graphRev;
stack<int> s;
vector<bool> visited;
ll n;
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
    cout << u << "."; // One element more to the current component.
}
void Kosaraju(){
    ll i;
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

    while(true) {
        while(!s.empty() && visited[s.top()] == true) s.pop();
        if(s.empty()) break;

        dfs2(s.top());
        cout << endl; // End of the current component.
    }
}

