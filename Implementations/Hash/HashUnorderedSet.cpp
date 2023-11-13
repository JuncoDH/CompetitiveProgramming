// Use unordered_set<pii, pair_hash> us or unordered_map<pii, int, pair_hash> um;
struct pair_hash
{
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const& pair) const
    {
        size_t const h1 = hash<T1>()(pair.first);
        size_t const h2 = hash<T2>()(pair.second);
        return (h1 ^ 0b11001001011001101) + (0b011001010011100111 ^ h2);
    }
};

