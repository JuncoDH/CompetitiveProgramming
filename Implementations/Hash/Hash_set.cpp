const int MAX = 2*1e5+5;
ll val[MAX]; // For random numbers and not index use f with random xor.

void ini() { // CALL ME ONCE.
    srand(time(0));
    for(int i = 0; i < MAX; i++) val[i] = rand();
}

// Hash_set contains a set of indices [0..MAX-1] with duplicates.
// a[i] = sum_x{val_x} % mod p[i].
class Hash_set {
    public:
    vll p = {1'237'273, 1'806'803, 3'279'209}; // Prime numbers.
    vll a = {0, 0, 0};
    int n = 3; // n = p.size();
    // Insert index x.
    void insert(int x) {
        for(int i = 0; i < n; i++) a[i] = (a[i] + val[x]) % p[i];
    }
    // Insert all the elements of hs.
    void insert (Hash_set hs) {
        for(int i = 0; i < n; i++) a[i] = (a[i] + hs.a[i]) % p[i];
    }

    bool operator == (Hash_set hs) {
        for(int i = 0; i < n; i++) if(a[i] != hs.a[i]) return false;
        return true;
    }
};
