// n choose r, nCr = n!/(r!*(n-r)!).
// O(n/2) time O(1) memory.
ll nCr(ll const n, ll r){
    ll ans = 1;
    if(r > n/2) r = n - r; // Symmetry.
    for(int i = 1; i <= r; ++i){
        ans *= n -i + 1;
        ans /= i;
    }
    return ans;
}

