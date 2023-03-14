#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back

const ll inf = LLONG_MAX/10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, tt, prevx, prevy, ans, i, a, b;
    cin >> tt;
    while(tt--) {
        cin >> n;
        ans = -inf;
        cin >> prevx >> prevy;
        for(i = 1; i < n; i++) {
            cin >> a >> b;
            ans = max(ans, 3*abs(a-prevx)+2*(b-prevy));
            prevx = a;
            prevy = b;
        }
        cout << ans << "\n";
    }
    
    return 0;
}