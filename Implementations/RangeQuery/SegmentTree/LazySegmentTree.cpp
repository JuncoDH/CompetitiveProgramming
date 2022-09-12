template<typename T>
class Node { // Only modify this class.
    public:
    int l = -1, r = -1; // Interval [l, r].
    T value = 0;
    static const T lazy_default = -inf; // Don't change.
    T lazy = lazy_default;
    Node() = default;
    Node(T _value) {value = _value;}
    // Merge nodes.
    Node(Node<T> a, Node<T> b) {value = max(a.value, b.value);} // MINMAX, SUM query.
    void actualize_update(T x) {
        if(x == -inf) return;
        if(lazy == -inf) lazy = 0;
        lazy += x; // (= SET update), (+= SUM update).
        value += x; // MINMAX query + (= SET update), (+= SUM update).
        // value = (r-l+1)*x; // SUM query + (= SET update), (+= SUM update).
    }
};
template<typename T>
class LazySegmentTree { // Use lazy propagation.
    vector<Node<T>> tree;
    vector<T> v;
    int n;
    // Value is the real value, and lazy is only for its children.
    void push_lazy(int k, int l, int r) {
        if(l != r) {
            tree[k<<1].actualize_update(tree[k].lazy);
            tree[k<<1|1].actualize_update(tree[k].lazy);
            tree[k] = Node<T>(tree[k<<1], tree[k<<1|1]);
            tree[k].l = l; tree[k].r = r;
        }
        tree[k].lazy = tree[k].lazy_default;
    }
    void build(int k, int l, int r) {
        if(l == r) {
            tree[k] = Node<T>(v[l]);
            tree[k].l = l; tree[k].r = r;
            return;
        }
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid+1, r);
        tree[k] = Node<T>(tree[k<<1], tree[k<<1|1]);
        tree[k].l = l; tree[k].r = r;
    }
    void update(int k, int l, int r, int ql, int qr, T x) {
        push_lazy(k, l, r);
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr) {
            tree[k].actualize_update(x);
        } else {
            int mid = (l + r) >> 1;
            update(k<<1, l, mid, ql, qr, x);
            update(k<<1|1, mid+1, r, ql, qr, x);
        }
        push_lazy(k, l, r);
    }
    Node<T> query(int k, int l, int r, int ql, int qr) {
        push_lazy(k, l, r);
        if(ql <= l && r <= qr) return tree[k];
        int mid = (l + r) >> 1;
        if(qr <= mid) return query(k<<1, l, mid, ql, qr);
        if(mid+1 <= ql) return query(k<<1|1, mid+1, r, ql, qr);
        Node<T> a = query(k<<1, l, mid, ql, qr);
        Node<T> b = query(k<<1|1, mid+1, r, ql, qr);
        return Node<T>(a, b);
    }
    public:
    LazySegmentTree() = default;
    LazySegmentTree(vector<T> _v) {
        v = _v;
        n = v.size();
        tree.assign(4*n, {});
        build(1, 0, n-1);
    }
    void update(int ql, int qr, T x) { // [ql, qr].
        if(ql > qr) swap(ql, qr);
        ql = max(ql, 0);
        qr = min(qr, n-1);
        update(1, 0, n-1, ql, qr, x);
    }
    T query(int ql, int qr) { // [ql, qr].
        if(ql > qr) swap(ql, qr);
        ql = max(ql, 0);
        qr = min(qr, n-1);
        Node<T> ans = query(1, 0, n-1, ql, qr);
        return ans.value;
    }
};

