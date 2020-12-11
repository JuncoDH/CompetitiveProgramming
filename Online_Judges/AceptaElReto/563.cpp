#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) (((x)>>(i))&1)
#define set_bit(x, i) {(x) |= 1ll<<(i);}

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

int n, m;
const int MAX = 40;
int dist[MAX][MAX];
vector<vector<char>> s;
const int int_inf = 9999;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int k, i, j, x;
    while(true) {
        cin >> n >> m >> k;
        if(!n && !m && !k) return 0;
        s.assign(n, vector<char>(m, '.'));
        for(i = 0; i < n; i++) for(j = 0; j < m; j++) cin >> s[i][j];
        map<char, int> f;
        set<char> visited;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) if(!f.count(s[i][j])) f[s[i][j]] = f.size()+1;
        }
        //echo2(f);
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < MAX; j++) dist[i][j] = int_inf;
            dist[i][i] = 0;
        }
        // LEFT.
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(visited.count(s[i][j])) continue;
                visited.insert(s[i][j]);
                dist[f[s[i][j]]][f[s[i][(j-1+m)%m]]] = 1;
            }
        }

        visited.clear();
        // RIGHT.
        for(i = 0; i < n; i++) {
            for(j = m-1; j >= 0; j--) {
                if(visited.count(s[i][j])) continue;
                visited.insert(s[i][j]);
                dist[f[s[i][j]]][f[s[i][(j+1)%m]]] = 1;
            }
        } 

        visited.clear();
        // DOWN.
        for(j = 0; j < m; j++) {
            for(i = n-1; i >= 0; i--) {
                if(visited.count(s[i][j])) continue;
                visited.insert(s[i][j]);
                dist[f[s[i][j]]][f[s[(i+1)%n][j]]] = 1;
            }
        }

        visited.clear();
        // UP.
        for(j = 0; j < m; j++) {
            for(i = 0; i < n; i++) {
                if(visited.count(s[i][j])) continue;
                visited.insert(s[i][j]);
                dist[f[s[i][j]]][f[s[(i-1+n)%n][j]]] = 1;
            }
        }
        for(i = 0; i < MAX; i++) dist[i][i] = 0;
        for(x = 0; x < MAX; x++) {
            for(i = 0; i < MAX; i++) {
                for(j = 0; j < MAX; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][x]+dist[x][j]);
                }
            }
        }
        string s2;
        int n2, sum = 0;
        for(i = 0; i < k; i++) {
            cin >> s2;
            sum = dist[f[s[0][0]]][f[s2[0]]];
            n2 = s2.length();
            for(j = 1; j < n2; j++) sum += dist[f[s2[j-1]]][f[s2[j]]];
            cout << sum << "\n";
        }

        cout << "---\n";
    }

    return 0;
}
