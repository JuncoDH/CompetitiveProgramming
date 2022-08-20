bool f(ll mid) { // Return true if is possible with mid.
    int i;
    for(i = 0; i < n; i++) {
    }
    return false;
}
// l is not possible, r is possible. [0..01..1].
ll bbin(ll l, ll r) {
    ll mid;
    while(l+1 < r) {
        mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    return r;
}
// ------------------------------------
bool find_bin(int l, int r, ll num) {
    int mid;
    if(num < v[l] || num > v[r]) return false;
    if(num == v[l] || num == v[r]) return true;
    while(l+1 < r) {
        mid = (l+r)/2;
        if(num == v[mid]) return true;
        if(num < v[mid]) r = mid;
        else l = mid;
    }
    return false;
}

