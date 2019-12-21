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


typedef pair<ll, ll> point;
//distance is a function
#define distance asdsa

vector<pair<ll, point>> distance;
ll dist_sz;
vector<vll> graph;
ll n, k;

ll dist(point a, point b) {
    ll dx = a.fi - b.fi;
    ll dy = a.se - b.se;
    return ceil(sqrt(dx * dx + dy * dy));
}

//construct a graph with graph[i][j] = 1 iff i and j are at distance less or equal than max_sz, previously computed and sorted
void construct(ll max_sz) {
    graph.assign(n + 2, vll(n + 2, 0)); //n is the source and n + 1 is the sink
    ll i;
    for(i = 0; i < dist_sz; ++i) {
        if(distance[i].fi > max_sz) break;
        graph[distance[i].se.fi][distance[i].se.se] = 1;
        graph[n][distance[i].se.fi] = 1;
        graph[distance[i].se.se][n + 1] = 1;
    }
}
vll parent;
bool BFS() {
    ll u, v;
    vector<bool> visited(n + 2, false);
    queue<ll> q;
    q.push(n);
    visited[n] = true;
    while(q.empty() == false) {
        u = q.front();
        q.pop();
        
        for(v = 0; v < n + 2; ++v) {
            if(visited[v] == false && graph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                if(v == n + 1) return true;
                q.push(v);
            }
        }
    }
    return false;
}
ll maxFlow() { //0-1 maxFlow, doesn't need to check for m's values
    ll max_flow = 0, v, m;
    parent.assign(n + 2, -1);
    while(BFS()) {
        m = LLONG_MAX;
        for(v = n + 1; v != n; v = parent[v]) {
            m = min(m, graph[parent[v]][v]);
        }
        max_flow += m;
        for(v = n + 1; v != n; v = parent[v]) {
            graph[parent[v]][v] -= m;
            graph[v][parent[v]] += m;
        }
    }
    
    return max_flow;
}

int main(){
    ios::sync_with_stdio(false);
    ll i, x, y, nCases = 1, Cases;
    string kind;

    cin >> nCases;
    for(Cases = 0; Cases < nCases; ++Cases) {
        cin >> n >> k;
        
        set<pair<point, ll>> red, blue;
        distance.clear();
        
        for(i = 0; i < n; ++i) {
            cin >> x >> y >> kind;
            if(kind == "red") red.insert(mp(mp(x, y), i));
            else blue.insert(mp(mp(x, y), i));
        }
        
        if((ll)red.size() < k || (ll)blue.size() < k) {cout << "Impossible\n"; continue;}
        
        for(auto r : red) {
            for(auto b : blue) {
                distance.pb(mp(dist(r.fi, b.fi), mp(r.se, b.se)));
            }
        }
        
        sort(distance.begin(), distance.end());
        dist_sz = distance.size();
        
        //KEY IDEA: binary search the answer and in every mid, construct a graph and check if you can have k connections, using MAX-FLOW
        ll l = 0, r = 4000, mid;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            construct(mid);
            if(maxFlow() >= k) r = mid;
            else l = mid;
        }
        
        cout << r << "\n";
    }


    return 0;
}


