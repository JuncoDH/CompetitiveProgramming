#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define push_back pb
#define make_pair mp

using namespace std;


typedef long long ll;
typedef vector<ll> vll;

const int MAX = 1e5+10;
ll tree[MAX*4];
vll v;

void build(int k, int l, int r) {
    if(l == r) {tree[k] = v[l]; return;}
    int mid = (l+r)/2;
    build(k<<1, l, mid);
    build(k<<1|1, mid+1, r);
    tree[k] = min(tree[k<<1], tree[k<<1|1]);
}

ll query(int k, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return tree[k];
    if(r < ql || qr < l) return LLONG_MAX;
    int mid = (l+r)/2;
    ll a = query(k<<1, l, mid, ql, qr);
    ll b =query(k<<1|1, mid+1, r, ql, qr);
    return min(a, b);
}


int main() {
    ll n, q, i, l, r;
    cin >> n >> q;
    v.assign(n, 0);
    for(i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1);
    for(i = 0; i < q; i++) {
        cin  >> l >> r;
        cout << query(1, 0, n-1, l, r) << "\n";
    }


    return 0;
}
