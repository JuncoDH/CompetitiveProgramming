#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))

#ifdef _LOCAL_
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}
#else
#define echobin(x)
#define echo(...) 
#endif

void ECHO(string _s){cout<<endl;(void)_s;}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i; string _s2="";
    for(_i=0;_i<sz(_s);++_i){if(_s[_i]==',')break;if(_s[_i]!=' ')_s2+=_s[_i];}
    if(_i==sz(_s)){--_i;}cout<<"  ("<<_s2<<"):"<<x;
    ECHO(_s.substr(_i+1, sz(_s)-_i-1), args...);
} 


template<typename T0, typename T1>
inline ostream& operator << (ostream& os, pair<T0, T1>& p){
    return os << "(" << p.first << ", " << p.second <<")";
}

template <typename T>
inline ostream& operator << (ostream& os, vector<T>& v){
    for(int i = 0; i < sz(v); ++i) {if(i > 0) cout << "_"; cout << v[i];} cout << endl;
    return os;
} 

//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;
const int int_inf = INT_MAX / 10;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Point{
    ll x, y;//, w; //weight
    bool operator == (Point a) {
        return x == a.x && y == a.y;
    }
    bool operator != (Point a) {
        return x != a.x || y != a.y;
    }
    bool operator < (Point a) {
        if(x != a.x) return x < a.x;
        return y < a.y;
    }
    ll getquad() {
        if(x > 0 && y >= 0) return 1;
        if(x <= 0 && y > 0) return 2;
        if(x < 0 && y <= 0) return 3;
        if(x >= 0 && y < 0) return 4;

        return 0;
    }
    void show() {
        cout << "(" << x << ", " << y << ")" << endl; 
    }
};

const int LEFT = 1;
const int RIGHT = -1;
int orientation(Point p1, Point p2, Point p3){
    ll ans = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    if(ans == 0) return ans;
    return ans > 0 ? LEFT : RIGHT;
}

ll n;
Point pole, cero;
vector<Point> v;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, ans = 0, cp, cn, ori;
    bool fail;
    cero = {0, 0};

    while(cin >> n) {
        if(n == 0) return 0;
        ans = 0;
        v.resize(n);
        fail = false;
        cin >> pole.x >> pole.y;
        //ajustar todos, mirar que todos sean != de pole
        for(i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y;
            if(v[i] == pole) fail = true;
            v[i].x -= pole.x;
            v[i].y -= pole.y;
        }
        v.pb(v[0]); //vuelve

        for(i = 1; i <= n; i++) {
            //echo(ans);
            cp = v[i-1].getquad();
            cn = v[i].getquad();
            //v[i-1].show(); v[i].show();
            ori = orientation(v[i-1], cero, v[i]);
            if(ori == 0) {
                if((v[i-1].x < 0 && 0 < v[i].x) || (v[i].x < 0 && 0 < v[i-1].x) || \
                (v[i-1].x == 0 && v[i].x == 0 && (((v[i-1].y < 0 && 0 < v[i].y)) || ((v[i-1].y < 0 && 0 < v[i].y)))) ) {
                    fail = true; break;
                }
                else continue;
            }
            //echo(cp, cn, ori == LEFT);
            if(cp == 1) {
                if(cn == 1 || cn == 2 || cn == 4) continue;
                
                if(ori == RIGHT) ++ans;
            }
            else if(cp == 2){
                if(cn == 1 || cn == 2) continue;
                if(cn == 3) {ans++; continue;}

                if(ori == RIGHT) ++ans;
            }
            else if(cp == 3) {
                if(cn == 3 || cn == 4) continue;
                if(cn == 2) {--ans; continue;}

                if(ori == LEFT) --ans;
            }
            else if(cp == 4) {
                if(cn == 1 || cn == 3 || cn == 4) continue;

                if(ori == LEFT) --ans;
            }
        }




        if(fail) cout << "Ouch!\n";
        else {
            if(ans > 0) cout << "+";
            cout << ans << "\n";
        }
    }


    return 0;
}



