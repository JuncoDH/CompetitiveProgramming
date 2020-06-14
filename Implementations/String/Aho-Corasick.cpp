//construct trie O(m) + automaton O(mk), O(mk) memory, m = sum(len(word_i))
#define next asdfa
//size of alphabet, 26 lowercase
const int k = 26;

struct vertex{
    vi next;
    //number of words ending at current vertex
    int leaf;
    //ancestor p and ch is the transition of p->v
    int p;
    char pch;
    //proper suffix link of the vertex
    int link;
    vi go;
    //how many suffixes there are in the tree;
    int count;

    vertex(int _p, char _pch) {
        next.assign(k, -1);
        leaf = 0;
        this->p = _p;
        this->pch = _pch;
        link = -1;
        go.assign(k, -1);
        count = -1;
    }
};

vector<vertex> t = {{-1, '$'}};
int t_size = 1;

//add string to the trie t
void add_string(string &s) {
    int c, p = 0;
    for(char ch : s) {
        c = ch - 'a';
        if(t[p].next[c] == -1) {
            t.pb({p, ch});
            t[p].next[c] = t_size++;
        }
        p = t[p].next[c];
    }
    t[p].leaf++;
}

//Search for any proper suffix of v that has next[c] transition
//call go(v, ch) for move the automaton from the vertex v using transition ch
int go(int v, char ch);

//get the proper suffix link of v. Once called, don't call anymore add_strings
int get_link(int v) {
    if(t[v].link == -1) {
        if(v == 0 || t[v].p == 0) t[v].link = 0;
        else t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if(t[v].go[c] == -1) {
        if(t[v].next[c] != -1) t[v].go[c] = t[v].next[c];
        //The root doesn't have next[c]
        else if(v == 0) t[v].go[c] = 0;
        else {
            t[v].go[c] = go(get_link(v), ch);
        }
    }
    return t[v].go[c];
}

//get the count of v
int count(int v) {
    if(t[v].count == -1) {
        t[v].count = t[v].leaf;
        if(v != 0) t[v].count += count(get_link(v));
    }
    return t[v].count;
}

//search the number of the strings in the automaton that are in the text
int search_num_string(string &text) {
    int p = 0, ans=0;

    for(auto ch : text) {
        ans += count(p);
        p = go(p, ch);
    }
    ans += count(p);
    return ans;
}
