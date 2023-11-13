map<pll, ll> hash_pair;
void insert_pair(pll const& x) {
    if(!hash_pair.count(x)) hash_pair[x] = hash_pair.size();
}
class HashVector{
public:
    HashSet hs;
    vll v;
    void push_back(ll x) {
        pll px = {x, v.size()};
        insert_pair(px);
        v.push_back(x);
        hs.insert(hash_pair[px]);
    }
    void pop_back() {
        ll x = v.back(); v.pop_back();
        pll px = {x, v.size()};
        hs.erase(hash_pair[px]);
    }
    bool operator == (HashVector const& hv) const {
        return hs == hv.hs;
    }
};

