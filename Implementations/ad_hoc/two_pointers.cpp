vll v;
ll n;
ll two_pointers() { // subarray [l, r].
    ll l = 0, ans = 0, temp = 0;
    for(ll r = 0; r < n; r++) {
        temp += v[r];
        while(l <= r && temp > 5) {
            temp -= v[l];
            l++;
        }
        ans = max(ans, r-l+1);
    }
    return ans;
}

