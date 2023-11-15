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
void ECHO(long long unsigned _s) {cout<<_s;}
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


class node{
    public:
    int len; // Length of the longest string in the equivalence classes.
    int suffix_link = -1; // The longest suffix that is not in the same equivalence class.
    map<char, int> next;
    node(int _len) {
        len = _len;
    }
};
class SuffixAutomaton{ // O(n) creation.
    vector<node> t = vector<node>(1, node(0));
    // int t_size = 1;
    int last = 0; // The node representing the entire string.
    public:
    void extend(string &s) {
        for(char c : s) extend(c);
    } // Extend the automaton character one by one.
    void extend(char c) {
        int p = last; // Head of the automaton.
        int q; // the node to duplicate.
        t.pb(node(t[last].len + 1));
        last = (int)t.size() - 1;
        // Add c to the previous suffixes.
        while(p != -1 && !t[p].next.count(c)) {
            t[p].next[c] = last;
            p = t[p].suffix_link;
        }
        // First time of c in the string.
        if(p == -1) {
            t[last].suffix_link = 0;
            return;
        }
        q = t[p].next[c];
        if(t[p].len + 1 == t[q].len) {
            t[last].suffix_link = q;
            return;
        }
        // Clone state q.
        t.pb(node(t[p].len + 1));
        t.back().next = t[q].next;
        t.back().suffix_link = t[q].suffix_link;

        // Add links of last and q.
        t[last].suffix_link = (int)t.size() - 1;
        t[q].suffix_link = (int)t.size() - 1;

        // Point to the last suffixes to q cloned.
        while(p != -1 && t[p].next[c] == q) {
            t[p].next[c] = (int)t.size() - 1;
            p = t[p].suffix_link;
        }
    }
    vector<bool> terminal_node; // If the node represent a suffix.
    void init_terminal() { // Call once.
        int p = last;
        terminal_node.assign((int)t.size(), false);
        while(p != -1) {
            terminal_node[p] = true;
            p = t[p].suffix_link;
        }
    }
    // Return true if w is a substring of s.
    // Can retrieve the longest prefis of w that is in s.
    // w is a suffix if the last p is a terminal node.
    bool is_substr(string &w) {
        int p = 0; // string s = "";
        for(char ch : w) {
            if(!t[p].next.count(ch)) return false;
            p = t[p].next[ch];
            // s += c;
        }
        return true;
    }
    // Number of different substrings in the automaton.
    // For the sum of all substring length:
    // ans[u] = sum_w(ans[w] + dp_num_substr[w])
    vll dp_num_substr;
    ll num_substr(int i = 0) { // Empty string also counts.
        ll ans = 1;
        if(dp_num_substr.empty()) dp_num_substr.assign((int)t.size(), -1);
        if(dp_num_substr[i] != -1) return dp_num_substr[i];
        for(auto el : t[i].next) ans += num_substr(el.se);
        return dp_num_substr[i] = ans;
    }
    // k-th string in the sorted substrings set, in [0, num_substr()-1].
    string k_substr(int k) {
        int p = 0;
        char prev;
        string ans = "";
        if(k >= num_substr()) return ans; // Error.
        while(k > 0) {
            prev = '$';
            for(auto el : t[p].next) {
                prev = el.fi;
                if(dp_num_substr[el.se] >= k) break;
                k -= dp_num_substr[el.se];
            }
            if(prev == '$') break; // Error.
            ans += prev;
            p = t[p].next[prev];
            k--;
        }
        return ans;
    }
    // Take greedily the first substring with same length as s.
    string smallest_cyclic_shift(string &s) {
        int p = 0, cnt = s.length();
        string ans = "", s2 = s+s;
        extend(s2);
        while(cnt--) {
            auto el = *(t[p].next.begin());
            ans += el.fi;
            p = el.se;
        }
        return ans;
    }
    void test() { // For debug.
        string s = "test";
        extend(s);
        ll n = num_substr();
        for(ll i = 0; i < n; i++) echo(i, k_substr(i));
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    SuffixAutomaton sa;
    sa.extend(s);
    ll n, num;
    cin >> n;
    while(n--) {
        cin >> num;
        cout << sa.k_substr(num) << "\n";
    }

    return 0;
}



