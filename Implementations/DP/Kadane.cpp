// Maximum sum in a vector. O(n).
ll kadane(vll const& v) {
    int n = v.size();
    if(!n) return 0;
    ll ans = 0, tans = 0;
    for(int i = 0; i < n; ++i) {
        tans += v[i];
        tans = max(tans, 0ll); // Throw current segment.
        ans = max(ans, tans);
    }
    return ans;
}

