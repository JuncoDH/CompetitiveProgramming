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

vector<vll> graph;
ll n;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll i;
    
    cin >> n;
    graph.assign(n, vll());
    for(i = 0; i < n-1; i++) {
        cin >> u;
        graph[u].pb(v);
        graph[v].pb(u);
    }


    return 0;
}