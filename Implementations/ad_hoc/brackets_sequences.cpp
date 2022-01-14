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

