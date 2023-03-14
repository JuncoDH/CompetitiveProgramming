#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back

vll vd, vp;
ll n, k;

bool f(ll num) {
    ll ret = 0, ansllev = 0, nllev = vp[0], i;
    for(i = 1; i < n; i++) {
        // cout << i << " " << ansllev << " " << nllev << " " << num << endl; 
        if(ansllev + nllev*(vd[i]-vd[i-1]) > num) {
            nllev = vp[i];
            ansllev = 0;
            ret++;
            if(ret > k) return false;
        } else {
            ansllev += nllev*(vd[i]-vd[i-1]);
            nllev += vp[i];
        }
    }
    // cout << "ret" << ret << " " << nllev << endl;
    if(nllev > 0) ret++;
    if(ret > k) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll l, r, mid, i;
    while(cin >> n >> k) {
        vd.assign(n, 0);
        vp.assign(n, 0);
        for(i = 0; i < n; i++) {
            cin >> vd[i] >> vp[i];
        }
        if(k == n) {
            cout << "0\n";
            continue;
        }
        /*for(i = 0; i < 10; i++) {
            cout << "i:" << i << endl;
            cout << f(i) << endl;
        }
        return 0;*/
        l = 0; r = 1e9;
        while(l + 1 < r) {
            mid = (l+r)/2;
            if(f(mid)) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }
    
    return 0;
}