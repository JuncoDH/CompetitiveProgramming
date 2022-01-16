ll n;
vll v, psum;

void ini_prefix_sum() {
    if(n == 0) return;
    psum.assign(n, 0);
    psum[0] = v[0];
    for(int i = 1; i < n; i++) psum[i] = psum[i-1] + v[i];
}
// get sum of the array v[l..r].
ll get_sum(ll l, ll r) {
    l = max(l, 0ll);
    r = min(r, n-1);
    if(r < l) return 0;
    if(l == 0) return psum[r];
    return psum[r] - psum[l-1];
}

