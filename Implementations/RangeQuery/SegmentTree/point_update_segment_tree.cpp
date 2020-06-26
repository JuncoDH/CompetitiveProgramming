// Point update and Range query.
template<typename T>
class SegTree {
    vector<T> t, v;
    int n;
    T f(T a, T b) { // The function of the query.
        return max(a, b);
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
        if(qr < l || r < ql) return -inf; // MAX SEGTREE
        int mid = (l + r) >> 1;
        T qa = query(k<<1, l, mid, ql, qr);
        T qb = query(k<<1|1, mid + 1, r, ql, qr);
        if(qr <= mid) return qa;
        if(mid+1 <= l) return qb;
        return f(qa, qb);
    }
    public:
    SegTree(vector<T> &_v) {
        v = _v;
        n = v.size();
        t.assign(4*n, 0);
        build(1, 0, n-1);
    }
    void update(int p, T x) {
        update(1, 0, n-1, p, x);
    }
    T query(int ql, int qr) {
        return query(1, 0, n-1, ql, qr);
    }
};
