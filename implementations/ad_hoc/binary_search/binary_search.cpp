bool f(ll const mid) { // Return true if is possible with mid.
    for(int i = 0; i < n; ++i) {
    }
    return false;
}
// l is not possible, r is possible. [0..01..1].
ll bbin(ll l, ll r) {
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    return r;
}
// ------------------------------------
// binary_search(v.begin(), v.end(), num); test
int find_bin(int l, int r, ll const num) {
    if(num < v[l] || num > v[r]) return -1;
    if(num == v[l]) return l;
    if(num == v[r]) return r;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(num == v[mid]) return mid;
        if(num < v[mid]) r = mid;
        else l = mid;
    }
    return -1;
}

