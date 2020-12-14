int LIS(vll &v) {
    int i, n = v.size();
    vll lis;
    if(!n) return 0;
    lis.pb(v[0]);
    for(i = 1; i < n; i++) {
        if(v[i] > lis.back()) {lis.pb(v[i]); continue;}
        auto it = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        // if(it > 0 && lis[it-1] == v[i]) continue; // USE IF YOU WANT STRICTLY INCREASING.
        lis[it] = v[i];
    }
    return lis.size();
}

// NOT TESTED.
vll v_LIS(vll &v) {
    int i, j, n = v.size();
    vll lis, lis_time(n), ans;
    if(!n) return ans;
    lis.pb(v[0]); lis_time[0] = 1;
    for(i = 1; i < n; i++) {
        if(v[i] > lis.back()) {lis.pb(v[i]); lis_time[i] = lis.size(); continue;}
        auto it = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        // if(it > 0 && lis[it-1] == v[i]) continue; // USE IF YOU WANT STRICTLY INCREASING.
        lis[it] = v[i];
        lis_time[i] = it+1;
    }
    j = lis.size();
    for(i = n-1; i >= 0; i--) {
        if(lis_time[i] == j && (ans.empty() || v[i] <= ans.back())) {ans.pb(v[i]); j--;} // <= or <.
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
