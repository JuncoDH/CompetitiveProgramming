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


const ll MAX = 10005;
ll v[MAX], vmn[MAX], dp[MAX];
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll ans, i, j, n;
    string s;
    
    while(cin >> n) {
        ans = 0;
        cin >> s;
        for(i = 0; i < n; i++) {
            v[i] = s[i]-'0';
        }
        vmn[n] = 0;
        vmn[n-1] = v[n-1];
        ans += v[n-1]; 
        for(i = n-2; i >= 0; i--) {
            vmn[i] = v[i];
            //a//ns += v[i];
            //ans %= mod;
            for(j = i+1; j < n; j++) {
                if(v[j] > v[i]) vmn[i] += v[i];
                else {
                    vmn[i] += vmn[j];
                    break;
                }
                vmn[i] %= mod;
            }
            vmn[i] %= mod;
            ans += vmn[i];
            ans %= mod;
        }
        cout  << (ans%mod) << "\n";
    }

    return 0;
}