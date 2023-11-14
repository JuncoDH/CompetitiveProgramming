// Get random primes: https://primes.utm.edu/nthprime/.
constexpr int MAX = 2 * 1e5 + 5;
ll val[MAX];
map<ll, ll> m; // Compress elements.
void init() { // CALL ONCE.
    srand(time(nullptr));
    for(int i = 0; i < MAX; i++) val[i] = rand();
}
// Contains a set of elements with duplicates.
// a[i] = sum_x{val[x]} % mod p[i].
class HashSet {
    vll p = { 1'237'273, 1'806'803, 3'279'209 }; // Prime numbers.
    vll a = {0, 0, 0};
    int n = 3; // n = p.size();
public:
    // Insert element x.
    void insert(ll const x) {
        if(!m.count(x)) m[x] = m.size();
        for(int i = 0; i < n; i++) a[i] = (a[i] + val[m[x]]) % p[i];
    }
    void erase(ll const x) {
        for(int i = 0; i < n; i++) a[i] = ((a[i] - val[m[x]]) % p[i] + p[i]) % p[i];
    }
    // Insert all the elements of hs.
    void insert(HashSet const& hs) {
        for(int i = 0; i < n; i++) a[i] = (a[i] + hs.a[i]) % p[i];
    }
    bool operator == (HashSet const hs) const {
        for(int i = 0; i < n; i++) if(a[i] != hs.a[i]) return false;
        return true;
    }
};

