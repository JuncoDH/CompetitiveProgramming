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

// Maximum sum in a nxm vector. O(n*m^2).
ll kadane_2d(vector<vll> &v) {
    int n = v.size(), m, i, j, k;
    ll ans = 0;
    if(!n) return 0;
    m = v[0].size();
    vector<vll> psum(n, vll(m, 0)); // Prefix sum by rows.
    for(i = 0; i < n; i++) {
        psum[i][0] = v[i][0];
        for(j = 1; j < m; j++) {
            psum[i][j] = v[i][j] + psum[i][j-1];
        }
    }
    vll vcol(n);
    for(i = 0; i < m; i++) { // Left column.
        for(j = i; j < m; j++) { // Rigth column.
            for(k = 0; k < n; k++) { // Current row.
                vcol[k] = psum[k][j];
                if(i > 0) vcol[k] -= psum[k][i-1];
            }
            ans = max(ans, kadane(vcol));
        }
    }
    return ans;
}
