typedef long double ftype; //NOT USE LONG LONG, complex cast to minor precission
typedef complex<ftype> point;
#define x real
#define y imag
 
ftype dot(point a, point b) {
    return (conj(a)*b).x();
}
 
ftype cross(point a, point b) {
    return (conj(a)*b).y();
}
//get min{k_i * x + b_i}. Insert k_i in ascending order. max {} = -min{-()}
class ConvexHullTrick {
    point im = {0, 1};
    vector<point> hull, normal;
    public:
    void add_line(ftype k, ftype b) {
        point nw = {k, b};
        //Create lower convex hull, with increasing k (add lines to the right only)
        while(!normal.empty() && dot(normal.back(), (nw - hull.back())) < 0) {
            hull.pop_back();
            normal.pop_back();
        }
        if(!hull.empty()) { //add the normal of vector (nw - hull.back())
            normal.pb(im * (nw - hull.back()));
        }
        hull.pb(nw);
    }
    // normal anti-clockwise, hull[it], normal clockwise
    ftype query(ftype x) {
        point px = {x, 1}; //query is min dot product {k, b} * {x, 1}
 
        auto it = lower_bound(normal.begin(), normal.end(), px, [](point a, point b) {
            return cross(a, b) > 0;
        }) - normal.begin();
        return dot(px, hull[it]);
    }
};
