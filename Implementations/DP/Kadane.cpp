// Maximum sum in a vector. O(n).
ll kadane(vll &v) {
    int n = v.size(), i;
    if(!n) return 0;
    ll ans = 0, tans = 0;
    for(i = 0; i < n; i++) {
        tans += v[i];
        tans = max(tans, 0ll); // Throw current segment.
        ans = max(ans, tans);
    }
    return ans;
}
