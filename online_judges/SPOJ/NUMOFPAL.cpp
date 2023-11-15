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
#define echoarr(x) {for(int _i=0,_n=min((size_t)15,sizeof(x)/sizeof(x[0]));_i<_n;_i++)\
 {cout << x[_i] << " ";} cout << endl;}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(x)
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


class Node{
    static const int ALPHA_SIZE = 26;
    public:
    int len = -1; // Length of the palindrome.
    int suffix_link = -1; // Link to biggest palindrome of a proper suffix.
    int to[ALPHA_SIZE] = {0};
    int num_palindromes = 0; // Number of palindromes finishing in this node.
    Node(int _len, int _suffix_link) {
        len = _len;
        suffix_link = _suffix_link;
    }
};
class PalindromicTree{
    vector<Node> tree; // Two roots, odd and even size palindroms.
    int last = 1; // Online processing.
    string s = "#";
    int n = 1;
    public:
    PalindromicTree() {
        tree.pb(Node(-1, -1));
        tree.pb(Node(0, 0));
    }
    int add_character(char c) {
        int ch = c - 'a';
        s += c; n++;
        int p = last;
        while(p != -1 && c != s[n - tree[p].len - 2])
            p = tree[p].suffix_link;
        if(!tree[p].to[ch]) {
            tree.pb(Node(tree[p].len + 2, -1));
            last = (int)tree.size() - 1;
            tree[p].to[ch] = last;
            p = tree[p].suffix_link;
            while(p != -1 && c != s[n - tree[p].len - 2]) 
                p = tree[p].suffix_link;
            if(p == -1) tree[last].suffix_link = 1;
            else tree[last].suffix_link = tree[p].to[ch];
            tree[last].num_palindromes = tree[tree[last].suffix_link].num_palindromes + 1;
        } else last = tree[p].to[ch];
        return tree[last].num_palindromes;
    }
};


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    PalindromicTree pt;
    string s;
    cin >> s;
    ll ans = 0;
    for(auto el : s) {
        ans += pt.add_character(el);
    }
    cout << ans << "\n";

    return 0;
}


