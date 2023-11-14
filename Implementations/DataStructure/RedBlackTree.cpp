class node {
    public:
    static constexpr int BLACK = 0;
    static constexpr int RED = 1;
    ll value = 0;
    node* l = nullptr, *r = nullptr, *p = nullptr;
    int color = BLACK;
    node() = default;
    node(ll const _value) {
        value = _value;
        l = new node(); l->p = this;
        r = new node(); r->p = this;
    }
    ~node() { delete l; delete r; }
    bool is_leaf() const {
        return l == nullptr && r == nullptr;
    }
};
// Satisfying this properties implies that the height of the tree is O(log n).
// 1 - A node is red or black.
// 2 - Root and leaves (NULL) are black.
// 3 - If a node is red its children are black.
// 4 - All paths node->leaf contain the same number of black nodes.
class RedBlackTree {
    void left_rotation(node* n) {
        node* ans = n->r;
        n->r = ans->l;
        ans->l->p = n;
        ans->l = n;
        ans->p = n->p;
        if(n->p && n->p->r == n) n->p->r = ans;
        if(n->p && n->p->l == n) n->p->l = ans;
        n->p = ans;
        if(n == root) root = ans;
    }
    void right_rotation(node* n) {
        node* ans = n->l;
        n->l = ans->r;
        ans->r->p = n;
        ans->r = n;
        ans->p = n->p;
        if(n->p && n->p->r == n) n->p->r = ans;
        if(n->p && n->p->l == n) n->p->l = ans;
        n->p = ans;
        if(n == root) root = ans;
    }
    void insert_fixup(node* z) {
        while(z != root && z->p->color == node::RED) {
            if(z->p == z->p->p->l) { // parent is left child.
                if(z->p->p->r->color == node::RED) {
                    z->p->p->r->color = node::BLACK;
                    z->p->color = node::BLACK;
                    z->p->p->color = node::RED;
                    z = z->p->p;
                } else {
                    if(z == z->p->r) {
                        z = z->p;
                        left_rotation(z);
                    }
                    z->p->color = node::BLACK;
                    z->p->p->color = node::RED;
                    right_rotation(z->p->p);
                    break;
                }
            } else { // parent is right child.
                if(z->p->p->l->color == node::RED) {
                    z->p->p->l->color = node::BLACK;
                    z->p->color = node::BLACK;
                    z->p->p->color = node::RED;
                    z = z->p->p;
                } else {
                    if(z == z->p->l) {
                        z = z->p;
                        right_rotation(z);
                    }
                    z->p->color = node::BLACK;
                    z->p->p->color = node::RED;
                    left_rotation(z->p->p);
                    break;
                }
            }
        }
        root->color = node::BLACK;
    }
    static node* get_next_higher(node* u) { // Get next higher node. u has to have 2 children.
        u = u->r;
        while(!u->l->is_leaf()) u = u->l;
        return u;
    }
    static void dfs_get_elements(node const* u, vll& v) {
        if(u->is_leaf()) return;
        dfs_get_elements(u->l, v);
        v.pb(u->value);
        dfs_get_elements(u->r, v);
    }
    void erase_fixup(node* x) {
        node* w = nullptr; // Sibling of x, allways has children.
        while(x != root && x->color == node::BLACK) {
            if(x == x->p->l) {
                w = x->p->r;
                if(w->color == node::RED) {
                    w->color = node::BLACK;
                    w->p->color = node::RED;
                    left_rotation(w->p);
                    w = x->p->r;
                }
                if(w->l->color == node::BLACK && w->r->color == node::BLACK) {
                    w->color = node::RED;
                    x = x->p;
                } else {
                    if(w->r->color == node::BLACK) {
                        w->color = node::RED;
                        w->l->color = node::BLACK;
                        right_rotation(w);
                        w = x->p->r;
                    }
                    w->color = x->p->color;
                    x->p->color = node::BLACK;
                    w->r->color = node::BLACK;
                    left_rotation(x->p);
                    break;
                }
            } else {
                w = x->p->l;
                if(w->color == node::RED) {
                    w->color = node::BLACK;
                    w->p->color = node::RED;
                    right_rotation(w->p);
                    w = x->p->l;
                }
                if(w->l->color == node::BLACK && w->r->color == node::BLACK) {
                    w->color = node::RED;
                    x = x->p;
                } else {
                    if(w->l->color == node::BLACK) {
                        w->color = node::RED;
                        w->r->color = node::BLACK;
                        left_rotation(w);
                        w = x->p->l;
                    }
                    w->color = x->p->color;
                    x->p->color = node::BLACK;
                    w->l->color = node::BLACK;
                    right_rotation(x->p);
                    break;
                }
            }
        }
        x->color = node::BLACK;
    }
    public:
    node* root = new node();
    ~RedBlackTree() { delete root; }
    bool search(ll const key) const {
        node *n = root;
        while(!n->is_leaf()) {
            if(key == n->value) return true;
            if(key < n->value) n = n->l;
            else n = n->r;
        }
        return false;
    }
    void insert(ll const key) {
        node* x = root;
        node* z = new node(key);
        if(root->is_leaf()) {
            delete root;
            root = z;
            return;
        }
        z->color = node::RED;
        while(!x->is_leaf()) {
            if(key == x->value) { delete z; return; } // Not insert duplicates.
            if(key < x->value) x = x->l;
            else x = x->r;
        }
        x = x->p;
        z->p = x;
        if(key < x->value) { delete x->l; x->l = z; }
        else { delete x->r; x->r = z; }
        insert_fixup(z);
    }
    void erase(ll const key) {
        node* z = root; // The node to remove.
        node* y = nullptr; // The real node to remove.
        node* x = nullptr; // The node that has been shifted.
        if(root->is_leaf()) return; // Empty tree.
        while(key != z->value) {
            if(z->is_leaf()) return; // Element not inserted.
            if(key < z->value) z = z->l;
            else z = z->r;
        }
        if(z->is_leaf()) return; // Element not inserted.
        if(z->l->is_leaf() || z->r->is_leaf()) y = z;
        else y = get_next_higher(z);
        if(y->r->is_leaf()) { delete y->r; x = y->l; }
        else { delete y->l; x = y->r; }
        x->p = y->p;
        if(y->p == nullptr) root = x;
        else if(y == y->p->l) y->p->l = x;
        else y->p->r = x;
        if(y != z) z->value = y->value;
        if(y->color == node::BLACK)
            erase_fixup(x);
        y->r = y->l = nullptr;
        delete y;
    }
    vll get_elements() const {
        vll ans;
        dfs_get_elements(root, ans);
        return ans;
    }
};

