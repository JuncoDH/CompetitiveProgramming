const ll mod = 1000003;
const int N_POINTS = 12;
ll x[N_POINTS], y[N_POINTS]; // Constraints: f(x[i]) = y[i]
ll cte[N_POINTS]; // Memorize the cte per x[i].

// ONLY USE WHEN MOD IS PRIME, ELSE USE GCD.
ll elevate(ll a, ll b) { // b >= 0.
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

// a^(mod - 1) = 1, Euler.
ll inv(ll a) {
    return elevate(((a%mod) + mod)%mod, mod - 2);
}

void precompute() {
    int i, j;
    for(i = 0; i < N_POINTS; i++) {
        cte[i] = y[i];
        for(j = 0; j < N_POINTS; j++) {
            if(i == j) continue;
            cte[i] *= inv(x[i]-x[j]);
            cte[i] %= mod;
        }
    }
}
// f(z) = \sum_{i=0}^{n-1} \prod_{j=0, j!=i}^{n-1} y[i]*(z-x[j])/(x[i]-x[j]). It's O(N_POINTS^2).
ll evaluate(ll z) {
    ll ans = 0, temp, i, j;
    for(i = 0; i < N_POINTS; i++) {
        temp = cte[i];
        for(j = 0; j < N_POINTS; j++) {
            if(i == j) continue;
            temp *= z-x[j];
            temp %= mod;
        }
        ans += temp;
        ans %= mod;
    }
    return ans;
}
