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


// Maximum matching in a bipartite graph.
// n1 size of set 1, complexity is O(n1*n1*n2).
// Set1 edges are [0, n1). Set2 edges are [0, n2).
class Kuhn{
    int n1, n2;
    vector<vi> graph;
    vector<bool> used;
    bool dfs(int u) {
        for(auto v : graph[u]) {
            if(used[v]) continue;
            used[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
        return false;
    }
    public:
    vi match;
    Kuhn(int _n1, int _n2) {
        n1 = _n1; n2 = _n2;
        graph.assign(n1, vi());
        match.assign(n2, -1);
    }
    void add_edge(int u, int v) { // edge u->v (capacity 1).
        graph[u].pb(v);
    }
    int get_max_match() {
        int i, ans = 0;
        vector<bool> used1(n1, false);
        for(i = 0; i < n1; i++) { // Start with random match.
            for(auto v : graph[i]) { // Improves time.
                if(match[v] == -1) continue;
                match[v] = i;
                used1[i] = true;
                break;
            }
        }
        for(i = 0; i < n1; i++) {
            if(used1[i]) continue;
            used.assign(n2, false);
            dfs(i);
        }
        for(i = 0; i < n2; i++) {
            if(match[i] != -1) { // Edge (match[i], i).
                ans++;
                // echo(match[i], i);
            }
        }
        return ans;
    }
};

ld dist(ld a, ld b, ld c, ld d) {
    ld dx = a-c;
    ld dy = b-d;
    return sqrt(dx*dx + dy*dy);
}
ld dist(pair<ld, ld> a, pair<ld, ld> b) {
    ld dx = a.fi - b.fi;
    ld dy = a.se - b.se;
    return sqrt(dx*dx + dy*dy);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, m, i, j, s, v;

    while(cin >> n >> m >> s >> v) {
        vector<pair<ld, ld>> v1(n), v2(m);
        for(i = 0; i < n; i++) cin >> v1[i].fi >> v1[i].se;
        for(i = 0; i < m; i++) cin >> v2[i].fi >> v2[i].se;
        Kuhn k(n, m);
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(s*v >= dist(v1[i], v2[j])) {
                    k.add_edge(i, j);
                }
            }
        }
        cout << n-k.get_max_match() << "\n";
    }

    return 0;
}

