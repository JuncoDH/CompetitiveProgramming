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

vll v;
vll tree1;
void build1(int k, int l, int r) {
    if(l == r) {tree1[k] = v[l]; return;}
    ll mid = (l+r)/2;
    build1(k<<1, l, mid);
    build1(k<<1|1, mid+1, r);
    tree1[k] = min(tree1[k<<1], tree1[k<<1|1]);
}
ll query1(int k, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return tree1[k];
    int mid = (l+r)/2;
    if(qr <= mid) return query1(k<<1, l, mid, ql, qr);
    if(mid+1 <= ql) return query1(k<<1|1, mid+1, r, ql, qr);
    auto a = query1(k<<1, l, mid, ql, qr);
    auto b = query1(k<<1|1, mid+1, r, ql, qr);
    return min(a, b);
}
vll tree2;
void build2(int k, int l, int r) {
    if(l == r) {tree2[k] = v[l]; return;}
    ll mid = (l+r)/2;
    build2(k<<1, l, mid);
    build2(k<<1|1, mid+1, r);
    tree2[k] = min(tree2[k<<1], tree2[k<<1|1]);
}
ll query2(int k, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return tree2[k];
    int mid = (l+r)/2;
    if(qr <= mid) return query2(k<<1, l, mid, ql, qr);
    if(mid+1 <= ql) return query2(k<<1|1, mid+1, r, ql, qr);
    auto a = query2(k<<1, l, mid, ql, qr);
    auto b = query2(k<<1|1, mid+1, r, ql, qr);
    return max(a, b);
}
vll tree3;
void build3(int k, int l, int r) {
    if(l == r) {tree3[k] = v[l]; return;}
    ll mid = (l+r)/2;
    build2(k<<1, l, mid);
    build2(k<<1|1, mid+1, r);
    tree2[k] = min(tree2[k<<1], tree2[k<<1|1]);
}
ll query2(int k, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return tree2[k];
    int mid = (l+r)/2;
    if(qr <= mid) return query2(k<<1, l, mid, ql, qr);
    if(mid+1 <= ql) return query2(k<<1|1, mid+1, r, ql, qr);
    auto a = query2(k<<1, l, mid, ql, qr);
    auto b = query2(k<<1|1, mid+1, r, ql, qr);
    return max(a, b);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, ans, l, r, i;
    while(cin >> n) {
        if(!n) return 0;
        ans = 0;
        v.assign(n, 0);
        tree1.assign(4*n, 0);
        tree2.assign(4*n, 0);
        build1(1, 0, n-1);
        build2(1, 0, n-1);
        for(i = 0; i < n; i++) cin >> v[i];
        for(r = 1; r < n; r++) {
            for(l = 0; l < r; l++) {
                auto mx1 = query2(1, 0, n-1, l, r);
                auto mn1 = query1(1, 0, n-1, l, r);
                
            }
        }
        cout << ans << "\n";
    }



    return 0;
}

