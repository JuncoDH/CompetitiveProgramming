// Virtual contest with time(NULL)
// https://uhunt.onlinejudge.org/vcontest/4ef2ee1843d616061b9cdd2a96239196
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t, i, k;
    cin >> t;
    ll ans = 0;
    while (t--) {
        priority_queue<ll> pq;
        queue<pair<ll, ll>> q;
        ll n, m;
        ans = 0;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            cin >> k;
            pq.push(k);
            q.push(mp(k, i));
        }

        while (!q.empty()) {
            auto u = pq.top();
            auto v = q.front();
            // cout << "aa" << v.fi << " " << v.se << endl;
            q.pop();
            if(v.fi != u) {
                q.push(v);
                continue;
            }
            ans++;
            pq.pop();
            if(v.se == m) break;
        }
        cout << ans << "\n";
    }

    return 0;
}
