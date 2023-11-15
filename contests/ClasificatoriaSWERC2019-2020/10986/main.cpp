/*AC*/
#include <bits/stdc++.h>

#define echo(x) cout << #x << ":" << x << endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

vector<vector<pll>> graph;
ll n, m, s, t;

ll diks() {
    vector<bool> visited(n+1, false);
    priority_queue<pll> p;
    pll x;
    p.push(mp(0, s));
    while(p.empty() == false) {
        x = p.top(); p.pop();
        if(visited[x.se] == true) continue;

        visited[x.se] = true;
        if(x.se == t) return -x.fi;
        for(auto el : graph[x.se]) {
            p.push(mp(x.fi - el.se, el.fi));
        }
    }
    
    
    return -1;
}

int main(void) {
    ll i, u, v, w, ans, tt, zz;
    cin >> tt;
    for(zz = 1; zz <= tt; ++zz) {
        cin >> n >> m >> s >> t;
        cout << "Case #" << zz << ": ";
        
        graph.clear();
        graph.resize(n+1);

        for(i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[u].pb(mp(v, w));
            graph[v].pb(mp(u, w));
        }


        ans = diks();
        if(ans == -1) {
            cout << "unreachable\n";
        }
        else {
            cout << ans << "\n";
        }
    }
    

    return 0;
}

/*
3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1
        *//*
5 5 1 5
1 4 5
1 2 100
3 4 2
2 3 1
2 5 2
        */
