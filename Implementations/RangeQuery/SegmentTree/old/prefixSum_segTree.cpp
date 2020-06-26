template<typename T>
class SegmentTreePrefixSum{ //searching minimum prefix sum and it's index, 0-based
    struct node {
        T prefixSum, mn;
        int minIndexMinimum = -1; //the minimum index with minimum prefix sum 
        int maxIndexMinimum = -1; //the maximum index with minimum prefix sum
        node() {}
        node(T _prefixSum, T _mn, int _minIndexMinimum, int _maxIndexMinimum) {
            prefixSum = _prefixSum;
            mn = _mn;
            minIndexMinimum = _minIndexMinimum;
            maxIndexMinimum = _maxIndexMinimum;
        }
        node operator + (node other) {//for tree[k] = tree[k<<1] + tree[k<<1|1]
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
    vector<T> lazy; //dx to update to each node (NOT interval)
    int size; //timeline [0.._size-1] events
    void build(int k, int l, int r) { //set the mnIndex y mxIndex
        if(l == r) {tree[k] = node(0, 0, l, l); return;}
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
    void update(int k, int l, int r, int ql, T x) {  //the update is [ql.._size-1]
        propagate(k, l, r);
        if(r < ql) return;
        if(ql <= l) {
            lazy[k] += x;
            return;
        }
        int mid = (l + r) >> 1;
        update(k<<1, l, mid, ql, x);
        update(k<<1|1, mid+1, r, ql, x);
        propagate(k<<1, l, mid);
        propagate(k<<1|1, mid+1, r);
        tree[k] = tree[k<<1] + tree[k<<1|1];
    }
    node query(int k, int l, int r, int ql, int qr) {
        propagate(k, l, r);
        if(r < ql || qr < l) return NULL_NODE;
        if(ql <= l && r <= qr) return tree[k];
        int mid = (l + r) >> 1;
        node a = query(k<<1, l, mid, ql, qr);
        node b = query(k<<1|1, mid+1, r, ql, qr);
        propagate(k<<1, l, mid);
        propagate(k<<1|1, mid+1, r);
        tree[k] = tree[k<<1] + tree[k<<1|1];
        if(a.prefixSum == NULL_NODE.prefixSum) return b;
        if(b.prefixSum == NULL_NODE.prefixSum) return a;
        return a+b;
    }
    node query(int ql, int qr) {
        return query(1, 0, size-1, ql, qr);
    }
    void showTree(int k, int l, int r) {
        propagate(k, l, r);
        tree[k].show();
        if(l == r) return;
        int mid = (l + r) >> 1;
        showTree(k<<1, l, mid);
        showTree(k<<1|1, mid+1, r);
    }
    public:
    SegmentTreePrefixSum() {}
    SegmentTreePrefixSum(int _size) { //store values [0..size-1]
        size = _size;
        tree.resize(4*_size);
        lazy.resize(4*_size);
        build(1, 0, _size-1);
    }
    void update(int ql, T dx) { //update [t.._size-1] + dx per node, O(log n)
        update(1, 0, size-1, ql, dx);
    }
    void externalQuery(int ql, int qr) {
        node n = query(ql, qr);
        n.show();
        cout << endl;
    }
    void showTree() {
        showTree(1, 0, size-1);
        cout << endl;
    }
    int getLastBridge(int t) { //O(log n) minimum prefix sum with the index <= t
        node n = query(0, t);
        if(n.mn != 0) return 0; //if there is no bridge
        return n.maxIndexMinimum;
    }
    int getNextBridge(int t) { //O(log n) minimum prefix sum with the index >= t
        node n = query(t, size-1);
        if(n.mn != 0) return size-1; //if there is no bridge
        return n.minIndexMinimum;
    }
};
