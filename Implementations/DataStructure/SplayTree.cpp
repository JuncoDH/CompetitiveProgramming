class node{
    public:
    ll value = 0;
    node *l = nullptr, *r = nullptr, *p = nullptr;
    node() = default;
    node(ll _value) {value = _value;}
    ~node() {delete l; delete r;}
    bool is_leaf() {
        return l == nullptr && r == nullptr;
    }
};
class SplayTree{
    void left_rotation(node *n) {
        node *ans = n->r;
        n->r = ans->l;
        if(ans->l) ans->l->p = n;
        ans->l = n;
        ans->p = n->p;
        if(n->p && n->p->r == n) n->p->r = ans;
        if(n->p && n->p->l == n) n->p->l = ans;
        n->p = ans;
        if(n == root) root = ans;
    }
    void right_rotation(node *n) {
        node *ans = n->l;
        n->l = ans->r;
        if(ans->r) ans->r->p = n;
        ans->r = n;
        ans->p = n->p;
        if(n->p && n->p->r == n) n->p->r = ans;
        if(n->p && n->p->l == n) n->p->l = ans;
        n->p = ans;
        if(n == root) root = ans;
    }
    void splay(node *n) { // Move n to the root.
        while(true) {
            node *p = n->p; // Parent.
            if(!p) break;
            node *pp = p->p; // Grand parent.
            if(!pp) { // Zig.
                if(n == p->l) right_rotation(p);
                else left_rotation(p);
                break;
            }
            if(p == pp->l) {
                if(n == p->l) { // Zig zig.
                    right_rotation(pp);
                    right_rotation(p);
                } else { // Zig zag.
                    left_rotation(p);
                    right_rotation(pp);
                }
            } else {
                if(n == p->l) { // Zig zag.
                    right_rotation(p);
                    left_rotation(pp);
                } else { // Zig zig.
                    left_rotation(pp);
                    left_rotation(p);
                }
            }
        }
        root = n;
    }
    void dfs_get_elements(node *u, vll &v) {
        if(!u) return;
        dfs_get_elements(u->l, v);
        v.pb(u->value);
        dfs_get_elements(u->r, v);
    }
    public:
    node *root = nullptr;
    ~SplayTree() {delete root;}
    void insert(ll value) {
        node *n = root, *nw = new node(value);
        if(!root) {
            root = nw;
            return;
        }
        while(true) {
            if(n->value == value) {delete nw; return;} // Not multiset.
            if(n->value < value) {
                if(n->r) n = n->r;
                else {n->r = nw; break;}
            }
            else{
                if(n->l) n = n->l;
                else {n->l = nw; break;}
            }
        }
        nw->p = n;
        splay(nw);
    }
    bool find(ll value) {
        node *n = root;
        if(!root) return false;
        while(true) {
            if(n->value == value) break;
            if(n->value < value) {
                if(!n->r) break;
                n = n->r;
            }
            else {
                if(!n->l) break;
                n = n->l;
            }
        }
        splay(n);
        return n->value == value;
    }
    void erase(ll value) {
        if(!find(value)) return; // Not inserted.
        node *n = root;
        node *p = n->r; // Next higher node.
        if(!p) {
            root = n->l;
            if(root) root->p = nullptr;
            n->l = n->r = nullptr;
            delete n;
            return;
        }
        while(p->l) p = p->l;
        n->value = p->value;
        if(!n->r->l) {
            n->r = p->r;
            if(p->r) p->r->p = n;
        } else {
            p->p->l = p->r;
            if(p->r) p->r->p = p->p;
        }
        p->l = p->r = nullptr;
        delete p;
    }
    vll get_elements() {
        vll ans;
        dfs_get_elements(root, ans);
        return ans;
    }
};

