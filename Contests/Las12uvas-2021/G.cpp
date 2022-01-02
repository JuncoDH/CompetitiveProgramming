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
void ECHO(long long unsigned _s) {cout<<_s;}
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
template<typename T> void ECHO(priority_queue<T> pq) {
    priority_queue<T> _pq = pq;
    while(!_pq.empty()) {ECHO(_pq.top()); cout << "->"; _pq.pop();}
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


ll is_leap_year(int y) {
    if(y%4 != 0) return 0;
    return 1;
}
ll days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll days_month_accumulate[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

// d 1-index, m 1-index.
ll date_to_num(ll d, ll m, ll y) {
    m -= 2;
    ll sum = d;
    if(m >= 1) sum += is_leap_year(y);
    y--;
    if(m >= 0) sum += days_month_accumulate[m];
    if(y >= 0) {
        sum += 365*y;
        sum += y/4;
    } 
    return sum;
}

int nd, nm, ny; // Tiny optimization, binary search the year, month and day.
void num_to_date(int num) {
    nd = 1; nm = 1; ny = 1; // The date searched is >= this date.
    while(date_to_num(nd, nm, ny) <= num) ny++;
    ny--;
    while(date_to_num(nd, nm, ny) <= num) nm++;
    nm--;
    while(date_to_num(nd, nm, ny) <= num) nd++;
    nd--;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll d, m, y, qy, qm, qd, num;
    char c;

    while(true) {
        cin >> d >> c >> m >> c >> y;
        cin >> qy >> qm >> qd;
        if(d == 0 && m == 0 && y == 0 && qy == 0 && qm == 0 && qd == 0) return 0;
        num = date_to_num(d, m, y);
        num_to_date(num+qd+(qm)*28 + qy*12*28);
        d = nd;
        m = nm;
        y = ny;
        if(d < 10) cout << "0";
        cout << d << "/";
        if(m < 10) cout << "0";
        cout << m << "/";
        if(y < 10) cout << "000";
        else if(y < 100) cout << "00";
        else if(y < 1000) cout << "0";
        cout << y;
        cout << "\n";
    }



    return 0;
}
