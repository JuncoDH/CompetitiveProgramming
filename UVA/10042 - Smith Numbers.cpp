#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))


typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll MAX = 1e5;
vector<bool> used(MAX, false);
vll prefactor(MAX);
vll primes;
ll primes_len;
void Fill_primes() {
    ll i, j;

    for(i = 2; i < MAX; ++i) {
        if(!used[i]) {primes.pb(i); ++primes_len; prefactor[i] = i;}
        for(j = 0; j < primes_len && i * primes[j] < MAX; ++j) {
            used[i * primes[j]] = true;
            prefactor[i * primes[j]] = prefactor[primes[j]];
            if(i % primes[j] == 0) break;
        }
    }
}


ll Digits(ll num) {
    ll ans = 0;
    while(num) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}


int is_prime; //number of divisors
ll Decomposition(ll num) {
    if(num == 1) return 0;
    ++is_prime;
    if(num < MAX) return Digits(prefactor[num]) + Decomposition(num / prefactor[num]);
    for(auto el : primes) if(num % el == 0) return Digits(el) + Decomposition(num / el);
    return Digits(num);
}

int main(){
    ios::sync_with_stdio(false);
    ll sum1, sum2, n, t;
    Fill_primes();
   /*echo(primes.size());
    
    ll p = primes[primes_len - 1];
    echo(p, p * p, p * p > 1e9);
    
    return 0;*/

   // echo(Decomposition(4997814), Digits(4997814), binary_search(primes.begin(), primes.end(), 4997814));     return 0;

    
    cin >> t;
    while(t--) {
        cin >> n;
        while(++n) {
            is_prime = 0;
            sum1 = Decomposition(n);
            sum2 = Digits(n);
            if(is_prime == 1 || binary_search(primes.begin(), primes.end(), n)) continue;
            if(sum1 == sum2) {cout << n << "\n"; break;}
        }
    }

    return 0;
}
