template<typename T>
class WaveletTree {
    // Map left function is psum[i], map right is i - psum[i].
    WaveletTree* pl = nullptr, *pr = nullptr;
    vector<T> psum; // psum[i] is the number of items in 0..i that will go to the left node.
    T mn, mx, md; // Minimum, maximum and medium element.
    WaveletTree(T const* vb, T const* ve, T const _mn, T const _mx) {
        mn = _mn;
        mx = _mx;
        md = (mx + mn) >> 1;
        if(_mn == _mx || vb == ve) return; // If is leaf node, or there aren't more items, return.
        psum.pb(0);
        for(int i = 0; vb + i != ve; ++i) { psum.pb(psum.back() + (vb[i] <= md)); }
        T mid_cpy = md;
        auto mid_pos = stable_partition(vb, ve, [mid_cpy](T a) { return a <= mid_cpy; });
        pl = new WaveletTree(vb, mid_pos, mn, md);
        pr = new WaveletTree(mid_pos, ve, md + 1, mx);
    }
public:
    WaveletTree() = default;
    // The array is considered as { empty, v }, so query 1-index, v[i] => q(i + 1).
    WaveletTree(T const* v, int const n) : WaveletTree(v, v + n, *min_element(v, v + n), *max_element(v, v + n)) { }
    // Number of times of q is in the subarray vi..vj.
    int rank(int const i, int const j, T const q) { // NOT tested.
        if(mn == mx) return mn == q ? j - i + 1 : 0;
        if(q <= md) return pl->rank(psum[i], psum[j], q);
        return pr->rank(i-psum[i], j - psum[j], q);
    }
    // Return the k element in the subarray vi..vj.
    T quantile(int const i, int const j, int const k) {
        if(mn == mx) return mn;
        int c = psum[j];
        if(i > 0) c -= psum[i - 1];
        if(k <= c) return pl->quantile(psum[i], psum[j], k);
        return pr->quantile(i - psum[i], j - psum[j], k - c);
    }
    // ToDo Update 1 can be swap element i by i + 1, just change psum values recursively.
    // ToDo Update 2 push back an element (take care to create the leave for the item if it doesn't exist).
};

