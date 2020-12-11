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
        vector<bool> freq(n, false);
        int i, ans = 0;
        for(i = 0; i < n; i++) freq[find_parent(i)] = true;
        for(i = 0; i < n; i++) ans += freq[i];
        return ans;
    }
};
