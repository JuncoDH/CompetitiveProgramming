#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <sstream>
#include <queue>


#define pb push_back
#define mp make_pair
#define se second
#define fi first

using namespace std;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int inix, iniy, finx, finy;
ll n, m;

vector<vector<ll>> graph;
vector<vector<bool>> visited;

vector<ll> ks;

int main() {
    ll i, j;
    string s;

    cin >> n >> m;
    graph.assign(n, vll(m, 0));
    visited.assign(n, vector<bool>(m, false));

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> s;
            //cout << s << endl;
            if(s == "S") {inix = i; iniy = j;}
            else if(s == "F") {finx = i; finy = j;}
            else graph[i][j] = stoll(s);
        }
    }
    priority_queue<pair<ll, pll>> q;
    q.push({0, {inix, iniy}});
    ll ans = -1;
    while(!q.empty()) {
        auto p = q.top(); q.pop();
        if(0 > p.se.fi || p.se.fi >= n) continue;
        if(0 > p.se.se || p.se.se >= m) continue;

        if(visited[p.se.fi][p.se.se]) continue;
        visited[p.se.fi][p.se.se] = true;
        if(p.se.fi == finx && p.se.se == finy) {ans = -p.fi; break;}
        auto num = p.fi-graph[p.se.fi][p.se.se];
        q.push({num, {p.se.fi+1, p.se.se+1}});
        q.push({num, {p.se.fi+1, p.se.se}});
        q.push({num, {p.se.fi+1, p.se.se-1}});
        q.push({num, {p.se.fi, p.se.se+1}});
        q.push({num, {p.se.fi, p.se.se-1}});
        q.push({num, {p.se.fi-1, p.se.se+1}});
        q.push({num, {p.se.fi-1, p.se.se}});
        q.push({num, {p.se.fi-1, p.se.se-1}});
    }
    cout << ans << "\n";

    ll e;
    cin >> e;
    vll v(e), a(e);
    for(i = 0; i < e; i++) cin >> v[i];
    for(i = 0; i < e; i++) cin >> a[i];

    ks.assign(ans+1, 0);
    for(i = 0; i < e; i++) {
        for(j = )
    }
    ll it = 0;
    while(true) {



        it++;
        if(it >= ans) {
            cout << "NO\n";
            return 0;
        }
    }



    return 0;
}
