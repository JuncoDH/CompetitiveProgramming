constexpr ll mod = 1000003;
constexpr int N_POINTS = 12;
ll x[N_POINTS], y[N_POINTS]; // Constraints: f(x[i]) = y[i]
ll cte[N_POINTS]; // Memorize the cte per x[i].
void precompute() {
    for(int i = 0; i < N_POINTS; i++) {
        cte[i] = y[i];
        for(int j = 0; j < N_POINTS; j++) {
            if(i == j) continue;
            cte[i] *= inv(x[i]-x[j]);
            cte[i] %= mod;
        }
    }
}
// f(z) = \sum_{i=0}^{n-1} \prod_{j=0, j!=i}^{n-1} y[i]*(z-x[j])/(x[i]-x[j]). It's O(N_POINTS^2).
ll evaluate(ll const z) {
    ll ans = 0;
    for(int i = 0; i < N_POINTS; i++) {
        ll temp = cte[i];
        for(int j = 0; j < N_POINTS; j++) {
            if(i == j) continue;
            temp *= z-x[j];
            temp %= mod;
        }
        ans += temp;
        ans %= mod;
    }
    return ans;
}

