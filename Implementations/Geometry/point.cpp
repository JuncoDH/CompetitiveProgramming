const int LEFT_TURN = -1;
const int RIGHT_TURN = 1;
class Point {
    public:
    ld x = inf, y = inf;
    ld euclidean_distance(Point other) {
        ld dx = abs(x - other.x);
        ld dy = abs(y - other.y);
        return sqrt(dx*dx + dy*dy);
    }
    ld manhattan_distance(Point other) {
        return abs(x - other.x) + abs(y - other.y);
    }
    friend ostream &operator << (ostream &os, Point &p);
    // First compare the y coordinate and then the x. Useful to get the bottomLeftmost point on the plane.
    bool operator < (const Point other) const {
        if(y != other.y) return y < other.y;
        return x < other.x;
    }
    // The line is this -> a -> b
    int left_turn(Point a, Point b) {
        ld ans = (b.x - a.x)*(y - a.y) - (b.y - a.y)*(x - a.x);
        if(ans == 0) return 0;
        return ans > 0 ? LEFT_TURN : RIGHT_TURN; 
    }
    // Sort all the points respect the angle.
    //Example:  sort(v.begin(), v.end(), [&](Point a, Point b) {return bottomLeft.angle_sort(a, b);});
    bool angle_sort(Point a, Point b) {
        int ans = left_turn(a, b);
        if(ans == 0) return a.x < b.x;
        return ans == LEFT_TURN;
    }
    // Get the quadrant of the point.
    ll getquad() {
        if(x > 0 && y >= 0) return 1;
        if(x <= 0 && y > 0) return 2;
        if(x < 0 && y <= 0) return 3;
        if(x >= 0 && y < 0) return 4;

        return 0; // Point (0, 0).
    }
};

ostream &operator << (ostream &os, Point &p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
