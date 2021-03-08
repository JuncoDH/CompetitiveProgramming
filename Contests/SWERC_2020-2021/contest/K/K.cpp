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

// copied code from https://github.com/JuncoDH/CompetitiveProgramming/blob/master/Implementations/String/Hash/Hash_str.cpp
//https://www.browserling.com/tools/prime-numbers
//s = a[i], hash = a[0] + b*a[1] + b^2*a[2] + b^n*a[n]
class HashStr {
    public:
    string s;
    int n, n_p;
    vector<vll> v; //contain the hash for [0..i]
    vll p = {16532849, 91638611, 83157709}; //prime numbers//15635513  77781229
    vll base = {37, 47, 53}; //base numbers: primes that > alphabet size //49 83
    vector<vll> b; //b[i][j] = (b_i^j) % p_i 
    vector<vll> b_inv;//b_inv[i][j] = (b_i^j)^-1 % p_i 

    ll elevate(ll a, ll _b, ll mod){
        ll ans = 1;
        while(_b){
            if(_b & 1) ans = ans * a % mod;
            _b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }

    //a^(mod - 1) = 1, Euler
    ll inv(int i, int j){
        if(b_inv[i][j] != -1) return b_inv[i][j];
        return b_inv[i][j] = elevate(b[i][j], p[i] - 2, p[i]);
    }

    HashStr(string &_s) { //not empty strings
        s = _s;
        n = _s.length();
        n_p = (int)p.size();
        v.assign(n_p, vll(n, 0));
        b.assign(n_p, vll(n, 0));
        b_inv.assign(n_p, vll(n, -1));
        int i, j;
        for(i = 0; i < n_p; i++) {
            b[i][0] = 1;
            for(j = 1; j < n; j++) {
                b[i][j] = (b[i][j-1]*base[i]) % p[i];
            }
        }
        char initial = 'a'; //change initial for range
        for(i = 0; i < n_p; i++) {
            v[i][0] = s[0]-initial+1;
            for(j = 1; j < n; j++) {
                v[i][j] = (b[i][j]*(s[j]-initial+1) + v[i][j-1]) % p[i];
            }
            //echo(i, v[i], b[i]);
        }
    }
    
    ll getHash(int l, int r, int imod) {
        ll ans = v[imod][r];
        if(l > 0) ans -= v[imod][l-1];
        ans *= inv(imod, l);
        //echo(l, r, imod, inv(imod, l)); // bug here
        ans = ((ans%p[imod])+p[imod])%p[imod];

        return ans;
    }
    ll getMyHash1(int l, int r) { // NEW.
        return getHash(l, r, 0);
    }
    //O(1)
    bool equals(HashStr other, int l, int r) {
        for(int i = 0; i < n_p; i++) {
            if(getHash(l, r, i) != other.getHash(l, r, i)) return false;
        }
        return true;
    }
    //O(1)
    bool operator == (HashStr other) {
        if(n != other.n) return false;
        return equals(other, 0, n-1);
    }
    //return the index of the Longest Comon Prefix, -1 if no Common Prefix
    //O(log n)
    int LCP(HashStr other) {
        int l = 0, r = min(n, other.n), mid;
        if(s[0] != other.s[0]) return -1;
        if(*this == other) return n-1;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            if(equals(other, 0, mid)) l = mid;
            else r = mid;
        }
        
        return l;
    }
    bool operator < (HashStr other) {
        int id = LCP(other);
        if(id == -1) return s[0] < other.s[0];
        if(*this == other) return false;
        if(id == n) return true; //"ho" < "hol"
        if(id == other.n) return false;

        return s[id+1] < other.s[id+1];
    }
};

string sss = "h";
string s;
HashStr hs(sss);
int n;

bool f(int x) {
    int i;
    unordered_map<ll, int> us;
    for(i = 0; i+x-1 < n; i++) {
        /*if(us.find(hs.getMyHash1(i, i+x-1)) != us.end()) {
            return true;
        }*/
        us[hs.getMyHash1(i, i+x-1)]++;
        //us.insert(hs.getMyHash1(i, i+x-1));
    }
    for(auto el : us) {
        if(el.se == 1) return true;
    } 
    return false;
}

void g(int x) {
    int i;
    unordered_map<ll, int> us;
    for(i = 0; i+x-1 < n; i++) {
        /*if(us.find(hs.getMyHash1(i, i+x-1)) != us.end()) {
            return true;
        }*/
        us[hs.getMyHash1(i, i+x-1)]++;
        //us.insert(hs.getMyHash1(i, i+x-1));
    }
    set<ll> pos_sol;
    for(auto el : us) {
        if(el.se == 1) {
            pos_sol.insert(el.fi);
        }
    }
    for(i = 0; i+x-1 < n; i++) {
        if(pos_sol.count(hs.getMyHash1(i, i+x-1)) > 0) {
            for(int j = 0; j < x; j++) {
                char c = s[i+j];
                c += 'A'-'a';
                cout << c;
            }
            cout << "\n";
            exit(0);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int i, l, r, mid;
    cin >> s;
    n = s.length();
    for(i = 0; i < n; i++) {
        s[i] += 'a' - 'A';
    }
    hs = HashStr(s);

    /*
    echo(hs.getMyHash1(0, 0));
    echo(hs.getMyHash1(1, 1));
    echo(hs.getMyHash1(0, 1));
    return 0;*/


    l = 0; r = n;
    while(l + 1 < r) {
        mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    // r es la sol.
    g(r);




    return 0;
}
