#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

#ifdef JUNCO_DEBUG
#define echoarr(_i, _v) {for(int _x=0;_x<_i;_x++){cout<<v[_x]<<" ";}cout<<endl;}
#define echoarr2(_i, _j, _v) {for(int _x=0;_x<_i;_x++){for(int _y=0;_y<_j;_y++) \
{cout<<_v[_x][_y]<<" ";}cout<<endl;}}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(_i, _v)
#define echoarr2(_i, _j, _v)
#define echo(...)
#define echo2(x)
#endif

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}
void ECHO(long long unsigned _s) {cout<<_s;}
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout.precision(7);cout<<fixed<<_s;}
void ECHO(long double _s){cout.precision(7);cout<<fixed<<_s;}
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
template<typename T> void ECHO(priority_queue<T> pq) {
    priority_queue<T> _pq = pq;
    while(!_pq.empty()) {ECHO(_pq.top()); cout << "->"; _pq.pop();}
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
istream& operator >> (istream &is, vector<T> &v) {
    for(T &el : v) is >> el;
    return is;
}
template<typename T> // Output vector<T>.
ostream& operator << (ostream &os, const vector<T> &v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}
using ll = long long;
bool is_set(ll x, ll i) {return (x>>i)&1;}
void set_bit(ll &x, ll i) {x |= 1ll<<i;}
void unset_bit(ll &x, ll i) {x = (x | (1ll<<i)) ^ (1ll<<i);}
ll LSB(ll x) {return x & (-x);}
int LSB_idx(ll x) { // Number of starting zeros.
    for(int i = 0; i < 63; i++) if(is_set(x, i)) return i;
    return -1;
}
ll MSB(ll x) {
    for(int i = 63; i >= 0; i--) if(is_set(x, i)) return 1<<i;
    return 0;
}
using ld = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// v is an AP if removing v from graph it split into more than one component.
// 1- v is the root and v has > 1 child in the DFS.
// 2- v is not the root and has one child u that dont have any back edge.
vector<vi> graph;
class ArticulationPoint{
    int n;
    vi low; // Minimum discover time using a back edge.
    vi discover; // Discover DFS time.
    vi parent;
    int Time = 0;
    void dfs(int u) { // Call dfs(root).
        if(discover[u] != -1) return;
        low[u] = discover[u] = Time++;
        int children = 0;
        for(auto v : graph[u]) {
            if(discover[v] == -1) {
                children++;
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                // Every time you set AP[u] = true, the number of components after
                // removing the nodes u or v from the graph increase.
                if(parent[u] == -1 && children > 1) AP[u] = true;
                if(parent[u] != -1 && low[v] >= discover[u]) AP[u] = true;
                //if(low[v] > discover[u]) {} // edge u->v is a bridge.
            }
            if(v != parent[u]) low[u] = min(low[u], discover[v]); // Back edge.
        }
    }
    public:
    vector<bool> AP; // True iff i is an Articulation Point.
    ArticulationPoint() {
        n = graph.size();
        low.assign(n, -1);
        discover.assign(n, -1);
        parent.assign(n, -1);
        AP.assign(n, false);
    }
    void get_AP() {
        for(int i = 0; i < n; i++) {
            if(discover[i] == -1) dfs(i);
        }
    }
};


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll i, n, r, zz = 1, ans;
    string s, s2;
    while(cin >> n) {
        if(!n) return 0;
        map<string, ll> m;
        vector<string> vs(n);
        for(i = 0; i < n; i++) {
            cin >> vs[i];
            m[vs[i]] = i;
        }
        cin >> r;
        graph.assign(n, vi());
        for(i = 0; i < r; i++) {
            cin >> s >> s2;
            graph[m[s]].pb(m[s2]);
            graph[m[s2]].pb(m[s]);
        }
        ArticulationPoint ap;
        ap.get_AP();
        ans = 0;
        for(i = 0; i < n; i++) if(ap.AP[i]) ans++;
        if(zz > 1) cout << "\n";
        cout << "City map #" << zz << ": " << ans << " camera(s) found\n";
        vector<string> vans;
        for(i = 0; i < n; i++) if(ap.AP[i]) vans.pb(vs[i]);
        sort(vans.begin(), vans.end());
        for(i = 0; i < (int)vans.size(); i++) cout << vans[i] << "\n";
        zz++;
    }


    return 0;
}


 
