// SOS: Sum Over Subsets. f[mask] = Sum_{s in mask} v[s].
// tutorial: https://codeforces.com/blog/entry/45223
// dp[mask][i] = Sum of submasks of masks having only the i+1 last bits different.
// if(is_set(mask, i)) dp[mask][i] = dp[mask][i-1] + dp[mask ^ (1ll << i)][i-1]
// else dp[mask][i] = dp[mask][i-1]. With base case dp[mask][-1] = v[mask].
// O(n * log(n))
vll SOS(vll &v) {
    int n_original = v.size();
    // Make v size power of two.
    while((int)v.size() != LSB((int)v.size())) v.pb(0); // 0 neutral sum element.
    int n = v.size(), i, mask;
    vll f(n, 0);
    for(mask = 0; mask < n; mask++) f[mask] = v[mask];
    for(i = 0; (1ll << i) < n; i++) {
        for(mask = 0; mask < n; mask++)
            if(is_set(mask, i))
                f[mask] += f[mask ^ (1ll << i)];
    }
    // Restore original v and f size.
    while((int) v.size() > n_original) v.pop_back(), f.pop_back();
    return f;
}

// Inclusion Exclusion over SOS = mu.
// https://codeforces.com/blog/entry/72488
// mu(v) = neg(SOS(neg(v))).
// mu(v) = Sum_{s in mask} (-1)^(mask\s) v[s].
vll inclusion_exclusion_SOS(vll &v) {
    vll f = v;
    for(int mask = 0; mask < (int)f.size(); mask++)
        if(__builtin_popcount(mask) % 2 == 1)
            f[mask] = -f[mask];
    vll ans = SOS(f);
    for(int mask = 0; mask < (int)f.size(); mask++)
        if(__builtin_popcount(mask) % 2 == 1)
            f[mask] = -f[mask];
    return ans;
}
