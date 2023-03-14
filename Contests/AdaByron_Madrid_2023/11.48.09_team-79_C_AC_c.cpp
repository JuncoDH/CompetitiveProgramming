#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back

const ll mod = 1000000007;
ll elevate(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) %mod;
        b >>= 1;
        a = (a*a)%mod;
    }
    return ans;
}
vector<vll> graph;
bool cycle;
vector<bool> visited;
ll node;

void f(ll u) {
    if(visited[u]) {
        cycle = true;
        return;
    }
    visited[u] = true;
    node++;
    for(auto el : graph[u]) {
        f(el);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, tt, m, u, v, i, ans;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        graph.assign(n, vll());
        visited.assign(n, false);
        for(i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        ans = 1;
        for(i = 0; i < n; i++) {
            if(visited[i]) continue;
            node = 0;
            cycle = false;
            f(i);
            if(node == 1) continue;
            ans *= elevate(2, node-1);
            ans %= mod;
        }
        cout << (ans%mod) << "\n";
    }
    
    return 0;
}