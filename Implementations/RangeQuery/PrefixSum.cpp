template<typename T>
class PrefixSum {
    int _n = 0;
    vector<T> psum;
public:
    PrefixSum() = default;
    explicit PrefixSum(vector<T> const& _v) {
        _n = _v.size();
        psum.assign(_n, 0);
        for(int i = 0; i < _n; i++) {
            if(i > 0) psum[i] = psum[i - 1];
            psum[i] += _v[i];
        }
    }
    // Get sum of the array v[ql..qr].
    T get_sum(int ql, int qr) {
        if(ql > qr) swap(ql, qr);
        ql = max(ql, 0);
        qr = min(qr, n - 1);
        if(ql == 0) return psum[qr];
        return psum[qr] - psum[ql - 1];
    }
};

