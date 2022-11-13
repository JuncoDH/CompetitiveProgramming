// Virtual contest with time(NULL)
// https://uhunt.onlinejudge.org/vcontest/4ef2ee1843d616061b9cdd2a96239196
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

using ll = long long;
using ld = long double;
using vi = vector<int>;

ld dist(ld a, ld b, ld c, ld d) {
    ld dx = a-c;
    ld dy = b-d;
    return sqrt(dx*dx + dy*dy);
}

class DSU {
    int n;
    vi parent;
    vi rank;
    int find_parent(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    public:
    DSU(int _n) {
        n = _n;
        parent.assign(n, 0);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    bool is_connected(int a, int b) {
        return find_parent(a) == find_parent(b);
    }
    void merge(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        if (a == b) return;
        if (rank[a] > rank[b]) parent[b] = a;
        else if (rank[a] < rank[b]) parent[a] = b;
        else { parent[a] = b; rank[b]++; }
    }
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll tt, n;

    ld x,y;
    ll i, j;
    cin >> tt;

    bool first = false;
    while (tt--)
    {
        cin >> n;
        if (first) cout << "\n";
        first = true;
        vector<pair<ld, ld>> v(n);
        vector<pair<ld, pair<ld, ld>>> edges;
        for (i = 0; i < n; i++)
        {
            cin >> v[i].fi >> v[i].se;
            for (j = 0; j < i; j++) {
                edges.pb(mp(dist(v[i].fi, v[i].se, v[j].fi, v[j].se), mp(i, j)));
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        ld ans =  0;
        for (auto e : edges) {  
            if (dsu.is_connected(e.se.fi, e.se.se)) continue;
            dsu.merge(e.se.fi, e.se.se);
            ans += e.fi;
        }
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
    
    
    return 0;
}
