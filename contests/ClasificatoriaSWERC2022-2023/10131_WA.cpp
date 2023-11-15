#include <bits/stdc++.h>
// https://uhunt.onlinejudge.org/vcontest/85630359e39dc70c2f45d2f75d3ab7ba
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

vector<pll> LIS(vector<pair<ll, ll>> &v) {
    int i, t, n = v.size();
    if (n==0) return vector<pll>();
    vector<pll> lis, ans;
    vll lis_t(n);
    lis.pb(v[0]); lis_t[0] = 1;
    for (i = 1; i < n; i++) {
        if(v[i] == lis.back()) continue;
        if(v[i].fi == lis.back().fi) continue;
        if(v[i].se == lis.back().se) continue;
        if (v[i] >= lis.back()) {
            lis.pb(v[i]); lis_t[i] = lis.size(); continue;
        }
        int pos = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if(pos>0 && lis[pos-1] == v[i] || lis[pos-1].fi == v[i].fi || lis[pos-1].se == v[i].se) continue;
        lis[pos] = v[i];
        lis_t[i] = pos+1;
    }
    for (i = n-1, t = lis.size(); i >= 0; i--) {
        if (lis_t[i] == t && (ans.empty() || v[i] < ans.back()))
            ans.pb(v[i]), t--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll num1, num2, i;
    vector<pair<pair<ll, ll>, ll>> v;
    i = 0;
    while(cin >> num1 >> num2) {
        v.pb(mp(mp(-num2, num1), i));
        i++;
    }
    sort(v.begin(), v.end());
    // reverse(v.begin(), v.end());
    for(i = 0; i < (int)v.size(); i++) {
        swap(v[i].fi.fi, v[i].fi.se);
        //v[i].fi.se *= -1;
    }
    vector<pll> b;
    for(i = 0; i < (int)v.size(); i++) {
        b.pb(v[i].fi);
    }
    for(auto el : b) {
        cout << el.fi << ".." << el.se << endl;
    }
    auto ans = LIS(b);
    cout << ans.size() << endl;
    for(auto el : ans) {
        cout << el.fi << " " << el.se << "\n";
    }
    //for(i = 0; i < (int)v.size(); i++) {
    //    cout << v[i].fi.fi << " " << v[i].fi.se << " " << v[i].se << "\n";
    //}
    //for(auto el : ans) {
    //    cout << el << "\n";
    //}
    ll j = 0;
    // cout << "asdf"<< endl;
    vll vans;
    // cout << ans.size() << "\n";
    ll prev = -1;
    /*for(i = 0; i< (int)v.size(); i++) {
        if(j == (int)ans.size()) break;
        if(v[i].fi.fi == ans[j]) {
            if(prev != -1 && v[prev].fi.fi >= v[i].fi.fi) continue;
            if(prev != -1 && v[prev].fi.se <= v[i].fi.se) continue;
            //cout << v[i].fi.fi << ".." << v[i].fi.se << endl;
            //cout << v[i].se +1 << "\n";
            vans.pb(v[i].se + 1);
            prev = i;
            j++;
        }
    }
    cout << vans.size() << "\n";
    for(auto el : vans) {
        cout << el << "\n";
    }*/

    return 0;
}

