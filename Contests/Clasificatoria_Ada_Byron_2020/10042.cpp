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

const ll NUM_MAX = 1e5; //OJOJOJOJJOOJJOJ
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

ll sum(ll n) {
    ll ans = 0;
    while(n) {
        ans += n%10;
        n /= 10;
    }
    return ans;
}

bool wron;

bool f(ll n) {
    ll num2 = n;
    ll ans2 = sum(n);
    ll ans = 0;
    for(auto p : prime) {
        if(p*p > n) {
            break;
        }
        while(n%p == 0) {
            ans += sum(p);
            n /= p;
        }
    }
    //cout << ans << " " << ans2 << " " << n << endl;
    if(n == num2) {return false;}
    if(n > 1) {
        ans += sum(n); 
    }
    if(ans == ans2) return true;
    return false;
}

int main(){
    //ll i;
    sieve(NUM_MAX -1);

    /*
    for(i = 1e7; i < 1e9+100; i++) {
        if(f(i)) {
            cout << i << endl;
        }
    }*/
    //cout << f(4937775) << endl;
    //cout << f(9985) << endl;
    //cout << f(6036) << endl;
    ll tt, n;
    cin >> tt;
    while(tt--) {
        cin >> n;
        for(n++;;++n) {
            if(binary_search(prime.begin(), prime.end(), n)) continue;
            //wron = false;
            if(f(n)) break;
        }
        cout << n << "\n";
    }


    return 0;
}