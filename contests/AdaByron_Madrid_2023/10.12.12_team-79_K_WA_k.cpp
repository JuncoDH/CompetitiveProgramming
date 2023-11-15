#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back

const ll mod = 256;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll tt, ans;
    uint32_t n, i;
    cin >> tt;
    while(tt--) {
        cin >> n;
        // n %= mod;
        ans = 0;
        for(i = 0; i <= 255; i++) {
            if(i == ((n*i)%mod)) ans++;
        }
        cout << ans << "\n";
    }


    return 0;
}