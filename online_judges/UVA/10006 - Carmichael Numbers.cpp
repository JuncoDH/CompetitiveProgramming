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


ll MAX = 65000;
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

ll mod;
ll bin_pow(ll a, ll e) {
    if(e == 0) return 1;
    ll ans = bin_pow(a, e / 2);
    if(e & 1) return (ans * ans % mod) * a % mod;
    return ans * ans % mod;
}

int main(){
    ios::sync_with_stdio(false);
    ll n, i;
    bool flag;
    Fill_primes();
    
    
    while(true) {
        cin >> n;
        if(!n) return 0;
        mod = n;

        flag = true;
        
        if(binary_search(primes.begin(), primes.end(), n)) {cout << n <<" is normal.\n"; continue; }
        for(i = 2; i <= n - 1; ++i) {
            if(bin_pow(i, n) != i) {flag = false; break;}
        }
        
        if(flag) cout << "The number "<< n <<" is a Carmichael number.\n";
        else cout << n <<" is normal.\n";

    }

    return 0;
}
