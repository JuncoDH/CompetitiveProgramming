//Sum Over Subsets
void SOS_optimized() {
    ll mask, j, n = 2; //A.size() = 2^n
    vll A = {7, 12, 14, 16}, F((1ll<<n));
    //Base case
    for(mask = 0; mask < (1ll<<n); mask++) {
        F[mask] = A[mask];
    }
    //the new mask differ from the mask only in the last j bits
    for(j = 0; j < n; j++) {
        for(mask = 0; mask < (1ll<<n); mask++) {
            if(mask&(1ll<<j)) {
                F[mask] += F[mask^(1ll<<j)];
            }
        }
    }
    echo(F);
}

//Sum Over Subsets
//https://codeforces.com/blog/entry/45223
//Calculate F[mask] = \sum_{i is submask of mask} A[i]
//Here is O(n*2^n), not optimized in memory (vvi dp can be deleted)
//DP[i][j] is the sum over all submask of the mask i with at most j last bits different, all A[x] that x^i < 2**(j+1)
void SOS() {
    ll mask, j, n = 2; //A.size() = 2^n
    vll A = {7, 12, 14, 16}, F((1ll<<n));
    vector<vll> dp((1ll<<n), vll(n + 1));
    for(mask = 0; mask < (1ll<<n); mask++) {
        //base case
        dp[mask][0] = A[mask];
        for(j = 0; j < n; j++) {
            //j bit set in mask, save in dp[mask][j+1]
            if(mask&(1ll<<j)) {
                dp[mask][j+1] = dp[mask][j] + dp[mask ^ (1ll<<j)][j];
            }
            else dp[mask][j+1] = dp[mask][j];
        }
        F[mask] = dp[mask][n];
    }
    echo(F);
}
