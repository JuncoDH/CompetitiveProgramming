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


ll MAX = 10000000;
vector<bool> used(MAX, false);
vll primes;
ll primes_len;
void Fill_primes() {
    ll i, j;

    for(i = 2; i < MAX; ++i) {
        if(!used[i]) {primes.pb(i); ++primes_len;}
        for(j = 0; j < primes_len && i * primes[j] < MAX; ++j) {
            used[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

vll prime_anagram = {2, 3, 5, 7};

bool valid(ll num) {
    int new_num;
    vi d;
    while(num) {
        d.pb(num % 10);
        num /= 10;
    }
    
    for(auto c : d) if(c == 2 || c == 4 || c == 6 || c == 8 || c == 0 || c == 5) return false;
    
    sort(d.begin(), d.end());
    do {
        new_num = 0;
        for(auto c : d) {
            new_num *= 10;
            new_num += c;
        }
        if(binary_search(primes.begin(), primes.end(), new_num) == false) return false;
        
    } while(next_permutation(d.begin(), d.end()));
    
    return true;
}

//there are only 22 prime anagrams
vi anagrams = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};


int main(){
    ios::sync_with_stdio(false);
    int n;
    
    /*Fill_primes();

    for(i = 4; i < primes_len; ++i) {
        if(valid(primes[i])) prime_anagram.pb(primes[i]);
    }*/
    
    while(true) {
        cin >> n;
        if(!n) return 0;
        
        if(n >= 991) {cout << "0\n"; continue;}
        
        auto it = upper_bound(anagrams.begin(), anagrams.end(), n) - anagrams.begin();
        
        if(floor(log10(n)) + 1 < floor(log10(anagrams[it])) + 1) {cout << "0\n"; continue;}
        
        cout << anagrams[it] << "\n";
    }

    return 0;
}
