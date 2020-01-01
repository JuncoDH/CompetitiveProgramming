map<pll, ll> m;

//num of numbers lower or equal than x with k bits set on
//DP with the left most 1 bit of x, if take it (x-MSB(x),k-1) or not take it (MSB(x)-1, k)
ll f(ll x, ll k) {
    ll i;
    if(k == 0) return 1;
    if(x == 0) return 0;

    if(m.count(mp(x, k))) return m[mp(x, k)];

    //61 for numbers less than 1e18
    for(i = 61; i >= 0; i--) {
        if(x&(1ll<<i)) { 
            return m[mp(x, k)] = f(x - (1ll<<i), k-1) + f((1ll<<i)-1, k);
        }
    }
    return 0;
}
