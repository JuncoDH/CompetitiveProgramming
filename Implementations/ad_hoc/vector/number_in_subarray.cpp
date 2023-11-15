class NumberInSubarray { // O(n log n).
    vll v;
    map<ll, set<int>> m;
public:
    NumberInSubarray() = default;
    explicit NumberInSubarray(vll const& _v) {
        v = _v;
        int n = v.size();
        for(int i = 0; i < n; ++i) {
            m[v[i]].insert(i);
        }
    }
    void update(int const i, ll const el) {
        m[v[i]].erase(i);
        v[i] = el;
        m[el].insert(i);
    } // Return true if there is an ocurrence of el in v[l, r].
    bool find(int const l, int const r, ll const el) {
        auto const it = m[el].lower_bound(l);
        if(it == m[el].end()) return false;
        return *it <= r;
    }
};

