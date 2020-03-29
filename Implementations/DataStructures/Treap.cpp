//https://cp-algorithms.com/data_structures/treap.html
//not implemented: find_by_order, order_of_key, find/search
template<typename K, typename V> //key (unique) and value (data)
class Treap {
    const pair<V, K> MINVK = mp(numeric_limits<V>::min(), numeric_limits<K>::min());
    const pair<V, K> MAXVK = mp(numeric_limits<V>::max(), numeric_limits<K>::max());
    struct node {
        K key; //unique, time or x-axis for example
        V data; // f[key] = data
        node *l = NULL, *r = NULL;
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
    void split(pnode t, pnode &l, pnode &r, K key) {
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
