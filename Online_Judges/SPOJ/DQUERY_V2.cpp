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

// You can use it when you can extend / shrink interval by 1 element.
// O((Q+N)sqrt(N)), is sqrt decomposition.
class Query{
    static const int BLOCK = 170; // sqrt(n) +-;
    public:
    int l, r, id;
    Query() = default;
    Query(int _l, int _r, int _id) {
        l = _l; r = _r; id = _id;
    }
    bool operator < (const Query &other) const {
        if(l/BLOCK != other.l/BLOCK) {
            return l/BLOCK < other.l/BLOCK;
        }
        if(r != other.r) return r < other.r;
        return l < other.l;
    }
};
// Calculate the num of different numbers in [l, r].
class Mo{
    static const int MAX_FREQ = 1e6+5;
    vector<Query> vquery;
    vll v; // Input vector.
    int currL = 0; // currAns represent answer for the
    int currR = -1;// interval [currL, currR].
    int currAns = 0;
    vi freq;
    void add(int i) {
        freq[v[i]]++;
        if(freq[v[i]] == 1) currAns++; 
    }
    void remove(int i) {
        freq[v[i]]--;
        if(freq[v[i]] == 0) currAns--;
    }
    public:
    Mo(vll &_v) {
        v = _v;
    }
    void insert_query(int l, int r, int id) {
        vquery.pb(Query(l, r, id));
    }
    vi solve() {
        int i, n = vquery.size();
        freq.assign(MAX_FREQ, 0);
        vector<pii> ans(n);
        sort(vquery.begin(), vquery.end());
        for(i = 0; i < n; i++) {
            while(currL < vquery[i].l) {
                remove(currL);
                currL++;
            }
            while(currL > vquery[i].l) {
                currL--;
                add(currL);
            }
            while(currR < vquery[i].r) {
                currR++;
                add(currR);
            }
            while(currR > vquery[i].r) {
                remove(currR);
                currR--;
            }
            ans[i] = mp(vquery[i].id, currAns);
        }
        sort(ans.begin(), ans.end());
        vi answer(n);
        for(i = 0; i < n; i++) {
            answer[i] = ans[i].se;
        }
        return answer;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll n, q, i, l, r;

    cin >> n;
    vll v(n);
    cin >> v;
    cin >> q;
    Mo mo(v);
    for(i = 0; i < q; i++) {
        cin >> l >> r;
        l--; r--;
        mo.insert_query(l, r, i);
    }
    vi ans = mo.solve();
    for(auto el : ans) {
        cout << el << "\n";
    }

    return 0;
}



