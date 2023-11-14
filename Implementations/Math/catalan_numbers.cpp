// (2nCn) / (n + 1).
ll catalan_number(ll i) {
    if(i == 0) return 1;
    if(i == 1) return 2;
    i++;
    ll ans = fact[2*i];
    ans *= inv_fact[i + 1];
    ans %= mod;
    ans *= inv_fact[i];
    ans %= mod;
    return ans;
}

