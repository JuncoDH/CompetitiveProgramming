#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll tt, ans;
    
    ll n, i, ret;

    cin >> tt;
    while(tt--) {
        cin >> n;
        if(n == 0) {
            cout << 1 << "\n";
            continue;
        }
        if(n == 1) {
            cout << (1ll<<32) << "\n";
            continue;
        }
        ans = 0;
        n--;
        ret = 0;
        while(n%2 == 0) {
            ret++;
            n /= 2;
        }
                
       
        cout << (1ll<<ret) << "\n";
    }


    return 0;
}

// 1
// 1073741824
// 2147483648
// 3221225472
