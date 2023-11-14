vector<vi> graph;
class Kosaraju { // SCC O(n). x2 times slower than Tarjan.
    vi s; // Stack.
    vector<vi> graphT;
    vector<bool> visited;
    void dfs1(int const u) {
        visited[u] = true;
        for(auto const& v : graph[u])
            if(!visited[v]) dfs1(v);
        s.pb(u);
    } // Add to the current component.
    void dfs2(int const u) {
        visited[u] = true;
        for(auto const& v : graphT[u])
            if(!visited[v]) dfs2(v);
        components.back().pb(u);
    }
    public:
    vector<vi> components;
    Kosaraju() {
        int i, n = graph.size();
        visited.assign(n, false);
        for(i = 0; i < n; i++)
            if(!visited[i]) dfs1(i);
        graphT.assign(n, vi());
        for(i = 0; i < n; i++)
            for(auto const& v : graph[i])
                graphT[v].pb(i);
        visited.assign(n, false);
        while(true) {
            while(!s.empty() && visited[s.back()]) s.pop_back();
            if(s.empty()) break;
            components.pb({});
            dfs2(s.back());
        }
    }
};
class Toposort{
    vector<bool> visited;
    void topo_rec(int const u) {
        if(visited[u]) return;
        visited[u] = true;
        for(auto const& _v : graph[u]) topo_rec(_v);
        vSorted.pb(u);
    }
    public:
    vi vSorted;
    explicit Toposort(int const n) {
        visited.assign(n, false);
        for(int i = 0; i < n; i++) topo_rec(i);
        reverse(vSorted.begin(), vSorted.end());
    }
};
class SAT{ // 2SAT, (xi or xj) and ()... O(n).
    public:
    explicit SAT(int const n) {
        graph.assign(2 * n, vi());
    }
    static int get_pos(int const i) {return 2 * i;}
    static int get_neg(int const i) {return 2 * i + 1;}
    static void add_or(int const i, int const j) { // Use it with get_pos.
        graph[i ^ 1].pb(j);
        graph[j ^ 1].pb(i);
    }
    static void add_value(int const i, int const val) { // x[i] = val;
        if(val) add_or(get_pos(i), get_pos(i));
        else add_or(get_neg(i), get_neg(i));
    }
    vector<bool> x; // Can add (xi or xi) if you know xi = true.
    bool solve() {
        Kosaraju const kosaraju;
        int i, n = graph.size(), n_component = kosaraju.components.size();
        vi el2component(n, 0);
        for(i = 0; i < n_component; i++)
            for(auto const& u : kosaraju.components[i]) el2component[u] = i;
        for(i = 0; i < n; i += 2)
            if(el2component[i] == el2component[i + 1]) return false;
        vector<vi> const graph2 = graph;
        graph.assign(n_component, {});
        for(i = 0; i < n; i++)
            for(auto const& u : graph2[i]) if(el2component[i] != el2component[u])
                graph[el2component[i]].pb(el2component[u]);
        Toposort const toposort(n_component);
        x.assign(n / 2, false);
        vi component_order(n_component, 0);
        for(i = 0; i < n_component; i++)
            component_order[toposort.vSorted[i]] = i;
        for(i = 0; i < n; i += 2)
            x[i / 2] = component_order[el2component[i]] > component_order[el2component[i + 1]];
        return true;
    }
};

