class DSU {
    int n;
    vi parent;
    vi rank;
    int find_parent(int a){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    public:
    int number_components;
    DSU() = default;
    DSU(int _n) {
        n = _n;
        number_components = n;
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
        number_components--;
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else {parent[a] = b; rank[b]++;}
    }
};
// Minimum spanning tree in a bidirected graph.
// graph contains elements [0..n-1], no extra space.
ll Kruskal(vector<vector<pii>> &graph) {
    int n = graph.size(), i;
    ll ans = 0;
    DSU dsu(n);
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
    if(dsu.number_components > 1) return -1;
    return ans;
}

