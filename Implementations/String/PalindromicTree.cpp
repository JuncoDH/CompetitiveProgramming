class Node{
    static constexpr int ALPHA_SIZE = 26;
public:
    int len = -1; // Length of the palindrome.
    int suffix_link = -1; // Link to biggest palindrome of a proper suffix.
    int to[ALPHA_SIZE] = {0};
    int num_palindromes = 0; // Number of palindromes finishing in this node.
    Node(int const _len, int const _suffix_link) {
        len = _len;
        suffix_link = _suffix_link;
    }
};
class PalindromicTree{ // Also called eertree.
    vector<Node> tree; // Two roots, odd and even size palindroms.
    int last = 1; // Online processing.
    string s = "#";
    int n = 1;
public:
    PalindromicTree() {
        tree.pb(Node(-1, -1));
        tree.pb(Node(0, 0));
    }
    int add_character(char const c) {
        int ch = c - 'a';
        s += c; n++;
        int p = last;
        while(p != -1 && c != s[n - tree[p].len - 2])
            p = tree[p].suffix_link;
        if(!tree[p].to[ch]) {
            tree.pb(Node(tree[p].len + 2, -1));
            last = (int)tree.size() - 1;
            tree[p].to[ch] = last;
            p = tree[p].suffix_link;
            while(p != -1 && c != s[n - tree[p].len - 2]) 
                p = tree[p].suffix_link;
            if(p == -1) tree[last].suffix_link = 1;
            else tree[last].suffix_link = tree[p].to[ch];
            tree[last].num_palindromes = tree[tree[last].suffix_link].num_palindromes + 1;
        } else last = tree[p].to[ch];
        return tree[last].num_palindromes;
    } // Number of different palindromes is tree.size()-2, or -1 if counts "".
};

