#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back

const ll inf = LLONG_MAX/10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll i, n, m, x, y, k, mn, mn2, ret;

    cin >> n >> m;
    vector<string> v(m);
    vll freq(10, 0);
    vll cont(10, inf);
    for(i = 0; i < m; i++) {
        cin >> v[i];
        for(auto c : v[i]) {
            if(c == '.') continue;
            cont[c-'0'] = 0;
            freq[c-'0']++;
        }
    }
    cin >> k;
    for(i = 0; i < k; i++) {
        cin >> x >> y;
        cont[v[x][y]-'0']++;
    }
    ret = 0;
    mn = inf;    
    for(i = 0; i < 10; i++) {
        mn = min(mn, cont[i]);
    }
    // cout << mn << cont[9] << endl;
    for(i = 0; i < 10; i++) {
        if(cont[i] == mn) ret++;
    }
    if(ret == 1) {
        for(i = 0; i < 10; i++) {
            if(cont[i] == mn) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    mn2 = inf;
    for(i = 0; i < 10; i++) {
        if(cont[i] == mn && freq[i] > 0) {
            mn2 = min(mn2, freq[i]);
        }
    }
    // cout << "mn" << mn << " " << mn2 << endl;

    for(i = 0; i < 10; i++) {
        if(cont[i] == mn && freq[i] == mn2) {
            cout << i << "\n";
            return 0;
        }
    }


    return 0;
}