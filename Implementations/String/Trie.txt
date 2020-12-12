const int ALPHABET = 26;
struct node {
    node *parent = NULL;
    node *child[ALPHABET];
    int count_word = 0;
    node(){for(int i = 0; i < ALPHABET; i++) child[i] = NULL;}
    node(node *p) {parent = p; for(int i = 0; i < ALPHABET; i++) child[i] = NULL;}
    ~node() {for(int i = 0; i < ALPHABET; i++) delete child[i];}
    void show(string s) { // Show all the nodes in lexicographical order.
        if(count_word > 0) echo(s); // NOT SHOWING DUPLICATE WORDS.
        for(int i = 0; i < ALPHABET; i++) {
            if(child[i]) child[i]->show(s + (char)(i+'a'));
        }
    }
};

class Trie {
    node *root = new node();
    public:
    ~Trie() {delete root;}
    void add(string s) {
        node *p = root;
        int nc;
        for(auto c : s) {
            nc = c - 'a';
            if(!p->child[nc]) p->child[nc] = new node(p);
            p = p->child[nc];
        }
        p->count_word++;
    }
    void remove(string s) {
        node *p = root;
        int nc;
        for(auto c : s) {
            nc = c - 'a';
            if(!p->child[nc]) return; // ERROR, remove one string not in the trie.
            p = p->child[nc];
        }
        if(p->count_word == 0) return ; // ERROR, remove one string not in the trie.
        p->count_word--;
    }
    bool search(string s) {
        node *p = root;
        int nc;
        for(auto c : s) {
            nc = c - 'a';
            if(!p->child[nc]) return false;
            p = p->child[nc];
        }
        return p->count_word > 0;
    }
    void show() {root->show("");}
};

