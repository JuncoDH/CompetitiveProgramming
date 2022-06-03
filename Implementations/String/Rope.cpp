unordered_set<void *> freezed_node; // List to not double free nodes.
class Node{
    Node *l = nullptr, *r = nullptr;
    ll weight = 0; // Number of characters ONLY in left subtree.
    string s = ""; // String in the leaves.
    public:
    Node() = default;
    Node(string _s) {
        s = _s;
        weight = s.length();
    }
    Node(Node *_l, Node *_r) {
        l = _l;
        r = _r;
        if(l) weight += l->get_length();
    }
    ~Node() { // Delete it if MLE.
        if(!freezed_node.count(l)) {
            freezed_node.insert(l);
            delete l;
        }
        if(!freezed_node.count(r)) {
            freezed_node.insert(r);
            delete r;
        }
    }
    void show() { // Print the whole string.
        if(l) l->show();
        cout << s;
        if(r) r->show();
    }
    // void balance() {} // TODO. O(n) vs O(log n).
    ll get_length() { // Get length of whole string.
        ll ans = weight;
        if(r) ans += r->get_length();
        return ans;
    } // Split in [0..i], [i+1..]. Can return null if i = -1 or n - 1.
    pair<Node*, Node*> split(ll index) { 
        index++; // 1 index. Number of chars, not position.
        pair<Node*, Node*> ret;
        if(index < weight) {
            if(!l) {
                return mp(new Node(s.substr(0, index)), new Node(s.substr(index)));
            }
            ret = l->split(index - 1); // -1 convert again.
            return mp(ret.fi, new Node(ret.se, r));
        } else if(index > weight) {
            ret = r->split(index - weight - 1);
            return mp(new Node(l, ret.fi), ret.se);
        } else {
            if(!r) return mp(this, new Node(""));
            return mp(l, r);
        }
    } // 1 Index str.
    char get_char(ll i) {
        if(i <= weight) {
            if(!l) return s[i - 1];
            return l->get_char(i);
        } else {
            return r->get_char(i - weight);
        }
    } // Get the substring [posl, posr].
    void get_substr(ll posl, ll posr, string &ans) {
        if(weight < posl || posr <= 0) return;
        if(l) l->get_substr(posl, posr, ans);
        int n = posr - posl + 1;
        if(!l && !r) ans += s.substr(posl-1, n);
        if(r) r->get_substr(max(posl - weight, 1ll), posr - weight, ans);
    }
};
// Is persistent. Since it can self-referenciate, the string
// can grows very fast, so use ll for indexes.
class Rope{ 
    vector<Node*> v; // All functions add the root to v.
    vector<Node*> to_delete; // Temporal list to free all the nodes.
    Node* concat(Node *l, Node *r) {return new Node(l, r);}
    public:
    ~Rope() {
        for(auto el : to_delete) v.pb(el);
        int i, n = v.size();
        for(i = 0; i < n; i++) {
            if(freezed_node.count(v[i])) continue;
            freezed_node.insert(v[i]);
            delete v[i];
        }
    } // Show string v[pos].
    void show(int pos) {
        v[pos]->show();
    } // Get char i of v[pos]. 
    char get_char(int pos, ll i) {
        return v[pos]->get_char(i + 1);
    } // Get the substring v[pos] [l..r].
    string get_substr(int pos, ll l, ll r) {
        string ans = "";
        v[pos]->get_substr(l+1, r+1, ans);
        return ans;
    } // Add a new string to the rope.
    void add(string &s) {
        v.pb(new Node(s));
    } // Concatenate v[posl] with v[posr].
    void concat(int posl, int posr) {
        v.pb(concat(v[posl], v[posr]));
    } // Convert v[pos1] to [0..i] + v[pos2] + [i+1..n-1].
    void insert(int pos1, int pos2, ll i) {
        if(i == -1) { // Append to the left.
            v.pb(concat(v[pos2], v[pos1]));
            return;
        }
        if(i == v[pos1]->get_length() - 1) { // Append to the right.
            v.pb(concat(v[pos1], v[pos2]));
            return;
        }
        pair<Node*, Node*> ret = v[pos1]->split(i);
        v.pb(concat(concat(ret.fi, v[pos2]), ret.se));
    } // Erase v[pos] [i..j].
    void erase(int pos, ll i, ll j) {
        pair<Node*, Node*> ret = v[pos]->split(i-1);
        pair<Node*, Node*> ret2 = ret.se->split(j-i);
        to_delete.pb(ret.se);
        to_delete.pb(ret2.fi);
        v.pb(concat(ret.fi, ret2.se));
    } // Cut v[pos] [i..j] and save it.
    void cut(int pos, ll i, ll j) {
        if(i > j) {
            v.pb(new Node(""));
            return;
        }
        pair<Node*, Node*> ret = v[pos]->split(i-1);
        pair<Node*, Node*> ret2 = ret.se->split(j-i);
        to_delete.pb(ret.fi);
        to_delete.pb(ret.se);
        to_delete.pb(ret2.se);
        v.pb(ret2.fi);
    }
};

