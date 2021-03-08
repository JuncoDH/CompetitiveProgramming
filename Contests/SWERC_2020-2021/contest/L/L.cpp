// Template from https://github.com/JuncoDH/CompetitiveProgramming/blob/master/Implementations/Template/template.cpp
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


vector<vi> pclient, prestaurant;
vi c;
vector<bool> assigned;
vector<map<int, int>> ptoprio; // client to priority [restaurant][people]
ll n, m;

vector<int> last_selection; // of the client
vector<priority_queue<pii>> people_in_restaurant; // (-priority, people)

void f(int p) {
    //echo(p);
    //echo(last_selection[p], pclient[p].size());
    if(last_selection[p] >= (int) pclient[p].size()) {
        assigned[p] = false;
        return;
    }
    int nxt_restaurant = pclient[p][last_selection[p]];
    //echo(nxt_restaurant)
    if((int) people_in_restaurant[nxt_restaurant].size() < c[nxt_restaurant]) { // Esta el restaurante libre.
        people_in_restaurant[nxt_restaurant].push(mp(ptoprio[nxt_restaurant][p], p));
        assigned[p] = true;
        last_selection[p]++;
        return;
    }
    auto p2 = people_in_restaurant[nxt_restaurant].top();
    //echo(p, p2.fi, p2.se, ptoprio[nxt_restaurant][p]);
    if(p2.fi < ptoprio[nxt_restaurant][p]) { // No entra en el restaurante.
        last_selection[p]++;
        f(p);
        return;
    } // Entra y el otro se tiene que ir
    people_in_restaurant[nxt_restaurant].pop();
    people_in_restaurant[nxt_restaurant].push(mp(ptoprio[nxt_restaurant][p], p));
    assigned[p] = true;
    last_selection[p]++;
    //last_selection[p2.se]++;
    f(p2.se);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    stringstream ss;
    ss.clear();
    ll i, num, cont;

    getline(cin, s);
    ss << s;
    ss >> s;
    n = stoll(s);
    ss >> s;
    m = stoll(s);
    

    pclient.assign(n, vi());
    prestaurant.assign(m, vi());
    c.assign(m, 0);
    assigned.assign(n, false);
    last_selection.assign(n, false);
    ptoprio.assign(m, map<int, int>());
    people_in_restaurant.assign(m, priority_queue<pii>());
    for(i = 0; i < m; i++) {
        getline(cin, s);
        c[i] = stoll(s);
    }
    for(i = 0; i < n; i++) {
        ss.clear();
        getline(cin, s);
        ss << s;
        while(ss >> s) {
            num = stoll(s);
            num--;
            pclient[i].pb(num);
        }
    }

    for(i = 0; i < m; i++) {
        ss.clear();
        getline(cin, s);
        ss << s;
        cont = 0;
        while(ss >> s) {
            num = stoll(s);
            num--; // PUEDE SER -1.
            if(num < 0) continue;
            prestaurant[i].pb(num);
            ptoprio[i][num] = cont;
            cont++;
        }
    }
    for(i = 0; i < n; i++) {
        f(i);
        /*for(int k = 0; k < m; k++) {
            if(people_in_restaurant[k].empty() == false) echo(k, people_in_restaurant[k].top());
        }*/
    }

    for(i = 0; i < n; i++) {
        if(assigned[i]) {
            cout << i+1 << "\n";
        }
    }



    return 0;
}
