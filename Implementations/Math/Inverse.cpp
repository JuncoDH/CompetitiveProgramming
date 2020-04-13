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
