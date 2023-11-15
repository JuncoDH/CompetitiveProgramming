class DSU {
    int n = 0;
    vi parent;
    // Is optional, improves the theoretical complexity,
    // but in practice it does not affect too much.
    vi rank;
    vi sz; // Size of the component.
    int find_parent(int const a){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    public:
    int number_components = 0;
    DSU() = default;
    explicit DSU(int const _n) {
        n = _n;
        number_components = n;
        parent.assign(n, 0);
        rank.assign(n, 0);
        sz.assign(n, 1);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    bool is_connected(int const a, int const b){
        return find_parent(a) == find_parent(b);
    }
    void merge(int a, int b){
        a = find_parent(a);
        b = find_parent(b);
        if(a == b) return;
        number_components--;
        if(rank[a] > rank[b]) parent[b] = a, sz[a] += sz[b];
        else if(rank[a] < rank[b]) parent[a] = b, sz[b] += sz[a];
        else { parent[a] = b; rank[b]++, sz[b] += sz[a]; }
    }
    int size(int const a) { return sz[find_parent(a)]; }
};

