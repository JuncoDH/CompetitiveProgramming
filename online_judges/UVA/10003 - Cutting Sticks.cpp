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

const ll inf = 999999999;

int main(){
    ios::sync_with_stdio(false);
    ll lmax, n, i, j, k, L;
    vector<vll> dp;
   

    while(true) {
        cin >> lmax;
        if(!lmax) return 0;
        cin >> n;
        vll v(n + 2);
        v[0] = 0;
        v[n + 1] = lmax;
        for(i = 1; i <= n; ++i) cin >> v[i];
        n += 2;
        

        dp.assign(n, vll(n, inf));
       
       for(i = 0; i < n; ++i) dp[i][i] = 0;
       for(i = 0; i + 1 < n; ++i) dp[i][i + 1] = 0;
       
       //L is the number of points we are in the stick of lenght [v[i], v[j]], i and j are no relevant    
       for(L = 3; L <= n; ++L) {
           for(j = L - 1; j < n; ++j){
               i = j - L + 1;
               for(k = i; k < j; ++k) {
                   dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[j] - v[i]);
               }
           }
       }

        cout << "The minimum cutting is " << dp[0][n - 1] << ".\n";
    }

    return 0;
}