template<typename T>
class BIT{
    vector<T> bit;
    int n;
    public:
    BIT() = default;
    BIT(int _n) {
        n = _n;
        bit.assign(n+1, 0);
    }
    BIT(vector<T> v) {
        n = v.size();
        bit.assign(n+1, 0);
        for(int i = 0; i < n; i++) update(i, v[i]);
    }
    // Point update. v[i] += dx.
    void update(int i, T dx) {
        for(i++; i < n+1; i += LSB(i)) bit[i] += dx;
    }
    // query [0, r].
    // query(x is the number of numbers <= x).
    T query(int r) {
        T ans = 0;
        for(r++; r > 0; r -= LSB(r)) ans += bit[r];
        return ans;
    }
    // query [l, r].
    T query(int l, int r) {
        if(l > r) swap(l, r);
        l = max(l, 0);
        r = min(r, n-1);
        return query(r) - query(l-1);
    }
    // k-th smallest element inserted.
    int k_element(ll k) { // k > 0 (1-indexed).
        int l = 0, r = n+1, mid;
        if(query(0) >= k) return 0;
        while(l + 1 < r) {
            mid = (l + r)/2;
            if(query(mid) >= k) r = mid;
            else l = mid;
        }
        return r;
    }
};

