class node {
    public:
    static const int ALPHABET = 2; // 2, 10, 26.
    static const char FIRST_LETTER = '0'; // '0', 'a', 'A'.
    node *p = nullptr; // Parent node.
    node *c[ALPHABET]; // Child nodes.
    int count_word = 0;
    int subtree_word = 0; // Number of words with the same prefix as the node.
    node(){fill(c, c+ALPHABET, nullptr);}
    node(node *_p) {p = _p; fill(c, c+ALPHABET, nullptr);}
    ~node() {for(int i = 0; i < ALPHABET; i++) delete c[i];}
    void show(string s) { // Show all the nodes in lexicographical order.
        if(count_word > 0) echo(s); // NOT SHOWING DUPLICATE WORDS.
        for(int i = 0; i < ALPHABET; i++) {
            if(c[i]) c[i]->show(s + (char)(i+FIRST_LETTER));
        }
    }
    void init_subtree_word() {
        subtree_word = count_word;
        for(int i = 0; i < ALPHABET; i++) {
            if(c[i]) {
                c[i]->init_subtree_word();
                subtree_word += c[i]->subtree_word;
            }
        }
    }
};
class Trie {
    public:
    node *root = new node();
    ~Trie() {delete root;}
    void add(string &s) {
        node *n = root;
        for(auto c : s) {
            int nc = c - node::FIRST_LETTER;
            if(!n->c[nc]) n->c[nc] = new node(n);
            n = n->c[nc];
        }
        n->count_word++;
    } // Add num with n digits (Add 0 to the left).
    void add(ll num, ll digit) { // Base 10.
        string s = to_string(num);
        string s2 = string(max(0ll, digit-(int)s.length()), '0') + s;
        add(s2);
    }
    void add_binary(ll num, ll digit) { // Base 2.
        string s = string(digit, '0');
        for(int i = 0; i < digit; i++) {
            if(is_set(num, i)) s[digit-i-1] = '1';
        }
        add(s);
    }
    void remove(string &s) {
        node *n = root;
        for(auto c : s) {
            int nc = c - node::FIRST_LETTER;
            if(!n->c[nc]) return; // ERROR, remove one string not in the trie.
            n = n->c[nc];
        }
        if(n->count_word == 0) return ; // ERROR, remove one string not in the trie.
        n->count_word--;
    }
    bool search(string &s) {
        node *n = root;
        for(auto c : s) {
            int nc = c - node::FIRST_LETTER;
            if(!n->c[nc]) return false;
            n = n->c[nc];
        }
        return n->count_word > 0;
    }
    void show() {root->show("");}
    void init_subtree_word() {root->init_subtree_word();}
    // number of words w <= s.
    ll num_less_eq_than(string &s) {
        node *n = root;
        ll ans = 0, i, j;
        for(i = 0; i < (int)s.length(); i++) {
            ans += n->count_word;
            for(j = 0; j < node::ALPHABET; j++) {
                if(n->c[j]) {
                    char ch = j + node::FIRST_LETTER;
                    if(ch > s[i]) {j = node::ALPHABET; break;}
                    if(ch == s[i]) {
                        n = n->c[j];
                        break;
                    }
                    ans += n->c[j]->subtree_word;
                }
            }
            if(j == node::ALPHABET) break;
        }
        if(j != node::ALPHABET) ans += n->count_word;
        return ans;
    }
};
class TriePointer{
    public:
    node *n = nullptr;
    TriePointer() = default;
    TriePointer(Trie &t) {
        n = t.root;
    }
    bool can_move(char c) {
        int nc = c - node::FIRST_LETTER;
        if(!n->c[nc]) return false;
        return true;
    }
    bool move(char c) {
        int nc = c - node::FIRST_LETTER;
        if(!n->c[nc]) return false;
        n = n->c[nc];
        return true;
    }
    void back() {
        if(n->p) n = n->p;
    }
};

