const ll NUM_MAX = 1e5 + 10;
bool num[NUM_MAX]; // if num[i] = false => i is prime.
vector<int> prime;
ll phi[NUM_MAX];

// phi[x] is the number of coprime numbers with x. phi(p^k) = p^k - p^(k-1).
void totient_function_generator(int max_num_prime){ // Works in O(n), also creates a sieve.
    int i, j, prime_size = 0;
    
    phi[1] = 1;
    
    for(i = 2; i <= max_num_prime; ++i){
        if(num[i] == false) {prime.push_back(i); ++prime_size; phi[i] = i - 1;} // If p is prime.
        
        for(j = 0; j < prime_size && i * prime[j] <= max_num_prime; ++j){
            num[i * prime[j]] = true;
            if(i % prime[j] != 0) // If p doesn't divide i.
                phi[i * prime[j]] = phi[i] * phi[prime[j]]; 
            else { // If p divides i.
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            } 
        }
    }
    
}

