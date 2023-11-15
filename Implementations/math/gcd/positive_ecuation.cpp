// Solve a * x + b * y = c, with x >= 0 && y >= 0.
// WARNING Return x < 0 or y < 0 if no solution.
void solve(ll const a, ll* x, ll const b, ll* y, ll const c) {
    gcdEx(a, b, x, y);
    *x = *x * c;
    *y = *y * c;
    // sup = floor((*y) / (ld)a); // low <= t <= sup, can take one.
    ll low = ceil(-(*x) / (ld)b);
    *x = *x + b * low;
    *y = *y - a * low;
}

