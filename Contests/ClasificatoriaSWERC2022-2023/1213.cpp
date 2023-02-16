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


const int MAX_PRIME = 1130;
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
map<ll, ll> dp;
void f(ll lst, ll sum, ll cnt) {
    if(sum > 1140) return;
    if(cnt > 14) return;
    dp[sum]++;
    for(auto el : prime) {
        if(el < lst) continue;
        f(el, sum+el, cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    linear_sieve();
    cout << prime.size() << endl;
    f(-1, 0, 0);
    cout << dp.size() << endl;


    return 0;
}

