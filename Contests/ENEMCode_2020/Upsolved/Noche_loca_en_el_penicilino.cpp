#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) ((x>>i)&1)

#ifdef GREMIO_DEBUG
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

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_PRIMES = 5*1e5+5;
bool num[MAX_PRIMES]; //if num[i] = false => i is prime
int num_div[MAX_PRIMES]; //number of divisors of i
int min_div[MAX_PRIMES]; //the smallest prime that divide i
vector<int> prime;
 
void linear_sieve(){
    int i, j, prime_size = 0;
    min_div[1] = 1;
    for(i = 2; i < MAX_PRIMES; ++i){
        if(num[i] == false) {prime.push_back(i); ++prime_size; num_div[i] = 1; min_div[i] = i;}
        
        for(j = 0; j < prime_size && i * prime[j] < MAX_PRIMES; ++j){
            num[i * prime[j]] = true;
            num_div[i * prime[j]] = num_div[i] + 1;
            min_div[i * prime[j]] = min(min_div[i], prime[j]);
            if(i % prime[j] == 0) break;
        }
    }
}
 
bool is_prime(ll n) {
    for(auto el : prime) {
        if(n == el) return true;
        if(n%el == 0) return false;
    }
    return true;
}
 
void factorize(int n) { //example of factoring n
    while(n != 1) {
        cout << min_div[n] << " ";
        n /= min_div[n];
    } cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    linear_sieve();
    ll tt, a, b;
    vector<ld> sol;
    cin >> tt;
    while(tt--) {
        cin >> a >> b;
        if(a%2 && a > 1) {cout << "No hay\n"; continue;}
        if(b%2 && b > 1) {cout << "No hay\n"; continue;}
        if(a == 1 && b == 1) {cout << "Infinitas\n"; continue;}

        if(!is_prime(a+1) || !is_prime(b+1)) {cout << "No hay\n"; continue;}

        if(a%2 == 0 && b%2 == 0) {
            cout << "1 (0.785, 0.785)\n";
            continue;
        }

        sol.clear();
        sol.pb(atan(1));
        // THE VECTOR SHOULD BE (b, a), SO THE ANGLE SHOULD BE atan(a/b) instead of (b/a).
        // IF THE CASE IS (1 4) I DONT KNOW WHY THE SOL CAN'T BE ((1, 4), (1, 1), (1, 1))...
        sol.pb(atan((ld)b/(ld)a));
        sort(sol.begin(), sol.end());
        cout << setprecision(3) << fixed;
        cout << "1 (" << sol[0] << ", " << sol[1] << ")\n";

    }




    return 0;
}
