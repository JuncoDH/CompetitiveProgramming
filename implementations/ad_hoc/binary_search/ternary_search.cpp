// f is a function that start decreasing and then change increasing.
// ternary_search will return the index where f(x) is minimum.
// There can be only one point such that f(x) == f(x + 1). In this case the solution will be x.
// Be sure that the function in [l, r] is strictly decreasing and then strictly increasing.
vi v;
ll n;
ll f(ll num) {
    ll suma = 0, sumb = 0, i, k;
    for(i = 0; i < n; i++) {
        k = min((ll)v[i], num);
        sumb += k;
        suma += v[i] - k;
    }
    return abs(sumb - suma);
}
ll ternary_search(ll l, ll r) {
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        ll f_mid = f(mid);
        ll f_mid_1 = f(mid + 1);
        if (f_mid == f_mid_1) return mid;
        // If the slope is decreasing.
        if(f_mid > f_mid_1) l = mid;
        else r = mid;
    }
    return f(l) < f(r) ? l : r;
}

