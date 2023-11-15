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

ll n, m;
vector<vector<char>> v;

bool valid(ll a, ll b) {
    if(a < 0 || b < 0 || a >= n || b >= m) return false;
    return v[a][b] != '#';
}

ll dirx, diry, dx, dy;
void ant() {
    if(dirx == -1 && diry == 0) {dirx = 0; diry = 1;}
    else if(dirx == 0 && diry == 1) {dirx = 1; diry = 0;}
    else if(dirx == 1 && diry == 0) {dirx = 0; diry = -1;}
    else if(dirx == 0 && diry == -1) {dirx = -1; diry = 0;}
}
void nxt() {
    if(dirx == -1 && diry == 0) {dirx = 0; diry = -1;}
    else if(dirx == 0 && diry == 1) {dirx = -1; diry = 0;}
    else if(dirx == 1 && diry == 0) {dirx = 0; diry = 1;}
    else if(dirx == 0 && diry == -1) {dirx = 1; diry = 0;}
}

void move() {
    dx += dirx;
    dy += diry;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll i, j;
    ll total_cost, cost, hj;
    while(cin >> m >> n) {
        v.assign(n, vector<char>(m, '0'));
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        for(j = 0; j < m; j++) {
            if(v[n-1][j] == '.') {hj = j; break;}
        }
        queue<pair<pii, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        q.push(mp(mp(n-1, hj), 0));
        total_cost = inf;
        while(!q.empty()) {
            auto el = q.front(); q.pop();
            dx = el.fi.fi;
            dy = el.fi.se;
            cost = el.se;
            if(visited[dx][dy]) continue;
            visited[dx][dy] = true;
            if(v[dx][dy] == 'T') {
                total_cost = cost;
                break;
            }
            if(valid(dx+1, dy)) q.push(mp(mp(dx+1, dy), cost+1));
            if(valid(dx, dy+1)) q.push(mp(mp(dx, dy+1), cost+1));
            if(valid(dx-1, dy)) q.push(mp(mp(dx-1, dy), cost+1));
            if(valid(dx, dy-1)) q.push(mp(mp(dx, dy-1), cost+1));
        }
        echo(total_cost);
        if(total_cost == inf) {
            cout << "IMPOSIBLE\n";
            continue;
        }
        cost = -1;
        dx = n-1; dy = hj;
        bool ok = false;
        dirx = -1; diry = 0;
        while(true) {
            if(ok && dx == n-1 && dy == hj) break;
            cost++;
            if(v[dx][dy] == 'T') break;
            ok = true;
            ant();
            if(valid(dx+dirx, dy+diry)) {
                move();
                continue;
            }
            nxt();
            if(valid(dx+dirx, dy+diry)) {
                move();
                continue;
            }
            nxt();
            if(valid(dx+dirx, dy+diry)) {
                move();
                continue;
            }
            nxt();
            if(valid(dx+dirx, dy+diry)) {
                move();
                continue;
            }
            nxt();
            if(valid(dx+dirx, dy+diry)) {
                move();
                continue;
            }

        }
        echo(cost, dx, dy);
        if(dx == n-1 && dy == hj) {
            cout << "INF\n";
            continue;
        }
        if(cost == total_cost) cout << "IGUAL\n";
        else cout << cost - total_cost << "\n";
    }



    return 0;
}
