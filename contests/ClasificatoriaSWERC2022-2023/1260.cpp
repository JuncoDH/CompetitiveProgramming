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
    ll tt, n, i, ans, j;
    cin >> tt;
    while(tt--) {
        cin >> n;
        vll v(n);
        for(i = 0; i < n; i++) cin >> v[i];
        ans = 0;
        
        for(i = 1; i < n; i++) {
            for(j = 0; j < i; j++) {
                if(v[j] <= v[i]) ans++;
            }
        }
        cout << ans << "\n";
    }



    return 0;
}

