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
    ll i, j, mx, i2, j2, n;
    char m[105][105];
    string s;
    for(i = 0; i < 105; i++) {
        for(j = 0; j < 105; j++) {
            m[i][j] = ' ';
        }
    }
    mx = 0;
    i = 0;
    while(getline(cin, s)) {
        n = s.length();
        mx = max(mx, n);
        for(j = 0; j < n; j++) {
            m[i][j] = s[j];
        }
        i++;
    }
    for(j2 = 0; j2 < mx; j2++) {
        for(i2 = i-1; i2 >= 0; i2--) {
            cout << m[i2][j2];
        }
        cout << "\n";
    }


    return 0;
}