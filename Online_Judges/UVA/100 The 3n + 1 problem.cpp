#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MAX = 1e6 * 2 + 5;
vector<ll> tree(4*MAX);
vector<ll> v(MAX);

void build(ll k, ll l, ll r) {
    if(l == r) {tree[k] = v[l]; return;}
    ll mid = (l + r) >> 1;
    build(k<<1, l, mid);
    build(k<<1|1, mid+1, r);
    tree[k] = max(tree[k<<1], tree[k<<1|1]);
}

ll query(ll k, ll l, ll r, ll ql, ll qr) {
    if(ql <= l && r <= qr) return tree[k];
    if(qr < l || r < ql) return -3;
    ll mid = (l + r) >> 1;
    if(qr <= mid) return query(k<<1, l, mid, ql, qr);
    if(mid < ql) return query(k<<1|1, mid+1, r, ql, qr);
    ll a = query(k<<1, l, mid, ql, qr);
    ll b = query(k<<1|1, mid+1, r, ql, qr);
    return max(a, b);
}

ll f(ll num) {
    if(num == 1) return 1;
    if(num % 2) return f(3*num+1) + 1;
    else return f(num/2) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    ll l, r, q;
    bool flag;
    
    ll i;
    for(i = 1; i < MAX; i++) {
        v[i] = f(i);
    }
    build(1, 0, MAX-1);
    //cout << endl << query(1, 0, MAX-1, 1, 10);
    while(cin >> l) {
        cin >> r;
        flag = false;
        if(l > r) {flag = true; swap(l, r);}
        q = query(1, 0, MAX-1, l, r);
        if(flag) swap(l, r);
        cout << l << " " << r << " " << q << "\n";
    }
    
    return 0;
}