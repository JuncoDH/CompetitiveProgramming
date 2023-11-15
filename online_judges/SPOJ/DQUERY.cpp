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

const int MAX_VERSION = 3*1e4+4; //maximum number of versions
template<typename T>
struct node {
    node *pl = NULL, *pr = NULL;
    int l, r, mid;
    T value = 0; //Sum segTree
    node(int _l, int _r) {l = _l; r = _r; mid = (l+r)>>1;}
    node(int _l, int _r, T _value) {l = _l; r = _r; value = _value; mid = (l+r)>>1;}
    void update() { //Sum segTree
        value = 0;
        if(pl) value += pl->value;
        if(pr) value += pr->value;
    }
};
node<ll> *root[MAX_VERSION]; //it stores the i versions after updates

template<typename T>
class PersistentSegmentTree {
    vector<T> arr; //copy of the array to build SegmentTree

    void build(node<T> *n) { //O(n)
        if(n->l == n->r) {n->value = arr[n->l]; return;}
        n->pl = new node<T>(n->l, n->mid);
        n->pr = new node<T>(n->mid+1, n->r);
        build(n->pl);
        build(n->pr);
        n->update();
    }
    node<T>* update(node<T> *n, int q, ll x) { //O(logn)
        if(n->l == n->r) {
            return new node<T>(n->l, n->r, x);
        }
        node<T> *nod = new node<T>(n->l, n->r);
        if(q <= n->mid) {
            nod->pl = update(n->pl, q, x);
            nod->pr = n->pr;
        } else {
            nod->pl = n->pl;
            nod->pr = update(n->pr, q, x);
        }
        nod->update();
        return nod;
    }
    T query(node<T> *n, int l, int r) { //O(logn)
        if(l <= n->l && n->r <= r) return n->value;
        if(r < n->l || n->r < l) return 0; //Sum segTree
        return query(n->pl, l, r) + query(n->pr, l, r);
    }
    public:
    PersistentSegmentTree() = default;
    PersistentSegmentTree(int n){ //Build from empty vector of size n
        arr.assign(n, 0);
        root[0] = new node<T>(0, n-1);
        build(root[0]);
    }
    PersistentSegmentTree(vector<T> &v) { //Build from vector v
        arr = v;
        root[0] = new node<T>(0, (int)arr.size() - 1);
        build(root[0]);
    }
    T query(int version, int l, int r) {return query(root[version], l, r);} //O(logn)
    void update(int version, int new_version, int idx, T x) { //update the segTree version into new_version root
        root[new_version] = update(root[version], idx, x); //O(logn)
    }
};

template<typename T>
class NumberDistinctNumbers { //Works for queries online. For offline can check MO's
    PersistentSegmentTree<T> pst;
    static const int MAX_ELEMENT_VALUE = 1e6+4; // for querying last[el]

    public:
    NumberDistinctNumbers(vector<T> &v) { //O(nlogn)
        T last[MAX_ELEMENT_VALUE]; //last ocurrence of the i-number in the array, updating from left to right
        int n = v.size();
        fill(last, last+MAX_ELEMENT_VALUE, -1);
        pst = PersistentSegmentTree<T>(n);
        for(int r = 0; r < n; r++) {
            pst.update(max(0, r-1), r, r, 1); //Actualize r
            if(last[v[r]] != -1) pst.update(r, r, last[v[r]], 0); //Remove last[v[r]]
            last[v[r]] = r; //Actualize last[v[r]]
        }
    }
    T query(int l, int r) { //Return the number of Distinct numbers in [l..r], O(logn)
        return pst.query(r, l, r);
    }
};


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll i, n, u, w, q;
    cin >> n;
    vll v(n);
    for(i = 0; i < n; i++) cin >> v[i];
    NumberDistinctNumbers<ll> ndn(v);
    cin >> q;

    for(i = 0; i < q; i++) {
        cin >> u >> w;
        u--; w--;
        cout << ndn.query(u, w) << "\n";
       //cout << endl;
    }



    return 0;
}
