// https://robert1003.github.io/2020/02/06/li-chao-segment-tree.html.
template<typename T>
class Line {
public:
    T m = 0, n = 0;
    Line() = default;
    Line(T _m, T _n) { m = _m; n = _n; }
    T evaluate(T x) {
        return m * x + n;
    }
};
// Only insert functions with one intersecction point, like lines.
// Constraint: query(x) has to be in [0, n - 1].
template<typename T>
class LiChaoTree {
    vector<Line<T>> st;
    int n = 0;
    // The node will save the best line for the mid point.
    // Left node is [l, mid] the right node is [mid + 1, r].
    void insert(int const k, int const l, int const r, Line<T> line) {
        if(l == r) {
            if(st[k].evaluate(l) < line.evaluate(l)) swap(st[k], line);
            return;
        }
        int mid = (l + r) / 2;
        if(st[k].m < line.m) swap(st[k], line);
        if(st[k].evaluate(mid) < line.evaluate(mid)) {
            swap(st[k], line);
            insert(k<<1|1, mid + 1, r, line);
        } else {
            insert(k<<1, l, mid, line);
        }
    }
    T query(int const k, int const l, int const r, T const x) {
        T ans = st[k].evaluate(x);
        if(l == r) {
            return ans;
        }
        int mid = (l + r) / 2;
        if(x <= mid) return max(ans, query(k<<1, l, mid, x));
        return max(ans, query(k<<1|1, mid + 1, r, x));
    }
public:
    LiChaoTree() = default;
    explicit LiChaoTree(int const _n) {
        n = _n;
        st.assign(4 * n, Line<T>());
    }
    void insert(Line<T> line) {
        insert(1, 0, n - 1, line);
    }
    // Return max evaluated value of all i in a set S = { m_i * x + n_i }.
    T query(T const x) {
        return query(1, 0, n - 1, x);
    }
};

