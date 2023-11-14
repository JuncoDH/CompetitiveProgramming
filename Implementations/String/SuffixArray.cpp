class SuffixArray {
    public:
    int n = 0;
    string s;
    vi p; // p[i] is the position in the order array of the ith suffix (s[i..n - 1]).
    vi c; // c[i] is the equivalence class of the ith suffix. When build, c[p[i]] = i, inverse.
    // Dont use lcp[0] = 0.
    vi lcp; // lcp[i] is the longest common prefix in s[p[i - 1]..n - 1] and s[p[i]..n - 1].
    // To get lcp(s[i..n - 1], s[j..n - 1) is min(lcp[c[i] + 1], lcp[c[j]]) (use SegTree).
    void radix_sort(vector<pair<pii, int>> const& v) const { // O(n).
        vector<pair<pii, int>> v2(n);
        vi freq(n, 0); // First frequency and then the index of the next item.
        int i, sum = 0, temp;
        for(i = 0; i < n; i++) freq[v[i].fi.se]++; // Sort by second component.
        for(i = 0; i < n; i++) { temp = freq[i]; freq[i] = sum; sum += temp; }
        for(i = 0; i < n; i++) { v2[freq[v[i].fi.se]] = v[i]; freq[v[i].fi.se]++; }
        freq.assign(n, 0); sum = 0;
        for(i = 0; i < n; i++) freq[v2[i].fi.fi]++; // Sort by first component.
        for(i = 0; i < n; i++) { temp = freq[i]; freq[i] = sum; sum += temp; }
        for(i = 0; i < n; i++) { v[freq[v2[i].fi.fi]] = v2[i]; freq[v2[i].fi.fi]++; }
    }
    SuffixArray() = default;
    explicit SuffixArray(string const& _s) {
        s = _s;
        s += "$"; // Smaller char to end the string.
        n = s.size();
        int i, k;
        p.assign(n, 0);
        c.assign(n, 0);
        vector<pii> v1(n); // Temporal vector to sort.
        for(i = 0; i < n; i++) v1[i] = { s[i], i };
        sort(v1.begin(), v1.end());
        for(i = 0; i < n; i++) p[i] = v1[i].se;
        c[p[0]] = 0;
        for(i = 1; i < n; i++) {
            if(v1[i].fi == v1[i - 1].fi) c[p[i]] = c[p[i - 1]];
            else c[p[i]] = c[p[i - 1]] + 1;
        }
        k = 0; // In k + 1 iterations sort strings of length 2^(k + 1).
        while(c[p[n-1]] != n-1) { // At most ceil(log2(n)).
            vector<pair<pii, int>> v2(n); // Temporal vector to sort.
            for(i = 0; i < n; i++) v2[i] = { { c[i], c[(i + (1 << k)) % n] }, i };
            radix_sort(v2);
            for(i = 0; i < n; i++) p[i] = v2[i].se;
            c[p[0]] = 0;
            for(i = 1; i < n; i++) {
                if(v2[i].fi == v2[i - 1].fi) c[p[i]] = c[p[i - 1]];
                else c[p[i]] = c[p[i - 1]] + 1;
            }
            k++;
        }
    }
    void show_suffixes() const { // IMPORTANT use this to debug.
        for(int i = 0; i < n; i++) cout << i << " " << p[i] << " " << s.substr(p[i]) << endl;
        if(!lcp.empty()) cout << "LCP: " << lcp << endl;
    }
    // cmp s with t. return -1 if s < t, 1 if s > t, 0 if s == t.
    int cmp_string(int const pos, string const& t) const {
        for(int i = p[pos], j = 0; j < (int) t.size(); i++, j++) {
            if(s[i] < t[j]) return -1; // i < n because s[n-1] = '$'.
            if(s[i] > t[j]) return 1;
        }
        return 0;
    }
    // Count the number of times t appears in s.
    int count_substring(string const& t) const {
        int l = -1, r = n, mid, L, R;
        while(l + 1 < r) { // -1, ... , -1 = L, 0 , ... , 0, 1 = R, ..., 1.
            mid = (l + r) / 2;
            if(cmp_string(mid, t) < 0) l = mid;
            else r = mid;
        }
        L = l;
        l = -1; r = n;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(cmp_string(mid, t) <= 0) l = mid;
            else r = mid;
        }
        R = r;
        return R - L - 1;
    }
    // O(n) build. At most 2n lcp++ and n lcp--;
    void build_lcp() {
        lcp.assign(n, 0);
        for(int i = 0; i < n - 1; i++) {
            if(i > 0) lcp[c[i]] = max(lcp[c[i - 1]] - 1, 0);
            while(s[i + lcp[c[i]]] == s[p[c[i] - 1] + lcp[c[i]]]) lcp[c[i]]++;
        }
    }
    ll number_substrings() const {
        ll ans = 0;
        for(int i = 1; i < n; i++) {
            ans += n - p[i - 1] - lcp[i]; // Length of the suffix - lcp with the next suffix.
        }
        ans += n - p[n - 1]; // Plus the last suffix.
        return ans - n; // Remove the '$' symbol on n substrings.
    }
};
string LCS(string s, string const& t) {
    int mx = 0, mxi = 0, n2 = t.length();
    string ans = "";
    s += "@" + t; // Concatenate with a special char.
    SuffixArray sa(s);
    sa.build_lcp();
    for(int i = 1; i < sa.n; i++) {
        // Suffix of s and before suffix of t.
        if(sa.n - sa.p[i] > n2 + 2 && sa.n - sa.p[i-1] <= n2 + 1) {
            if(sa.lcp[i] > mx) mx = sa.lcp[i], mxi = i;
        }
        // Suffix of t and before suffix of s.
        if(sa.n - sa.p[i] <= n2 + 1 && sa.n - sa.p[i - 1] > n2 + 2) {
            if(sa.lcp[i] > mx) mx = sa.lcp[i], mxi = i;
        }
    }
    return sa.s.substr(sa.p[mxi], mx);
}

