#include <bits/stdc++.h>

//#pragma GCC diagnostic ignored "-Wsign-compare"

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, k;
bool box_sort(pair<vi, int> &a, pair<vi, int> &b) {
    int i;
    for(i = 0; i < n; ++i) {
        if(a.fi[i] != b.fi[i]) return a.fi[i] < b.fi[i];
    }
    return true;
}

bool Fit(pair<vi, int> &a, pair<vi, int> &b) {
    int i;
    for(i = 0; i < n; ++i) {
        if(a.fi[i] >= b.fi[i]) return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    vector<pair<vi, int>> v;
    vi LIS, ans;
    ll i, j, M, Mi;

    while(cin >> k) {
        cin >> n;
        v.assign(k, mp(vi(n, 0), 0));
        LIS.assign(k, 0);
        ans = vi();
        for(i = 0; i < k; ++i) {
            for(j = 0; j < n; ++j) cin >> v[i].fi[j];
            sort(v[i].fi.begin(), v[i].fi.end());
            v[i].se = i;
        }
        
        sort(v.begin(), v.end(), box_sort);
        //cout << v;
        
        for(i = 0; i < k; ++i) {
            for(j = i + 1; j < k; ++j) {
                if(Fit(v[i], v[j])) {
                    LIS[j] = max(LIS[j], LIS[i] + 1);
                }
            }
        }
        
        //show LIS
       
        Mi = max_element(LIS.begin(), LIS.end()) - LIS.begin();
        M = *max_element(LIS.begin(), LIS.end());
        --M;
        ans.pb(v[Mi].se);
        for(i = Mi- 1; i >= 0; --i) {
            if(LIS[i] == M && Fit(v[i], v[Mi])) {
                M--;
                Mi = i;
                ans.pb(v[i].se);
            }
        }
        cout << ans.size() << "\n";
        for(i = ans.size() - 1; i >= 0; --i){
            cout << ans[i] + 1;
            if(i > 0) cout << " ";
        }
        cout << "\n";


    }
    return 0;
}