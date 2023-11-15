#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

const int MAX_N = 15;
const int MAX_MASK = (1<<MAX_N);
const int inf = INT_MAX/10;

int v[MAX_N+1][MAX_N+1]; 
int dp[MAX_MASK][MAX_N];


int main(int argc, char** argv) {
    int tt, n, i, j, mask, k;
    
    cin >> tt;
    while(tt--) {
        cin >> n;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        
        for(k = 0; k < n; k++) {
            for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
        
        
        
        for(i = 0; i < MAX_MASK; i++) {
            for(j = 0; j < MAX_N; j++) {
                dp[i][j] = inf;
            }
        }
        int ult_mask = (1<<n)-1;
        for(i = 1; i < n; i++) {
            dp[1<<i][i] = v[0][i];
        }
        for(mask = 0; mask < ult_mask; mask++) {
            for(i = 1; i < n; i++) { //i esta a 0
                if((mask & (1<<i)) != 0) continue;
                //
                for(j = 1; j < n; j++) { //j esta puesto, 1
                    if((mask & (1<<j)) == 0) continue;
                        dp[mask|(1<<i)][i] = min(dp[mask|(1<<i)][i], dp[mask][j] + v[j][i]);   
                }
            }
        }
        
        int ans = inf;
        for(i = 1; i < n; i++) {
            ans = min(ans, dp[ult_mask-1][i] + v[i][0]);
        }
        cout << ans << "\n";
        
        //cout << endl << endl;
        //cout << dp[0][0] << " " << dp[0b10][1] << " .. " << dp[0b110][1] <<"="<<dp[0b110][2]<<endl;
        
    }
    
    return 0;
}

