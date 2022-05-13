vll LIS(vll &v) { // Is >=, but can be transformed to fit >.
    int i, t, n = v.size();
    if(n == 0) return vll();
    vll lis, lis_t(n), ans;
    lis.pb(v[0]); lis_t[0] = 1;
    for(i = 1; i < n; i++) {
        // if(v[i] == lis.back()) continue; // For >.
        if(v[i] >= lis.back())
            {lis.pb(v[i]); lis_t[i] = lis.size(); continue;}
        int pos = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        // if(pos > 0 && lis[pos - 1] == v[i]) continue; // For >.
        lis[pos] = v[i];
        lis_t[i] = pos+1;
    }
    for(i = n-1, t = lis.size(); i >= 0; i--) {
        if(lis_t[i] == t && (ans.empty() || v[i] <= ans.back()))
            ans.pb(v[i]), t--; // v[i] < ans.back() for >.
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

