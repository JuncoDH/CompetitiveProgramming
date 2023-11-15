#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef long long ll;
typedef vector<ll> vll;

int main() {
    ll tt, n, i, k;


    cin >> tt;
    while(tt--) {
        cin >> n >> k;
        vll v(n);
        vll ma(n);
        ll ans = 0;
        for(i = 0; i < n; i++) {
            cin >> v[i];
        }
        ma[n-1] = v[n-1];
        for(i = n-2; i>= 0; i--) {
            ma[i] = max(ma[i+1], v[i]);
        }
        for(i = 0; i < n-1; i++) {
            if(ma[i+1] > v[i]) ans += ma[i+1]-v[i];
        }
        if(ans > k) cout << ans - k << "\n";
        else cout << "En tiempo\n";
    }

    return 0;
}
