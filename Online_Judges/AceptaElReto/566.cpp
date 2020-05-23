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

//O(V^2*E) max flow algorithm. For bipartite matching O(sqrt(V)*E), always faster than Edmond-Karp.
//Creates layer's graph with a BFS and then it tries all possibles DFS, branching while the path doesn't reach the sink
struct EdgeFlow {
    ll u, v;
    ll cap, flow = 0; //capacity and current flow
    EdgeFlow(ll _u, ll _v, ll _cap) : u(_u), v(_v), cap(_cap) { }
};

struct Dinic {
    vector<EdgeFlow> edge; //keep the edges
    vector<vll> graph; //graph[u] is the list of their edges
    ll n, n_edges = 0;
    ll source, sink, inf_flow = inf;
    vll lvl; //lvl of the node to the source
    vll ptr; //ptr[u] is the next edge you have to take in order to branch the DFS
    queue<ll> q;

    Dinic(ll _n, ll _source, ll _sink) : n(_n), source(_source), sink(_sink) { //n nodes
        graph.assign(_n, vll());
    }

    void add_edge(ll u, ll v, ll flow) { //u->v with cost x
        EdgeFlow uv(u, v, flow), vu(v, u, 0);
        edge.pb(uv);
        edge.pb(vu);
        graph[u].pb(n_edges);
        graph[v].pb(n_edges+1);
        n_edges += 2;
    }

    bool BFS() {
        ll u;
        while(q.empty() == false) {
            u = q.front(); q.pop();
            for(auto el : graph[u]) {
                if(lvl[edge[el].v] != -1) {
                    continue;
                }
                if(edge[el].cap - edge[el].flow <= 0) {
                    continue;
                }
                lvl[edge[el].v] = lvl[edge[el].u] + 1;
                q.push(edge[el].v);                
            }
        }

        return lvl[sink] != -1;
    }

    ll dfs(ll u, ll min_flow) {
        if(u == sink) return min_flow;
        ll pushed, el;
        for(;ptr[u] < (int)graph[u].size(); ptr[u]++) { //if you can pick ok, else you crop that edge for the current bfs layer
            el = graph[u][ptr[u]];
            if(lvl[edge[el].v] != lvl[edge[el].u] + 1 || edge[el].cap - edge[el].flow <= 0) {
                continue;
            }
            pushed = dfs(edge[el].v, min(min_flow, edge[el].cap - edge[el].flow));
            if(pushed > 0) {
                edge[el].flow += pushed;
                edge[el^1].flow -= pushed;
                return pushed;
            }
            
        }
        return 0;
    }

    ll max_flow() {
        ll flow = 0, pushed;
        while(true) {
            lvl.assign(n, -1);
            lvl[source] = 0;
            q.push(source);
            if(!BFS()) {
                break;
            }

            ptr.assign(n, 0);
            while(true) {
                pushed = dfs(source, inf_flow);
                if(!pushed) break;
                flow += pushed;
            }
        }
        return flow;
    }
};

ll n, m, ci, cj, li, lj;
const int MAX = 31;
char arr[MAX][MAX];

ll toN(int i, int j) {
    return j + MAX*i;
}
ll toNV(int i, int j) {
    return j + MAX*i + MAX*MAX;
}
bool valid(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}
bool is_wolf(int i, int j) {
    if(!valid(i, j)) return false;
    return arr[i][j] == 'L';
}

