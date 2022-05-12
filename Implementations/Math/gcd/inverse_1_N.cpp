const ll mod = 31;
ll inverse[mod]; 
// O(mod) calculate inverse[i] % const mod.
void calc() {
    inverse[1] = 1;
    for(ll i = 2; i < mod; i++) {
        inverse[i] = -(mod/i)*inverse[mod%i];
        inverse[i] = (inverse[i]%mod + mod) % mod;
    }
}

