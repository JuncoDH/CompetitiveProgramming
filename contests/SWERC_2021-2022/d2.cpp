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

vll psum;
ll f(ll l, ll r) {
    ll ans = psum[r];
    if(l > 0) ans -= psum[l-1];
    return ans;
}

bool intersect(ll shop1, ll p1, ll p2, ll shop2) {
    if(p1 <= shop1) return false;
    if(p2 >= shop2) return false;
    ll dx1 = p1 - shop1;
    ll dx2 = shop2 - p2;
    if(p1 + dx1 > p2 - dx2) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, m, i, ans, tans, l, r;
    bool ok;

    cin >> n >> m;
    vll p(n), shop(m);
    psum.assign(n, 0);
    for(i = 0; i < n; i++) cin >> p[i];
    for(i = 0; i < m; i++) cin >> shop[i];
    ans = 0;
    sort(shop.begin(), shop.end());
    for(i = 0; i < m; i++) {
        if(shop[i]%100 == 0 && shop[i]/100 < n) {
            p[shop[i]/100] = 0;
        }
    }
    psum[0] = p[0];
    for(i = 1; i < n; i++) psum[i] = psum[i-1] + p[i];
    tans = 0;
    for(i = 0; i < n; i++) {
        if(100*i >= shop[0]) break;
        tans += p[i];
    }
    ans = max(ans, tans);
    tans = 0;
    for(i = n-1; i >= 0; i--) {
        if(100*i <= shop[m-1]) break;
        tans += p[i];
    }
    ans = max(ans, tans);

    l = 0;
    for(i = 0; i < m-1; i++) { // shop i, i+1.
        while(l < n && 100*l <= shop[i]) l++;
        if(l >= n) break;
        r = l;
        tans = 0;
        ok = false;
        while(100*l < shop[i+1]) {          
            while(intersect(shop[i], 100*l, 100*r, shop[i+1])) {
                tans += p[r];
                // cout << "inter" << l << " " << r << endl;
                ans = max(ans, tans);
                r++;
                if(r >= n) {
                    ok = true; break;
                }
            }
            if(ok) break;
            tans -= p[l];
            l++;
            if(l >= n) {ok = true; break;}
            if(l > r) break;
        }
        if(ok) break;  
    }



    cout << ans << "\n";


    return 0;
}