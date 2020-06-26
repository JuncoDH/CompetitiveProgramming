const int MAX_PRIMES = 5*1e5+5;
bool num[MAX_PRIMES]; //if num[i] = false => i is prime
int num_div[MAX_PRIMES]; //number of divisors of i
int min_div[MAX_PRIMES]; //the smallest prime that divide i
vector<int> prime;
 
void linear_sieve(){
    int i, j, prime_size = 0;
    min_div[1] = 1;
    for(i = 2; i < MAX_PRIMES; ++i){
        if(num[i] == false) {prime.push_back(i); ++prime_size; num_div[i] = 1; min_div[i] = i;}
        
        for(j = 0; j < prime_size && i * prime[j] < MAX_PRIMES; ++j){
            num[i * prime[j]] = true;
            num_div[i * prime[j]] = num_div[i] + 1;
            min_div[i * prime[j]] = min(min_div[i], prime[j]);
            if(i % prime[j] == 0) break;
        }
    }
}
 
bool is_prime(ll n) {
    for(auto el : prime) {
        if(n == el) return true;
        if(n%el == 0) return false;
    }
    return true;
}
 
void factorize(int n) { //example of factoring n
    while(n != 1) {
        cout << min_div[n] << " ";
        n /= min_div[n];
    } cout << endl;
}
