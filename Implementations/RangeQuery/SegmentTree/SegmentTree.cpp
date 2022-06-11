// Point update and Range query.
template<typename T>
class SegmentTree {
    vector<T> t, v;
    int n;
    T f(T a, T b) { // The function of the query. __gcd, +, |, &, max, min.
        return __gcd(a, b);
    }
    void build(int k, int l, int r) {
        if(l == r) {t[k] = v[l]; return;}
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid + 1, r);
        t[k] = f(t[k<<1], t[k<<1|1]);
    }
    void update(int k, int l, int r, int p, T x) {
        if(l == r) {t[k] = x; return;}
        int mid = (l + r) >> 1;
        if(p <= mid) update(k<<1, l, mid, p, x);
        else update(k<<1|1, mid+1, r, p, x);
        t[k] = f(t[k<<1], t[k<<1|1]);
    }
    T query(int k, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return t[k];
        int mid = (l + r) >> 1;
        if(qr <= mid) return query(k<<1, l, mid, ql, qr);
        if(mid+1 <= ql) return query(k<<1|1, mid + 1, r, ql, qr);
        T qa = query(k<<1, l, mid, ql, qr);
        T qb = query(k<<1|1, mid + 1, r, ql, qr);
        return f(qa, qb);
    }
    public:
    SegmentTree() = default;
    SegmentTree(vector<T> &_v) {
        v = _v;
        n = v.size();
        t.assign(4*n, 0);
        build(1, 0, n-1);
    }
    void update(int p, T x) {
        update(1, 0, n-1, p, x);
    } // [ql, qr].
    T query(int ql, int qr) {
        return query(1, 0, n-1, ql, qr);
    }
};

