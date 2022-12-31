ll count_zeros(ll num) { // Number of zeros in num!.
    ll ans = 0;
    while(num) {
        ans += num/5;
        num /= 5;
    }
    return ans;
}
ll get_num_k_zeros(ll k) { // Get the number with k zeros in its factorial.
    ll l = -1, r = inf, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(count_zeros(mid) < k) l = mid;
        else r = mid;
    }
    return r;
}

