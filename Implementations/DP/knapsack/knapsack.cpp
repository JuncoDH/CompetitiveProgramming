constexpr int MAX_KNAPSACK = 2000005;
ll dp[MAX_KNAPSACK]; // dp[i] is maximum value can get with i weight.
vector<pll> v; // (value, weight).
// Return max value with weight <= max_knapsack. O(n * max_knapsack).
// If can repeat elements, iterate 0->max_knapsack.
ll knapsack(int max_knapsack) {
    int i, j, n = v.size();
    ll ans = 0, g = v[0].se;
    for(i = 1; i < n; ++i) g = __gcd(g, v[i].se);
    for(i = 0; i < n; ++i) v[i].se /= g;
    max_knapsack /= g;
    for(i = 1; i <= max_knapsack; ++i) dp[i] = -inf;
    dp[0] = 0;
    for(i = 0; i < n; ++i) {
        for(j = max_knapsack; j >= 0; --j) {
            if(dp[j] != -inf && j + v[i].se < MAX_KNAPSACK)
                dp[j + v[i].se] = max(dp[j + v[i].se], dp[j] + v[i].fi);
        }
    }
    for(i = max_knapsack; i >= 0; --i) ans = max(ans, dp[i]);
    return ans;
}

