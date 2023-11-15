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


//2D-SegmentTree, query (max, min) p x1 y1 x2 y2; update value c x1 y1 val
//It's a SegmentTree of SegmentTrees, first it fix the y-axis and then the x-axis
//creation O(n * n), update = query = O(log(n) log(n))

vector<vector<pii>> tree;
vector<vi> v;
int n, tree_size;

pii f(pii a, pii b) {
    pii ans;
    ans.fi = max(a.fi, b.fi);
    ans.se = min(a.se, b.se);
    return ans;
}

void Build1D(int k, int l, int r, int y, int vy) {
    if(l == r) {tree[y][k] = mp(v[vy][l], v[vy][l]); return;}
    int mid = (l + r) >> 1;
    Build1D(k<<1, l, mid, y, vy);
    Build1D(k<<1|1, mid + 1, r, y, vy);
    tree[y][k] = f(tree[y][k<<1], tree[y][k<<1|1]);    
}

void Build2D(int k, int l, int r) {
    if(l == r) {Build1D(1, 0, n - 1, k, l); return;}
    int mid = (l + r) >> 1;
    Build2D(k<<1, l, mid);
    Build2D(k<<1|1, mid + 1, r);
    for(int i = 0; i < tree_size; ++i){
        tree[k][i] = f(tree[k<<1][i], tree[k<<1|1][i]);
    }
}

pii Query1D(int k, int l, int r, int x1, int x2, int y) {
    if(r < x1 || x2 < l) return mp(INT_MIN, INT_MAX);
    if(x1 <= l && r <= x2) return tree[y][k];
    int mid = (l + r) >> 1;
    pii a = Query1D(k<<1, l, mid, x1, x2, y);
    pii b = Query1D(k<<1|1, mid + 1, r, x1, x2, y);
    return f(a, b);
}

//before a question, swap(x1, y1) and swap(x2, y2) because first fix the y, but v[x][y]
pii Query2D(int k, int l, int r, int x1, int y1, int x2, int y2) {
    if(r < y1 || y2 < l) return mp(INT_MIN, INT_MAX);
    if(y1 <= l && r <= y2) return Query1D(1, 0, n - 1, x1, x2, k);
    int mid = (l + r) >> 1;
    pii a = Query2D(k<<1, l, mid, x1, y1, x2, y2);
    pii b = Query2D(k<<1|1, mid + 1, r, x1, y1, x2, y2);
    return f(a, b);
}

void Update1D(int k, int l, int r, int pos, int val, int y) {
    if(l == r) {tree[y][k] = mp(val, val); return;}
    int mid = (l + r) >> 1;
    if(pos <= mid) Update1D(k<<1, l, mid, pos, val, y);
    else Update1D(k<<1|1, mid + 1, r, pos, val, y);
    tree[y][k] = f(tree[y][k<<1], tree[y][k<<1|1]);
}

void Update2D(int k, int l, int r, int posx, int posy, int val) {
    if(l == r) {Update1D(1, 0, n - 1, posx, val, k); return;}
    int mid = (l + r) >> 1;
    if(posy <= mid) Update2D(k<<1, l, mid, posx, posy, val);
    else Update2D(k<<1|1, mid + 1, r, posx, posy, val);
    
    for(int i = 0; i < tree_size; ++i){
        tree[k][i] = f(tree[k<<1][i], tree[k<<1|1][i]);
    }
}


int main(){
    ios::sync_with_stdio(false);
    int i, j, x1, y1, y2, x2, val, q;
     char type;
     pii ans;
     
     
     cin >> n;
     v.assign(n, vi(n, 0));
     tree.assign(4 * n, vector<pii>(4 * n, mp(0, 0)));
     tree_size = 4 * n;
    
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    
    Build2D(1, 0, n - 1);
    
    cin >> q;
    
    for(i = 0; i < q; ++i) {
        cin >> type;
        if(type == 'c') {
            cin >> x1 >> y1 >> val;
            --x1; --y1;
            swap(x1, y1);
            Update2D(1, 0, n - 1, x1, y1, val);
        }
        else {
            cin >> x1 >> y1 >> x2 >> y2;
            --x1; --y1; --x2; --y2;
            swap(x1, y1);
            swap(x2, y2);
            ans = Query2D(1, 0, n - 1, x1, y1, x2, y2);
            cout << ans.fi << " " << ans.se << "\n";
        }
    }



    return 0;
}