bool is_free(int i, int j) {
    if(!valid(i, j)) return false;
    return arr[i][j] == '.';
}
Dinic d(1, 1, 1);
void add_entrante(int i, int j, int i2, int j2) {
    d.add_edge(toN(i, j), toN(i2, j2), 1);
}
void add_saliente(int i, int j, int i2, int j2) {
    d.add_edge(toNV(i, j), toNV(i2, j2), 1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, j, zz;
    cin >> zz;
    while(zz--) {
        cin >> n >> m;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                cin >> arr[i][j];
                if(arr[i][j] == 'C') {
                    ci = i; cj = j;
                }
                else if(arr[i][j] == 'L') {
                    li = i; lj = j;
                }
            }
        }
        //echo(ci, cj, arr[ci][cj1]);
        if(is_wolf(ci+1, cj)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci, cj+1)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci-1, cj)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci, cj-1)) {cout << "IMPOSIBLE\n"; continue;}

        if(is_wolf(ci+1, cj-1) && is_free(ci+1, cj)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci+1, cj-1) && is_free(ci, cj-1)) {cout << "IMPOSIBLE\n"; continue;}

        if(is_wolf(ci+1, cj+1) && is_free(ci+1, cj)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci+1, cj+1) && is_free(ci, cj+1)) {cout << "IMPOSIBLE\n"; continue;}

        if(is_wolf(ci-1, cj-1) && is_free(ci-1, cj)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci-1, cj-1) && is_free(ci, cj-1)) {cout << "IMPOSIBLE\n"; continue;}

        if(is_wolf(ci-1, cj+1) && is_free(ci-1, cj)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci-1, cj+1) && is_free(ci, cj+1)) {cout << "IMPOSIBLE\n"; continue;}


        if(is_wolf(ci+2, cj) && is_free(ci+1, cj)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci, cj+2) && is_free(ci, cj+1)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci-2, cj) && is_free(ci-1, cj)) {cout << "IMPOSIBLE\n"; continue;}
        if(is_wolf(ci, cj-2) && is_free(ci, cj-1)) {cout << "IMPOSIBLE\n"; continue;}

        d = Dinic(2*MAX*MAX, toN(li, lj), toN(ci, cj));
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(!is_free(i, j) && !is_wolf(i, j)) continue;
                if(is_wolf(i, j))  d.add_edge(toN(i, j), toNV(i, j), 4);
                else d.add_edge(toN(i, j), toNV(i, j), 1);
                
                if(is_free(i+1, j)) d.add_edge(toNV(i, j), toN(i+1, j), 1);
                if(is_free(i, j+1)) d.add_edge(toNV(i, j), toN(i, j+1), 1);
                if(is_free(i-1, j)) d.add_edge(toNV(i, j), toN(i-1, j), 1);
                if(is_free(i, j-1)) d.add_edge(toNV(i, j), toN(i, j-1), 1);
            }
        }
        if(is_free(ci+1, cj-1) && (is_free(ci+1, cj) || is_free(ci, cj-1))) d.add_edge(toNV(ci+1, cj-1), toN(ci, cj), 1);
        if(is_free(ci+1, cj+1) && (is_free(ci+1, cj) || is_free(ci, cj+1))) d.add_edge(toNV(ci+1, cj+1), toN(ci, cj), 1);
        if(is_free(ci-1, cj-1) && (is_free(ci-1, cj) || is_free(ci, cj-1))) d.add_edge(toNV(ci-1, cj-1), toN(ci, cj), 1);
        if(is_free(ci-1, cj+1) && (is_free(ci-1, cj) || is_free(ci, cj+1))) d.add_edge(toNV(ci-1, cj+1), toN(ci, cj), 1);

        if(is_free(ci+2, cj) && is_free(ci+1, cj)) d.add_edge(toNV(ci+2, cj), toN(ci, cj), 1);
        if(is_free(ci, cj+2) && is_free(ci, cj+1)) d.add_edge(toNV(ci, cj+2), toN(ci, cj), 1);
        if(is_free(ci-2, cj) && is_free(ci-1, cj)) d.add_edge(toNV(ci-2, cj), toN(ci, cj), 1);
        if(is_free(ci, cj-2) && is_free(ci, cj-1)) d.add_edge(toNV(ci, cj-2), toN(ci, cj), 1);
   
        cout << d.max_flow() << "\n";
    }



    return 0;
}