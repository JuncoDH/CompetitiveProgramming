template<typename T>
struct node{
    T value = numeric_limits<T>::max(); //MIN query
    T lazy = 0;    //SUM update
    int id = -1;
    node(T _value) {value = _value;}
    node() {} //Dummy node
};

template<typename T>
class lazy_seg{ //SUM update + MIN query
    vector<node<T>> tree;
    vector<T> v_input;
    int _size;

    void build(int k, int l, int r) {
        if(l == r) {tree[k] = node<T>(v_input[l]); tree[k].id = l; return;}
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid+1, r);
        tree[k] = f(tree[k<<1], tree[k<<1|1]);
    }
    
    void push(int k, int l, int r) { //actualize lazy push
        if(l != r) {
            actualize_update(k<<1, tree[k].lazy);
            actualize_update(k<<1|1, tree[k].lazy);
        }
        tree[k].lazy = 0; //Sum update
    }
    void actualize_update(int k, T x) { //actualize when the range is in the update range
        tree[k].value += x; // MIN-MAX query
        tree[k].lazy += x; // SUM update
    }
    node<T> f(node<T> a, node<T> b) { //merge nodes, function
        node<T> n(min(a.value, b.value)); // MIN tree query
        n.id = a.value < b.value ? a.id : b.id; // MIN tree query
        return n;
    }
    //Don't change, implementation below -------------------------------------------------------
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

    //INTERFACE, Don't change ------------------------------------------------------
    public:
    lazy_seg(int __size, vector<T> v) {
        _size = __size;
        tree.assign(4*__size, {});
        v_input = v;
        build(1, 0, __size-1);
    }
    
    void update(int ql, int qr, T x) {
        update(1, 0, _size-1, ql, qr, x);
    }
    node<T> query(int ql, int qr) {
        return query(1, 0, _size-1, ql, qr);
    }
    void showt() {//debug tree
        for(int i = 1; i < 2*_size; i++) {
            cout << "(" << tree[i].value << "," << tree[i].lazy << ")   ";
            if(i+1 == LSB(i+1)) cout << endl;
        }cout << endl;
    }
    void showv(string s = "") {//debug vector
        cout << s << endl;
        for(int i = 0; i < _size; i++) cout << query(i, i).value << " ";
        cout << endl; 
    }
};
