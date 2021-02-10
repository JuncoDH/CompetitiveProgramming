// Fill the first factorials and factorials^-1 and you'll get nCr in O(1)
const ll mod = (ll)1e9 + 7;
const int MAX = 1e5 + 10;
//inv_fact is fact^-1
ll fact[MAX], inv_fact[MAX];
 
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
    return elevate(((a%mod) + mod)%mod, mod - 2);
}
 
void ini() {
    int i = 0;
    fact[0] = 1;
    inv_fact[0] = 1;
    for(i = 1; i < MAX; i++) {
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
        inv_fact[i] = inv(fact[i]);
    }
}
 
ll comb(ll a, ll b) {
    if(b > a) return -1;
    return ((fact[a] * inv_fact[b])%mod) * inv_fact[a-b] %mod;
}
