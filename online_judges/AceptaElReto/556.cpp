#include <bits/stdc++.h>
//#pragma GCC optimization ("O3")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) ((x>>i)&1)

#ifdef GREMIO_DEBUG
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

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//const int MAX = (1<<15)+3;
int v[16];


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, i, ans, mask, sum, tot, num, num2;
    while(true) {
        cin >> m;
        if(m == 0) return 0;
        cin >> n;
        //fill(dp, dp+MAX, INT_MAX/10);
        //dp[0] = 0;
        for(i = 0; i < n; i++) cin >> v[i];
        sort(v, v+n);
        reverse(v, v+n);
        ans = 0;
        for(mask = 1; mask < (1<<n); mask++) {
//            echo(bitset<8>(mask));
          //   Huffman coding.
            sum = 0;
            for(i = 0; i < n; i++) if(is_set(mask, i)) sum += v[i];
            if(sum <= ans) continue; // Can't improve answer.
            
            if(mask == LSB(mask)) {if(sum <= m) ans = max(ans, sum); continue;} // Just one element.

            if(sum > m) continue; // If there is > 1 element you'll need at least sum mana.

            priority_queue<int> pq;
            tot = 0;
            for(i = 0; i < n; i++) if(is_set(mask, i)) pq.push(-v[i]);
            while((int)pq.size() > 1) {
                num = pq.top(); pq.pop();
                num2 = pq.top(); pq.pop();
                tot += num + num2;
                if(-tot > m) break;
                pq.push(num+num2);
            }
            if(-tot <= m) ans = max(ans, sum);
        }
        //echoarr(dp);
        cout << ans << "\n";
    }




    return 0;
}
