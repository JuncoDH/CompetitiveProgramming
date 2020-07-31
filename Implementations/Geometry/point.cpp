//All of this code have been tested by an AC in a problem

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
    ll getquad() {
        if(x > 0 && y >= 0) return 1;
        if(x <= 0 && y > 0) return 2;
        if(x < 0 && y <= 0) return 3;
        if(x >= 0 && y < 0) return 4;

        return 0;
    }
    void show() {
        cout << "(" << x << ", " << y << ")" << endl; 
    }
};

const int LEFT = 1;
const int RIGHT = -1;
int orientation(Point p1, Point p2, Point p3){
    ll ans = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    if(ans == 0) return ans;
    return ans > 0 ? LEFT : RIGHT;
}

//distance point a to rect of points p1 and p2
//rect Ax+By+C = 0
NOT TESTED
ld distRect(point a, point p1, point p2){
    ll A = p1.y - p2.y;
    ll B = -(p1.x - p2.x);
    ll C = p1.x * p2.y - p1.y * p2.x;
    return abs(A * a.x + B * a.y + C) / (ld) sqrt(A * A + B * B);
}

//THIS FUNCTION GIVES RE
RE
//Sort counterclockwise the points, with the center in v[0].
//Starts at 6:00, no 3 points are collinear
bool cmp_counterclockwise(Point a, Point b) {
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
