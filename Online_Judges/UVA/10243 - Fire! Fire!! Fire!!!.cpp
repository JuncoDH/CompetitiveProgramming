#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))


typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


vector<vi> graph, notTree;
vector<vll> dp;

//minimum vertex cover
ll f(int id, bool caught) {
    ll ans1 = 1, ans2 = 0; //ans1 if you pick vertex id, ans2 if you don't
    
    if(dp[caught][id] != -1) return dp[caught][id];
    
    for(auto el : graph[id]) {
        ans1 += f(el, true);
    }
    if(caught == false) return dp[caught][id] = ans1;
    
    for(auto el : graph[id]) {
        ans2 += f(el, false);
    }
    return dp[caught][id] = min(ans1, ans2);
}

vector<bool> visited;
void dfs(int id, int p) {
    visited[id] = true;
    graph[p].pb(id);
    for(auto el : notTree[id]) {
        if(visited[el] == false) dfs(el, id);
    }
}

int main(){
    ios::sync_with_stdio(false);
    ll n = 8, i, j, num, d, ans;
    vll components;

    while(true) {
        cin >> n;
        if(n == 0) return 0;
        
        graph.assign(n, vi());
        notTree.assign(n, vi());
        visited.assign(n, false);
        dp.assign(2, vll(n, -1));
        components.clear();
        ans = 0;
        
        //take input
        for(i = 0; i < n; ++i) {
            cin >> d;
            for(j = 0; j < d; ++j) {
                cin >> num;
                --num;
                notTree[i].pb(num);
            }
        }

        //construct a tree from a dfs for all components (the graph may be unconnected)
        for(i = 0; i < n; ++i) {
            if(visited[i]) continue;
            visited[i] = true;
            components.pb(i);
            for(auto el : notTree[i]) if(visited[el] == false) dfs(el, i);
        
        }

        
        for(auto el : components) {
            if(graph[el].empty()) ans++; //if the compoent is just a point, like case n: 1, edge: 1-1
            else ans += f(el, true);
        }
        cout << ans << "\n";
    }
    
    return 0;
}

