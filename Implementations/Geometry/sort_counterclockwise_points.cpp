struct Point{
    ll x, y, w; //weight
    bool operator == (Point a) {
        return x == a.x && y == a.y;
    }
    bool operator != (Point a) {
        return x != a.x || y != a.y;
    }
    bool operator < (Point a) {
        if(x != a.x) return x < a.x;
        return y < a.y;
    }
};

const int LEFT = 1;
const int RIGHT = -1;
int orientation(Point p1, Point p2, Point p3){
    ll ans = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    if(ans == 0) return ans;
    return ans > 0 ? LEFT : RIGHT;
}

//Sort counterclockwise the points, with the center in v[0].
//Starts at 6:00, no 3 points are collinear
bool point_cmp3(Point a, Point b) {
    if(a.x == v[0].x) return true;
    if(b.x == v[0].x) return false;
    if(a.x > v[0].x && v[0].x > b.x) {
        return true;
    }
    if(b.x > v[0].x && v[0].x > a.x) {
        return false;
    }
    return orientation(a, v[0], b) == RIGHT;
}
