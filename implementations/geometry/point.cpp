template<typename T>
class Point {
    public:
    static constexpr int LEFT_TURN = 1;
    static constexpr int RIGHT_TURN = -1;
    T x = 0, y = 0;
    Point() = default;
    Point(T const _x, T const _y) {
        x = _x;
        y = _y;
    }
    friend ostream& operator << (ostream& os, Point<T> p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    bool operator == (Point<T> const other) const {
        return x == other.x && y == other.y;
    }
    // Get the (1º) bottom (2º) left point.
    bool operator < (Point<T> const other) const {
        if(y != other.y) return y < other.y;
        return x < other.x;
    }
    T euclidean_distance(Point<T> const other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
    T euclidean_distance_squared(Point<T> other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return dx * dx + dy * dy;
    }
    T manhatan_distance(Point<T> const other) const {
        return abs(other.x - x) + abs(other.y - y);
    }
    // Get the height of the triangle with base b1, b2.
    T height_triangle(Point<T> const b1, Point<T> const b2) const {
        if(b1 == b2 || *this == b1 || *this == b2) return 0; // It's not a triangle.
        T a = euclidean_distance(b1);
        T b = b1.euclidean_distance(b2);
        T c = euclidean_distance(b2);
        T d = (c * c - b * b - a * a) / (2 * b);
        return sqrt(a * a - d * d);
    }
    int get_quadrant() const {
        if(x > 0 && y >= 0) return 1;
        if(x <= 0 && y > 0) return 2;
        if(x < 0 && y <= 0) return 3;
        if(x >= 0 && y < 0) return 4;
        return 0; // Point (0, 0).
    }
    // Relative quadrant respect the point other, not the origin.
    int get_relative_quadrant(Point<T> const other) const {
        Point<T> p(other.x - x, other.y - y);
        return p.get_quadrant();
    }
    // Orientation of points *this -> a -> b.
    int get_orientation(Point<T> const& a, Point<T> const& b) const {
        T prod = (a.x - x) * (b.y - a.y) - (a.y - y) * (b.x - a.x);
        if(prod == 0) return 0;
        return prod > 0? LEFT_TURN : RIGHT_TURN;
    }
    // True if a have less angle than b, if *this->a->b is a left turn.
    bool angle_cmp(Point<T> const a, Point<T> const b) const {
        if(get_relative_quadrant(a) != get_relative_quadrant(b))
            return get_relative_quadrant(a) < get_relative_quadrant(b);
        int ori = get_orientation(a, b);
        if(ori == 0) return euclidean_distance_squared(a) < euclidean_distance_squared(b);
        return ori == LEFT_TURN;
    }
    // Anticlockwise sort starting at 1º quadrant, respect to *this point.
    void polar_sort(vector<Point<T>>& v) const {
        sort(v.begin(), v.end(), [&](Point<T> const a, Point<T> const b) { return angle_cmp(a, b); });
    }
    // Convert v to its convex hull, Do a Graham Scan. O(n log n).
    void convert_convex_hull(vector<Point<T>>& v) const {
        if((int)v.size() < 3) return;
        Point<T> bottom_left = v[0], p2;
        for(auto const& p : v) bottom_left = min(bottom_left, p);
        bottom_left.polar_sort(v);
        vector<Point<T>> v_input = v; v.clear();
        for(auto const& p : v_input) {
            while(v.size() >= 2) {
                p2 = v.back(); v.pop_back();
                if(v.back().get_orientation(p2, p) == LEFT_TURN) {
                    v.pb(p2);
                    break;
                }
            }
            v.pb(p);
        }
    }
    // Constraint: The points have to be in order
    // p0 -> p1 -> ... -> pn, and exist edge pn -> p0.
    static ld get_area_polygon(vector<Point<T>>& v) {
        if(v.size() < 3) return 0;
        ll sum = 0, n = v.size();
        for(int i = 0; i < n; ++i) {
            sum += v[i].x * v[(i + 1) % n].y - v[(i + 1) % n].x * v[i].y;
        }
        return abs(sum) / 2.0;
    }
    // Rotate p alpha radians (anti clock wise) respect to this point.
    Point<T> rotate(Point<T> const p, ld const alpha) const {
        Point<T> q(p.x - x, p.y - y); // p shifted.
        return Point<T>(x + q.x * cos(alpha) - q.y * sin(alpha),
                        y + q.x * sin(alpha) + q.y * cos(alpha));
    }
};
template<typename T>
class Line {
    public:
    bool is_vertical = false; // If vertical, line := x = n.
    T m = 0, n = 0; // y = mx + n.
    Line(T const _m, T const _n) { m = _m; n = _n; }
    Line(Point<T> const p1, Point<T> const p2) {
        if(p1.x == p2.x) { is_vertical = true; n = p1.x; return; }
        m = (p2.y - p1.y) / (p2.x - p1.x);
        n = m * -p1.x + p1.y;
    }
    friend ostream& operator << (ostream& os, Line<T> l) {
        if(l.is_vertical) os << "x = " << l.n;
        else os << "y = " << l.m << "x + " << l.n;
        return os;
    }
    Point<T> intersection(Line<T> const l) const {
        if(is_vertical && l.is_vertical) return Point<T>(-inf, -inf);
        if(is_vertical) return Point<T>(n, l.m * n + l.n);
        if(l.is_vertical) return Point<T>(l.n, m * l.n + n);
        T new_m = (l.n - n) / (m - l.m);
        return Point<T>(new_m, m * new_m + n);
    }
};
// Point of intersection of two lines formed by (p1, p2), (p3, p4).
Point<ld> intersection4points(Point<ld> const p1, Point<ld> const p2, Point<ld> const p3, Point<ld> const p4) {
    Line<ld> l1(p1, p2), l2(p3, p4);
    return l1.intersection(l2);
}
// Fermat point is the one that minimize the sum to the point to the vertices of a triangle.
pair<Point<ld>, ld> get_fermat_point(Point<ld> const p1, Point<ld> const p2, Point<ld> const p3) {
    Point<ld> fermat = p1, ret;
    ld ans = inf, tans;
    ans = p1.euclidean_distance(p2) + p1.euclidean_distance(p3);
    tans = p2.euclidean_distance(p1) + p2.euclidean_distance(p3);
    if(tans < ans) { ans = tans; fermat = p2; }
    tans = p3.euclidean_distance(p1) + p3.euclidean_distance(p2);
    if(tans < ans) { ans = tans; fermat = p3; }
    ret = intersection4points(p3, p2.rotate(p1, PI / 3), p1, p2.rotate(p3, PI / 3));
    tans = ret.euclidean_distance(p1) + ret.euclidean_distance(p2) + ret.euclidean_distance(p3);
    if(tans < ans) { ans = tans; fermat = ret; }
    ret = intersection4points(p3, p2.rotate(p1, PI / 3), p1, p2.rotate(p3, -PI / 3));
    tans = ret.euclidean_distance(p1) + ret.euclidean_distance(p2) + ret.euclidean_distance(p3);
    if(tans < ans) { ans = tans; fermat = ret; }
    ret = intersection4points(p3, p2.rotate(p1, -PI / 3), p1, p2.rotate(p3, PI / 3));
    tans = ret.euclidean_distance(p1) + ret.euclidean_distance(p2) + ret.euclidean_distance(p3);
    if(tans < ans) { ans = tans; fermat = ret; }
    ret = intersection4points(p3, p2.rotate(p1, -PI / 3), p1, p2.rotate(p3, -PI / 3));
    tans = ret.euclidean_distance(p1) + ret.euclidean_distance(p2) + ret.euclidean_distance(p3);
    if(tans < ans) { ans = tans; fermat = ret; }
    return { fermat, ans };
}
// Return random float in [0, 1].
ld rand_float() {
    return rand() / (ld)RAND_MAX;
} // Return a point inside a triangle formed by p1, p2, p3.
Point<ld> random_triangle(Point<ld> const p1, Point<ld> const p2, Point<ld> const p3) {
    ld u1 = rand_float(), u2 = rand_float();
    if(u1 + u2 > 1) u1 = 1 - u1, u2 = 1 - u2; // rectangle -> triangle.
    return { p2.x + (p1.x - p2.x) * u1 + (p3.x - p2.x) * u2,
                     p2.y + (p1.y - p2.y) * u1 + (p3.y - p2.y) * u2 };
}

