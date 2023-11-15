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

vector<vll> graph;
vll dp;
ll n;

ll f(ll num) {
    if(graph[num].empty()) return 1;
    ll sum = 0;
    if(dp[num] != -1) return dp[num];
    
    for(auto el : graph[num]) {
        sum += f(el);
    }
    return dp[num] = sum;
}

int main(void) {
    ll i, j, t, num;
    bool first = true;

    while(cin >> n) {
        if(first == false) cout << "\n";
        first = false;
    
        graph.clear();
        graph.resize(n+1);
        for(i = 0; i < n; i++) {
            graph[i].clear();
        }
        dp.clear();
        dp.assign(n+1, -1);
        for(i = 0; i < n; i++) {
            cin >> t;
            for(j = 0; j < t; j++) {
                cin >> num;
                graph[i].pb(num);
            }
        }
        cout << f(0) << "\n";
    }

    
    
    return 0;
}

/*
6
3 1 2 5
3 2 3 4
2 3 4
0
1 5
0
        *//*
6
3 1 2 5
3 2 3 4
2 3 4
0
1 5
0
        
6
3 1 2 5
3 2 3 4
2 3 4
0
1 5
0
        
5
2 1 2
0
2 3 4
1 4
0
        */