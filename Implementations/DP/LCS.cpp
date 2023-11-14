string s, t;
int LCS() { // Longest Common Subsequence.
    int ns = s.length(), nt = t.length(), i, j;
    vector<vi> dp(ns + 1, vi(nt + 1, 0)); // One empty row and column, dp is 1-index
    for(i = 1; i <= ns; i++) {
        for(j = 1; j <= nt; j++) {
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    /* string ans = ""; // Recover the LCS.
    i = ns; j = nt;
    while(dp[i][j]) {
        while(i > 0 && dp[i][j] == dp[i - 1][j]) i--;
        while(j > 0 && dp[i][j] == dp[i][j - 1]) j--;
        ans += s[i - 1];
        i--; j--;
    }
    reverse(ans.begin(), ans.end()); */
    return dp[ns][nt]; // Length.
}

