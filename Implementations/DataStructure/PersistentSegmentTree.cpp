constexpr int MAX_VERSION = 3 * 1e4 + 4; // Maximum number of versions.
template<typename T>
struct node {
    node* pl = nullptr, *pr = nullptr;
    int l, r, mid;
    T value = 0; // Sum query.
    node(int const _l, int const _r) { l = _l; r = _r; mid = (l + r)>>1; }
    node(int const _l, int const _r, T const _value) { l = _l; r = _r; value = _value; mid = (l + r)>>1; }
    void update() { // Sum query.
        value = 0;
        if(pl) value += pl->value;
        if(pr) value += pr->value;
    }
}; // Declare outside, else static memory gives seg fault.
node<ll> *root[MAX_VERSION]; //it stores the i versions after updates, start at 0.
template<typename T>
class PersistentSegmentTree {
    vector<T> arr; // Copy of the array to build SegmentTree.
    void build(node<T>* n) { // O(n).
        if(n->l == n->r) { n->value = arr[n->l]; return; }
        n->pl = new node<T>(n->l, n->mid);
        n->pr = new node<T>(n->mid + 1, n->r);
        build(n->pl);
        build(n->pr);
        n->update();
    }
    node<T>* update(node<T>* n, int const q, ll const x) { // O(logn).
        if(n->l == n->r) {
            return new node<T>(n->l, n->r, x);
        }
        node<T>* nod = new node<T>(n->l, n->r);
        if(q <= n->mid) {
            nod->pl = update(n->pl, q, x);
            nod->pr = n->pr;
        } else {
            nod->pl = n->pl;
            nod->pr = update(n->pr, q, x);
        }
        nod->update();
        return nod;
    }
    T query(node<T> const* n, int const l, int const r) { // O(logn).
        if(l <= n->l && n->r <= r) return n->value;
        if(r < n->l || n->r < l) return 0; // Sum query.
        return query(n->pl, l, r) + query(n->pr, l, r);
    }
    public:
    PersistentSegmentTree() = default;
    PersistentSegmentTree(int n){ // Build from empty vector of size n.
        arr.assign(n, 0);
        root[0] = new node<T>(0, n-1);
        build(root[0]);
    }
    explicit PersistentSegmentTree(vector<T> const& v) { // Build from vector v.
        arr = v;
        root[0] = new node<T>(0, (int)arr.size() - 1);
        build(root[0]);
    }
    T query(int const version, int l, int r) { return query(root[version], l, r); } // O(logn).
    // Set v[idx] = x. Set update.
    void update(int const version, int const new_version, int idx, T x) { // update the segTree version into new_version root.
        root[new_version] = update(root[version], idx, x); // O(logn).
    }
};
template<typename T>
class NumberDistinctNumbers { // Works for queries online. For offline can check MO's.
    PersistentSegmentTree<T> pst;
    constexpr int MAX_ELEMENT_VALUE = 1e6 + 4; // for querying last[el].
    public:
    NumberDistinctNumbers() = default;
    explicit NumberDistinctNumbers(vector<T> const& v) { // O(nlogn).
        T last[MAX_ELEMENT_VALUE]; // last ocurrence of the i-number in the array, updating from left to right.
        int n = v.size();
        fill(last, last + MAX_ELEMENT_VALUE, -1);
        pst = PersistentSegmentTree<T>(n);
        for(int r = 0; r < n; r++) {
            pst.update(max(0, r-1), r, r, 1); // Actualize r.
            if(last[v[r]] != -1) pst.update(r, r, last[v[r]], 0); // Remove last[v[r]].
            last[v[r]] = r; // Actualize last[v[r]].
        }
    }
    T query(int const l, int const r) { // Return the number of Distinct numbers in [l..r], O(logn).
        return pst.query(r, l, r);
    }
};

