class Node{
    public:
    Node* p = nullptr; // Parent.
    Node* l = nullptr; // Double linked list (c, c->r, c->r->r, ..., ->c).
    Node* r = nullptr; // l and r wont be nullptr.
    Node* c = nullptr; // One child. 
    int degree = 0; // Number of direct children. It has O(log n).
    int value = 0; // Value of the node, int, ll...
    explicit Node(int const _value) {
        value = _value;
        l = this;
        r = this;
    } // n->l <-> this <-> n.
    void insert_left(Node* n) {
        if(!n) return;
        l = n->l;
        r = n;
        n->l->r = this;
        n->l = this;
    } // Add n as a child of this.
    void insert_child(Node* n) {
        if(!n) return;
        n->p = this;
        if(!c) c = n->l = n->r = n;
        else n->insert_left(c);
        degree++;
    }
};
// Min Heap.
class FibonacciHeap{
    void consolidate() { // Compress and recalculate min_el.
        int d, D = log2(n_nodes+1) + 2;
        vector<Node *> vn(D, nullptr);
        Node* n = min_el;
        Node* y = nullptr;
        Node* next_n = n->r;
        Node* prev_node = min_el;
        Node* end_node = min_el->l;
        while(true) {
            d = n->degree;
            while(vn[d]) {
                y = vn[d];
                if(n->value > y->value) swap(n, y);
                y->l->r = y->r;
                y->r->l = y->l;
                n->insert_child(y);
                vn[d] = nullptr;
                d++;
            }
            vn[d] = n;
            if(prev_node == end_node) break;
            n = next_n;
            prev_node = n;
            next_n = next_n->r;
        }
        min_el = nullptr;
        for(int i = 0; i < D; i++) {
            if(!vn[i]) continue;
            vn[i]->l = vn[i]->r = vn[i];
            if(min_el) vn[i]->insert_left(min_el);
            if(!min_el || vn[i]->value < min_el->value) min_el = vn[i];
        }
    }
    int n_nodes = 0;
    static void release_memory(Node* n) {
        if(!n) return;
        release_memory(n->c);
        Node* end_node = n;
        Node* prev_node = nullptr;
        do{
            prev_node = n;
            n = n->r;
            delete prev_node;
        } while(n != end_node);
    }
    public:
    Node *min_el = nullptr;
    FibonacciHeap() = default;
    ~FibonacciHeap() {release_memory(min_el);}
    void push(int const value) {
        Node *n = new Node(value);
        if(min_el) n->insert_left(min_el);
        if(!min_el || n->value < min_el->value) min_el = n;
        n_nodes++;   
    }
    int top() const { // Get minimum element.
        if(!min_el) return INT_MAX;
        return min_el->value;
    }
    void merge(FibonacciHeap const& fh) { // Add fh nodes to this.
        if(!min_el) {
            min_el = fh.min_el;
        } else if(fh.min_el) {
            min_el->insert_left(fh.min_el);
            if(fh.min_el->value < min_el->value) 
                min_el = fh.min_el;
        }
        n_nodes += fh.n_nodes;
    }
    void pop() { // Extract the minimum element.
        if(!min_el) return;
        Node* z = min_el; // Node to delete.
        if(z->c) {
            Node* first_c = z->c;
            Node* x = z->c;
            Node* next_c = nullptr;
            do{
                next_c = x->r;
                x->insert_left(min_el);
                x->p = nullptr;
                x = next_c;
            } while(next_c != first_c);
        }
        z->l->r = z->r;
        z->r->l = z->l;
        if(z == z->r) min_el = nullptr;
        else min_el = z->r;
        z->l = z->r = z->c = nullptr; delete z;
        n_nodes--;
        if(!min_el) return;
        consolidate();
    }
    int size() const {
        return n_nodes;
    }
    bool empty() const {
        return n_nodes == 0;
    }
};

