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


ll ans = 0;

const int ALPHABET = 26;
struct node {
    int cnt = 0;
    node *parent = NULL;
    node *child[ALPHABET];
    int count_word = 0;
    node(){for(int i = 0; i < ALPHABET; i++) child[i] = NULL;}
    node(node *p) {parent = p; for(int i = 0; i < ALPHABET; i++) child[i] = NULL;}
    ~node() {for(int i = 0; i < ALPHABET; i++) delete child[i];}
    void show(string s) { // Show all the nodes in lexicographical order.
        if(count_word > 0) echo(s); // NOT SHOWING DUPLICATE WORDS.
        for(int i = 0; i < ALPHABET; i++) {
            if(child[i]) child[i]->show(s + (char)(i+'a'));
        }
    }
};

class Trie {
    node *root = new node();
    public:
    ~Trie() {delete root;}
    void add(string s) {
        node *p = root;
        int nc;
        for(auto c : s) {
            nc = c - 'a';
            if(!p->child[nc]) p->child[nc] = new node(p);
            p = p->child[nc];
            p->cnt++;
        }
        p->count_word++;
    }
    void remove(string s) {
        node *p = root;
        int nc;
        for(auto c : s) {
            nc = c - 'a';
            if(!p->child[nc]) return; // ERROR, remove one string not in the trie.
            p = p->child[nc];
        }
        if(p->count_word == 0) return ; // ERROR, remove one string not in the trie.
        p->count_word--;
    }
    bool search(string s) {
        node *p = root;
        int nc;
        for(auto c : s) {
            nc = c - 'a';
            if(!p->child[nc]) return false;
            p = p->child[nc];
        }
        ans = p->cnt;
        return p->count_word > 0;
    }
    void show() {root->show("");}
};



int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    ll n, q, i;
    Trie t;
    cin >> n >> q;
    for(i = 0; i < n; i++) {
        cin >> s;
        t.add(s);
    }
    for(i = 0; i < q; i++) {
        ans = 0;
        cin >> s;
        t.search(s);
        cout << ans << "\n";
    }



    return 0;
}

