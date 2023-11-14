// f is a function that start to decreasing and then start to increasing.
// There can only be one interval such that f(mid) == f(mid + 1).
ll p1, p2;
ll f(ll const mid) {
    ll const dx1 = count_digits(mid)-count_digits(p1 - 1);
    ll const dx2 = count_digits(p2) - count_digits(mid);
    return abs(dx2 - dx1);
}
// return true if mid is the searched solution.
bool is_solution(ll mid) {
    ll const dx1 = count_digits(mid)-count_digits(p1 - 1);
    ll const dx2 = count_digits(p2) - count_digits(mid);
    ll const dx3 = count_digits(mid + 1)-count_digits(p1 - 1);
    ll const dx4 = count_digits(p2) - count_digits(mid + 1);
    if(dx1 < 0 || dx2 < 0 || dx3 < 0 || dx4 < 0) return false;
    if(dx2 - dx1 >= 0 && dx4 - dx3 < 0) return true;
    return false;
}
// Split [l, r] into [l, ans], [ans + 1, r].
ll ternary_search(ll l, ll r) {
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(is_solution(mid)) return mid;
        // If the slope is decreasing.
        if(f(mid) >= f(mid + 1)) l = mid;
        else r = mid;
    }
    return l;
}

