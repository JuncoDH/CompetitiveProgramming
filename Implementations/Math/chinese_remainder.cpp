//given n x == a[i] mod p[i], find x % supermod.
const ll supermod = 1'000'000'007; //if you have to find your solution with one more modulus

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

const ll MAX = 10;
ll a[MAX], p[MAX], n;

void solve() {
    ll i, x, y; //x is p[0]^-1 mod p[i], because maybe p[i] is not prime (p[i] = 9)
    for(i = 1; i < n; i++) {
        gcdEx(p[0], p[i], &x, &y);

        a[0] = a[0] + p[0]*(a[i] - a[0]) * x;
        p[0] = p[0]*p[i];
        a[0] = a[0] %p[0];

        a[0] %= supermod;
        p[0] %= supermod;
    }
    a[0] += p[0];
    a[0] %= p[0];

    a[0] %= supermod;
    p[0] %= supermod;
}


void check() { //function to test [1..n] ecuations without supermod
    ll x = a[0], m = p[0], i;
    echo(x, m);
    for(i = 1; i < n; i++) {
        if(x%p[i] != a[i]) {
            echo("WA: ", a[i], p[i], x%p[i]);
            return;
        }
    }
    echo("AC");
}
