// You can do Mobius inversion,
// that is Sum_{d|n} mu[d] = [n == 1]. (Maybe n = gcd(a_i) usually).
constexpr int MAX = 1e5;
int mu[MAX]; // mu(n) = 0 if n is square prime and (-1)^t if n = p1...pt.
void mobius_init() {
    vi prime;
    bool is_composite[MAX];
    fill(is_composite, is_composite + MAX, false);
    mu[1] = 1;
    for(int i = 2; i < MAX; ++i) {
        if(!is_composite[i]) prime.pb(i), mu[i] = -1;
        for(auto const& p : prime) {
            if(i * p >= MAX) break;
            is_composite[i * p] = true;
            if(i % p == 0) { // if p divides i.
                // mu[i * p] = 0; // Already 0.
                break;
            }
            mu[i * p] = mu[i] * mu[p];
        }
    }
}

