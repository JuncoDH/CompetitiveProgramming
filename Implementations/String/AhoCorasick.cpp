class Node {
    public:
    static constexpr int alpha_size = 26;
    int leaf_cnt = 0; // Number of words ending at current node.
    vi next_letter;
    int p; // Parent of the node.
    char pch; // Parent -pch-> node.
    int suffix_link = -1; // Longest proper suffix of the string ending at node p.
    vi go; // DP for go().
    int count_words_dp = -1; // DP for count_words().
    Node(int const _p, char const _pch) {
        next_letter.assign(alpha_size, -1);
        p = _p;
        pch = _pch;
        go.assign(alpha_size, -1);
    }
}; // O(m * alpha_size) memory, O(m) runtime. m = sum(length(s_i)).
class AhoCorasick {
    vector<Node> t = vector<Node>(1, Node(-1, '$'));
    public:
    void add_string(string const& s) {
        int c, p = 0;
        for(char const& ch : s) {
            c = ch - 'a';
            if(t[p].next_letter[c] == -1) {
                t[p].next_letter[c] = t.size();
                t.pb(Node(p, ch));
            }
            p = t[p].next_letter[c];
        }
        t[p].leaf_cnt++;
    }
    // Get the proper suffix link of v.
    // Once called, don't call anymore add_strings.
    int get_link(int const v) {
        if(t[v].suffix_link == -1) {
            if(v == 0 || t[v].p == 0) t[v].suffix_link = 0;
            else t[v].suffix_link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].suffix_link;
    }
    // Search for the longest proper suffix of v that has next_letter[c] transition.
    int go(int const v, char const ch) {
        int c = ch - 'a';
        if(t[v].go[c] == -1) {
            if(t[v].next_letter[c] != -1) t[v].go[c] = t[v].next_letter[c];
            else if(v == 0) t[v].go[c] = 0;
            else t[v].go[c] = go(get_link(v), ch);
        }
        return t[v].go[c];
    }
    // Get the number of words in the automaton that are a suffix of the node v.
    int count_words(int const v) { // with duplicates.
        if(t[v].count_words_dp == -1) {
            t[v].count_words_dp = t[v].leaf_cnt;
            if(v != 0) t[v].count_words_dp += count_words(get_link(v));
        }
        return t[v].count_words_dp;
    }
    // Get the number of words in the automaton that are in the text.
    int search_num_string(string const& text) { // With duplicates.
        int p = 0, ans = count_words(0);
        for(auto ch : text) {
            p = go(p, ch);
            ans += count_words(p);
        }
        return ans;
    }
    bool smallest_not_contained_str(int const i, int const L, int const v, string& ans) {
        if(count_words(v) > 0) return false;
        if(i == L) return true;
        for(int j = 0; j < Node::alpha_size; j++) {
            char ch = j + 'a';
            ans += ch;
            bool ok = smallest_not_contained_str(i + 1, L, go(v, ch), ans);
            if(ok) return true;
            ans.pop_back();
        }
        return false;
    }
    // Get the smallest string of length L that dont contains any word in the automaton.
    string smallest_not_contained_str(int const L) {
        string ans = "";
        smallest_not_contained_str(0, L, 0, ans);
        return ans;
    }
};

