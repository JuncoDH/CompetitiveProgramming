// Get the MEX in the interval [0..n] in O(log n).
class Mex{
    int n; // Maximum Mex possible.
    vi cnt; // cnt of the inserted elements.
    set<int> s; // Elements NOT inserted.

    public:
    Mex(int _n) {
        _n++;
        n = _n;
        cnt.assign(n, 0);
        for(int i = 0; i < n; i++) s.insert(i);
    }

    void insert(int k) { // O(log n) insertion.
        cnt[k]++;
        if(cnt[k] == 1) s.erase(k);
    }

    void erase(int k) { // O(log n) deletion.
        cnt[k]--;
        if(cnt[k] == 0) s.insert(k);
    }

    int getMex() { // O(1) query.
        return *s.begin();
    }
};

/* THIS USE SEGMENT TREE AND IS LONGER, SO USE THE VERSION ABOVE.
// Get the MEX in the interval [0..n] in O(log n).
class Mex{
    int n; // Maximum Mex possible.
    vi cnt; // cnt of the inserted elements.
    vi st; // Segment tree of array arr[i] = (cnt > 0).

    void update(int k, int l, int r, int pos, int dx) { // Update arr[pos] = dx.
        if(l == r) {st[k] = dx; return;}
        int mid = (l + r) >> 1;
        if(pos <= mid) update(k<<1, l, mid, pos, dx);
        else update(k<<1|1, mid+1, r, pos, dx);
        st[k] = st[k<<1] + st[k<<1|1];
    }

    int query(int k, int l, int r) { // Return the index of the first 0 of the array.
        if(l == r) return l;
        int mid = (l + r) >> 1;
        if(st[k<<1] < mid - l + 1) return query(k<<1, l, mid);
        return query(k<<1|1, mid+1, r);
    }

    public:
    Mex(int _n) {
        _n++;
        n = _n;
        cnt.assign(n, 0);
        st.assign(4*n, 0);
    }

    void insert(int k) {
        cnt[k]++;
        if(cnt[k] == 1) update(1, 0, n-1, k, 1);
    }

    void erase(int k) {
        cnt[k]--;
        if(cnt[k] == 0) update(1, 0, n-1, k, 0);
    }

    int getMex() {
        return query(1, 0, n-1);
    }
};
*/
