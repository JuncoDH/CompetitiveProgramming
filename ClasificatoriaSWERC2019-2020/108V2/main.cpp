/*AC*/
#include <bits/stdc++.h>

#define echo(x) cout << #x << ":" << x << endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll inf = (LLONG_MAX/10);

int main(void) {
    ll i, j, n, ans = -inf, lans, k;
    cin >> n;
    vector<vector<ll>> v(n+1, vector<ll>(n+1, 0));
    vector<vector<ll>> p(n+1, vector<ll>(n+1, 0));
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cin >> v[i][j];
            ans = max(ans, v[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            p[i][j+1] = p[i][j] + v[i][j];
        }
    }

    
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            lans = 0;
            for(k = 0; k < n; k++) {
                lans += p[k][i+1] - p[k][j];
                ans = max(ans, lans);
                if(lans <= 0) lans = 0;
            }
        }
    }
    
    cout << ans << "\n";
    
    
    
    return 0;
}
/*
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
        *//*
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2*/