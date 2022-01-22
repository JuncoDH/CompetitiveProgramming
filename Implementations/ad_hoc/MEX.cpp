// Get the MEX in the interval [0..n] in O(log n).
class Mex{
    int n; // Maximum Mex possible.
    vi cnt; // cnt of the inserted elements.
    set<int> s; // Elements NOT inserted.
    vi last_inserted; // Elements to be removed in the .clear().

    public:
    Mex(int _n) {
        n = _n + 2; // +2 To be sure.
        cnt.assign(n, 0);
        for(int i = 0; i < n; i++) s.insert(i);
    }
    void insert(int k) { // O(log n) insertion.
        cnt[k]++;
        last_inserted.pb(k);
        if(cnt[k] == 1) s.erase(k);
    }
    void erase(int k) { // O(log n) deletion.
        cnt[k]--;
        if(cnt[k] == 0) s.insert(k);
    }
    int getMex() { // O(1) query.
        return *s.begin();
    }
    void clear() { // Clear the Mex with the same n.
        for(auto el : last_inserted) {
            erase(el);
        }
        last_inserted.clear();
    }
};
