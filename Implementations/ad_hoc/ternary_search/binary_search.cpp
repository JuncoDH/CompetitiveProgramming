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

