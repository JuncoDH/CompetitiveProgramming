// RBS, Regular Bracket Sequences.
string s;
vll index_pair;
// index_pair[i] is the index of the other bracket pair. ( <-> ).
void get_index_pair() {
    ll i, _n = s.length();
    index_pair.assign(_n, -1);
    vll stck;
    for(i = 0; i < _n; i++) {
        if(s[i] == '(') stck.pb(i);
        else if(!stck.empty()) {
            index_pair[i] = stck.back();
            index_pair[stck.back()] = i;
            stck.pop_back();
        }
    }
}
---------------------------------------------------------
// Convert a string of '(' and ')' to a regular bracket sequence, deleting elements.
// It will prioritize continuous range, ie: ()) -> (). and not (.)
void convert_to_rbs(string &s) { // rbs - regular bracket sequence.
    stack<int> st;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '(') st.push(i);
        else if(st.empty()) s[i] = '.';
        else st.pop();
    }
    while(!st.empty()) {s[st.top()] = '.'; st.pop();}
}
---------------------------------------------------------
bool is_valid_rbs(string &s) { // (()) ok.
    int i, cnt = 0;
    for(i = 0; i < (int)s.size(); i++) {
        if(s[i] == ')') cnt--;
        else cnt++;
        if(cnt < 0) return false;
    }
    return cnt == 0;
}

