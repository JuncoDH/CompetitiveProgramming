template<typename T>
class SquareRootDecomposition {
    const int B = //3; //size of the bucket, ~ sqrt(N)
    vector<T> bucket;//(N/B + 1, 0T);
    vector<T> v;
    public:
    SquareRootDecomposition() = default;
    SquareRootDecomposition(vector<T> &_v) {
        bucket.assign((int)_v.size()/B +1, 0);
        v = _v;
        for(int i = 0; i < (int)v.size(); i++) {
            bucket[i/B] += v[i];
        }
    }
    // [l..r].
    T query(int l, int r) {
        if(l > r) swap(l, r);
        l = max(l, 0);
        r = min(r, n-1);
        T ans = 0;
        int i;
        if(l/B == r/B) {
            for(i = l; i <= r; i++) ans += v[i]; // Same block.
            return ans;
        }
        for(i = l/B + 1; i <= r/B -1; i++) ans += bucket[i]; //middle blocks
        for(i = l; i/B == l/B; i++) ans += v[i]; //left block
        for(i = r; i/B == r/B; i--) ans += v[i]; //right block
        return ans;
    }
    // Replace v[x] by dx.
    void update(int x, T dx) {
        bucket[x/B] += dx - v[x];
        v[x] = dx;
    }
};

