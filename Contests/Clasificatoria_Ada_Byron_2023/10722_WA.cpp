// WA because it has overflow in C++, but code is correct.
#include <bits/stdc++.h>

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


const ll MAX = 105;
ll dp[MAX][2];
ll b;
ll f(ll d, bool used) {
    ll ans = 0;
    // cout << "d" << d << " " << used << endl;
    if(d == 0) return 1;
    if(dp[d][used] != -1) return dp[d][used];
    if(!used) {
        ans = (b-1)*f(d-1, false) + f(d-1, true);
    } else {
        ans = (b-2)*f(d-1, false) + f(d-1, true);
    }
    return dp[d][used] = ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll d, i;

    while(cin >> b >> d) {
        if(b == 0 && d == 0) return 0;
        for(i = 0; i < d+2; i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        cout << f(d-1, true) + (b-2)*f(d-1, false) << "\n";
    }

    return 0;
}
