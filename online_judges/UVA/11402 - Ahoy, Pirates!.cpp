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

//This SegmentTree store the number of 1's in the binary string v. have 4 operations :
//in [al, qr] F: put 1's, E: put 0's, I: invert, S query how many 1's there are
vi tree, lazy;
string v;

void Build(int k, int l, int r) {
    if(l == r) {tree[k] = v[l] == '1'; return;}
    int mid = (l + r) >> 1;
    Build(k<<1, l, mid);
    Build(k<<1|1, mid + 1, r);
    tree[k] = tree[k<<1] + tree[k<<1|1];
}

int Query(int k, int l, int r, int ql, int qr) {
    if(lazy[k] == 1) {
        tree[k] = r - l + 1;
        if(l != r) lazy[k<<1] = lazy[k<<1|1] = 1;
    }
    else if(lazy[k] == 0) {
        tree[k] = 0;
        if(l != r) lazy[k<<1] = lazy[k<<1|1] = 0;
    }
    else if(lazy[k] == -1) {
        tree[k] = r - l + 1 - tree[k];
        if(l != r) {
            if(lazy[k<<1] == -2) lazy[k<<1] = -1;
            else if(lazy[k<<1] == -1) lazy[k<<1] = -2;
            else if(lazy[k<<1] == 0) lazy[k<<1] = 1;
            else lazy[k<<1] = 0;
            
            if(lazy[k<<1|1] == -2) lazy[k<<1|1] = -1;
            else if(lazy[k<<1|1] == -1) lazy[k<<1|1] = -2;
            else if(lazy[k<<1|1] == 0) lazy[k<<1|1] = 1;
            else lazy[k<<1|1] = 0;
        }
    }
    lazy[k] = -2;
    
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return tree[k];
    int mid = (l + r) >> 1;
    int a = Query(k<<1, l, mid, ql, qr);
    int b = Query(k<<1|1, mid + 1, r, ql, qr);
    
    return a + b;    
}

int Update(int k, int l, int r, int ql, int qr, char type) {
    if(lazy[k] == 1) {
        tree[k] = r - l + 1;
        if(l != r) lazy[k<<1] = lazy[k<<1|1] = 1;
    }
    else if(lazy[k] == 0) {
        tree[k] = 0;
        if(l != r) lazy[k<<1] = lazy[k<<1|1] = 0;
    }
    else if(lazy[k] == -1) {
        tree[k] = r - l + 1 - tree[k];
        if(l != r) {
            if(lazy[k<<1] == -2) lazy[k<<1] = -1;
            else if(lazy[k<<1] == -1) lazy[k<<1] = -2;
            else if(lazy[k<<1] == 0) lazy[k<<1] = 1;
            else lazy[k<<1] = 0;
            
            if(lazy[k<<1|1] == -2) lazy[k<<1|1] = -1;
            else if(lazy[k<<1|1] == -1) lazy[k<<1|1] = -2;
            else if(lazy[k<<1|1] == 0) lazy[k<<1|1] = 1;
            else lazy[k<<1|1] = 0;
        }
    }
    lazy[k] = -2;
    
    if(r < ql || qr < l) return tree[k];
    if(ql <= l && r <= qr) {
        if(type == 'F') {
            lazy[k] = 1;
            return r - l + 1;
        }
        else if(type == 'E') return lazy[k] = 0;
        else lazy[k] = -1;
        return r - l + 1 - tree[k];
    }
    
    int mid = (l + r) >> 1;
    int a = Update(k<<1, l, mid, ql, qr, type);
    int b = Update(k<<1|1, mid + 1, r, ql, qr, type);
    
    return tree[k] = a + b;
}

int main(){
    ios::sync_with_stdio(false);
    int n, m, t, j, i, q, nq, ql, qr, cases, z;
    char type;
    string s;
    
    cin >> cases;
    for(z = 1; z <= cases; ++z) {
        cout << "Case " << z << ":\n";
        cin >> m;
        v = "";
        for(i = 0; i < m; ++i) {
            cin >> t;
            cin >> s;
            for(j = 0; j < t; ++j) v += s;
        }
        
        nq = 1;
        n = v.length();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -2);
        
        Build(1, 0, n - 1);
        
        cin >> q;

        for(i = 0; i < q; ++i) {
            cin >> type >> ql >> qr;
            if(type == 'S') cout << "Q" << nq++ << ": " << Query(1, 0, n - 1, ql, qr) << "\n";
            else Update(1, 0, n - 1, ql, qr, type);
        }

    }

    return 0;
}