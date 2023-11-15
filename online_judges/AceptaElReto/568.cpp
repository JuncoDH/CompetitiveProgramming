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


int is_leap_year(int y) { //0 is leap-year
    if(y%4 || (y%100==0 && y%400)) return 0;
    return 1;
}
int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_month_accumulate[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

//d 1-index, m 1-index
int date_to_num(int d, int m, int y) {
    m -= 2;
    int sum = d;
    if(m >= 1) sum += is_leap_year(y);
    y--;
    if(m >= 0) sum += days_month_accumulate[m];
    if(y >= 0) {
        sum += 365*y;
        sum += y/4 -y/100 + y/400;
    } 
    return sum;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m1, d1, m2, d2, i;


    while(scanf("%d", &n) != EOF) {
        vector<pii> v;
        for(i = 0; i < n; i++) {
            scanf("%d-%d %d-%d", &d1, &m1, &d2, &m2);
            v.pb(mp(date_to_num(d1, m1, 0), date_to_num(d2, m2, 0)));
        }
        sort(v.begin(), v.end());
        int sum = 0, j;
        vi cur(4, -1);
        for(i = 0; i < n; i++) {
            sort(cur.begin(), cur.end());
            for(j = 0; j < 4; j++) {
                if(cur[j] < v[i].fi) {
                    cur[j] = v[i].se;
                    sum++;
                    j = 6;
                    break;
                }
            }
            if(j < 6) {
                cur[3] = min(cur[3], v[i].se);
            }
            //echo(cur);
        }
        //echo(v);
        if(sum < 0) {return -1;}
        printf("%d\n", sum);

    }



    return 0;
}
