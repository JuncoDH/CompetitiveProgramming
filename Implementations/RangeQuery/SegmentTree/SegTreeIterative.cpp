template<typename T>
class SegTreeIterative {
    vector<T> st; // 0: dummy, 1..n-1: st, n..2n-1: the input v.
    int n = 0; // Size of the vector.
    // The function: + , max, min...
    static T f(T const a, T const b){
        return a + b;
    }
    public:
    SegTreeIterative() = default;
    SegTreeIterative(int const _n) {
        n = _n;
        // Complete to a power of two, if f is sum add 0, if f is min add INT_MAX...
        while(n != LSB(n)) ++n;
        st.resize(2*n);
    }
    SegTreeIterative(vector<T> const& v){
        n = v.size();
        // Complete to a power of two, if f is sum add 0, if f is min add INT_MAX...
        while(n != LSB(n)){v.pb((T)0); ++n;}
        st.resize(2*n);
        
        for(int i = n; i < 2*n; i++) st[i] = v[i - n]; // The last n elements are the array.
        for(int i = n-1; i > 0; --i) st[i] = f(st[i<<1], st[i<<1|1]);
    }
    // Add dx to v[pos]. 
    void update(int pos, T const dx){ 
        st[pos + n] += dx;
        for(pos = (pos + n)>>1; pos > 0; pos >>= 1) st[pos] = f(st[pos<<1], st[pos<<1|1]);
    }
    T query(int l, int r){
        l += n; r += n;
        T ans = 0; // Sum ST.
        while(l < r) {
            if((l&1) == 1) ans = f(ans, st[l++]); // l is the right child, add and move to the right father.
            if((r&1) == 0) ans = f(ans, st[r--]); // r is the left child, add and move to the left father.
            l >>= 1;
            r >>= 1;
        }
        return ans + st[l]; // Add the central interval.
    }
};

