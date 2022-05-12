const ll mod = 1000000007;
const int MAX = 2*1e6+5;
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
// (2nCn) / (n+1).
ll catalan_number(ll i) {
    if(i == 0) return 1;
    if(i == 1) return 2;
    i++;
    ll ans = fact[2*i];
    ans *= inv_fact[i+1];
    ans %= mod;
    ans *= inv_fact[i];
    ans %= mod;
    return ans;
}

