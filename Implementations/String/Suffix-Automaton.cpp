#define next _42_
//Suffix Automaton, save a directed acyclic graph and a suffix link tree with all the suffix of a word
struct state {
    //length of the longest string in the equivalence classes
    int len;
    //suffix link
    int link = -1;
    map<char, int> next;
    state(int _len) {
        len = _len;
    }
};

vector<state> t = {{0}};
int t_size = 1, last = 0;

//add a character to the automaton
//last is the state of the last char c added, p is the head of the automaton
//q is the state to duplicate
void sa_extend(char c) {
    int p = last, q;
    t.pb({t[last].len + 1});
    last = t_size; t_size++;
    //add c to the previous suffixes
    while(p != -1 && t[p].next.find(c) == t[p].next.end()) {
        t[p].next[c] = last;
        p = t[p].link;
    }
    //first time of c in the string
    if(p == -1) {
        t[last].link = 0;
        return;
    }
    q = t[p].next[c];
    if(t[p].len + 1 == t[q].len) {
        t[last].link = q;
        return;
    }
    //clone state q
    t.pb({t[p].len + 1});
    t_size++;
    t[t_size - 1].next = t[q].next;
    t[t_size - 1].link = t[q].link;

    //add links of last and q
    t[last].link = t_size - 1;
    t[q].link = t_size - 1;

    //point the last suffixes to q cloned
    while(p != -1 && t[p].next.find(c) != t[p].next.end()) {
        t[p].next[c] = t_size - 1;
        p = t[p].link;
    }
}

//O(s.length()) to create the automaton. Be careful adding any char once called another function
void sa_ini(string &s) {
    for(char c : s) sa_extend(c);
}

//A path from root to a terminal node is a suffix of the automaton string
vector<bool> terminal;
void sa_terminal() {
    int p = last;
    if(terminal.empty() == false) return; //previously calculated
    terminal.assign(t_size, false);
    while(p != -1) {
        terminal[p] = true;
        p = t[p].link;
    }
}

//true if w is a substring of the automaton string
//Also s is the longest prefix of w that is in s
//w is a suffix if the last p is a terminal state
bool sa_is_substr(string &w) {
    int p = 0; //string s;
    for(char ch : w) {
        if(t[p].next.find(ch) == t[p].next.end()) return false;
        p = t[p].next[ch];
        //s += c;
    }
    return true;
}

vll dp_num_substr;
ll num_substr_rec(int i) {
    ll sum = 1;
    if(dp_num_substr[i] != -1) return dp_num_substr[i];
    for(auto el : t[i].next) sum += num_substr_rec(el.se);
    return dp_num_substr[i] = sum;
}
//Number of different substrings of the automaton string (Is the number of different paths in the automaton)
//For the number of the length of all different substring the recursive formula is 
// sum of dp_num_substr[i] + dp_num_len_substr[i], the previous answer + 1*number of different substrings
ll sa_num_substr() {
    if(dp_num_substr.empty() == false) return dp_num_substr[0]; //previously calculated
    dp_num_substr.assign(t_size, -1);
    num_substr_rec(0);
    return dp_num_substr[0]; // -1 if you don't want the empty substring
}

//k-th string in the sorted substrings set of the automaton string. It's the k-th path in the graph
//k is [0..sa_num_substr()-1]
string sa_k_substr(int k) {
    int p = 0;
    char prev = '$';
    string ans = "";
    if(k > sa_num_substr()) return ans; //not exists that k-th string, error
    while(k > 0) {
        prev = '$';
        for(auto el : t[p].next) {
            prev = el.fi;
            if(dp_num_substr[el.se] >= k) break;
            k -= dp_num_substr[el.se];
        }
        if(prev == '$') break; //error
        ans += prev;
        p = t[p].next[prev];
        k--;
    }
    return ans;
}

//lexicographically smallest cyclic shift of the string s
string sa_small_cyclic_shift(string &s) {
    int p = 0, cnt = s.length();
    string ans = "";
    sa_ini(s + s); //initialize sa with s+s, the ans is greedy the first path with length s.length()
    while(cnt--) {
        auto el = *(t[p].next.begin()); //take greedy the first edge
        ans += el.fi;
        p = el.se;
    }

    return ans;
}

//int sa_num_ocurrences(string w); //Better use Aho-Corasick


//Test of the automaton string, the number of the substrings and the substrings, sorted
void sa_test1() {
    ll i, n;
    sa_ini("test");
    n = sa_num_substr();
    cout << n << endl;
    for(i = 0; i < n; i++)
        cout << sa_k_substr(i) << endl;
}

