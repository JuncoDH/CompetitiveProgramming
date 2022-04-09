template<typename T>
class PrefixSum {
    int _n;
    vector<T> psum;
    public:
    PrefixSum(vector<T> &v) {
        _n = v.size();
        psum.assign(_n, 0);
        psum[0] = v[0];
        for(int i = 1; i < _n; i++) psum[i] = psum[i-1] + v[i];
    }
    // get sum of the array v[l..r].
    T get_sum(int l, int r) {
        l = max(l, 0);
        r = min(r, _n-1);
        if(r < l) return 0;
        if(l == 0) return psum[r];
        return psum[r] - psum[l-1];
    }
};

