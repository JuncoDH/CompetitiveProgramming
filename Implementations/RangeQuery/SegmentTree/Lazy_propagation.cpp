const pii default_lazy_value = {-1, -1}; // -1 SET update (0 if SUM update).

template<typename T>
struct node{
    T value = numeric_limits<T>::min(); // MAX query.
    T lazy = default_lazy_value; 
    int pos_i = -1; // Index of the query result in the array.
    node(T _value) {value = _value;}
    node() {} // Dummy node.
};

template<typename T>
class lazy_seg{ // SET value to a range + MAX query.
    vector<node<T>> tree;
    vector<T> v_input;
    int _size;
    
    void push(int k, int l, int r) { // actualize lazy push.
        if(l != r) {
            actualize_update(k<<1, tree[k].lazy);
            actualize_update(k<<1|1, tree[k].lazy);
        }
        tree[k].lazy = default_lazy_value;
    }
    void actualize_update(int k, T x) { // actualize when the range is in the update range.
        if(x == default_lazy_value) return; // SET update, comment for SUM update.
        tree[k].value = x; // MIN-MAX query. (= if SET update), (+ if SUM update).
        tree[k].lazy = x; // (= if SET update), (+ if SUM update).
    }
    node<T> f(node<T> a, node<T> b) { // merge nodes, function.
        node<T> n(max(a.value, b.value)); // MAX query.
        n.pos_i = a.value > b.value ? a.pos_i : b.pos_i; // MAX query.
        return n;
    }
    // DONT CHANGE BELOW -------------------------------------------------------
    void build(int k, int l, int r) {
        if(l == r) {tree[k] = node<T>(v_input[l]); tree[k].pos_i = l; return;}
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid+1, r);
        tree[k] = f(tree[k<<1], tree[k<<1|1]);
    }
    void update(int k, int l, int r, int ql, int qr, T x) {
        push(k, l, r);
        if(r < ql || qr < l) {}
        else if(ql <= l && r <= qr) {
            actualize_update(k, x);
            return;
        } else {
            int mid = (l + r) >> 1;
            update(k<<1, l, mid, ql, qr, x);
            update(k<<1|1, mid+1, r, ql, qr, x);
        }
        if(l != r)
            tree[k] = f(tree[k<<1], tree[k<<1|1]);
    }
    node<T> query(int k, int l, int r, int ql, int qr) {
        push(k, l, r);
        node<T> ans;
        if(r < ql || qr < l) ans = node<T>();
        else if(ql <= l && r <= qr) ans = tree[k];
        else {
            int mid = (l + r) >> 1;
            node<T> a = query(k<<1, l, mid, ql, qr);
            node<T> b = query(k<<1|1, mid+1, r, ql, qr);
            ans = f(a, b);
        }
        if(l != r)
            tree[k] = f(tree[k<<1], tree[k<<1|1]);
        return ans;
    }

    public:
    lazy_seg(vector<T> v) {
        _size = (int) v.size();
        tree.assign(4*_size, {});
        v_input = v;
        build(1, 0, _size - 1);
    }
    lazy_seg(int __size) {
        _size = __size;
        tree.assign(4*_size, {});
        v_input = vector<T>(__size, mp(0, 0)); // default vector value.
        build(1, 0, _size - 1);
    }  
    void update(int ql, int qr, T x) {
        update(1, 0, _size-1, ql, qr, x);
    }
    pair<T, int> query(int ql, int qr) { // Returns the value T and its index position.
        node<T> n = query(1, 0, _size-1, ql, qr);
        return mp(n.value, n.pos_i);
    }
    void showt() { // debug tree.
        for(int i = 1; i < 2*_size; i++) {
            cout << "(" << tree[i].value << "," << tree[i].lazy << ")   ";
            if(i+1 == LSB(i+1)) cout << endl;
        }cout << endl;
    }
    void showv(string s = "") { // debug vector.
        cout << s << endl;
        for(int i = 0; i < _size; i++) cout << query(i, i).value << " ";
        cout << endl; 
    }
};
