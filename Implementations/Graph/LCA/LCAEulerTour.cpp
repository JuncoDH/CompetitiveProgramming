// Point update and Range query.
// pair<T, pii> is (value, (posL, posR)).
// posL is the leftmost index that has value, in the range.
template<typename T>
class SegmentTree {
    vector<pair<T, pii>> t;
    vector<T> v;
    int n = 0;
    pair<T, pii> f(pair<T, pii> const a, pair<T, pii> const b) { 
        pair<T, pii> ans;
        ans.fi = min(a.fi, b.fi); // The function of the query. __gcd, +, |, &, max, min.
        if(ans.fi == a.fi) ans.se = a.se;
        else ans.se = b.se;
        if(ans.fi == b.fi) {
            ans.se.fi = min(ans.se.fi, b.se.fi);
            ans.se.se = max(ans.se.se, b.se.se);
        }
        return ans;
    }
    void build(int const k, int const l, int const r) {
        if(l == r) {t[k] = mp(v[l], mp(l, l)); return;}
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid + 1, r);
        t[k] = f(t[k<<1], t[k<<1|1]);
    }
    void update(int const k, int const l, int const r, int const p, T const x) {
        if(l == r) {t[k].fi = x; return;}
        int mid = (l + r) >> 1;
        if(p <= mid) update(k<<1, l, mid, p, x);
        else update(k<<1|1, mid+1, r, p, x);
        t[k] = f(t[k<<1], t[k<<1|1]);
    }
    pair<T, pii> query(int const k, int const l, int const r, int const ql, int const qr) const {
        if(ql <= l && r <= qr) return t[k];
        int mid = (l + r) >> 1;
        if(qr <= mid) return query(k<<1, l, mid, ql, qr);
        if(mid+1 <= ql) return query(k<<1|1, mid + 1, r, ql, qr);
        pair<T, pii> qa = query(k<<1, l, mid, ql, qr);
        pair<T, pii> qb = query(k<<1|1, mid + 1, r, ql, qr);
        return f(qa, qb);
    }
    public:
    SegmentTree() = default;
    explicit SegmentTree(vector<T> const& _v) {
        v = _v;
        n = v.size();
        t.assign(4 * n, {});
        build(1, 0, n - 1);
    }
    void update(int const p, T const x) {
        update(1, 0, n - 1, p, x);
    } // [ql, qr].
    pair<T, pii> query(int const ql, int const qr) const {
        return query(1, 0, n-1, ql, qr);
    }
};
class EulerTour{
    vector<vi> graph;
    vi tour;
    vi lvl;
    vi first_ocurrence;
    SegmentTree<int> st;
    void dfs(int const u, int const p, int const _lvl) {
        first_ocurrence[u] = tour.size();
        tour.pb(u);
        lvl.pb(_lvl);
        for(auto v : graph[u]) {
            if(v == p) continue;
            dfs(v, u, _lvl+1);
            tour.pb(u);
            lvl.pb(_lvl);
        }
    }
    public:
    EulerTour() = default;
    explicit EulerTour(vector<vi> const& _graph) {
        graph = _graph;
        first_ocurrence.assign(graph.size(), 0);
        dfs(0, -1, 0); // Rooted at 0.
        st = SegmentTree<int>(lvl);
    }
    int lca(int u, int v) const {
        u = first_ocurrence[u], v = first_ocurrence[v];
        if(u > v) swap(u, v);
        return tour[st.query(u, v).se.fi];
    }
    int dist(int u, int v) const {
        int w = first_ocurrence[lca(u, v)];
        u = first_ocurrence[u], v = first_ocurrence[v];
        return lvl[u] + lvl[v] - 2*lvl[w];
    }
};

