srand(time(nullptr));
class HashNumber{
    map<ll, ll> m; // num -> hash.
    map<ll, ll> minv; // hash -> num.
    public:
    ll get_hash(ll num) {
        if(m.count(num)) return m[num];
        ll num2 = rand() ^ num ^(ll)0b1001100101010111000101100010101;
        minv[num2] = num;
        return m[num] = num2;
    }
    ll get_hash_inv(ll num2) {
        if(minv.count(num2) == 0) return -1;
        return minv[num2];
    }
};

