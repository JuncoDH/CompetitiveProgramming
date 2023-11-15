#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, n, m, mw, mr, i, ri, wi, cont;

    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        mr = mw = 0;
        for(i = 0; i < m; i++) {
            cin >> ri >> wi;
            mr = max(mr, ri);
            mw = max(mw, wi);
        }
        if(mr + mw > n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cont = 0;
        for(i = 0; i < mr; i++) {
            cout << "R";
            cont++;
        }
        for(i = 0; i < mw; i++) {
            cout << "W";
            cont++;
        }
        for(; cont < n; cont++) {
            cout << "W";
        }
        cout << "\n";
    }

    return 0;
}