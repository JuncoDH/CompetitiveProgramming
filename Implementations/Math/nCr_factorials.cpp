//Fills the first factorials and factorials^-1 and you get nCr in O(1)
ll mod = (ll)1e9 + 7;
const ll MAX = 1e5 + 10;
//mfact is fact^-1
ll fact[MAX], mfact[MAX];
 
ll elevate(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
 
//a^(mod - 1) = 1, Euler
ll inv(ll a){
    return elevate(a, mod - 2);
}
 
void rellenar() {
    int i = 0;
    fact[0] = 1;
    mfact[0] = 1;
    for(i = 1; i < MAX; i++) {
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
        mfact[i] = inv(fact[i]);
    }
}
 
ll comb(ll a, ll b) {
    if(b > a) return -1;
    return ((fact[a] * mfact[b])%mod) * mfact[a-b] %mod;
}