template<typename T>
class Node { // Only modify this class.
    public:
    T value = numeric_limits<T>::max(); // max for MIN query.
    static const T lazy_default = 0; // Default value for lazy.
    T lazy = lazy_default;
    Node(T _value) {value = _value;}
    // Merge nodes.
    Node(Node<T> a, Node<T> b) {value = min(a.value, b.value);} // MIN query.
    Node() = default;
    void actualize_update(T x) {
        value += x; // MIN query + (= SET update), (+= SUM update).
        lazy += x; // MIN query + (= SET update), (+= SUM update).
    }
};

template<typename T>
class Lazy_SegTree {
    vector<Node<T>> tree;
    vector<T> v_input;
    int v_size;
    // Value is the real value, and lazy is only for its children.
    void push_lazy(int k, int l, int r) {
        if(l != r) {
            tree[k<<1].actualize_update(tree[k].lazy);
            tree[k<<1|1].actualize_update(tree[k].lazy);
            tree[k] = Node<T>(tree[k<<1], tree[k<<1|1]);
        }
        tree[k].lazy = tree[k].lazy_default;
    }
    void build(int k, int l, int r) {
        if(l == r) {tree[k] = Node<T>(v_input[l]); return;}
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid+1, r);
        tree[k] = Node<T>(tree[k<<1], tree[k<<1|1]);
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
    Lazy_SegTree(vector<T> v) {
        v_input = v;
        v_size = v_input.size();
        tree.assign(4*v_size, {});
        build(1, 0, v_size-1);
    }
    void update(int ql, int qr, T x) { // [ql, qr].
        update(1, 0, v_size-1, ql, qr, x);
    }
    T query(int ql, int qr) { // [ql, qr].
        Node<T> ans = query(1, 0, v_size-1, ql, qr);
        return ans.value;
    }
};
