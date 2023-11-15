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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, n;
    while(cin >> n) {
        if(!n) return 0;
        vll a(n);
        vector<pll> b(n);
        vector<bool> alive(n, true);
        for(i = 0; i < n; i++) {
            cin >> a[i] >> b[i].fi;
            b[i].se = i;
        }
        lazy_seg<ll> t(n, a);
        sort(b.begin(), b.end());
        int sum = 0, gente = n;
        i = n-1;
        while(gente > 0) {
            //t.showv("inicio");
            //cout << sum << " " << gente << "....." << endl;

            while(i >= 0 && b[i].fi > gente) {
                if(alive[b[i].se]) {
                    t.update(b[i].se, b[i].se, LLONG_MAX/10);
                    gente--;
                }
                alive[b[i].se] = false;
                i--;
               // t.showv("fin while");
            }
            if(gente <= 0) break;
            auto no = t.query(0, n-1);
            sum = no.value;
            //echo(no.value, no.id, sum, gente);
            //t.update(0, n-1, -no.value);
            t.update(no.id, no.id, LLONG_MAX/10);
            alive[no.id] = false;
            gente--;

        }
        if(sum >= LLONG_MAX/10) return -1;

        cout << sum << "\n";
        //echo("------------------------")
    }



    return 0;
}

