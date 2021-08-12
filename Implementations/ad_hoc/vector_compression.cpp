// O(n log n) coordinate compression.
void vector_compression(vll &v) {
    set<ll> s;
    map<ll, int> m;
    for(auto el : v) s.insert(el);
    for(auto el : s) m[el] = (int) m.size();
    for(auto &el : v) el = m[el];
}

