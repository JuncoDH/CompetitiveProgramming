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


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, x;
    cin >> tt;
    while(tt--) {
        cin >> x;
        x *= 567;
        x /= 9;
        x += 7492;
        x *= 235;
        x /= 47;
        x -= 498;
        x /= 10;
        cout << (abs(x)%10) << "\n";
    }


    return 0;
}