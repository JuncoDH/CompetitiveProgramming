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

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){cout<<_s;}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){cout<<_s;}
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


const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;


typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



const ll MAX_PRIMES = 5*1e5+200;
bool num[MAX_PRIMES]; //if num[i] = false => i is prime
int num_div[MAX_PRIMES]; //number of divisors of i
int min_div[MAX_PRIMES]; //the smallest prime that divide i
vector<int> prime;
void linear_sieve(int max_num_primo){
    int i, j, prime_size = 0;
    min_div[1] = 1;
    for(i = 2; i <= max_num_primo; ++i){
        if(num[i] == false) {prime.push_back(i); ++prime_size; num_div[i] = 1; min_div[i] = i;}
        
        for(j = 0; j < prime_size && i * prime[j] <= max_num_primo; ++j){
            num[i * prime[j]] = true;
            num_div[i * prime[j]] = num_div[i] + 1;
            min_div[i * prime[j]] = min(min_div[i], prime[j]);
            if(i % prime[j] == 0) break;
        }
    }
    
}

void factorize(int n) { //example of factoring n
    while(n != 1) {
        cout << min_div[n] << " ";
        n /= min_div[n];
    } cout << endl;
}


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

int id[MAX_PRIMES], v[MAX_PRIMES]; //pos of i in the input, or -1

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, x, tt, zz, n;

    linear_sieve(MAX_PRIMES -1);

    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        for(i = 0; i < MAX_PRIMES; i++) {
            id[i] = -1;
        }

        cin >> n;
        Dinic d(n+2, n, n+1);


        for(i = 0; i < n; i++) {
            cin >> v[i];
            id[v[i]] = i;
        }

        for(i = 0; i < n; i++) {
            x = v[i];
            while(x != 1) {
                if(id[v[i]/min_div[x]] != -1) {
                    if(num_div[v[i]] % 2 == 0) {
                        d.add_edge(i, id[v[i]/min_div[x]], 1);
                    } else{
                        d.add_edge(id[v[i]/min_div[x]], i, 1);
                    }
                }
                
                while(x != 1 && min_div[x] == min_div[x / min_div[x]]) {
                    x /= min_div[x];
                }
                x /= min_div[x];
            }
        }

        for(i = 0; i < n; i++) {
            if(num_div[v[i]] % 2 == 0) {
                d.add_edge(n, i, 1);
            }
            else {
                d.add_edge(i, n+1, 1);
            }
        }



        cout << "Case " << zz << ": " << n - d.max_flow() << "\n";
    }

    return 0;
}

/*
3
5
2 4 8 16 32
5
2 3 4 6 9
3
1 2 3
*/
