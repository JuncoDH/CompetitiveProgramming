ll gcdEx(ll a, ll b, ll *x1, ll *y1) {
    if(a == 0) {
        *x1 = 0;
        *y1 = 1;
        return b;
    }
    ll x0, y0, g;
    g = gcdEx(b%a, a, &x0, &y0);    
    *x1 = y0 - (b/a)*x0;
    *y1 = x0;
    return g;
}
//solve a*x+b*y = c, with x >= 0 && y >= 0. WARNING Return x < 0 or y < 0 if no solution
void solve(ll a, ll *x, ll b, ll *y, ll c) {
    gcdEx(a, b, x, y);
    *x = *x *c;
    *y = *y *c;
    ll low = ceil(-(*x)/((ld)b));//, sup = floor((*y)/((ld)a)); //low <= t <= sup, can take one
    *x = *x+b*low;
    *y = *y-a*low;
}

