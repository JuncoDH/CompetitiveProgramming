const int MAX = 20;
ll dp[MAX], k = 1; // 1 <= k <= 9.
// f(num) is the number of numbers <= num that has a digit == k.
ll f(ll num, int i = 0, ll ten = 1) {
    ll ans = 0, d = num%10, num2 = num/10;
    bool ok = false;
    if(num == 0) return 0;
    if(i == 0) dp[0] = 1;
    else dp[i] = ten + 9*dp[i-1];
    while(num2) {
        if(num2%10 == k) {ok = true; break;}
        num2/=10;
    }
    if(ok) ans += d*ten;
    else if(i == 0) ans += d >= k;
    else if(d == k) ans += 1 + d*dp[i-1];
    else if(d < k) ans += d*dp[i-1];
    else ans += ten + (d-1)*dp[i-1];
    return ans + f(num/10, i+1, ten*10);
}
ll ten_to_nine(ll num) {return num - f(num);}
ll nine_to_ten(ll num) { // Lefmost r.
    ll l = 0, r = 5*1e17, mid;
    while(l+1 < r) {
        mid = (l+r)/2;
        if(mid-f(mid) < num) l = mid;
        else r = mid;
    }
    return r;
}

