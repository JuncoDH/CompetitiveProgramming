function<ll(ll, ll)> st_min = [](ll const a, ll const b) { return min(a, b); };
function<ll(ll, ll)> st_max = [](ll const a, ll const b) { return max(a, b); };
function<ll(ll, ll)> st_sum = [](ll const a, ll const b) { return a + b; };
function<ll(ll, ll)> st_gcd = [](ll const a, ll const b) { return __gcd(a, b); };
// Point update and Range query.
template<typename T>
class SegmentTree {
    vector<T> t, v;
    int n = 0;
    function<ll(ll, ll)> merge; // The function of the query. __gcd, + , |, &, max, min.
    void build(int const k, int const l, int const r) {
        if(l == r) { t[k] = v[l]; return; }
        int mid = (l + r) / 2;
        build(k<<1, l, mid);
        build(k<<1|1, mid + 1, r);
        t[k] = merge(t[k<<1], t[k<<1|1]);
    }
    void update(int const k, int const l, int const r, int const p, T const x) {
        if(l == r) { t[k] = x; return; }
        int mid = (l + r) / 2;
        if(p <= mid) update(k<<1, l, mid, p, x);
        else update(k<<1|1, mid + 1, r, p, x);
        t[k] = merge(t[k<<1], t[k<<1|1]);
    }
    T query(int const k, int const l, int const r, int const ql, int const qr) {
        if(ql <= l && r <= qr) return t[k];
        int mid = (l + r) / 2;
        if(qr <= mid) return query(k<<1, l, mid, ql, qr);
        if(mid + 1 <= ql) return query(k<<1|1, mid + 1, r, ql, qr);
        T qa = query(k<<1, l, mid, ql, qr);
        T qb = query(k<<1|1, mid + 1, r, ql, qr);
        return merge(qa, qb);
    }
public:
    SegmentTree() = default;
    SegmentTree(vector<T> const& _v, function<ll(ll, ll)> const& _merge) {
        v = _v;
        n = v.size();
        t.assign(4 * n, 0);
        merge = _merge;
        build(1, 0, n - 1);
    }
    void update(int const p, T const x) {
        update(1, 0, n - 1, p, x);
    } // [ql, qr].
    T query(int ql, int qr) {
        if(ql > qr) swap(ql, qr);
        ql = max(ql, 0);
        qr = min(qr, n - 1);
        return query(1, 0, n - 1, ql, qr);
    }
};

