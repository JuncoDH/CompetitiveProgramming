// (m n) = prod_{i=0, i <= k} (mi ni) %mod; m = sum_{i=0, i <= k} mi*p^i
const ll mod = 1009;
const int MAX = 1009 + 10;
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
void init() {
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
    if(b > a) return 0;
    return ((fact[a] * inv_fact[b])%mod) * inv_fact[a-b] %mod;
}
ll lucas_theorem(ll m, ll n) {
    if(n > m) return 0;
    ll ans = 1;
    while(m || n) {
        ans *= comb(m%mod, n%mod);
        ans %= mod;
        m /= mod;
        n /= mod;
    }
    return ans;
}

