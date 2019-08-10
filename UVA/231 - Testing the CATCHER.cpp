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



//O(n log n) LIS
int LIS_len(vi &v) {
    int i, n = v.size(), it;
    vi LIS;
    LIS.pb(v[0]);

    for(i = 1; i < n; ++i) {
        if(binary_search(LIS.begin(), LIS.end(), v[i])) continue;
        else if(v[i] > LIS.back()) LIS.pb(v[i]);
        else {
            it = upper_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
            LIS[it] = v[i];
        }
    }
    return (int)LIS.size();
}

int main(){
    ios::sync_with_stdio(false);
    ll num, nCase = 1;
    
    while(true){
        cin >> num;
        if(num == -1) return 0;
        vi v;
        v.pb(num);
        while(true) {
            cin >> num;
            if(num == -1) break;
            v.pb(num);
        }
        reverse(v.begin(), v.end());
        if(nCase > 1) cout << "\n";
        cout << "Test #"<< nCase++ <<":\n";
        cout << "  maximum possible interceptions: " << LIS_len(v) << "\n"; 
    }

    
    
    
    return 0;
}