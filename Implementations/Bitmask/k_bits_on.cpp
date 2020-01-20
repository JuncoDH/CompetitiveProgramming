//Digit DP, number of numbers lower or equal than num with cnt bits on
//sweep from left to right with the position pos. cnt is the number of bits to set on and 
//f1 is a flag whether your current number is lower than num (You construct the number but don't keep the number).
//With a modification you can do it for decimal system
ll dp[64][2][5];
ll num;
ll f(ll pos, ll f1, ll cnt) {
    if(cnt == 0) return 1;
    if(cnt > pos+1) return 0;
    if(pos < 0) return 0;
    if(dp[pos][f1][cnt] != -1) return dp[pos][f1][cnt];
    
    if(f1 == 1 || ((1ll<<pos) & num) != 0) return dp[pos][f1][cnt] = f(pos - 1, f1, cnt-1) + f(pos - 1, 1, cnt);
    else return dp[pos][f1][cnt] = f(pos - 1, f1, cnt);
}

//////////////////////////////////////////////////////////////////////////////////////
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
