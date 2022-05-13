template<typename T>
class PrefixSum {
    int _n;
    vector<T> psum;
    public:
    PrefixSum(vector<T> &_v) {
        _n = _v.size();
        psum.assign(_n, 0);
        for(int i = 0; i < _n; i++) {
            if(i > 0) psum[i] = psum[i-1];
            psum[i] += _v[i];
        }
    }
    // Get sum of the array v[l..r].
    T get_sum(int l, int r) {
        l = max(l, 0);
        r = min(r, _n-1);
        if(r < l) return 0;
        if(l == 0) return psum[r];
        return psum[r] - psum[l-1];
    }
};

