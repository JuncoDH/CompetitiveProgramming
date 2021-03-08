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

// copied from https://github.com/JuncoDH/CompetitiveProgramming/blob/master/Implementations/RangeQuery/SegmentTree/Lazy_propagation.cpp
template<typename T>
struct node{
    T value = numeric_limits<T>::max(); //MIN query
    T lazy = 0;    //SUM update
    int id = -1;
    node(T _value) {value = _value;}
    node() {} //Dummy node
};

template<typename T>
class lazy_seg{ //SUM update + MIN query
    vector<node<T>> tree;
    vector<T> v_input;
    int _size;

    void build(int k, int l, int r) {
        if(l == r) {tree[k] = node<T>(v_input[l]); tree[k].id = l; return;}
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid+1, r);
        tree[k] = f(tree[k<<1], tree[k<<1|1]);
    }
    
    void push(int k, int l, int r) { //actualize lazy push
        if(l != r) {
            actualize_update(k<<1, tree[k].lazy);
            actualize_update(k<<1|1, tree[k].lazy);
        }
        tree[k].lazy = 0; //Sum update
    }
    void actualize_update(int k, T x) { //actualize when the range is in the update range
        tree[k].value += x; // MIN-MAX query
        tree[k].lazy += x; // SUM update
    }
    node<T> f(node<T> a, node<T> b) { //merge nodes, function
        node<T> n(min(a.value, b.value)); // MIN tree query
        n.id = a.value < b.value ? a.id : b.id; // MIN tree query
        return n;
    }
    //Don't change, implementation below -------------------------------------------------------
    void update(int k, int l, int r, int ql, int qr, T x) {
        push(k, l, r);
        if(r < ql || qr < l) {}
        else if(ql <= l && r <= qr) {
            actualize_update(k, x);
            return;
        } else {
            int mid = (l + r) >> 1;
            update(k<<1, l, mid, ql, qr, x);
            update(k<<1|1, mid+1, r, ql, qr, x);
        }
        if(l != r)
            tree[k] = f(tree[k<<1], tree[k<<1|1]);
    }

    node<T> query(int k, int l, int r, int ql, int qr) {
        push(k, l, r);
        node<T> ans;
        if(r < ql || qr < l) ans = node<T>();
        else if(ql <= l && r <= qr) ans = tree[k];
        else {
            int mid = (l + r) >> 1;
            node<T> a = query(k<<1, l, mid, ql, qr);
            node<T> b = query(k<<1|1, mid+1, r, ql, qr);
            ans = f(a, b);
        }
        if(l != r)
            tree[k] = f(tree[k<<1], tree[k<<1|1]);
        return ans;
    }

    //INTERFACE, Don't change ------------------------------------------------------
    public:
    lazy_seg(int __size, vector<T> v) {
        _size = __size;
        tree.assign(4*__size, {});
        v_input = v;
        build(1, 0, __size-1);
    }
    
    void update(int ql, int qr, T x) {
        update(1, 0, _size-1, ql, qr, x);
    }
    node<T> query(int ql, int qr) {
        return query(1, 0, _size-1, ql, qr);
    }
    void showt() {//debug tree
        for(int i = 1; i < 2*_size; i++) {
            cout << "(" << tree[i].value << "," << tree[i].lazy << ")   ";
            if(i+1 == LSB(i+1)) cout << endl;
        }cout << endl;
    }
    void showv(string s = "") {//debug vector
        cout << s << endl;
        for(int i = 0; i < _size; i++) cout << query(i, i).value << " ";
        cout << endl; 
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, s, i;
    cin >> n >> s;
    vll v(n);
    for(i = 0; i < n; i++) cin >> v[i];
    lazy_seg<ll> st(n, v);
    ll ans = 0;

    for(i = 0; i < n; i++) {
        st.update(i, i, (n-1)*s);
        if(i-1 >= 0)
            st.update(0, i-1, -s);
        if(i+1 <= n-1)
            st.update(i+1, n-1, -s);

        auto p = st.query(0, n-1);
        ans = max(ans, p.value);
    }
    cout << ans << "\n";


    return 0;
}
