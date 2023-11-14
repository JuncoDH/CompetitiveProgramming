class HashQueue {
    static constexpr int max_digits = 10; // Always numbers < 10^max_digits.
    static string to_str(ll const x) {
        string s = to_string(x);
        while((int)s.length() < max_digits) s = "0" + s;
        return s;
    }
    public:
    HashQueue() {
        string dummy = "0";
        hs = HashString(dummy);
    }
    HashString hs;
    int id = 0;
    int l = 1, r = 0; // [l, r].
    deque<pll> d;
    void push_back(ll const x) {
        string s = to_str(x);
        hs.add(s);
        r += max_digits;
    }
    void pop_front() {
        l += max_digits;
    }
    bool empty() const {
        return l > r;
    }
    bool operator == (HashQueue const& other) const {
        if(empty() && other.empty()) return true;
        if(empty() || other.empty()) return false;
        return hs.getHash(l, r) == other.hs.getHash(other.l, other.r);
    }
};

