class Node {
    public:
    ll value = 0;
    Node* l = nullptr, *r = nullptr, *p = nullptr;
    Node() = default;
    Node(ll const _value) { value = _value; }
    ~Node() { delete l; delete r; }
    bool is_leaf() const {
        return l == nullptr && r == nullptr;
    }
};
class SplayTree {
    void left_rotation(Node* n) {
        Node* ans = n->r;
        n->r = ans->l;
        if(ans->l) ans->l->p = n;
        ans->l = n;
        ans->p = n->p;
        if(n->p && n->p->r == n) n->p->r = ans;
        if(n->p && n->p->l == n) n->p->l = ans;
        n->p = ans;
        if(n == root) root = ans;
    }
    void right_rotation(Node* n) {
        Node* ans = n->l;
        n->l = ans->r;
        if(ans->r) ans->r->p = n;
        ans->r = n;
        ans->p = n->p;
        if(n->p && n->p->r == n) n->p->r = ans;
        if(n->p && n->p->l == n) n->p->l = ans;
        n->p = ans;
        if(n == root) root = ans;
    }
    void splay(Node* n) { // Move n to the root.
        while(true) {
            Node* p = n->p; // Parent.
            if(!p) break;
            Node* pp = p->p; // Grand parent.
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
    static void dfs_get_elements(Node const* u, vll& v) const {
        if(!u) return;
        dfs_get_elements(u->l, v);
        v.pb(u->value);
        dfs_get_elements(u->r, v);
    }
    public:
    Node* root = nullptr;
    ~SplayTree() { delete root; }
    void insert(ll const value) {
        Node* n = root, *nw = new Node(value);
        if(!root) {
            root = nw;
            return;
        }
        while(true) {
            if(n->value == value) { delete nw; return; } // Not multiset.
            if(n->value < value) {
                if(n->r) n = n->r;
                else { n->r = nw; break; }
            }
            else {
                if(n->l) n = n->l;
                else { n->l = nw; break; }
            }
        }
        nw->p = n;
        splay(nw);
    }
    bool find(ll const value) {
        Node* n = root;
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
    void erase(ll const value) {
        if(!find(value)) return; // Not inserted.
        Node* n = root;
        Node* p = n->r; // Next higher node.
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
    vll get_elements() const {
        vll ans;
        dfs_get_elements(root, ans);
        return ans;
    } // Return the next highest element > num, or inf if there is none.
    ll next(ll const num) const {
        ll ans = inf;
        if(!root) return ans;
        Node* n = root;
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

