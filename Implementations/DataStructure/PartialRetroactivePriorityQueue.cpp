add srand
// Paper: https://erikdemaine.org/papers/Retroactive_TALG/paper.pdf
// Video: https://www.youtube.com/watch?v=WqCWghETNDc&list=WL&index=11&t=0s
// Problem: https://codeforces.com/blog/entry/74961#comment-590583
template<typename T>
class SegmentTreePrefixSum { // Searching minimum prefix sum and it's index, 0-based.
    struct node {
        T prefixSum, mn;
        int minIndexMinimum = -1; // The minimum index with minimum prefix sum.
        int maxIndexMinimum = -1; // The maximum index with minimum prefix sum.
        node() {}
        node(T _prefixSum, T _mn, int _minIndexMinimum, int _maxIndexMinimum) {
            prefixSum = _prefixSum;
            mn = _mn;
            minIndexMinimum = _minIndexMinimum;
            maxIndexMinimum = _maxIndexMinimum;
        }
        node operator + (node other) { // for tree[k] = tree[k<<1] + tree[k<<1|1].
            int mnIndex = (mn <= other.mn) ? minIndexMinimum : other.minIndexMinimum;
            int mxIndex = (other.mn <= mn) ? other.maxIndexMinimum : maxIndexMinimum;
            return node(prefixSum + other.prefixSum, min(mn, other.mn), mnIndex, mxIndex);
        }
        void show() {
            cout << "(" << prefixSum << "," << mn << "," << minIndexMinimum << "," << maxIndexMinimum << ")";
        }
    };
    node NULL_NODE = node(numeric_limits<T>::max(), numeric_limits<T>::max(), -1, -1);
    vector<node> tree;
    vector<T> lazy; // dx to update to each node (NOT interval).
    int size; // Timeline [0.._size - 1] events.
    void build(int k, int l, int r) { // Set the mnIndex y mxIndex.
        if(l == r) { tree[k] = node(0, 0, l, l); return; }
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid + 1, r);
        tree[k] = tree[k<<1] + tree[k<<1|1];
    }
    void propagate(int k, int l, int r) {
        tree[k].prefixSum += (r - l + 1) * lazy[k];
        tree[k].mn += lazy[k];
        if(l != r) {
            lazy[k<<1] += lazy[k];
            lazy[k<<1|1] += lazy[k];
        }
        lazy[k] = 0;
    }
    void update(int k, int l, int r, int ql, T x) {  // The update is [ql.._size - 1].
        propagate(k, l, r);
        if(r < ql) return;
        if(ql <= l) {
            lazy[k] += x;
            return;
        }
        int mid = (l + r) >> 1;
        update(k<<1, l, mid, ql, x);
        update(k<<1|1, mid + 1, r, ql, x);
        propagate(k<<1, l, mid);
        propagate(k<<1|1, mid + 1, r);
        tree[k] = tree[k<<1] + tree[k<<1|1];
    }
    node query(int k, int l, int r, int ql, int qr) {
        propagate(k, l, r);
        if(r < ql || qr < l) return NULL_NODE;
        if(ql <= l && r <= qr) return tree[k];
        int mid = (l + r) >> 1;
        node a = query(k<<1, l, mid, ql, qr);
        node b = query(k<<1|1, mid + 1, r, ql, qr);
        propagate(k<<1, l, mid);
        propagate(k<<1|1, mid + 1, r);
        tree[k] = tree[k<<1] + tree[k<<1|1];
        if(a.prefixSum == NULL_NODE.prefixSum) return b;
        if(b.prefixSum == NULL_NODE.prefixSum) return a;
        return a + b;
    }
    node query(int ql, int qr) {
        return query(1, 0, size - 1, ql, qr);
    }
    void showTree(int k, int l, int r) {
        propagate(k, l, r);
        tree[k].show();
        if(l == r) return;
        int mid = (l + r) >> 1;
        showTree(k<<1, l, mid);
        showTree(k<<1|1, mid + 1, r);
    }
    public:
    SegmentTreePrefixSum() {}
    SegmentTreePrefixSum(int _size) { // Store values [0..size - 1].
        size = _size;
        tree.resize(4 * _size);
        lazy.resize(4 * _size);
        build(1, 0, _size - 1);
    }
    void update(int ql, T dx) { // Update [t.._size - 1] + dx per node, O(log n).
        update(1, 0, size - 1, ql, dx);
    }
    void externalQuery(int ql, int qr) {
        node n = query(ql, qr);
        n.show();
        cout << endl;
    }
    void showTree() {
        showTree(1, 0, size - 1);
        cout << endl;
    }
    int getLastBridge(int t) { // O(log n) minimum prefix sum with the index <= t.
        node n = query(0, t);
        if(n.mn != 0) return 0; // If there is no bridge.
        return n.maxIndexMinimum;
    }
    int getNextBridge(int t) { // O(log n) minimum prefix sum with the index >= t.
        node n = query(t, size - 1);
        if(n.mn != 0) return size - 1; // If there is no bridge.
        return n.minIndexMinimum;
    }
};
// Push and pop in the past and query in the present. It's minimum pq, for maximum push(-num).
template<typename T> // int, ll.
class PartialRetroactivePriorityQueue {
    Treap<int, T> qnow; // The elements that are in Qnow.
    Treap<int, T> nqnow; // The elements that are NOT in Qnow.
    SegmentTreePrefixSum<T> bridge; // If the query(t', t') == 0, there is a bridge in t'.
    public:
    PartialRetroactivePriorityQueue() = default;
    PartialRetroactivePriorityQueue(int _size) {
        bridge = SegmentTreePrefixSum<T>(_size);
    }
    void insertPush(int t, T data){ // Insert(t, "insert(data)") O(log n).
        int tl = bridge.getLastBridge(t);
        nqnow.insert(t, data);
        bridge.update(t, 1);
        pair<T, int> add = nqnow.getMaximumAfter(tl);
        nqnow.erase(add.second);
        qnow.insert(add.second, add.first);
        bridge.update(add.second, -1);
    }
    void insertPop(int t) { // Insert(t, "pop_min()"). Be sure in all t, num Push >= num Pop O(log n).
        int tl = bridge.getNextBridge(t);
        bridge.update(t, -1);
        pair<T, int> rem = qnow.getMinimumBefore(tl);
        qnow.erase(rem.second);
        nqnow.insert(rem.second, rem.first);
        bridge.update(rem.second, 1);
    }
    T getPeak() { // get minimum of the rpq in Qnow. Be sure the rpq is not empty. O(1).
        return qnow.getMinimumAll().first;
    }
};

