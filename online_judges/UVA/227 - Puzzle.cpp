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

string arr[5];
ll x, y;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, j;
    bool flag;
    ll tt = 1;

    while(true) {
        for(i = 0; i < 5; i++) {
            getline(cin, arr[i]);
            if(arr[i] == "Z") return 0;
          //  if(arr[i].length() < 5) {echo(i); while(true);} ////catch fail  reading arr[i]
            for(j = 0; j < 5; j++) {
                if(arr[i][j] == ' ') {x = i; y = j;}
            }
        }

        flag = true;
        bool ex = true;
        string s;
        while(ex) {
            getline(cin, s);
            //echo(s);
            //cin >> c;
            for(auto c : s) {
                //echo(c, x, y);
                if(c == '0') {ex = false; break;}
                if(flag == false) continue;
                if(c == 'A') {
                    if(x == 0) {flag = false; continue;}
                    swap(arr[x][y], arr[x-1][y]);
                    x--;
                }
                else if(c == 'R') {
                    if(y == 4) {flag = false; continue;}
                    swap(arr[x][y], arr[x][y+1]);
                    y++;
                }
                else if(c == 'L') {
                    if(y == 0) {flag = false; continue;}
                    swap(arr[x][y], arr[x][y-1]);
                    y--;
                }
                else if(c == 'B') {
                    if(x == 4) {flag = false; continue;}
                    swap(arr[x][y], arr[x+1][y]);
                    x++;
                }
            }
        }

        if(tt > 1) cout << "\n";
        cout << "Puzzle #" << tt++ << ":\n";
        if(flag == false) {
            cout << "This puzzle has no final configuration.\n";
            continue;
        }
        for(i = 0; i < 5; i++) {
            for(j = 0; j < 5; j++) {
                if(j > 0) cout << " ";
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }



    return 0;
}



