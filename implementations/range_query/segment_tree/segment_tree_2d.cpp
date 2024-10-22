// Creation O(n * m), query O(log(n) * log(m)), update O(n * log(n) * log(m)).
template<typename T>
class SegmentTree_2D {
    vector<vector<T>> tree;
    vector<vector<T>> v;
    int n = 0, m = 0;
    static T f(T const a, T const b) {
        return a + b;
    }
    // Fixed the x, build based on y. kx and vs fixed.
    void Build1D(int const k, int const l, int const r, int const kx, int const vx) {
        if(l == r) { tree[kx][k] = v[vx][l]; return; }
        int mid = (l + r) / 2;
        Build1D(2 * k, l, mid, kx, vx);
        Build1D(2 * k + 1, mid + 1, r, kx, vx);
        tree[kx][k] = f(tree[kx][2 * k], tree[kx][2 * k + 1]);    
    }
    T Query1D(int const k, int const l, int const r, int const y1, int const y2, int const kx) {
        if(r < y1 || y2 < l) return 0;
        if(y1 <= l && r <= y2) return tree[kx][k];
        int mid = (l + r) / 2;
        T a = Query1D(2 * k, l, mid, y1, y2, kx);
        T b = Query1D(2 * k + 1, mid + 1, r, y1, y2, kx);
        return f(a, b);
    }
    void Update1D(int const k, int const l, int const r, int const y, T const val, int const kx) {
        if(l == r) { tree[kx][k] += val; return; }
        int mid = (l + r) / 2;
        if(y <= mid) Update1D(2 * k, l, mid, y, val, kx);
        else Update1D(2 * k + 1, mid + 1, r, y, val, kx);
        tree[kx][k] = f(tree[kx][2 * k], tree[kx][2 * k + 1]);
    }
    void Build2D(int const k, int const l, int const r) {
        if(l == r) { Build1D(1, 0, m - 1, k, l); return; }
        int mid = (l + r) / 2;
        Build2D(2 * k, l, mid);
        Build2D(2 * k + 1, mid + 1, r);
        // Merge the STs.
        for(int i = 0; i < (int)tree[0].size(); ++i){
            tree[k][i] = f(tree[2 * k][i], tree[2 * k + 1][i]);
        }
    }
    T Query2D(int const k, int const l, int const r, int const x1, int const y1, int const x2, int const y2) {
        if(r < x1 || x2 < l) return 0;
        if(x1 <= l && r <= x2) return Query1D(1, 0, m - 1, y1, y2, k);
        int mid = (l + r) / 2;
        T a = Query2D(2 * k, l, mid, x1, y1, x2, y2);
        T b = Query2D(2 * k + 1, mid + 1, r, x1, y1, x2, y2);
        return f(a, b);
    }
    void Update2D(int const k, int const l, int const r, int const x, int const y, T const val) {
        if(l == r) { Update1D(1, 0, m - 1, y, val, k); return; }
        int mid = (l + r) / 2;
        if(x <= mid) Update2D(2 * k, l, mid, x, y, val);
        else Update2D(2 * k + 1, mid + 1, r, x, y, val);
        for(int i = 0; i < (int)tree[0].size(); ++i){
            tree[k][i] = f(tree[2 * k][i], tree[2 * k + 1][i]);
        }
    }
    public:
    SegmentTree_2D() = default;
    SegmentTree_2D(int const _n, int const _m) {
        n = _n;
        m = _m;
        tree.assign(4 * n, vector<T>(4 * m, 0));
    }
    void update(int const x, int const y, T const val) {
        Update2D(1, 0, n - 1, x, y, val);
    }
    T query(int x1, int y1, int x2, int y2) {
        if(x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2); // (x1, y1) is the bottom-left corner.
        return Query2D(1, 0, n - 1, x1, y1, x2, y2);
    }
};

