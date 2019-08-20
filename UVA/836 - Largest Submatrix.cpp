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



int main(){
    ios::sync_with_stdio(false);
    ll i, j, n, sum, x1, x2, y1, y2, t;
    ll M;
    vector<string> v(30);
    a
    cin >> t;
    while(t--) {
        cin >> v[0];
        n = v[0].length();
        vector<vi> dp(n, vi(n));
        for(i = 1; i < n; ++i) cin >> v[i];
        
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                dp[i][j] = v[i][j] == '1';
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
                if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        
        M = 0;
        for(y2 = 0; y2 < n; ++y2) for(x2 = 0; x2 < n; ++x2) {
            for(y1 = 0; y1 <= y2; ++y1) for(x1 = 0; x1 <= x2; ++x1) {
                sum = dp[x2][y2];
                if(x1 > 0) sum -= dp[x1 - 1][y2];
                if(y1 > 0) sum -= dp[x2][y1 - 1];
                if(x1 > 0 && y1 > 0) sum += dp[x1 - 1][y1 - 1];
                if(sum == (x2 - x1 + 1) * (y2 - y1 + 1)) {
                    M = max(M, sum);
                }
            }
        }
        cout << M << "\n";
        if(t) cout << "\n";
    }

    
    
    return 0;
}


