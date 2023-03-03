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
    ll tt, i, n;
    string s, t;
    cin >> tt;
    while(tt--) {
        cin >> s;
        n = s.length();
        set<string> ss;
        s += s;
        for(i = 0; i < n; i++) {
            t = s.substr(i, n);
            ss.insert(t);
        }
        cout << (*ss.begin()) << "\n";
    }


    return 0;
}