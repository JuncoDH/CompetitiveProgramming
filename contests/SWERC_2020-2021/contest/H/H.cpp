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


// copied from https://github.com/JuncoDH/CompetitiveProgramming/blob/master/Implementations/DataStructure/PersistentSegmentTree.cpp
const int MAX_VERSION = 3*1e5+4; //maximum number of versions
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
}; // Declare outside, else static memory gives seg fault
node<int> *root[MAX_VERSION]; //it stores the i versions after updates
// HERE CHANGE TO INT.

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


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, i, num, cur_ver = 0;
    char c;
    string s;
    stringstream ss;

    getline(cin, s);
    n = stoll(s);
    PersistentSegmentTree<int> st(n+3);
    vi my_version;
    my_version.pb(0);
    for(i = 0; i < n; i++) {
        getline(cin, s);
        ss.clear();
        ss << s;
        while(ss >> s) {
            c = s[0];
            num = stoll(s.substr(1));
            if(c == '+')
                st.update(cur_ver, cur_ver+1, num, 1);
            else if(c == '-')
                st.update(cur_ver, cur_ver+1, num, 0);
            cur_ver++;
        }
        my_version.pb(cur_ver);
    }

    /*echo(st.query(0, 0, 3));
    echo(st.query(1, 0, 3));
    echo(st.query(2, 0, 3));
    echo(st.query(3, 0, 3));
    echo(st.query(4, 0, 3));
    echo(st.query(5, 0, 3));*/

    int x = 0, sum;
    for(i = 0; i < n; i++) {
        getline(cin, s);
        num = stoll(s);
        sum = st.query(my_version[num], x, n);
        //echo(x, sum, num, my_version[num]);
        x = (x+sum)%n;
    }
    cout << x << "\n";

    return 0;
}
