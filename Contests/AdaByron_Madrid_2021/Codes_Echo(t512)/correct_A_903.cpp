#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

#define pb push_back
#define fi first
#define se second
#define LSB(x) (x)&(-(x))
using namespace std;

using vi = vector<int>;
using ll = unsigned long long;
using pi = pair<int,int>;
using vll = vector<ll>;

const int MAX = 1e5+5;
ll dp[MAX][11];

class BIT {
    vector<ll> bit;
    int n;
    public:
    BIT(int _n) {
        n = _n;
        bit.assign(n+1, 0);
    }
    void update(int i, ll dx) {
        for(i++; i<n+1; i += LSB(i)) bit[i] += dx;
    }
    ll query(int r) {
        ll ans = 0;
        for(r++; r > 0; r-=LSB(r)) ans += bit[r];
        return ans;
    }
};

int main(){
    ll n, k, i, z;
    cin >> n >> k;
    vll v(n), v2(n);
    for(i = 0; i < n; i++) {
        cin >> v2[i];
        v[i] = v2[i];
    }
    sort(v2.begin(), v2.end());
    for(i = 0; i < n; i++) {
        v[i] = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
    }

    for(i = 0; i < n; i++) dp[i][0] = 1;

    for(z = 1; z < k; z++) {
        BIT bit(n + 2);

        for (i = 0; i < n; i++) {
            dp[i][z] = bit.query(v[i] - 1);
            bit.update(v[i], dp[i][z-1]);
            // cout << dp[i][z] << " ";
        }
       // cout << endl;
    }
    ll ans = 0;
    for(i = 0; i < n; i++) {
        ans += dp[i][k-1];
    }
    cout << ans << "\n";

}