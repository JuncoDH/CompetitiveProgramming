// a * x1 + b * y1 = g;
ll gcdEx(ll a, ll b, ll* x1, ll* y1) {
    if(a == 0) {
        *x1 = 0;
        *y1 = 1;
        return b;
    }
    ll x0, y0, g;
    g = gcdEx(b % a, a, &x0, &y0);
    *x1 = y0 - (b / a) * x0;
    *y1 = x0;
    return g;
}

