class Node {
    public:
    Node* r = nullptr; // Root list and child list, sorted < degree, finishing in nullptr.
    Node* c = nullptr; // Biggest child, sorted > degree.
    int degree = 0; // Number of direct children. It has log n.
    int value = 0; // Value of the node, int, ll...
    explicit Node(int const _value) {
        value = _value;
    }
    ~Node() { delete c; delete r; }
    void insert_child(Node* n) { // Insert n as a child of this.
        if(!n) return;
        n->r = c;
        c = n;
        ++degree;
    }
    static Node* merge(Node* a, Node* b) { // Merge nodes with same degree.
        if(a->value >= b->value) swap(a, b);
        a->insert_child(b);
        a->r = nullptr; // Isolate the ans tree.
        return a;
    }
};
// Min Heap.
class BinomialHeap {
    int n_nodes = 0;
    Node* merge_next(Node* ans, Node* n) {
        if(!ans) return root = ans = n;
        return ans->r = n;
    }
    public:
    Node* root = nullptr;
    BinomialHeap() = default;
    ~BinomialHeap() { delete root; }
    void merge(BinomialHeap const& bh) { // Add bh nodes to this.
        n_nodes += bh.n_nodes;
        Node* a = root;
        Node* b = bh.root;
        Node* tmp = nullptr;
        Node* ans = nullptr;
        Node* nxta = nullptr;
        Node* nxtb = nullptr;
        while(a && b) {
            if(tmp && tmp->degree < min(a->degree, b->degree)) {
                ans = merge_next(ans, tmp);
                tmp = nullptr;
                continue;
            }
            if(a->degree > b->degree) swap(a, b);
            if(a->degree < b->degree) {
                if(tmp) {
                    nxta = a->r;
                    tmp = Node::merge(a, tmp);
                    a = nxta;
                } else {
                    ans = merge_next(ans, a);
                    a = a->r;
                }
            } else {
                if(tmp) {
                    ans = merge_next(ans, tmp);
                    tmp = nullptr;
                }
                nxta = a->r;
                nxtb = b->r;
                tmp = Node::merge(a, b);
                a = nxta;
                b = nxtb;
            }
        }
        if(b) swap(a, b);
        while(a && tmp) {
            if(tmp->degree < a->degree) {
                ans = merge_next(ans, tmp);
                tmp = nullptr;
            } else {
                nxta = a->r;
                tmp = Node::merge(a, tmp);
                a = nxta;
            }
        }
        if(a) ans = merge_next(ans, a);
        if(tmp) ans = merge_next(ans, tmp);
    }
    void push(int const value) {
        Node* n = new Node(value);
        ++n_nodes;
        BinomialHeap bh;
        bh.root = n;
        merge(bh);
        bh.root = nullptr;
    }
    int top() const { // Get minimum element.
        int ans = INT_MAX;
        Node* n = root;
        while(n) {
            ans = min(ans, n->value);
            n = n->r;
        }
        return ans;
    }
    void pop() { // Extract the minimum element.
        if(!root) return;
        int mn = top();
        Node* n = root;
        Node* tmp = nullptr;
        if(n->value == mn) root = n->r;
        else {
            while(n->r->value != mn) n = n->r;
            tmp = n->r;
            n->r = n->r->r;
            n = tmp;
        }
        n_nodes--;
        if(!n->c) { n->r = nullptr; delete n; return; }
        BinomialHeap bh;
        vector<Node*> v;
        tmp = n->c;
        while(tmp) { v.pb(tmp); tmp = tmp->r; }
        reverse(v.begin(), v.end());
        for(int i = 0; i < (int)v.size() - 1; ++i) v[i]->r = v[i + 1];
        v.back()->r = nullptr;
        bh.root = v[0];
        merge(bh);
        bh.root = nullptr;
        n->c = n->r = nullptr; delete n;
    }
    int size() const {
        return n_nodes;
    }
    bool empty() const {
        return n_nodes == 0;
    }
};

