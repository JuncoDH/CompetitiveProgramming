add srand
// paper: https://erikdemaine.org/papers/Retroactive_TALG/paper.pdf
// video: https://www.youtube.com/watch?v=WqCWghETNDc&list=WL&index=11&t=0s
// problem: https://codeforces.com/blog/entry/74961#comment-590583
template<typename K, typename V> //key (unique) and value (data)
class Treap {
    const pair<V, K> MINVK = mp(numeric_limits<V>::min(), numeric_limits<K>::min());
    const pair<V, K> MAXVK = mp(numeric_limits<V>::max(), numeric_limits<K>::max());
    struct node {
        K key; //unique, time or x-axis for example
        V data; // f[key] = data
        node* l = NULL, *r = NULL;
        int priority;
        pair<V, K> mx, mn; //maximum and minimum values over all subtrees, V 1º to be comparable <
        node(K _key, V _data) {
            key = _key;
            data = _data;
            mx = mn = mp(_data, _key);
            priority = rand();//((ll)rand()<<16)^(ll)rand(); //hope there is no collision...
        }
    };
    typedef node* pnode;
    pnode root = NULL;
    pair<V, K> getMaximumVK(pnode t) { //O(1)
        if(!t) return MINVK;
        else return t->mx;
    }
    pair<V, K> getMinimumVK(pnode t) { //O(1)
        if(!t) return MAXVK;
        else return t->mn;
    }
    void update (pnode t) {
        if(!t) return;
        t->mx = max({mp(t->data, t->key), getMaximumVK(t->l), getMaximumVK(t->r)});
        t->mn = min({mp(t->data, t->key), getMinimumVK(t->l), getMinimumVK(t->r)});
    }
    //return a subtree l and r such as key(l) < key < key(r), similar to rotations
    void split(pnode t, pnode& l, pnode& r, K key) {
        if(!t) l = r = NULL;
        else if(key < t->key) split(t->l, l, t->l, key), r = t;
        else split(t->r, t->r, r, key), l = t;
        update(t);
    }
    //merge two trees l and r into one, t, allKey(l) < allKey(r)
    void merge(pnode &t, pnode l, pnode r) {
        if(!l || !r) t = l ? l : r;
        else if(l->priority < r->priority) merge(r->l, l, r->l), t = r;
        else merge(l->r, l->r, r), t = l;
        update(t);
    }
    void insert(pnode &t, pnode it) {
        if(!t) t = it;
        else if(t->priority < it->priority) split(t, it->l, it->r, it->key), t = it;
        else insert(it->key < t->key ? t->l : t->r, it);
        update(t);
    }
    void erase(pnode &t, K key) { //only erase if the element exists
        if(!t) {echo("estas borrando pero no esta:", key); exit(-1);}
        if(t->key == key) merge(t, t->l, t->r);
        else erase(key < t->key ? t->l : t->r, key);
        update(t);
    }
    void showTree(pnode t) { //preOrder, the inOrder is the tree sorted 
        if(!t) return;
        cout << "(" << t->key << "," << t->data << ")";
        showTree(t->l); showTree(t->r);
    }
    // UP CONSTRUCTION, BELOW QUERIES
    pair<V, K> getMaximumAfter(pnode t, K key) { //max node with key >= t, O(log(n))
        if(!t) return MINVK;
        pair<V, K> mid = t->key >= key ? mp(t->data, t->key) : MINVK;
        if(key < t->key) return max({getMaximumAfter(t->l, key), getMaximumVK(t->r), mid}); //maybe equals also here
        else return max({getMaximumAfter(t->r, key), mid});
    }
    pair<V, K> getMinimumBefore(pnode t, K key) { //min node with key <= t, O(log(n))
        if(!t) return MAXVK;
        pair<V, K> mid = t->key <= key ? mp(t->data, t->key): MAXVK;
        if(key > t->key) return min({getMinimumBefore(t->r, key), getMinimumVK(t->l), mid});
        else return min({getMinimumBefore(t->l, key), mid});
    }
    public:
    void insert(K key, V data) { //O(log n)
        pnode n = new node(key, data);
        insert(root, n);
    }
    void erase(K key) { //O(log n)
        erase(root, key);
    }
    void showTree() { //debug
        showTree(root);
        cout << endl;
    }
    pair<V, K> getMaximumAfter(K t) { //O(log n)
        return getMaximumAfter(root, t);
    }
    pair<V, K> getMinimumBefore(K t) { //O(log n)
        return getMinimumBefore(root, t);
    }
    pair<V, K> getMaximumAll() { //all the tree, O(1)
        return getMaximumVK(root);
    }
    pair<V, K> getMinimumAll() { //all the tree, O(1)
        return getMinimumVK(root);
    }
};
template<typename T>
class SegmentTreePrefixSum { //searching minimum prefix sum and it's index, 0-based
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
        return query(1, 0, size-1, ql, qr);
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
//push and pop in the past and query in the present. It's minimum pq, for maximum push(-num)
template<typename T> //int, ll
class PartialRetroactivePriorityQueue {
    Treap<int, T> qnow; //the elements that are in Qnow
    Treap<int, T> nqnow; //the elements that are NOT in Qnow
    SegmentTreePrefixSum<T> bridge; //if the query(t', t') == 0, there is a bridge in t'
    public:
    PartialRetroactivePriorityQueue() = default;
    PartialRetroactivePriorityQueue(int _size) {
        bridge = SegmentTreePrefixSum<T>(_size);
    }
    void insertPush(int t, T data){//Insert(t, "insert(data)") O(log n)
        int tl = bridge.getLastBridge(t);
        nqnow.insert(t, data);
        bridge.update(t, 1);
        pair<T, int> add = nqnow.getMaximumAfter(tl);
        nqnow.erase(add.second);
        qnow.insert(add.second, add.first);
        bridge.update(add.second, -1);
    }
    void insertPop(int t) { //Insert(t, "pop_min()"). Be sure in all t, num Push >= num Pop O(log n)
        int tl = bridge.getNextBridge(t);
        bridge.update(t, -1);
        pair<T, int> rem = qnow.getMinimumBefore(tl);
        qnow.erase(rem.second);
        nqnow.insert(rem.second, rem.first);
        bridge.update(rem.second, 1);
    }
    T getPeak() {// get minimum of the rpq in Qnow. Be sure the rpq is not empty. O(1)
        return qnow.getMinimumAll().first;
    }
};

