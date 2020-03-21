const ll MAX = //3*1e5+2; //Change, MAX size of the vector

struct node{
    ll value, lazy;    //Change, type of value stored
    node() {value = 0; lazy = 0;}//Change, value by default
    node(bool is_dummy) {value = -inf, lazy = 0;(void)is_dummy;} //Change, dummy node for queries out of range
};

struct lazy_seg{ //SUM update + MAX query
    vector<node> tree;
    ll _size;

    lazy_seg(ll __size) {
        _size = __size;
        tree.assign(4*__size, {});
    }
    void push(ll k, ll l, ll r) { //actualize lazy push
        if(l != r) {//Change, SUM tree update
            tree[k<<1].value += tree[k].lazy;
            tree[k<<1|1].value += tree[k].lazy;
            tree[k<<1].lazy += tree[k].lazy;
            tree[k<<1|1].lazy += tree[k].lazy;
        }
        tree[k].lazy = 0;
    }
    void actualize_update(ll k, ll x) { //actualize when the range is in the update range
        tree[k].value += x; //Change, MAX tree update value
        tree[k].lazy += x; //Change, SUM tree update lazy
    }
    node f(node a, node b) { //merge nodes, function
        node n;
        n.value = max(a.value, b.value); //Change, MAX tree query
        return n;
    }
    //Don't change, implementation below -------------------------------------------------------
    void update(ll k, ll l, ll r, ll ql, ll qr, ll x) {
        push(k, l, r);
        if(r < ql || qr < l) {}
        else if(ql <= l && r <= qr) {
            actualize_update(k, x);
            return;
        } else {
            ll mid = (l + r) >> 1;
            update(k<<1, l, mid, ql, qr, x);
            update(k<<1|1, mid+1, r, ql, qr, x);
        }
        if(l != r)
            tree[k] = f(tree[k<<1], tree[k<<1|1]);
    }

    node query(ll k, ll l, ll r, ll ql, ll qr) {
        push(k, l, r);
        node ans;
        if(r < ql || qr < l) ans = node(true);
        else if(ql <= l && r <= qr) ans = tree[k];
        else {
            ll mid = (l + r) >> 1;
            node a = query(k<<1, l, mid, ql, qr);
            node b = query(k<<1|1, mid+1, r, ql, qr);
            ans = f(a, b);
        }
        if(l != r)
            tree[k] = f(tree[k<<1], tree[k<<1|1]);
        return ans;
    }

    //INTERFACE, Don't change ------------------------------------------------------
    void update(ll ql, ll qr, ll x) {
        update(1, 0, _size-1, ql, qr, x);
    }
    node query(ll ql, ll qr) {
        return query(1, 0, _size-1, ql, qr);
    }
    void showt() {//debug tree
        for(ll i = 1; i < 2*_size; i++) {
            cout << "(" << tree[i].value << "," << tree[i].lazy << ")   ";
            if(i+1 == LSB(i+1)) cout << endl;
        }cout << endl;
    }
    void showv() {//debug vector
        for(ll i = 1; i < _size; i++) cout << query(i, i).value << " ";
        cout << endl; 
    }

} t(MAX);
