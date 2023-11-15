function<ll(ll, ll)> st_min = [](ll const a, ll const b) { return min(a, b); };
function<ll(ll, ll)> st_max = [](ll const a, ll const b) { return max(a, b); };
function<ll(ll, ll)> st_sum = [](ll const a, ll const b) { return a + b; };
function<ll(ll, ll)> st_gcd = [](ll const a, ll const b) { return __gcd(a, b); };
// Point update and Range query.
// pair<T, pii> is (value, (posL, posR)).
// posL is the leftmost index that has value, in the range.
template<typename T>
class SegmentTree {
    vector<pair<T, pii>> t;
    vector<T> v;
    int n = 0;
    function<ll(ll, ll)> merge; // The function of the query. __gcd, + , |, &, max, min.
    pair<T, pii> f(pair<T, pii> const& a, pair<T, pii> const& b) {
        pair<T, pii> ans;
        ans.fi = merge(a.fi, b.fi);
        if(ans.fi == a.fi) ans.se = a.se;
        else ans.se = b.se;
        if(ans.fi == b.fi) {
            ans.se.fi = min(ans.se.fi, b.se.fi);
            ans.se.se = max(ans.se.se, b.se.se);
        }
        return ans;
    }
    void build(int const k, int const l, int const r) {
        if(l == r) { t[k] = { v[l], { l, l } }; return; }
        int mid = (l + r) / 2;
        build(2 * k, l, mid);
        build(2 * k + 1, mid + 1, r);
        t[k] = f(t[2 * k], t[2 * k + 1]);
    }
    void update(int const k, int const l, int const r, int const p, T const x) {
        if(l == r) { t[k].fi = x; return; }
        int mid = (l + r) / 2;
        if(p <= mid) update(2 * k, l, mid, p, x);
        else update(2 * k + 1, mid + 1, r, p, x);
        t[k] = f(t[2 * k], t[2 * k + 1]);
    }
    pair<T, pii> query(int const k, int const l, int const r, int const ql, int const qr) {
        if(ql <= l && r <= qr) return t[k];
        int mid = (l + r) / 2;
        if(qr <= mid) return query(2 * k, l, mid, ql, qr);
        if(mid + 1 <= ql) return query(2 * k + 1, mid + 1, r, ql, qr);
        pair<T, pii> qa = query(2 * k, l, mid, ql, qr);
        pair<T, pii> qb = query(2 * k + 1, mid + 1, r, ql, qr);
        return f(qa, qb);
    }
    public:
    SegmentTree() = default;
    SegmentTree(vector<T> const& _v, function<ll(ll, ll)> const& _merge) {
        v = _v;
        n = v.size();
        t.assign(4 * n, {});
        merge = _merge;
        build(1, 0, n - 1);
    }
    void update(int const p, T const x) {
        update(1, 0, n - 1, p, x);
    } // [ql, qr].
    pair<T, pii> query(int ql, int qr) {
        if(ql > qr) swap(ql, qr);
        ql = max(ql, 0);
        qr = min(qr, n - 1);
        return query(1, 0, n - 1, ql, qr);
    }
};

