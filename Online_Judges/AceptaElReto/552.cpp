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

const ll MAX = 21;
int s[MAX+1][MAX+1];
int ci, cj, ti, tj;

void show() {
    int i, j;
    
    for(i = MAX; i > 0; i--) {
        if(i < 10) cout << " ";
        cout << i<<":";
        for(j = 1; j<= MAX; j++) {
            cout << s[i][j] << " ";
            if(j > 9) cout << " ";
        }
        cout << endl;
    }
    cout << "   ";
    for(i = 1; i <= MAX; i++) {
        cout << i << " ";
        
    }
    cout << endl;
}

void ini() {
    int i;
    for(i = 2; i < 12; i++) {
        s[i][11] = 1;
    }
    ci = cj = 11;
    ti =2;
    tj = 11;
}
bool alive;
#define time asdfasd
int time_alive, time;


bool move(bool crece) {
    if(!alive) return false;
    time_alive++;
    //echo(time);
    //if(time < 13) show();
    if(time % 10 == 1 && time > 1) crece = true;

    if(!crece) {
        //MOVE TAIL
        if(s[ti][tj] == 1) {
            s[ti][tj] = 0;
            ti++;
        } else if(s[ti][tj] == 2) {
            s[ti][tj] = 0;
            tj++;
        } else if(s[ti][tj] == 3) {
            s[ti][tj] = 0;
            ti--;
        }
        else {
        s[ti][tj] = 0;
            tj--;
        }
    }

    //MOVE HEAD
    if(s[ci][cj] == 1) { //up
        if(ci == 21) return false;
        ci++;
        if(s[ci][cj] != 0) return false;
        s[ci][cj] = 1;
    }
    else if(s[ci][cj] == 2) {//right
        if(cj == 21) return false;
        cj++;
        if(s[ci][cj] != 0) return false;
        s[ci][cj] = 2;
    }
    else if(s[ci][cj] == 3) {//down
        if(ci == 1) return false;
        ci--;
        if(s[ci][cj] != 0) return false;
        s[ci][cj] = 3;
    }
    else { //left
        if(cj == 1) return false;
        cj--;
        if(s[ci][cj] != 0) return false;
        s[ci][cj] = 4;
    }


    


    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    char c;
    ll n, i, t;

   /* show();

    while(true) {
        cin >> c;
        if(c == 'U') s[ci][cj] = 1;
        else if(c == 'R') s[ci][cj] = 2;
        else if(c == 'D') s[ci][cj] = 3;
        else s[ci][cj] = 4;
        move();
        show();
    }*/

    while(true) {
        cin >> n;
        if(!n) return 0;
        for(i = 0; i < MAX+1; i++) {
            for(int j = 0; j < MAX+1; j++) {
                s[i][j] = 0;
            }
        }
        ini();

        alive = true;
        time_alive = 0;
        time = 1;
        for(i = 0; i < n; i++) {
            cin >> t >> c;
            while(time <= t) {
                if(move(false) == false) {alive = false; break;}
                time++;
            }

            if(c == 'U') s[ci][cj] = 1;
            else if(c == 'R') s[ci][cj] = 2;
            else if(c == 'D') s[ci][cj] = 3;
            else s[ci][cj] = 4;
            //show();
            //echo(alive, time_alive);
        }

        while(alive) {
            if(move(false) == false) alive = false;
            ++time;
        }

        cout << time_alive-1 << "\n";

    }

    return 0;
}
