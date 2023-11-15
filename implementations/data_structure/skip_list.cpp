class Node {
    public:
    ll value = 0;
    vector<Node*> prev; // Normal array is layer 0.
    vector<Node*> nxt;
    Node(ll const _value) { value = _value; }
}; // Probabilistic Datastructure. O(log n) average, O(n) worst case.
class SkipList {
    Node* begin = new Node(-inf); // Values in range (-inf, inf).
    Node* end = new Node(inf);
    // Return a node with the next >= value than num.
    Node* find_nxt(ll const num) const {
        Node* n = begin;
        int layer = begin->nxt.size();
        while(layer >= 0) {
            while(layer < (int)n->nxt.size() && n->nxt[layer]->value < num)
                n = n->nxt[layer];
            layer--;
        }
        return n->nxt[0];
    }
    public:
    SkipList() {
        srand(time(nullptr));
        begin->prev = { nullptr };
        begin->nxt = { end };
        end->prev = { begin };
        end->nxt = { nullptr };
    }
   ~SkipList() {
       Node* n = begin, *nxt = begin->nxt[0];
       for(; nxt; nxt = nxt->nxt[0]) {
           delete n;
           n = nxt;
       }
       delete n;
    }
    bool find(ll const num) const {
        Node* n = find_nxt(num);
        return n->value == num;
    }
    void insert(ll const num) {
        Node* r = find_nxt(num);
        Node* l = r->prev[0];
        Node* n = new Node(num);
        int layer = -1;
        while(layer == -1 || rand() % 2) {
            ++layer;
            if(layer >= (int)begin->nxt.size()) {
                begin->prev.pb(nullptr);
                begin->nxt.pb(nullptr);
                end->prev.pb(nullptr);
                end->nxt.pb(nullptr);
            }
            while(layer >= (int)l->nxt.size()) l = l->prev[0];
            while(layer >= (int)r->nxt.size()) r = r->nxt[0];
            l->nxt[layer] = n;
            n->prev.pb(l);
            r->prev[layer] = n;
            n->nxt.pb(r);
        }
    }
    void erase(ll const num) {
        Node* n = find_nxt(num);
        if(n->value != num) return;
        Node* l = n->prev[0];
        Node* r = n->nxt[0];
        int layer = 0;
        while(layer < (int)n->nxt.size()) {
            while(layer >= (int)l->nxt.size()) l = l->prev[0];
            while(layer >= (int)r->nxt.size()) r = r->nxt[0];
            l->nxt[layer] = r;
            r->prev[layer] = l;
            ++layer;
        }
        delete n;
    }
    vll get_elements() const {
        vll ans;
        Node* n = begin->nxt[0];
        while(n != end) {
            ans.pb(n->value);
            n = n->nxt[0];
        }
        return ans;
    }
    ll next(ll const num) const {
        Node* n = find_nxt(num);
        return n->value;
    }
};

