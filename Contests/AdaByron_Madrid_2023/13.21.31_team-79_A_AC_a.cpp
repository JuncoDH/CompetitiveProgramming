#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back

const ll MAX = 4*100000+3;
ll tree[MAX];
vll df;
void build(int k, int l, int r) {
    if(l == r) {
        tree[k] = df[l];
        return;
    }
    int mid = (l+r)/2;
    build(k<<1, l, mid);
    build(k<<1|1, mid+1, r);
    tree[k] = max(tree[k<<1], tree[k<<1|1]);
}

void update(int k, int l, int r, int x) {
    if(x < l || x > r) return;
    if(l == r) {
        tree[k] = 0;
        return;
    }
    int mid = (l+r)/2;
    update(k<<1, l, mid, x);
    update(k<<1|1, mid+1, r, x);
    tree[k] = max(tree[k<<1], tree[k<<1|1]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, tt, i, ans;
    cin >> tt;
    while(tt--) {
        cin >> n;
        vll v(n);
        for(i = 0; i < n; i++) cin >> v[i];
        if(n == 1) {
            cout << "0\n";
            continue;
        }
        df.assign(n-1, 0);
        sort(v.begin(), v.end());
        for(i = 0; i < n-1; i++) {
            df[i] = v[i+1]-v[i];
        }
        sort(df.begin(), df.end());
        ans = 0;
        for(i = 0; i < n-1; i++) ans += df[i];
        for(i = 0; i < n-1; i++) {
            cout << ans << " ";
            ans -= df.back();
            df.pop_back();
        }
        cout << "0\n";

        /*map<ll, vll> m;
        for(i = 0; i < n-1; i++) {
            df[i] = v[i+1]-v[i];
            m[df[i]].pb(i);
        }
        build(1, 0, n-2);
        do {
            ans = tree[1];
            cout << ans << " .";
            auto u = m[ans];
            // cout << u.size() << "gr"
            update(1, 0, n-2, u.back());
            m[ans].pop_back();

        } while(ans != 0);
        cout << "\n";*/
    }
    
    return 0;
}