// Get the MEX in the interval [0..n] in O(log n).
class Mex{ // change set -> unordered_set for O(1) all.
    int n; // Maximum Mex possible.
    vi cnt; // cnt of the inserted elements.
    set<int> s; // Elements NOT inserted.
    set<int> to_clear; // Elements inserted.
    public:
    Mex(int _n) {
        n = _n + 2; // + 2 To be sure.
        cnt.assign(n, 0);
        for(int i = 0; i < n; i++) s.insert(i);
    }
    void insert(int k) { // O(log n) insertion.
        cnt[k]++;
        if(cnt[k] == 1) s.erase(k), to_clear.insert(k);
    }
    void erase(int k) { // O(log n) deletion.
        cnt[k]--;
        if(cnt[k] == 0) s.insert(k), to_clear.erase(k);
    }
    int get_mex() { // O(1) query.
        return *s.begin();
    }
    void clear() { // Clear the Mex with the same n.
        vi temp = vi(to_clear.begin(), to_clear.end());
        for(auto el : temp) {
            erase(el);
        }
    }
};

