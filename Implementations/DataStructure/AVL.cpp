class Node {
    int height = 1;
    void update_height() {
        if(l) height = max(height, l->height + 1);
        if(r) height = max(height, r->height + 1);
    }
    int get_balance() const {
        int ret = 0; // r->height - l->height.
        if(r) ret += r->height;
        if(l) ret -= l->height;
        return ret;
    }
    void right_rotate() {
        Node *ans = l; // The new parent.
        l = ans->r;
        if(ans->r) ans->r->p = this;
        ans->r = this;
        ans->p = p;
        if(p && p->l == this) p->l = ans;
        if(p && p->r == this) p->r = ans;
        p = ans;
        update_height();
        ans->update_height();
    }
    void left_rotate() {
        Node *ans = r; // The new parent.
        r = ans->l;
        if(ans->l) ans->l->p = this;
        ans->l = this;
        ans->p = p;
        if(p && p->l == this) p->l = ans;
        if(p && p->r == this) p->r = ans;
        p = ans;
        update_height();
        ans->update_height();
    }
    public:
    Node *l = nullptr, *r = nullptr, *p = nullptr;
    ll value = 0;
    Node() = default;
    explicit Node(ll const _value) { value = _value; }
    ~Node() { delete l; delete r; }
    void balance() {
        int balance = get_balance(), balance_l = 0, balance_r = 0;
        if(l) balance_l = l->get_balance();
        if(r) balance_r = r->get_balance();
        if(balance < -1 && balance_l <= 0){
            right_rotate();
        }
        if(balance < -1 && balance_l > 0) {
            l->left_rotate();
            right_rotate();
        }
        if(balance > 1 && balance_r >= 0) {
            left_rotate();
        }
        if(balance > 1 && balance_r < 0) {
            r->right_rotate();
            left_rotate();
        }
        if(p) p->balance();
    }
    void get_elements(vll& ret) const {
        if(l) l->get_elements(ret);
        ret.pb(value);
        if(r) r->get_elements(ret);
    }
};
class AVL {
    Node *root = nullptr;
    public:
    ~AVL() { delete root; }
    bool search(ll const num) const {
        Node *n = root;
        if(!root) return false;
        while(n) {
            if(num == n->value) return true;
            if(num < n->value) n = n->l;
            else n = n->r;
        }
        return false;
    }
    void insert(ll const num) {
        Node *n = root, *nw_node = new Node(num);
        if(!root) {
            root = nw_node;
            return;
        }
        while(true) {
            if(num < n->value) {
                if(!n->l) { n->l = nw_node; nw_node->p = n; break; }
                n = n->l;
            } else if(num > n->value) {
                if(!n->r) { n->r = nw_node; nw_node->p = n; break; }
                n = n->r;
            } else {
                delete nw_node;
                return; // Already inserted.
            }
        }
        n->balance();
        while(n->p) { n = n->p; }
        root = n;
    }
    void erase(ll const num) {
        Node *n = root, *x = nullptr; // x the node to erase.
        while(n) {
            if(num == n->value) break;
            if(num < n->value) n = n->l;
            else n = n->r;
        }
        if(!n) return; // Element not inserted.
        if(!n->r) {
            if(!n->p) root = n->l;
            else if(n == n->p->l) n->p->l = n->l;
            else if(n == n->p->r) n->p->r = n->l;
            if(n->l) n->l->p = n->p;
            if(n->p) n->p->balance();
            n->l = n->r = nullptr;
            delete n;
            return;
        }
        x = n->r;
        while(x->l) x = x->l;
        swap(n->value, x->value);
        if(x->p && x == x->p->l) x->p->l = x->r;
        if(x->p && x == x->p->r) x->p->r = x->r;
        if(x->r) x->r->p = x->p;
        if(x->p) x->p->balance();
        x->l = x->r = nullptr;
        delete x;
    }
    vll get_elements() const {
        vll ans;
        root->get_elements(ans);
        return ans;
        } // Return the next highest element > num, or inf if there is none.
    ll next(ll const num) const {
        ll ans = inf;
        if(!root) return ans;
        Node *n = root;
        while(n) {
            if(num < n->value) {
                ans = min(ans, n->value);
                n = n->l;
            } else {
                n = n->r;
            }
        }
        return ans;
    }
};

