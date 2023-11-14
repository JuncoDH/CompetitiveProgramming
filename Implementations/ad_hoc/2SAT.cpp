class SAT { // 2SAT, (xi or xj) and ()... O(n).
    public:
    explicit SAT(int const n) {
        graph.assign(2 * n, vi());
    }
    static int get_pos(int const i) { return 2 * i; }
    static int get_neg(int const i) { return 2 * i + 1; }
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

