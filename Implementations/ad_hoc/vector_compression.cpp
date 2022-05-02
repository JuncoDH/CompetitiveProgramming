// O(n log n) coordinate compression.
void vector_compression(vll &v) {
    set<ll> s;
    map<ll, int> m;
    for(auto &el : v) s.insert(el);
    for(auto &el : s) m[el] = (int) m.size();
    for(auto &el : v) el = m[el];
}

void matrix_compression(vector<vll> &v) {
    set<ll> s;
    map<ll, int> m;
    for(auto &v2 : v) for(auto &el : v2) s.insert(el);
    for(auto &el : s) m[el] = (int) m.size();
    for(auto &v2 : v) for(auto &el : v2) el = m[el];
}

void vector_compression_map(vll &v, map<ll, ll> &value2pos, map<ll, ll> &pos2value) {
    set<ll> s;
    for(auto el : v) s.insert(el);
    for(auto el : s) value2pos[el] = value2pos.size();
    for(auto el : value2pos) pos2value[el.se] = el.fi;
}
