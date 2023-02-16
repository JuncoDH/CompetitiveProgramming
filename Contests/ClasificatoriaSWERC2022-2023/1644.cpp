#include <bits/stdc++.h>
// https://uhunt.onlinejudge.org/vcontest/85630359e39dc70c2f45d2f75d3ab7ba
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long long inf = LLONG_MAX/10;

using ld = long double;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MAX_PRIME = 2*1e6+5;
bool num[MAX_PRIME];
vector<int> prime;
void linear_sieve() {
    int i, j, prime_size = 0;
    for(i = 2; i < MAX_PRIME; i++) {
        if(num[i] == false) {prime.pb(i); prime_size++;}
        for(j = 0; j < prime_size && i*prime[j] < MAX_PRIME; j++) {
            num[i*prime[j]] = true;
            if(i%prime[j] == 0) break;
        }
    }
}

bool f(ll x) {
    if(x <= 1) return false;
    return num[x] == false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll i;
    linear_sieve();
    //for(i = 0; i < 10; i++) {
    //    cout << i << " " << f(i) << endl;
    // }
    ll x, l, r;
    while(cin >> x) {
        if(x == 0) return 0;
        l = r = x;
        if(f(x)) {
            cout << 0 << "\n";
            continue;
        }
        while(!f(l)) l--;
        while(!f(r)) r++;
        cout << r-l << endl;
    }



    return 0;
}

