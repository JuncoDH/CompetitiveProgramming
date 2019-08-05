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

struct node{
    int l, cl;
    int m, cm;
    int r, cr;
};

vi v;
vector<node> tree;

void Set(node &a, node &n1, node &n2) {
    a.l = n1.l;
    a.cl = n1.cl;
    a.r = n2.r;
    a.cr = n2.cr;
    if(n1.cm >= n2.cm && (v[n1.r] != v[n2.l] || n1.cm >= n1.cr + n2.cl)) {
        a.cm = n1.cm;
        a.m = n1.m;
    }
    else if(n2.cm >= n1.cm && (v[n1.r] != v[n2.l] || n2.cm >= n1.cr + n2.cl)) {
        a.cm = n2.cm;
        a.m = n2.m;
    }
    else if(v[n1.r] == v[n2.l]){
        a.cm = n1.cr + n2.cl;
        a.m = n1.r;
    }
    
    if(v[a.l] == v[a.m]) a.cl = a.cm;
    if(v[a.r] == v[a.m]) a.cr = a.cm;
}
void Build(int k, int l, int r) {
    if(l == r) {
        tree[k].cl = tree[k].cm = tree[k].cr = 1;
        tree[k].l = tree[k].m = tree[k].r = l;
        return;
    }
    int mid = (l + r) >> 1;
    Build(k<<1, l, mid);
    Build(k<<1|1, mid + 1, r);
    Set(tree[k], tree[k<<1], tree[k<<1|1]);
}

node Query(int k, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return {-1, -1, -1, -1, -1, -1};
    if(ql <= l && r <= qr) return tree[k];
    if(l == r) return tree[k];
    int mid = (l + r) >> 1;
    node a = Query(k<<1, l, mid, ql, qr);
    node b = Query(k<<1|1, mid + 1, r, ql, qr);
    if(a.l == -1) return b;
    if(b.l == -1) return a;
    node ans;
    Set(ans, a, b);
    return ans;
}


int main(){
    ios::sync_with_stdio(false);

    int n, q, i, l, r;
    node ans;
    while(true) {
        cin >> n;
        if(n == 0) return 0;
        cin >> q;
        v = vi(n);
        tree.resize(4 * n);
        for(i = 0; i < n; ++i) cin >> v[i];
        Build(1, 0, n - 1);
        for(i = 0; i < q; ++i) {
            cin >> l >> r;
            --l; --r;
            ans = Query(1, 0, n - 1, l, r);
            cout << ans.cm << "\n";
        }


    }

    return 0;
}