// Virtual contest with time(NULL)
// https://uhunt.onlinejudge.org/vcontest/4ef2ee1843d616061b9cdd2a96239196
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

using ll = long long;
ll x;
bool f(ll mid) {
    return (mid*(mid+1))/2 <= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll l, r, mid, tt;
    cin >> tt;
    while(tt--) {
        cin >> x;
        if(x == 0) {
            cout << "0\n";
            continue;
        }
        l = 0; r = 3*1e9;
        while(l + 1 < r) {
            mid = (l+r)/2;
            // cout << mid << " " << f(mid) << endl;
            if(f(mid)) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }

    return 0;
}
