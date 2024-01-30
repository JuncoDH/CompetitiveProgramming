// Auxiliary class to use custom comparator.
// The default from vector is the lexigraphical order.
// The order has to be total.
// The order v[i].fi < v[j].fi && v[i].se < v[j].se. is not total.
// Order by only the first dimension is total, but you lose the < in the second dimension.
// Maybe this lis O(n log n) does not solve the problem, and you need the O(n^2) version.
template<typename T> // Works for int, ll, vll...
vector<T> lis (vector<T> const& v, bool is_strictly_increasing = true) {
    int i, j;
    vi dp;
    vi predecessor(v.size(), -1);
    // The indice i represent the element v[i] and the time t when the element was processed.
    for (i = 0; i < (int)v.size(); ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), v[i], [&](auto a, int b) { return a < v[b]; });
        if (is_strictly_increasing && it != dp.begin() && v[*(it - 1)] == v[i]) continue;
        if (it == dp.end()) dp.pb(i);
        else if (v[i] < v[*it]) { predecessor[i] = *it; *it = i; }
        else predecessor[i] = *it;
    }
    vector<T> ans(dp.size());
    for (i = (int)dp.size() - 1; i >= 0; --i) {
        j = dp[i];
        while (i < (int)dp.size() - 1 && j >= dp[i + 1]) {
            j = predecessor[j];
        }
        ans[i] = v[j];
    }
    return ans;
}
// LIS O(n^2), useful for custom < comparator, like v[i].fi < v[j].fi && v[i].se < v[j].se.
template<typename T>
vector<T> lis_cuadratic (vector<T> const& v) {
    vi dp((int)v.size(), 1);
    auto custom_strict_less_comparator = [](T const& a, T const& b) { // Change this.
        return a[0] < b[0] && a[1] < b[1];
    };
    for (int i = 0; i < (int)v.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (custom_strict_less_comparator(v[j], v[i]))
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    vector<T> ans;
    int M = *max_element(dp.begin(), dp.end());
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        if (dp[i] == M && (ans.empty() || custom_strict_less_comparator(v[i], ans.back()))) {
            ans.pb(v[i]);
            --M;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

