#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))

#ifdef _LOCAL_
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echo(...) 
#define echo2(x) 
#endif

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){cout<<_s;}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(long double _s){cout<<_s;}
void ECHO(bitset<8> b) {cout << b;}//resize bitset
template<typename T> void ECHO(set<T> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(map<T1, T2> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(pair<T1, T2> _s) {
    cout << "("; ECHO(_s.fi); cout << ","; ECHO(_s.se); cout << ")";
}
template<typename T> void ECHO(vector<T> v) {
    for(auto el : v) {ECHO(el); cout << "_";}
}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i, c = 0;
    for(_i = 0; _i < (int)_s.size(); _i++) {
        if(c==0 && _s[_i]==',') break;
        if(_s[_i] == '(') c++;
        if(_s[_i] == ')') c--;
    }
    cout << " (" << _s.substr(0, _i) << "): "; ECHO(x);
    while(_i < (int)_s.size() && (_s[_i] == ',' || _s[_i] == ' ')) _i++;
    ECHO(_s.substr(_i), args...);
} 

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 4001;
vector<pii> graph[MAX_N];
map<int, int> cost[MAX_N]; 
int k, n, m;
int realv[MAX_N]; //if we can get the value i
int parent[MAX_N]; //the parent in the dfs
int sum[MAX_N]; //sum i with parent[i]
int dist[MAX_N]; //parity of the distance of i and parent[i]
int big_parent; //only 1 parent for 1 dfs

//Fills cycle vector with a path that creates an odd cycle.
// There exist a path from u to cycle[0]
//Take care of self-edges: u --> u
vi cycle;
int color[MAX_N]; 
bool rec(int u, int c) {
    if(color[u] != -1) {
        if(color[u] == c) return false;
        cycle.pb(u);
        return true;
    }
    color[u] = c;
    for(auto el : graph[u]) {
        if(rec(el.fi, c^1)) {
            if(cycle.size() > 1 && cycle.back() == cycle[0]) return true;
            cycle.pb(u);
            return true;
        }
    }
    return false;
}
//The graph has odd cycle iff is not bipartite iff is 2-coloreable
void find_odd_cycle(int u) {
    cycle.clear();
    for(int i = 0; i < MAX_N; i++) color[i] = -1;
    rec(u, 0);
    reverse(cycle.begin(), cycle.end());
}


void add(int i, int j, int w) {
    graph[i].pb(mp(j, w));
    graph[j].pb(mp(i, w));
    cost[i][j] = w;
    cost[j][i] = w;
}


void destroy(int u) {
    while(true) {
        if(graph[u].empty()) break;
        auto el = graph[u].back();
        graph[u].pop_back();
        realv[el.fi] = el.se - realv[u];
        destroy(el.fi);
    }
}

void do_tree(int u, int _dist, int _sum) {
    if(parent[u] != -1) return;
    parent[u] = big_parent;
    dist[u] = _dist;
    sum[u] = _sum;
    for(auto el : graph[u]) {
        if(_dist) do_tree(el.fi, _dist^1, _sum - cost[u][el.fi]);
        else do_tree(el.fi, _dist^1, _sum + cost[u][el.fi]);
    }
}

int ask(int u, int v) {
    if(realv[u] != -1 && realv[v] != -1) return realv[u] + realv[v];
    if(realv[u] != -1 || realv[v] != -1) return -1;
    if(parent[u] != parent[v]) return -1;
    if(dist[u] == dist[v]) return -1;
    if(dist[u] == 1) return sum[u] - sum[v];
    else return -sum[u] + sum[v];
}

int ask(int u) {
    return realv[u];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int i, u, v, w, dx, suma, ans;

    while(cin >> k >> n >> m) {
        if(!k && !n && !m) return 0;

        for(i = 0; i <= k; i++) {
            graph[i].clear();
            realv[i] = -1;
            cost[i].clear();
            parent[i] = -1;
            //sum[i] = -1; //no need
            //dist[i] = -1; //no need
        }

        for(i = 0; i < n; i++) {
            cin >> dx;
            if(dx == 1) {
                cin >> u >> w;
                realv[u] = w;
                destroy(u);
            } else {
                cin >> u >> v >> w;
                if(u == v) {
                    realv[u] = w/2;
                    destroy(u);
                }
                else add(u, v, w);
            }
        }
        
        for(i = 0; i <= k; i++) if(realv[i] != -1) destroy(i);
        
        for(i = 0; i <= k; i++) {
            if(parent[i] != -1 || realv[i] != -1) continue;

            find_odd_cycle(i); //find if in its SCC there are odd cycle
            if(!cycle.empty()) { //delete all SCC
                suma = 0;
                for(int j = 0; j + 1< (int)cycle.size(); j++) {
                    if(j%2) suma -= cost[cycle[j]][cycle[j+1]];
                    else suma += cost[cycle[j]][cycle[j+1]];
                }
                realv[cycle[0]] = suma/2;
                destroy(cycle[0]);
            } else { //dfs
                big_parent = i;
                do_tree(big_parent, 0, 0);
            }
        }
        //queries
        for(i = 0; i < m; i++) {
            cin >> dx;
            if(dx == 1) {
                cin >> u;
                ans = ask(u);
            } else {
                cin >> u >> v;
                ans = ask(u, v);
            }
            if(ans == -1) cout << "CUIDADO\n";
            else cout << ans << "\n";
        }
        cout << "---\n";
    }



    return 0;
}