// phi of Euler. O(sqrt(n)).
ll phi(ll n) {
    ll ans = n;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            ans -= ans / i;
        }
    }
    if(n > 1) ans -= ans / n;
    return ans;
}

