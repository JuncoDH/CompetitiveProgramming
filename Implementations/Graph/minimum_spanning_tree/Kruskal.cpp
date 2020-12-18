class DSU{
    int n;
    vi parent;
    vi rank;
    int find_parent(int a){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    public:
    DSU(int _n) {
        n = _n;
        parent.assign(n, 0);
        rank.assign(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    bool is_connected(int a, int b){
        return find_parent(a) == find_parent(b);
    }
    void Union(int a, int b){
        a = find_parent(a);
        b = find_parent(b);
        
        if(a == b) return;

        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else {parent[a] = b; rank[b]++;}
    }
    // Return the number of components in [0..n-1]. Be careful with single components not used in [n..n+extra_space].
    int number_components() {
        int ans = 0, i;
        for(i = 0; i < n; i++) ans += find_parent(i) == i;
        return ans;
    }
};
DSU dsu(1);
// Minimum spanning tree in a bidirected graph.
// graph contains elements [0..n-1], no extra space.
ll kruskal(vector<vector<pii>> &graph) {
    int n = graph.size(), i;
    ll ans = 0;
    dsu = DSU(n);
    vector<pair<ll, pii>> edge;
    for(i = 0; i < n; i++) {
        for(auto el : graph[i]) {
            if(i < el.fi) { // Only adds one edge.
                edge.pb(mp(el.se, mp(i, el.fi)));
            }
        }
    }
    sort(edge.begin(), edge.end());
    for(auto e : edge) {
        if(!dsu.is_connected(e.se.fi, e.se.se)) {
            dsu.Union(e.se.fi, e.se.se);
            ans += e.fi;
        }
    }
    return ans;
}
