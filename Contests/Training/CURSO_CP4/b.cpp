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

//paper: https://erikdemaine.org/papers/Retroactive_TALG/paper.pdf
//video: https://www.youtube.com/watch?v=WqCWghETNDc&list=WL&index=11&t=0s
template<typename K, typename V> //key (unique) and value (data)
class Treap {
    const pair<V, K> MINVK = mp(numeric_limits<V>::min(), numeric_limits<K>::min());
    const pair<V, K> MAXVK = mp(numeric_limits<V>::max(), numeric_limits<K>::max());
    struct node {
        K key; //unique, time or x-axis for example
        V data; // f[key] = data
        node *l = NULL, *r = NULL;
        int priority;
        pair<V, K> mx, mn; //maximum and minimum values over all subtrees, V 1º to be comparable <
        node(K _key, V _data, ll p) {
            key = _key;
            data = _data;
            mx = mn = mp(_data, _key);
            priority = p;//rand();//((ll)rand()<<16)^(ll)rand(); //hope there is no collision...
        }
    };
    typedef node* pnode;
    pnode root = NULL;
    pair<V, K> getMaximumVK(pnode t) { //O(1)
        if(!t) return MINVK;
        else return t->mx;
    }
    pair<V, K> getMinimumVK(pnode t) { //O(1)
        if(!t) return MAXVK;
        else return t->mn;
    }
    void update (pnode t) {
        if(!t) return;
        t->mx = max({mp(t->data, t->key), getMaximumVK(t->l), getMaximumVK(t->r)});
        t->mn = min({mp(t->data, t->key), getMinimumVK(t->l), getMinimumVK(t->r)});
    }
    //return a subtree l and r such as key(l) < key < key(r), similar to rotations
    void split(pnode t, pnode &l, pnode &r, K key) {
        if(!t) l = r = NULL;
        else if(key < t->key) split(t->l, l, t->l, key), r = t;
        else split(t->r, t->r, r, key), l = t;
        update(t);
    }
    //merge two trees l and r into one, t, allKey(l) < allKey(r)
    void merge(pnode &t, pnode l, pnode r) {
        if(!l || !r) t = l ? l : r;
        else if(l->priority < r->priority) merge(r->l, l, r->l), t = r;
        else merge(l->r, l->r, r), t = l;
        update(t);
    }
    void insert(pnode &t, pnode it) {
        if(!t) t = it;
        else if(t->priority < it->priority) split(t, it->l, it->r, it->key), t = it;
        else insert(it->key < t->key ? t->l : t->r, it);
        update(t);
    }
    void erase(pnode &t, K key) { //only erase if the element exists
        if(!t) {echo("estas borrando pero no esta:", key); exit(-1);}
        if(t->key == key) merge(t, t->l, t->r);
        else erase(key < t->key ? t->l : t->r, key);
        update(t);
    }
    void showTree(pnode t) { //preOrder, the inOrder is the tree sorted 
        if(!t) return;
        cout << "(" << t->key << "," << t->data << ")";
        showTree(t->l); showTree(t->r);
    }
    // UP CONSTRUCTION, BELOW QUERIES
    pair<V, K> getMaximumAfter(pnode t, K key) { //max node with key >= t, O(log(n))
        if(!t) return MINVK;
        pair<V, K> mid = t->key >= key ? mp(t->data, t->key) : MINVK;
        if(key < t->key) return max({getMaximumAfter(t->l, key), getMaximumVK(t->r), mid}); //maybe equals also here
        else return max({getMaximumAfter(t->r, key), mid});
    }
    pair<V, K> getMinimumBefore(pnode t, K key) { //min node with key <= t, O(log(n))
        if(!t) return MAXVK;
        pair<V, K> mid = t->key <= key ? mp(t->data, t->key): MAXVK;
        if(key > t->key) return min({getMinimumBefore(t->r, key), getMinimumVK(t->l), mid});
        else return min({getMinimumBefore(t->l, key), mid});
    }

    public:
    void insert(K key, V data,ll p) { //O(log n)
        pnode n = new node(key, data, p);
        insert(root, n);
    }
    void erase(K key) { //O(log n)
        erase(root, key);
    }
    void showTree() { //debug
        showTree(root);
        cout << endl;
    }
    pair<V, K> getMaximumAfter(K t) { //O(log n)
        return getMaximumAfter(root, t);
    }
    pair<V, K> getMinimumBefore(K t) { //O(log n)
        return getMinimumBefore(root, t);
    }
    pair<V, K> getMaximumAll() { //all the tree, O(1)
        return getMaximumVK(root);
    }
    pair<V, K> getMinimumAll() { //all the tree, O(1)
        return getMinimumVK(root);
    }
    pll getOther() {
        return mp(root->key, root->priority);
    }
};


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll i, m, num, c, r;
    //srand(time(0));

    Treap<ll, ll> t;

    cin >> m;
    vll mes(m);
    for(i = 0; i < m; i++) {
        cin >> mes[i];
    }   
    map<ll, int> h;
    vll carta;
    map<ll, ll> original;
    cin >> c;
    for(i = 0; i < c; i++) {
        cin >> num;
        h[num] = (int)carta.size();
        original[(int)carta.size()] = num;
        carta.pb(num);
    }
    cin >> r;
    for(i = 0; i < r; i++) {
        cin >> num;
        h[num] = (int)carta.size();
        original[(int)carta.size()] = num;
        carta.pb(num*2);
    }
   // echo(carta);
    for(i = 0; i < (int)carta.size(); i++) {
        //rpq.insertPush(i+1, carta[i]);
        t.insert(i+1, 1, -carta[i]);
        //echo("meto", i+1, carta[i]);
    }

    ll total = 0;
    //bool flag = false;
    ll borro = 0;
    //echo(rpq.getOther());
    bool ok = false;
  //  echo(t.getOther());
    ll j, k, P, hn;
    for(i = 0; i < m; i++) {
        cin >> j;
        for(k = 0; k < j; k++) {
            cin >> num >> P;
            if(ok) continue;
            hn = h[num];
           // echo(hn);
            if(carta[hn] == -1) continue;
            //rpq.insertPop(hn+1);
            t.erase(hn+1);
            //echo(1, rpq.getOther());
            carta[hn] = min(carta[hn], P);
            //rpq.insertPush(hn+1, carta[hn]);
            t.insert(hn+1, 1, -carta[hn]);
            //echo(2, rpq.getOther());
        }
        if(ok) continue;
        ll sum = 0;
        //pll a = rpq.getOther();
        pll a = t.getOther();
       // echo("obtengo", a);
        while(sum-a.se <= mes[i]) {
            sum -= a.se;
            //rpq.insertPop(a.se);
            t.erase(a.fi);
            ++borro;
            //echo(borro);
            if(borro == (int)carta.size()) {ok=true; break;}
            carta[a.fi -1] = -1;
            //a = rpq.getOther();
            a = t.getOther();
        }
        total += sum;
       // echo(i, carta);
        //break;
    }

    cout << total << "\n";
    if(ok) cout << "COMPLETADA\n";
    else {
        vll faltan;
        for(i = 0; i < (int)carta.size(); i++) {
            if(carta[i] != -1) faltan.pb(original[i]);
        }
        sort(faltan.begin(), faltan.end());
        for(i = 0; i < (int)faltan.size(); i++) {
            if(i > 0) cout << " ";
            cout << faltan[i];
        }
        cout << "\n";
    }
    //echo(carta);
    

    return 0;
}


