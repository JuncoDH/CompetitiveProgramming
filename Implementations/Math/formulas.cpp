// a/b is truncate function.
ll floor_div(ll a, ll b) {
    return a/b - ((a^b) < 0 && a%b);
}
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
// Sum_{0, n} (x + i*d) Arithmetic sum.
ll formula_4(ll x, ll d, ll _n) {
    return _n*x + d*formula_1(_n);
}
// Sum_{0, n} i^2 = Sum of i^2 in [0, n] = (n(n+1)(2n+1))/6.
ll formula_5(ll _n) {
    return _n*(_n+1)*(2*_n+1)/6;
}
// Sum_{0, n} i^3 = Sum of i^3 in [0, n] = ((n(n+1))/2)^2.
ll formula_6(ll _n) {
    ll ans = formula_1(_n);
    return ans*ans;
}
// Sum_{0, inf} x^i = 1/(1-x) if abs(x) < 1, inf abs(x) >= 1.
// Sum_{0, inf} i*x^i = x/(1-x)^2 if abs(x) < 1, inf abs(x) >= 1.
ll elevate(ll a, ll b) { // b >= 0.
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        b >>= 1;
        a = a * a;
    }
    return ans;
}
// Sum_{0, n} x^i = Sum of x^i in [0, n] = (Last*Ratio - First)/(Ratio - 1). Geometric sum.
ll formula_7(ll r, ll n) {
    return (elevate(r, n + 1) - 1) / (r - 1);
}
// Number of digits of num in base 10.
ll formula_8(ll num) {
    return log10(num)+1;
}

