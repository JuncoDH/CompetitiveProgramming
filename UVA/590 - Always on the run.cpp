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


const ll inf = LLONG_MAX;

int main(){
    ios::sync_with_stdio(false);
    ll i, j, n, k, z, d, num, Cases = 1;

    while(true) {
        cin >> n >> k;
        if(n == 0 && k == 0) return 0;

        //dp[i][j] is the minimum amount to pay if you start in the city i + 1 and the day j + 1. The answer is in dp[0][0]. At the beginning, dp[i][k] = inf and dp[n - 1][k] = 0.
        //transitions: dp[i][j] = min_{z / exist a travel between i and z the day j + 1} (dp[z][j + 1] + conexion[i][z][day j])

        vector<vector<vll>> graph(n, vector<vll>(n));
        vector<vll> dp(n, vll(k + 1, -1));
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j){
                if(j == i) continue;
                cin >> d;
                graph[i][j].pb(d);
                for(z = 0; z < d; ++z) {cin >> num; graph[i][j].pb(num);}         
            }
        }


        for(i = 0; i < n; ++i) if(i == n - 1) dp[i][k] = 0; else dp[i][k] = inf;

        for(j = k - 1; j >= 0; --j) {
            for(i = 0; i < n; ++i){
                dp[i][j] = inf;
                for(z = 0; z < n; ++z){
                    if(z == i || dp[z][j + 1] == inf) continue;

                    if(graph[i][z][j % graph[i][z][0] + 1] != 0) 
                        dp[i][j] = min(dp[i][j], graph[i][z][j % graph[i][z][0] + 1] + dp[z][j + 1]);
                }
            }

        }

        
        cout << "Scenario #" << Cases++ << "\n";
        if(dp[0][0] == inf) cout << "No flight possible.\n\n";
        else cout << "The best flight costs " << dp[0][0] << ".\n\n";
        
    }
    
    
    return 0;
}

