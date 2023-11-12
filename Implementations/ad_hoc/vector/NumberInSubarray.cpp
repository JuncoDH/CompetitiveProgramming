class NumberInSubarray{ // O(n log n).
    vll v;
    map<ll, set<int>> m;
    public:
    NumberInSubarray() = default;
    NumberInSubarray(vll& _v) {
        v = _v;
        int i, n = v.size();
        for(i = 0; i < n; i++) {
            m[v[i]].insert(i);
        }
    }
    void update(int i, ll el) {
        m[v[i]].erase(i);
        v[i] = el;
        m[el].insert(i);
    } // Return true if there is an ocurrence of el in v[l, r].
    bool find(int l, int r, ll el) {
        auto it = m[el].lower_bound(l);
        if(it == m[el].end()) return false;
        return *it <= r;
    }
};

