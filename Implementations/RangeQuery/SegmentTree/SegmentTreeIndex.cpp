// SegmentTree to work with the index in a set, can insert and remove.
class SegmentTreeIndex {
    vi tree;
    int n;
    void update(int k, int l, int r, int pos, int dx) {
        if(l == r) {tree[k] = dx;return;}
        int mid = (l+r)>> 1;
        if(pos <= mid) update(k<<1, l, mid, pos, dx);
        else update(k<<1|1, mid+1, r, pos, dx);
        tree[k] = tree[k<<1] + tree[k<<1|1];
    }
    int queryR(int k, int l, int r, int pos) {
        if(tree[k] == 0) return -1;
        if(l == r) return l;
        int mid = (l+r)>>1;
        int ans = -1;
        if(pos <= mid) ans = queryR(k<<1, l, mid, pos);
        if(ans != -1) return ans;
        return queryR(k<<1|1, mid+1, r, pos);
    }
    int queryL(int k, int l, int r, int pos) {
        if(tree[k] == 0) return -1;
        if(l == r) return l;
        int mid = (l+r)>>1;
        int ans = -1;
        if(pos > mid) ans = queryL(k<<1|1, mid+1, r, pos);
        if(ans != -1) return ans;
        return queryL(k<<1, l, mid, pos);
    }
    int k_ele(int k, int l, int r, int kth) {
        if(l == r) return l;
        int mid = (l+r) >> 1;
        if(tree[k<<1] >= kth) return k_ele(k<<1, l, mid, kth);
        return k_ele(k<<1|1, mid+1, r, kth - tree[k<<1]);
    }
    public:
    SegmentTreeIndex(int _n) {
        n = _n;
        tree.assign(4*n, 0);
    }
    // set pos to dx (1 if insert, 0 if remove)
    void update(int pos, int dx) {
        update(1, 0, n-1, pos, dx);
    }
    // Return the position of the right most index at Left of pos set to 1, -1 if none
    int queryL(int pos) { // NOT TESTED BUT COPIED FROM queryR TESTED
        return queryL(1, 0, n-1, pos);
    }
    // Return the position of the left most index at Right of pos set to 1, -1 if none
    int queryR(int pos) {
        return queryR(1, 0, n-1, pos);
    }
    // Return the k-th element in the range [0..n-1], 1-INDEXED
    int k_ele(int k) { // NOT TESTED by AC
        return k_ele(1, 0, n-1, k);
    }
};

