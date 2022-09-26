#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

#ifdef JUNCO_DEBUG
#define echoarr(_i, _v) {for(int _x=0;_x<_i;_x++){cout<<v[_x]<<" ";}cout<<endl;}
#define echoarr2(_i, _j, _v) {for(int _x=0;_x<_i;_x++){for(int _y=0;_y<_j;_y++) \
{cout<<_v[_x][_y]<<" ";}cout<<endl;}}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(_i, _v)
#define echoarr2(_i, _j, _v)
#define echo(...)
#define echo2(x)
#endif

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}
void ECHO(long long unsigned _s) {cout<<_s;}
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout.precision(7);cout<<fixed<<_s;}
void ECHO(long double _s){cout.precision(7);cout<<fixed<<_s;}
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
istream& operator >> (istream &is, vector<T> &v) {
    for(T &el : v) is >> el;
    return is;
}
template<typename T> // Output vector<T>.
ostream& operator << (ostream &os, const vector<T> &v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}
using ll = long long;
bool is_set(ll x, ll i) {return (x>>i)&1;}
void set_bit(ll &x, ll i) {x |= 1ll<<i;}
void unset_bit(ll &x, ll i) {x = (x | (1ll<<i)) ^ (1ll<<i);}
ll LSB(ll x) {return x & (-x);}
int LSB_idx(ll x) { // Number of starting zeros.
    for(int i = 0; i < 63; i++) if(is_set(x, i)) return i;
    return -1;
}
ll MSB(ll x) {
    for(int i = 63; i >= 0; i--) if(is_set(x, i)) return 1<<i;
    return 0;
}
using ld = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MAX = 1e6 + 5;
map<ll, ll> m;
map<ll, ll> minv;

ll get_hash(ll num) {
    if(m.count(num)) return m[num];
    ll num2 = rand() ^ num ^(ll)0b10111000101100010101;
    minv[num2] = num;
    return m[num] = num2;
}
ll get_hash_inv(ll num2) {
    if(minv.count(num2) == 0) return -1;
    return minv[num2];
}

template<typename T>
class Node { // Only modify this class.
    public:
    int l = -1, r = -1; // Interval [l, r].
    T value = 0;
    static const T lazy_default = -inf; // Don't change.
    T lazy = lazy_default;
    Node() = default;
    Node(T _value) {value = _value;}
    // Merge nodes.
    Node(Node<T> a, Node<T> b) {value = a.value + b.value;} // MINMAX, SUM query.
    void actualize_update(T x) {
        if(x == -inf) return;
        if(lazy == -inf) lazy = 0;
        lazy = x; // (= SET update), (+= SUM update).
        // value += x; // MINMAX query + (= SET update), (+= SUM update).
        value = (r-l+1)*x; // SUM query + (= SET update), (+= SUM update).
    }
};
template<typename T>
class LazySegmentTree { // Use lazy propagation.
    vector<Node<T>> tree;
    vector<T> v;
    int n;
    // Value is the real value, and lazy is only for its children.
    void push_lazy(int k, int l, int r) {
        if(l != r) {
            tree[k<<1].actualize_update(tree[k].lazy);
            tree[k<<1|1].actualize_update(tree[k].lazy);
            tree[k] = Node<T>(tree[k<<1], tree[k<<1|1]);
            tree[k].l = l; tree[k].r = r;
        }
        tree[k].lazy = tree[k].lazy_default;
    }
    void build(int k, int l, int r) {
        if(l == r) {
            tree[k] = Node<T>(v[l]);
            tree[k].l = l; tree[k].r = r;
            return;
        }
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid+1, r);
        tree[k] = Node<T>(tree[k<<1], tree[k<<1|1]);
        tree[k].l = l; tree[k].r = r;
    }
    void update(int k, int l, int r, int ql, int qr, T x) {
        push_lazy(k, l, r);
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr) {
            tree[k].actualize_update(x);
        } else {
            int mid = (l + r) >> 1;
            update(k<<1, l, mid, ql, qr, x);
            update(k<<1|1, mid+1, r, ql, qr, x);
        }
        push_lazy(k, l, r);
    }
    Node<T> query(int k, int l, int r, int ql, int qr) {
        push_lazy(k, l, r);
        if(ql <= l && r <= qr) return tree[k];
        int mid = (l + r) >> 1;
        if(qr <= mid) return query(k<<1, l, mid, ql, qr);
        if(mid+1 <= ql) return query(k<<1|1, mid+1, r, ql, qr);
        Node<T> a = query(k<<1, l, mid, ql, qr);
        Node<T> b = query(k<<1|1, mid+1, r, ql, qr);
        return Node<T>(a, b);
    }
    public:
    LazySegmentTree() = default;
    LazySegmentTree(vector<T> _v) {
        v = _v;
        n = v.size();
        tree.assign(4*n, {});
        build(1, 0, n-1);
    }
    void update(int ql, int qr, T x) { // [ql, qr].
        if(ql > qr) swap(ql, qr);
        ql = max(ql, 0);
        qr = min(qr, n-1);
        update(1, 0, n-1, ql, qr, x);
    }
    T query(int ql, int qr) { // [ql, qr].
        if(ql > qr) swap(ql, qr);
        ql = max(ql, 0);
        qr = min(qr, n-1);
        Node<T> ans = query(1, 0, n-1, ql, qr);
        return ans.value;
    }
};

set<int> vs[MAX];
void insert_vs(ll el, int i) {
    vs[el].insert(i);
}
void remove_vs(ll el, int i) {
    vs[el].erase(i);
}
bool check(ll el, int l, int r) {
    if(el == -1) return false;
    auto it = vs[el].lower_bound(l);
    if(it == vs[el].end()) return false;
    return (*it) <= r;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, zz, q, l, r, i, n, mid, ans, a, b, t;
    ll tmp;
    srand(time(0));
    string s;
    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        m.clear();
        minv.clear();
        cin >> n;
        vll v(n);
        cin >> v;
        cin >> q;
        auto v2 = v;
        for(i = 0; i < n; i++) {
            insert_vs(v[i], i);
            v2[i] = get_hash(v[i]);
        }
        LazySegmentTree<ll> lst(v2);
        ans = 0;
        for(i = 0; i < q; i++) {
            cin >> t >> l >> r;
            l--;
            if(t == 1) {
                remove_vs(v[l], l);
                v[l] = r;
                insert_vs(v[l], l);
                lst.update(l, l, get_hash(r));
                continue;
            }
            r--;
            if((r-l+1)%2 == 0) continue;
            if(l == r) {
                ans++;
                continue;
            }
            mid = (l+r)/2;
            a = lst.query(l, mid);
            b = lst.query(mid+1, r);
            tmp = a-b;
            if(check(get_hash_inv(tmp), l, mid)) {
                ans++;
                continue;
            }
            a = lst.query(l, mid-1);
            b = lst.query(mid, r);
            tmp = b-a;
            if(check(get_hash_inv(tmp), mid, r)) {
                ans++;
                continue;
            }
        }
        cout << "Case #" << zz << ": " << ans << "\n";
        for(i = 0; i < n; i++) remove_vs(v[i], i);
    }


    return 0;
}


