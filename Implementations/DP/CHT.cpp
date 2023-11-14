// https://codeforces.com/blog/entry/63823
ll floor_div(ll a, ll b) { // a / b is truncate function.
    return a / b - ((a ^ b) < 0 && a % b);
}
class Line { // Represent y = m * x + n.
    public:
    ll m = 0, n = 0;
    mutable ll p = -inf; // Rightmost point of the line in the convex hull.
    Line() = default;
    Line(ll _m, ll _n) {
        m = _m;
        n = _n;
    }
    bool operator <(Line const & l) const { return m < l.m; }
    bool operator <(ll x) const { return p < x; }
}; // Convex Hull Trick. Return max{ m * x + n }.
class CHT : multiset<Line, less<>> {
    bool is_min = false; // true for find minimum.
    // Actualize p and return true if the line y has to be removed.
    bool update_p(iterator x, iterator y) { // Line x < Line y.
        if(y == end()) { x->p = inf; return false; }
        if(x->m == y->m) x->p = x->n > y->n ? inf : -inf;
        else x->p = floor_div(y->n - x->n, x->m - y->m);
        return x->p >= y->p;
    }
    public:
    CHT() = default;
    CHT(bool _is_min) { is_min = _is_min; }
    void add(ll m, ll n) {
        if(is_min) m = -m, n = -n;
        iterator x = insert(Line(m, n));
        iterator y = x;
        y++;
        while(update_p(x, y)) y = erase(y); // Lines to the right.
        if(x != begin()) { // Inserted line.
            y = x;
            x--;
            if(update_p(x, y)) update_p(x, erase(y));
        }
        while((y = x) != begin() && (--x)->p >= y->p)
            update_p(x, erase(y));
    }
    ll query(ll x) { // Need size > 0.
        Line l = *lower_bound(x);
        ll ans = l.m * x + l.n;
        if(is_min) ans = -ans;
        return ans;
    }
};

