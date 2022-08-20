// If a and b is connected, they have the same sign.
// If a and -b is connected, they have oppossite sign.
// DON'T USE ELEMENT 0.
class DSU_neg {
    int n;
    vi parent;
    public:
    int find_parent(int a){
        if(a < 0) return -find_parent(-a);
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    DSU_neg() = default;
    DSU_neg(int _n) {
        n = _n;
        parent.assign(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    bool is_connected(int a, int b){
        return abs(find_parent(a)) == abs(find_parent(b));
    }
    void merge(int a, int b){
        a = find_parent(a);
        b = find_parent(b);
        if(is_connected(a, b)) return;
        if(a < 0) parent[-a] = -b;
        else parent[a] = b;
    }
};

