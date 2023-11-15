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

const int INF = INT_MAX/5;
int n, m;
const int MAX_L = 105;
const int MAX_N = 1005;
int l[MAX_L][MAX_L]; //son un grafo que conecta las estaciones i con la j. INF si no hay conexion y sino el tiempo minimo de espera
vector<pii> v[MAX_N]; //v[i][j] te dice (a, b) que la estacion i esta en la lina a y que tarda b minutos
bool finish[MAX_N], start[MAX_N]; //start te dice si la estacion 1 esta en la linea i, y finish si la estacion n esta en la linea i

//haces Dijkstra en el grafo l
int dijk() {
    int i;
    priority_queue<pii> p;
    vi visited(m, INF);
    vector<bool> visitedb(m, false);
    pii u;
    for(i = 0; i < m; i++) {
        if(start[i]) {
            p.push(mp(0, i));
            //visited[i] = 0;
        }
    }
    while(p.empty() == false) {
        u = p.top(); p.pop();
        if(finish[u.se]) return -u.fi;
        if(visitedb[u.se]) continue;
        visited[u.se] = 0;
        visitedb[u.se] = true;
        for(i = 0; i < m; i++) {
            if(l[u.se][i] == INF || visited[i] < -(u.fi -l[u.se][i])) continue;
            visited[i] = -(u.fi -l[u.se][i]);
            p.push(mp(u.fi -l[u.se][i], i));
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s, s2;
    int sum, dx, last, i, n2, j, k, ans;

    while(getline(cin, s)) {
        stringstream fl; //read first line
        fl << s;
        fl >> n >> m;

        for(i = 0; i < MAX_N; i++) {
            start[i] = finish[i] = false;
            v[i].clear();
        }

        for(i = 0; i < MAX_L; i++) {
            for(j = 0; j < MAX_L; j++) {
                l[i][j] = INF;
            }
        }

        for(i = 0; i < m; i++) {
            getline(cin, s);
            stringstream ss; //no sabes cuantas estaciones hay en la linea i
            ss << s;
            sum = 0;
            ss >> s2;
            last = stoi(s2);
            v[last].pb(mp(i, 0));
            if(last == 1) start[i] = true;
            if(last == n) finish[i] = true;
            while(ss >> s2) {
                dx = stoi(s2);
                sum += dx;
                ss >> s2;
                last = stoi(s2);
                v[last].pb(mp(i, sum));
                if(last == 1) start[i] = true;
                if(last == n) finish[i] = true;
            }
        }
        //echo(v);
        for(i = 1; i <= n; i++) {
            n2 = (int)v[i].size();
            for(j = 0; j < n2; j++) {
                for(k = j+1; k < n2; k++) {
                    //relajas las aristas (una y su reciproca)
                    l[v[i][j].fi][v[i][k].fi] = min(l[v[i][j].fi][v[i][k].fi], (60+v[i][k].se - v[i][j].se)%60);
                    l[v[i][k].fi][v[i][j].fi] = min(l[v[i][k].fi][v[i][j].fi], (60+v[i][j].se - v[i][k].se)%60);
                }
            }
        }
        /*
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                if(l[i][j] == inf) cout << "inf ";
                else cout << l[i][j] << " ";
            }cout << endl;
        }*/
        //echo(start, finish);

        ans = dijk();
        if(ans != -1) cout << ans << "\n";
        else cout << "Hoy no vuelvo\n";
    }

    return 0;
}



