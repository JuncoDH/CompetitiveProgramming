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

const ll MAX = 200'010;
vector<vll>  in;//(n, vll(3, 0));
/*ll f(ll i, ll j) {
    if(i == 0) return 0;
    if(j == 1) {
        return min(f(i, 0), f(i, 2));
    }
    //if(j == 0) 
    return abs(in[i-1][j] - in[i][j]) + f(i-1, j);

}*/

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, j, n;
    string s;

    getline(cin, s);
    n = stoll(s);

    in.assign(n, vll(4, 0));

    for(j = 0; j < 4; j++) {
        getline(cin, s);
//echo(s);
        for(i = 0; i < n; i++) {
            if(s[i] == ' ') continue;
            in[i][j] = s[i]-'A';
            //if(j == 3) echo(i, s[i], (int)(s[i]-'A'));
        }
    }
    //echo2(in);
    ll ans1, ans2;
    ans2 = ans1 = 0; j = 0;
    for(i = 0; i < n-1; i++) {
        if(i%2 == 1) {
            ans1 += abs(in[i][3] - in[i][2]) + abs(in[i][2] - in[i][1]) + abs(in[i][1] - in[i][0]);
            ans2 += abs(in[i][3] - in[i][2]) + abs(in[i][2] - in[i][1]) + abs(in[i][1] - in[i][0]);
            //echo(abs(in[i][3] - in[i][2]) + abs(in[i][2] - in[i][1]) + abs(in[i][1] - in[i][0]));
        }
        if(i%4 == 0) {
            ans1 += abs(in[i][0] - in[i+1][0]);
            ans2 += abs(in[i][3] - in[i+1][3]);
        } else if(i%4 == 1) {
            ans2 += abs(in[i][0] - in[i+1][0]);
            ans1 += abs(in[i][3] - in[i+1][3]);
        }
        else if(i%4 == 2) {
            ans2 += abs(in[i][0] - in[i+1][0]);
            ans1 += abs(in[i][3] - in[i+1][3]);
        }
        else {
            ans1 += abs(in[i][0] - in[i+1][0]);
            ans2 += abs(in[i][3] - in[i+1][3]);
        }
    }
    //echo(ans1, ans2);
    cout << min(ans1, ans2) << "\n";


    return 0;
}


