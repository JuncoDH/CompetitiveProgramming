#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) (((x)>>(i))&1)
#define set_bit(x, i) {(x) |= 1ll<<(i);}
#define unset_bit(x, i) {(x) = ((x) | (1ll<<(i))) ^ (1ll<<(i));}


#ifdef JUNCO_DEBUG
#define echoarr(x) {for(int _i=0,_n=min((size_t)15,sizeof(x)/sizeof(x[0]));_i<_n;_i++)\
 {cout << x[_i] << " ";} cout << endl;}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(x)
#define echo(...) 
#define echo2(x) 
#endif

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout<<_s;}
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

template<typename T> // Input vector<T>.
istream& operator >> (istream& is, vector<T>& v) {
    for(T& el : v) is >> el;
    return is;
}

template<typename T> // Output vector<T>.
ostream& operator << (ostream& os, const vector<T>& v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll LOG_N = 20; //log2(MAX_N) + 4
const ll MAX_N = 1e5 + 3; //1e5, example
vector<vector<ll>> graph2, graph; //graph2 is the bidirectional and graph is the one you ask LCA
//---------------------------------------- LCA in a tree rooted at 0 ------------------------------------------------------------
int parent[LOG_N][MAX_N]; //parent[i][j] is the ancestor 2^i of node j. Is a sparse table
int level[MAX_N]; //depth of the node in the tree

//call dfs0(0, 0);
void dfs0(int u, int p) {
    parent[0][u] = p;
    for(auto v : graph[u]) {
        if(v == p) continue;
        level[v] = level[u] + 1;
        dfs0(v, u);
    }
}

//O(n log n)
void preprocess() {
    int i, j;
    dfs0(0, 0);
    for(i = 1; i < LOG_N; ++i) {
        for(j = 0; j < MAX_N; ++j) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
}

//rise b to the same level as a and continue moving up. O(log n)
int lca(int a, int b) {
    int i;

    if(level[a] > level[b]) swap(a, b);
    int d = level[b] - level[a];
    
    for(i = 0; i < LOG_N; ++i) {
        if((d >> i) & 1) b = parent[i][b];
    }
    if(a == b) return a;
    
    for(i = LOG_N - 1; i >= 0; --i) {
        if(parent[i][a] != parent[i][b])
            a = parent[i][a], b = parent[i][b];
    }
        
    return parent[0][a];
}

//distance between two nodes in a tree
int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u, v)];
}

//call dfs(0, -1) to root a tree at 0. the graph had to be bidirectional
vector<bool> visitedd;
void dfs(int x, int p) {
    if(visitedd[x]) return;
    visitedd[x] = true;
    if(p != -1) graph[p].pb(x);
    for(auto el : graph2[x]) {
        if(el == p) continue;
        dfs(el, x);
    }
}

vll c;

vector<bool> visited_fb;
vll sum;
void dfs_facebook(int u, int p) {
    if(u == 0) sum[0] = c[0];
    else sum[u] = sum[p] + c[u];
    for(auto v : graph[u]) {
        if(v == p) continue;
        dfs_facebook(v, u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll zz, tt, n, i, u, v, ans, tans, j;
    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        cin >> n;
        c.assign(n, 0);
        cin >> c;
        graph2.assign(n, vll());
        graph.assign(n, vll());
        visitedd.assign(n, false);
        for(i = 0; i < n - 1; i++) {
            cin >> u >> v;
            u--; v--;
            graph2[u].pb(v);
            graph2[v].pb(u);
        }
        
        dfs(0, -1);
        preprocess();

        visited_fb.assign(n, false);
        sum.assign(n, 0);
        dfs_facebook(0, -1);

        ans = 0;
        for(i = 1; i < n; i++) {
            for(j = i+1; j < n; j++) {
                u = lca(i, j);
                if(u != 0) continue;
                tans = sum[i] + sum[j] - c[0];
                ans = max(ans, tans); 
            }
        }
        for(i = 0; i < n; i++) ans = max(ans, sum[i]);

        cout << "Case #" << zz << ": " << ans << "\n";
    }



    return 0;
}
