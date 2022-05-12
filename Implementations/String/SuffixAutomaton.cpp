class node{
    public:
    int len; // Length of the longest string in the equivalence classes.
    int suffix_link = -1; // The longest suffix that is not in the same equivalence class.
    map<char, int> next;
    node(int _len) {
        len = _len;
    }
};
class SuffixAutomaton{ // O(n) creation.
    vector<node> t = vector<node>(1, node(0));
    // int t_size = 1;
    int last = 0; // The node representing the entire string.
    public:
    void extend(string &s) {
        for(char c : s) extend(c);
    } // Extend the automaton character one by one.
    void extend(char c) {
        int p = last; // Head of the automaton.
        int q; // the node to duplicate.
        t.pb(node(t[last].len + 1));
        last = (int)t.size() - 1;
        // Add c to the previous suffixes.
        while(p != -1 && !t[p].next.count(c)) {
            t[p].next[c] = last;
            p = t[p].suffix_link;
        }
        // First time of c in the string.
        if(p == -1) {
            t[last].suffix_link = 0;
            return;
        }
        q = t[p].next[c];
        if(t[p].len + 1 == t[q].len) {
            t[last].suffix_link = q;
            return;
        }
        // Clone state q.
        t.pb(node(t[p].len + 1));
        t.back().next = t[q].next;
        t.back().suffix_link = t[q].suffix_link;

        // Add links of last and q.
        t[last].suffix_link = (int)t.size() - 1;
        t[q].suffix_link = (int)t.size() - 1;

        // Point to the last suffixes to q cloned.
        while(p != -1 && t[p].next[c] == q) {
            t[p].next[c] = (int)t.size() - 1;
            p = t[p].suffix_link;
        }
    }
    vector<bool> terminal_node; // If the node represent a suffix.
    void init_terminal() { // Call once.
        int p = last;
        terminal_node.assign((int)t.size(), false);
        while(p != -1) {
            terminal_node[p] = true;
            p = t[p].suffix_link;
        }
    }
    // Return true if w is a substring of s.
    // Can retrieve the longest prefis of w that is in s.
    // w is a suffix if the last p is a terminal node.
    bool is_substr(string &w) {
        int p = 0; // string s = "";
        for(char ch : w) {
            if(!t[p].next.count(ch)) return false;
            p = t[p].next[ch];
            // s += c;
        }
        return true;
    }
    // Number of different substrings in the automaton.
    // For the sum of all substring length:
    // ans[u] = sum_w(ans[w] + dp_num_substr[w]).
    vll dp_num_substr;
    ll num_substr(int i = 0) { // Empty string also counts.
        ll ans = 1;
        if(dp_num_substr.empty()) dp_num_substr.assign((int)t.size(), -1);
        if(dp_num_substr[i] != -1) return dp_num_substr[i];
        for(auto el : t[i].next) ans += num_substr(el.se);
        return dp_num_substr[i] = ans;
    }
    // k-th string in the sorted substrings set, in [0, num_substr()-1].
    string k_substr(int k) {
        int p = 0;
        char prev;
        string ans = "";
        if(k >= num_substr()) return ans; // Error.
        while(k > 0) {
            prev = '$';
            for(auto el : t[p].next) {
                prev = el.fi;
                if(dp_num_substr[el.se] >= k) break;
                k -= dp_num_substr[el.se];
            }
            if(prev == '$') break; // Error.
            ans += prev;
            p = t[p].next[prev];
            k--;
        }
        return ans;
    }
    // Take greedily the first substring with same length as s.
    string smallest_cyclic_shift(string &s) {
        int p = 0, cnt = s.length();
        string ans = "", s2 = s+s;
        extend(s2);
        while(cnt--) {
            auto el = *(t[p].next.begin());
            ans += el.fi;
            p = el.se;
        }
        return ans;
    }
    void test() { // For debug.
        string s = "test";
        extend(s);
        ll n = num_substr();
        for(ll i = 0; i < n; i++) echo(i, k_substr(i));
    }
};

