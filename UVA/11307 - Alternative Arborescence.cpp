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


ll n;
vector<vi> graph, notTree;
ll N_COLORS = 20;
vector<vll> dp;

//f(id, color) is the minimum chromatic sum for the sub-tree with root id if you pait it with the color color. color is in range [1, N_COLORS]. As there are just 10000 nodes, the strength of the tree is less than 20.
ll f(int id, int color) {
    ll ans = color, c, m;
    
    if(dp[id][color] != -1) return dp[id][color];
    
    for(auto el : graph[id]) {
        m = LLONG_MAX;
        for(c = 1; c <= N_COLORS; ++c) if(c != color) m = min(m, f(el, c));
        ans += m;
    }
    
    return dp[id][color] = ans;
}

//root the tree at node 0 (We create a graph from the tree given in the input), usign BFS
vector<bool> visited;
void bfs() {
    visited.assign(n, false);
    queue<int> q;
    int u;
    visited[0] = true;
    for(auto el : notTree[0]) {visited[el] = true; q.push(el); graph[0].pb(el);}
    while(q.empty() == false) {
        u = q.front();
        q.pop();
        for(auto el : notTree[u]) if(!visited[el]) {
            visited[el] = true;
            q.push(el);
            graph[u].pb(el);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    ll i, ans = LLONG_MAX, p;
    string s, trash;
    stringstream ss;
    
    
    while(true) {
        getline(cin, s);
        n = stoll(s);
        if(n == 0) return 0;
        
        graph.assign(n, vi());
        notTree.assign(n, vi());
        dp.assign(n, vll(N_COLORS + 1, -1));
        ans = LLONG_MAX;
        
        for(i = 0; i < n; ++i) {
            getline(cin, s);
            ss.clear();
            ss << s;
            ss >> trash;
            while(ss >> p) {notTree[i].pb(p); notTree[p].pb(i);}
        }
        
        
        bfs();
        //echo(graph);
        
        for(i = 1; i <= N_COLORS; ++i) ans = min(f(0, i), ans);
        
        
        cout << ans << "\n";
        getline(cin, s); //empty line
    }
    

    return 0;
}


