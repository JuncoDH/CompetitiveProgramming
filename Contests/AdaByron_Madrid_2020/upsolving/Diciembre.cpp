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

const ll MAX = 2*1e5+5;
vll graph[MAX];
ll n, m;
ll cont = 0, discovered[MAX], low[MAX], component[MAX]; //number of remaining components if erasing i node 

void add_edge(ll u, ll v) {
    graph[u].pb(v);
    graph[v].pb(u);
}
ll root;
void dfs(ll u, ll p) {
    ll child = 0; //number of childs in the dfs tree
    if(discovered[u] != -1) return;
    discovered[u] = cont;
    low[u] = cont++;
    for(auto el : graph[u]) {
        if(el == p) continue;
        if(discovered[el] == -1)  {
            child++;
            if(u == root && child > 1) {
                component[u]++;
            }
            dfs(el, u);
            if(discovered[u] < low[el]) {
                //echo( u, el); //bridge
                //u--el is a bridge, u is articulation if u is not a leaf, el is articulation if el is not a leaf
                component[u]++; component[el]++;
            }
        }
        low[u] = min(low[u], low[el]);
    }
}
//for(i = 0; i < MAX; i++) component[i] = min(component[i], (ll)graph[i].size()); //add at the end

void show(ll _n) { //debugging purpose
   
    for(int i= 0; i < _n; i++) {
        cout << i << " ";
    }
     cout << "discovered: " << endl;

    for(int i= 0; i < _n; i++) {
        cout << discovered[i] << " ";
    }
    cout << "------- low: " << endl;
    for(int i= 0; i < _n; i++) {
        cout << low[i] << " ";
    }
    cout << "------- component: " << endl;
    for(int i= 0; i < _n; i++) {
        cout << component[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, u, v;

    for(i = 0; i < MAX; i++) {
        discovered[i] = -1;
        component[i] = 1;
    }

    cin >> n >> m;
    for(i = 0; i < m; i++) {
        cin >> u >> v;
        add_edge(u, v);
    }

    for(i = 0; i < MAX; i++) {root = i; dfs(i, -1);}

    for(i = 0; i < MAX; i++) component[i] = min(component[i], (ll)graph[i].size());
    //show(n);

    ll ans = 0;
    for(i = 0; i < MAX; i++) {
        if(component[i] > component[ans]) ans = i;
    }
    cout << ans << "\n";

    return 0;
}



