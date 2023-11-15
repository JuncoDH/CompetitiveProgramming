map<pll, ll> hash_pair;
void insert_pair(pll const& x) {
    if(!hash_pair.count(x)) hash_pair[x] = hash_pair.size();
}

