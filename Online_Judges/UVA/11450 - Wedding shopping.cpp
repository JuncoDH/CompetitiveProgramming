#include <bits/stdc++.h>

//#pragma GCC diagnostic ignored "-Wsign-compare"

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;




int main(){
    ios::sync_with_stdio(false);
    ll c, n, k, i, num, j, u, cases;

    cin >> cases;
    
    while(cases--) {
        cin >> c >> n;
        cin >> k;
        vector<vector<bool> > dp(n, vector<bool>(c + 1, false));
        for(i = 0; i < k; ++i) {
            cin >> num;
            if(num < c + 1) dp[0][num] = true;
        }
        for(i = 1; i < n; ++i) {
            cin >> k;
            for(j = 0; j < k; ++j) {
                cin >> num;
                for(u = 0; u < c + 1; ++u) {
                    if(u + num >= c + 1) break;
                    if(dp[i - 1][u] == true) dp[i][u + num] = true;
                }
            }
        }
        
        for(i = c; i >= 0; --i) if(dp[n - 1][i]) break;
        
        if(i < 0) cout << "no solution\n";
        else cout << i << "\n";
        
    }


    return 0;
}