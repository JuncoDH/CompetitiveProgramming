#include <bits/stdc++.h>

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


template<typename T>
class WaveletTree {
    public:
    // Map left function is psum[i], map right is i-psum[i] 
    WaveletTree *pl, *pr;
    vector<T> psum;
    T mn, mx, md;
    WaveletTree(T* v, int n) {// the array is considered as {empty, v}, so query 1-index, v[i] => q(i+1)
        mn = *min_element(v, v + n);
        mx = *max_element(v, v + n);
        md = (mx + mn) >> 1;
        psum.pb(0);
        for(int i = 0; i < n; i++) {psum.pb(psum.back() + (v[i] <= md));}
        T mid_cpy = md;
        auto mid = stable_partition(v, v+n, [mid_cpy](T a) {return a <= mid_cpy;});
        pl = new WaveletTree(v, mid, mn, md);
        pr = new WaveletTree(mid, v+n, md+1, mx);
    }
    WaveletTree(T *vb, T *ve, T _mn, T _mx) {
        mn = _mn;
        mx = _mx;
        if(_mn == _mx || vb == ve) return;
        md = (mx + mn) >> 1;
        psum.pb(0);
        for(int i = 0; vb + i != ve; i++) {psum.pb(psum.back() + (vb[i] <= md));}
        T mid_cpy = md;
        auto mid = stable_partition(vb, ve, [mid_cpy](T a) {return a <= mid_cpy;});
        pl = new WaveletTree(vb, mid, mn, md);
        pr = new WaveletTree(mid, ve, md+1, mx);
    }
    // Number of times q is in the prefix 0..i
    int rank(T q, int i) {
        if(mn == mx) return mn == q ? i : 0;
        if(q <= md) return pl->rank(q, psum[i]);
        return pr->rank(q, i-psum[i]);
    }
    // Return the k element in the subarray vi..vj
    T quantile(int i, int j, int k) {
        if(mn == mx) return mn;
        //echo(i, j, k, psum[i-1], psum[j]);
        int c = psum[j];
        if(i > 0) c -= psum[i-1];
        if(k <= c) return pl->quantile(psum[i], psum[j], k);
        return pr->quantile(i-psum[i], j-psum[j], k-c);
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll n, q, i, u, w2, w, num;
    const int MAX = 1e5+5;
    ll a[MAX];
    cin >> n >> q;
    vll v(n);
    for(i = 0; i < n; i++) {cin >> v[i]; a[i] = v[i];}
    sort(v.begin(), v.end());

    vector<vll> pos(MAX, vll());
    for(i = 0; i < n; i++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        pos[a[i]].pb(i);
    }
    
    //for(i = 0; i < n; i++) echo(a[i]);
    WaveletTree<ll> wt = WaveletTree<ll>(a, n);
    //echo(wt.quantile(1, 5, 2));

    for(i = 0; i < q; i++) {
        cin >> u >> w2 >> w;
        num = wt.quantile(1, w2+1, u);
        //echo(num);
        if((int)pos[num].size() < w) cout << "-1\n";
        else cout << pos[num][w-1] << "\n";
    }

    return 0;
}
