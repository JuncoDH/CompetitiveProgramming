template<typename T>
class Point {
    public:
    static const int LEFT_TURN = 1;
    static const int RIGHT_TURN = -1;
    T x = 0, y = 0;
    Point() = default;
    Point(T _x, T _y) {
        x = _x;
        y = _y;
    }
    friend ostream &operator << (ostream &os, Point<T> &p) {
        os << "(" << p.x << " " << p.y << ")";
        return os;
    }
    bool operator == (const Point<T> other) const {
        return x == other.x && y == other.y;
    }
    // Get the (1º) bottom (2º) left point.
    bool operator < (const Point<T> other) const {
        if(y != other.y) return y < other.y;
        return x < other.x;
    }
    T euclidean_distance(Point<T> other) {
        T dx = x - other.x;
        T dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }
    T euclidean_distance_squared(Point<T> other) {
        T dx = x - other.x;
        T dy = y - other.y;
        return dx*dx + dy*dy;
    }
    T manhatan_distance(Point<T> other) {
        return abs(other.x - x) + abs(other.y - y);
    }
    // Get the height of the triangle with base b1, b2.
    T height_triangle(Point<T> b1, Point<T> b2) {
        if(b1 == b2 || *this == b1 || *this == b2) return 0; // It's not a triangle.
        T a = euclidean_distance(b1);
        T b = b1.euclidean_distance(b2);
        T c = euclidean_distance(b2);
        T d = (c*c-b*b-a*a)/(2*b);
        return sqrt(a*a - d*d);
    }
    int get_quadrant() {
        if(x > 0 && y >= 0) return 1;
        if(x <= 0 && y > 0) return 2;
        if(x < 0 && y <= 0) return 3;
        if(x >= 0 && y < 0) return 4;
        return 0; // Point (0, 0).
    }
    // Relative quadrant respect the point other, not the origin.
    int get_relative_quadrant(Point<T> other) {
        Point<T> p(other.x - x, other.y - y);
        return p.get_quadrant();
    }
    // Orientation of points *this -> a -> b.
    int get_orientation(Point<T> a, Point<T> b) {
        T prod = (a.x - x)*(b.y - a.y) - (a.y - y)*(b.x - a.x);
        if(prod == 0) return 0;
        return prod > 0? LEFT_TURN : RIGHT_TURN;
    }
    // True if a have less angle than b, if *this->a->b is a left turn.
    bool angle_cmp(Point<T> a, Point<T> b) {
        if(get_relative_quadrant(a) != get_relative_quadrant(b)) 
            return get_relative_quadrant(a) < get_relative_quadrant(b);
        int ori = get_orientation(a, b);
        if(ori == 0) return euclidean_distance_squared(a) < euclidean_distance_squared(b);
        return ori == LEFT_TURN;
    }
    // Anticlockwise sort starting at 1º quadrant, respect to *this point.
    void polar_sort(vector<Point<T>> &v) {
        sort(v.begin(), v.end(), [&](Point<T> a, Point<T> b) {return angle_cmp(a, b);});
    }
    // Convert v to its convex hull, Do a Graham Scan. O(n log n).
    void convert_convex_hull(vector<Point<T>> &v) {
        if(v.size() < 3) return;
        Point<T> bottom_left = v[0], p2;
        for(auto p : v) bottom_left = min(bottom_left, p);
        bottom_left.polar_sort(v);
        vector<Point<T>> v_input = v; v.clear();
        for(auto p : v_input) {
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
};
