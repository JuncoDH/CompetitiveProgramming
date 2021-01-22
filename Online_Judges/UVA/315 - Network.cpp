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


// v is an AP if removing v from graph it split into more than one component.
// 1- v is the root and v has > 1 child in the DFS.
// 2- v is not the root and has one child u that dont have any back edge.
ll n;
vector<vll> graph;
vll low; // Minimum discover time using a back edge.
vll discover; // Discover DFS time.
vll parent;
vector<bool> AP; // True iff i is an Articulation Point.

void ini() {
    graph.assign(n, vll());
    low.assign(n, -1);
    discover.assign(n, -1);
    parent.assign(n, -1);
    AP.assign(n, false);
}

void dfs(int u) { // Call dfs(root).
    static int Time = 0;
    if(discover[u] != -1) return;
    low[u] = discover[u] = Time++;
    int childs = 0;
    for(auto v : graph[u]) {
        if(discover[v] == -1) {
            childs++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            // Every time you set AP[u] = true, the number of components after
            // removing the nodes u or v from the graph increase.
            if(parent[u] == -1 && childs > 1) AP[u] = true;
            if(parent[u] != -1 && low[v] >= discover[u]) AP[u] = true;
        }
        if(v != parent[u]) low[u] = min(low[u], discover[v]); // Back edge.
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    ll u, v;
    while(true) {
        getline(cin, s);
        n = stoll(s);
        if(!n) return 0;
        ini();
        while(true) {
            getline(cin, s);
            stringstream ss;
            ss << s;
            ss >> s;
            u = stoll(s);
            if(!u) break;
            u--;
            while(ss >> s) {
                v = stoll(s);
                v--;
                graph[u].pb(v);
                graph[v].pb(u);
            }
        }
        dfs(0);
        ll ans = 0, i;
        for(i = 0; i < n; i++) if(AP[i]) ans++;
        cout << ans << "\n";
    }



    return 0;
}

