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



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, i, sum, x, j;
    while(cin >> n) {
        vll v(n);
        for(i = 0; i < n; i++) cin >> v[i];
        sum = 0;
        for(i = 0; i < n; i++) {
            sum += v[i];
        }
        if(sum%2 == 1) {
            cout << "No\n";
            continue;
        }
        vll dp(sum, 0), dp2(sum, 0);
        dp[0] = 1;
        for(j = 0; j < n; j++) {
            for(i = 0; i < sum; i++) {
                if(dp[i] && i+j < sum) dp2[i+j] = 1;
            }
            dp = dp2;
        }
        if(dp[sum] == 0) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        x = sum/2;
        for(j = 0; j < n; j++) {
            if(j > 0) cout << " ";
            if(x > 0 && x-v[j] >= 0 && dp[x-v[j]]) {
                cout << 1;
            } else cout << -1;
        }
        cout << "\n";
        
        
    }



    return 0;
}

