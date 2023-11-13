srand(time(nullptr));
class HashNumber{
    map<ll, ll> m; // num -> hash.
    map<ll, ll> minv; // hash -> num.
public:
    ll get_hash(ll const num) {
        if(m.count(num)) return m[num];
        ll num2 = num ^(ll)978297864536453112;
        num2 ^= rand() ^ ((ll)rand() << 30);
        minv[num2] = num;
        return m[num] = num2;
    }
    ll get_hash_inv(ll const num2) {
        if(minv.count(num2) == 0) return -1;
        return minv[num2];
    }
};

