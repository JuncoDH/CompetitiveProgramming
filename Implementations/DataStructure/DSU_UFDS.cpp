const int MAX = 20;

class DSU{
    vi parent;
    vi rank;
    public:
    DSU() : parent(MAX, 0), rank(MAX, 0) {
        for(int i = 0; i < MAX; ++i) parent[i] = i;
    }
    int find_parent(int a){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    bool connected(int a, int b){
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
    // Return the number of components in [0..MAX-1]. Be careful with single components not used in [n..MAX-1].
    int number_components() {
        bool freq[MAX];
        int i, ans = 0;
        fill(freq, freq+MAX, false);
        for(i = 0; i < MAX; i++) freq[find_parent(i)] = true;
        for(i = 0; i < MAX; i++) ans += freq[i];
        return ans;
    }
};
