// Auxiliary class to use custom comparator.
// The default from vector is the lexigraphical order.
// The order has to be total.
// The order for all i, a[i] < b[i] is not total.
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

