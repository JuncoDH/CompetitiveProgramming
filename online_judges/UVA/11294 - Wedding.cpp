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


// 2-SAT. Check values (xi or xj) and ... and (xk or xz).
// xi will be element 2*i and not xi will be 2*i+1. Change them with xi xor 1.
vector<vi> graph; // size of graph will be 2*(the number of xi).

int get_element(int n) {return 2*n;} // Get pos of xi.
int get_not_element(int n) {return 2*n + 1;} // Get pos of not xi.
// Add (xi or xj), two edges: (not xj => xi) and (not xi => xj).
// inclusive or: 1 or 1 = 1. For exclusive use 2 clausules. (xi or xj) and (not xi or not xj).
void add_or_clausule(int i, int j) {
    int neg_i = i^1, neg_j = j^1;
    graph[neg_i].pb(j);
    graph[neg_j].pb(i);
}

// Use Kosaraju to find the SCCs.
vector<vi> graphRev;
stack<int> s;
vector<bool> visited; // It will be reutilized in SAT.
vector<vi> components;

void dfs1(ll u){
    visited[u] = true;
    for(auto v : graph[u]){
        if(!visited[v]) dfs1(v);
    }
    s.push(u);
}

void dfs2(ll u){
    visited[u] = true;
    for(auto v : graphRev[u]){
        if(!visited[v]) dfs2(v);
    }
    components.back().pb(u); // One element more to the current component.
}

void Kosaraju(){
    ll i, n = graph.size();
    graphRev.assign(n, vi());
    s = stack<int>();
    //transpose graph to graphRev
    for(i = 0; i < n; ++i){
        for(auto v : graph[i]){
            graphRev[v].pb(i);
        }
    }
    
    visited.assign(n, false);
    for(i = 0; i < n; i++)
        if(!visited[i])
            dfs1(i);
    visited.assign(n, false);
    components.pb(vi());
    while(true) {
        while(!s.empty() && visited[s.top()] == true) s.pop();
        if(s.empty()) break;

        dfs2(s.top());
        components.pb(vi()); // End of the current component.
    }
}
// Do a topoSort of the SCCs.
vector<vi> graph_topo;
vi vSorted;
void topo_rec(int u) {
    if(visited[u]) return;
    visited[u] = true;
    for(auto _v : graph_topo[u]) topo_rec(_v);
    vSorted.pb(u);
}
// Topo sort the n_sz first values of graph.
void topo_sort(int n_sz) {
    vSorted.clear(); 
    visited.assign(n_sz, false);
    for(int i = 0; i < n_sz; i++) topo_rec(i);
    reverse(vSorted.begin(), vSorted.end());
}
// xi_value[i] is 0 if xi is false, 1 if true. 
vi xi_value;
// If you know in advance elements of xi add a clausule (xi or xi).
// Return true if the base is satisfactible, false otherwise.
// All calls are O(n).
vi node2component; // Index of the component of the node.
vi component2order; // Order of the component in the topological sort.
bool SAT() {
    Kosaraju();
    int n_components = components.size(), i, n = graph.size();
    node2component.assign(n, 0);
    graph_topo.assign(n_components, vi());
    component2order.assign(n_components, 0);
    // All components in the same SCC will have the same truth value.
    for(i = 0; i < n_components; i++) {
        for(auto u : components[i]) node2component[u] = i;
    }
    // If xi and not xi are in the same component is UNSAT.
    for(i = 0; i < n; i += 2) {
        if(node2component[i] == node2component[i+1]) return false;
    }
    for(i = 0; i < n; i++) {
        for(auto u : graph[i]) {
            if(node2component[i] != node2component[u])
                graph_topo[node2component[i]].pb(node2component[u]);
        }
    }
    topo_sort(n_components);
    for(i = 0; i < n_components; i++) {
        component2order[vSorted[i]] = i;
    }
    xi_value.assign(n/2, -1);
    for(i = 0; i < n; i += 2) {
        if(component2order[node2component[i]] > component2order[node2component[i+1]]) xi_value[i/2] = true;
        else xi_value[i/2] = false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, k, i, num1, num2, el1, el2;
    char c1, c2;
    string s1, s2;

    // pair iw is number 2*i, ih is 2*i+1.
    while(cin >> n >> k) {
        if(!n && !k) return 0;
        graph.assign(2*2*n, vi());
        add_or_clausule(get_element(0), get_element(0)); // bride is true.
        add_or_clausule(get_not_element(1), get_not_element(1)); // groom is false.
        for(i = 1; i < n; i++) { // The marriages cant be in the same side of the table.
            add_or_clausule(get_element(2*i), get_element(2*i+1));
            add_or_clausule(get_not_element(2*i), get_not_element(2*i+1));
        }
        for(i = 0; i < k; i++) {
            cin >> s1 >> s2;
            c1 = s1.back();
            c2 = s2.back();
            s1.pop_back();
            num1 = stoll(s1);
            num2 = stoll(s2);
            if(c1 == 'w') el1 = 2*num1;
            else el1 = 2*num1+1;
            if(c2 == 'w') el2 = 2*num2;
            else el2 = 2*num2+1;
            // The bride cant see el1 or el2.
            add_or_clausule(get_element(el1), get_element(el2));
        }

        bool ans = SAT();
        if(!ans) {cout << "bad luck\n"; continue;}
        // echo(xi_value);
        for(i = 2; i < 2*n; i++) {
            if(xi_value[i] == 1) {
                if(i/2 > 1) cout << " ";
                cout << i/2;
                if(i%2 == 0) cout << "w";
                else cout << "h";
            }
        }
        cout << "\n";

    }




    return 0;
}

