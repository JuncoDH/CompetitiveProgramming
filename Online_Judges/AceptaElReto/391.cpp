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
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){cout<<_s;}
void ECHO(bitset<8> b) {cout << b;}//resize bitset
template<typename T1, typename T2> void ECHO(pair<T1, T2> _s) {
    cout << "("; ECHO(_s.fi); cout << ","; ECHO(_s.se); cout << ")";
}
template<typename T> void ECHO(set<T> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(map<T1, T2> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
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


map<int, int> graph[2005];
int dijks[6][2005];
int mini[6][6];
vi pueblo, perm;
int np, nc;
const int INF = INT_MAX / 10;

void show(int n) {
    for(int i = 1; i <= np; i++) cout << dijks[n][i] << " ";
    cout << "---------------------" << endl;
}

void dijkstra(int t) {
    int i;
    pii u;
    for(i = 1; i <= np; i++) {
        dijks[t][i] = INF;
    }
    //(-weight, -village)
    priority_queue<pii, vector<pii>, greater<pii>> p;
    p.push(mp(0, pueblo[t]));
    while(p.empty() == false) {
        u = p.top(); p.pop();
        if(dijks[t][u.se] != INF) continue;
        dijks[t][u.se] = u.fi;
        for(auto el : graph[u.se]) {
            if(dijks[t][el.fi] == INF)
                p.push(mp(u.fi + el.se, el.fi));
        }
    }
    //show(t);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int i, j, a, b, c, k, ans, ansi, s;
    //bool flag;

    while(cin >> np >> nc) {
        //graph.clear();
        //graph.resize(np+1);
        for(i = 0; i <= np; i++) graph[i].clear();
        for(i = 0; i < nc; i++) {
            cin >> a >> b >> c;
            if(graph[a].count(b)) graph[a][b] = min(graph[a][b], c);
            else graph[a][b] = c;

            if(graph[b].count(a)) graph[b][a] = min(graph[b][a], c);
            else graph[b][a] = c;
        }

        cin >> c;
        
        while(c--) {
            cin >> k;
            pueblo.resize(k);
            perm.resize(k);
            for(i = 0; i < k; i++) {
                cin >> pueblo[i];
                dijkstra(i);
                perm[i] = i;
            }
            
            for(i = 0; i < k; i++) {
                for(j = 0; j < k; j++) {
                    mini[i][j] = INF;
                }
            }
            do{
                s = 0;
                for(i = 1; i < k; i++) {
                    s += dijks[perm[i]][pueblo[perm[i-1]]];
                }
                mini[perm[0]][perm[k-1]] = min(mini[perm[0]][perm[k-1]], s);
            } while(next_permutation(perm.begin(), perm.end()));

            ansi = 1; ans = INF;

            sort(pueblo.begin(), pueblo.end());
            for(i = 1; i <= np; i++) {
                if(binary_search(pueblo.begin(), pueblo.end(), i)) continue;

                for(j = 0; j < k; j++) {
                    for(a = j; a < k; a++) {
                        if(dijks[j][i] + dijks[a][i] + mini[j][a] < ans) {
                            ans = dijks[j][i] + dijks[a][i] + mini[j][a];
                            ansi = i;
                        }
                    }
                }
            }

            cout << ansi << " " << ans << "\n";
        }
        cout << "---\n";
    }

    return 0;
}
