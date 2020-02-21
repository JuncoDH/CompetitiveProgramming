#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back


typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

const ll NUM_MAX = 65005; //OJOJOJOJJOOJJOJ
bool num[NUM_MAX];
vector<int> prime;

void sieve(int max_num_primo) {
    int i, j, prime_size = 0;

    for(i = 2; i <= max_num_primo; i++) {
        if(num[i] == false) { prime.pb(i); ++prime_size;
        }
        for(j = 0; j<  prime_size && i*prime[j] <= max_num_primo; ++j) {
            num[i * prime[j]] = true;
            if(i%prime[j] == 0) break;
        }
    }
}

ll mod;
ll elevate(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans*a % mod;
        b >>= 1;
        a = a*a % mod;
        //cout << b << " " << ans << " " << a << endl;
    }
    return ans;
}

int main(){
    ll n, i;
    bool flag;
    sieve(NUM_MAX-1);
   /* for(int i = 0; i < 10; i++) {
        cout << prime[i] << endl;
    }

    mod = 77;
    cout << elevate(2, 3) << endl;*/
    while(true) {
        cin >> n;
        if(n == 0) return 0;
        
        flag = true;
        if(binary_search(prime.begin(), prime.end(), n)) flag = false;
        else {
            mod = n;
            for(i = 2; i < n; i++) {
                if(elevate(i, n) != i) {flag = false; break;}
            }
        }
        if(flag) {
            cout << "The number " << n << " is a Carmichael number.\n";
        }
        else cout << n << " is normal.\n";
    }


    return 0;
}