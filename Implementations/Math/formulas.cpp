// Sum_{0, n} i = Sum of i in [0, n] = n*(n+1)/2.
ll formula_1(ll _n) {
    return _n*(_n+1)/2;
}
// Sum_{a, b} i = Sum of i in [a, b].
ll formula_2(ll _a, ll _b) {
    return formula_1(_b) - formula_1(_a-1);
}
// Sum_{n} i/k = Sum of i/k (floor) in [0, n]. n >= 0.
ll formula_3(ll _n, ll _k) {
    ll _ans = 0, r = _n;
    while((r+1)%_k != 0) {_ans += r/_k; r--;}
    return _ans + _k*formula_1(r/_k);
}
// Sum_{0, n} (x + i*d)
ll formula_4(ll x, ll d, ll _n) {
    return _n*x + d*formula_1(_n);
}

