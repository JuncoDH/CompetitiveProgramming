constexpr int MAX_PRIME = 1e6 + 5;
bool num[MAX_PRIME]; // If num[i] = false => i is prime.
int num_div[MAX_PRIME]; // Number of prime divisors of i.
int min_div[MAX_PRIME]; // The smallest prime that divide i.
vector<int> prime;
void linear_sieve(){
    int prime_size = 0;
    min_div[1] = 1;
    for(int i = 2; i < MAX_PRIME; ++i){
        if(num[i] == false) { prime.push_back(i); ++prime_size; num_div[i] = 1; min_div[i] = i; }
        for(int j = 0; j < prime_size && i * prime[j] < MAX_PRIME; ++j){
            num[i * prime[j]] = true;
            num_div[i * prime[j]] = num_div[i] + 1;
            min_div[i * prime[j]] = min(min_div[i], prime[j]);
            if(i % prime[j] == 0) break;
        }
    }
}
bool is_prime(ll const n) {
    for(auto const& el : prime) {
        if(n == el) return true;
        if(n % el == 0) return false;
    }
    return true;
}
vll fact, nfact; // The factors of n and their exponent. n >= 1.
void factorize(int n) { // Up to MAX_PRIME*MAX_PRIME.
    ll cont, prev_p;
    fact.clear(); nfact.clear();
    for(auto const& p : prime) {
        if(n < MAX_PRIME) break;
        if(n % p == 0) {
            fact.pb(p);
            cont = 0;
            while(n % p == 0) n /= p, cont++;
            nfact.pb(cont);
        }
    }
    if(n >= MAX_PRIME) {
        fact.pb(n);
        nfact.pb(1);
        return;
    }
    while(n != 1) { // When n < MAX_PRIME, factorization in almost O(1).
        prev_p = min_div[n];
        cont = 0;
        while(n % prev_p == 0) n /= prev_p, cont++;
        fact.pb(prev_p);
        nfact.pb(cont);
    }
}

