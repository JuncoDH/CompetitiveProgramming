// Creation O(n*m), query O(log(n)*log(m)), updat O(n*log(n)*log(m)).
template<typename T>
class SegTree_2D {
    vector<vector<T>> tree;
    vector<vector<T>> v;
    int n, m;
    T f(T a, T b) {
        return a + b;
    }
    // Fixed the x, build based on y. kx and vs fixed.
    void Build1D(int k, int l, int r, int kx, int vx) {
        if(l == r) {tree[kx][k] = v[vx][l]; return;}
        int mid = (l + r) >> 1;
        Build1D(k<<1, l, mid, kx, vx);
        Build1D(k<<1|1, mid + 1, r, kx, vx);
        tree[kx][k] = f(tree[kx][k<<1], tree[kx][k<<1|1]);    
    }
    T Query1D(int k, int l, int r, int y1, int y2, int kx) {
        if(r < y1 || y2 < l) return 0;
        if(y1 <= l && r <= y2) return tree[kx][k];
        int mid = (l + r) >> 1;
        T a = Query1D(k<<1, l, mid, y1, y2, kx);
        T b = Query1D(k<<1|1, mid + 1, r, y1, y2, kx);
        return f(a, b);
    }
    void Update1D(int k, int l, int r, int y, T val, int kx) {
        if(l == r) {tree[kx][k] += val; return;}
        int mid = (l + r) >> 1;
        if(y <= mid) Update1D(k<<1, l, mid, y, val, kx);
        else Update1D(k<<1|1, mid + 1, r, y, val, kx);
        tree[kx][k] = f(tree[kx][k<<1], tree[kx][k<<1|1]);
    }
    void Build2D(int k, int l, int r) {
        if(l == r) {Build1D(1, 0, m - 1, k, l); return;}
        int mid = (l + r) >> 1;
        Build2D(k<<1, l, mid);
        Build2D(k<<1|1, mid + 1, r);
        // Merge the STs.
        for(int i = 0; i < (int)tree[0].size(); ++i){
            tree[k][i] = f(tree[k<<1][i], tree[k<<1|1][i]);
        }
    }
    T Query2D(int k, int l, int r, int x1, int y1, int x2, int y2) {
        if(r < x1 || x2 < l) return 0;
        if(x1 <= l && r <= x2) return Query1D(1, 0, m - 1, y1, y2, k);
        int mid = (l + r) >> 1;
        T a = Query2D(k<<1, l, mid, x1, y1, x2, y2);
        T b = Query2D(k<<1|1, mid + 1, r, x1, y1, x2, y2);
        return f(a, b);
    }
    void Update2D(int k, int l, int r, int x, int y, T val) {
        if(l == r) {Update1D(1, 0, m - 1, y, val, k); return;}
        int mid = (l + r) >> 1;
        if(x <= mid) Update2D(k<<1, l, mid, x, y, val);
        else Update2D(k<<1|1, mid + 1, r, x, y, val);
        
        for(int i = 0; i < (int)tree[0].size(); ++i){
            tree[k][i] = f(tree[k<<1][i], tree[k<<1|1][i]);
        }
    }
    public:
    SegTree_2D() = default;
    SegTree_2D(int _n, int _m) {
        n = _n;
        m = _m;
        tree.assign(4*n, vector<T>(4*m, 0));
    }
    void update(int x, int y, T val) {
        Update2D(1, 0, n-1, x, y, val);
    }
    T query(int x1, int y1, int x2, int y2) {
        if(x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2); // (x1, y1) is the bottom-left corner.
        return Query2D(1, 0, n-1, x1, y1, x2, y2);
    }
};

