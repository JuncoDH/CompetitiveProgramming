/*---------------------------------------------------------------------*\
| SWERC 2015 - Saint John Festival (J)                                  |
| Author: Miguel Araujo                                                 |
| Date: 16.11.2015                                                      |
| Approach:   O(L log L + S log H), where H is the number of vertices   |
|    in the convex hull of the large lanterns                           |
|  - finds the convex hull C of the large lanterns in O(L log L)        |
|    Graham scan                                                        |
|  - for checking if a small lantern is not in Exterior(C) uses         |
|    binary search to analyse the relative position to upper hull       |
|    and the lower hull                                                 |
|  - performs floating point operations                                 |
\*---------------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAXN 10010
#define MAXM 50010
#define EPS 1e-7
#define CP const Point

using namespace std;

typedef long long CoordType;

struct Point {
  CoordType x , y ;
  Point( CoordType xx = 0 , CoordType yy = 0 ) { x = xx , y = yy; }
  Point operator + ( CP & a ) const { return Point( x+a.x , y+a.y ); }
  Point operator - ( CP & a ) const { return Point( x-a.x , y-a.y ); }
  Point operator * ( double n ) const { return Point( x * n , y * n ); }
  Point operator / ( double n ) const { return Point( x / n , y / n ); }
  CoordType operator * ( CP & a ) const { return x * a.x + y * a.y; } // dot
  CoordType operator ^ ( CP & a ) const { return x * a.y - y * a.x; } // cross
  bool operator < ( CP & p ) const {
    return x < p.x || (fabs(x-p.x) < EPS && y < p.y);
  }
};
CoordType cross( CP & A, CP &B, CP &C) { return (B-A) ^ (C-A); }


int convexHull(vector<Point> & P , vector<Point> & H) {
  int i , t, k = 0 , n = P.size();
  int midpoint;
  H.resize(2*n);
  sort( P.begin() , P.end() ); // Sort points lexicographically
  // Build lower hull
  for (i = 0; i < n; i++) {
    while (k > 1 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }
  midpoint = k; // index de separacao entre lower e upper hull
  // Build upper hull
  for (i = n-2, t = k; i >= 0; i--) {
    while (k > t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }
  H.resize(k);
  return midpoint;
}

bool above(int sign, Point k, vector<Point>& h) {
  if (k.x == h[0].x) return (sign > 0 ? k.y >= h[0].y : k.y <= h[0].y);
  if (k.x == h[h.size()-1].x) return (sign > 0 ? k.y >= h[h.size()-1].y : k.y <= h[h.size()-1].y);
  
  if (k.x < h[0].x || k.x > h[h.size()-1].x) return false;

  int lower = 0, upper = h.size()-1, mid;
  while (lower < upper) {
    mid = lower+(upper-lower)/2;
    if (mid == lower) break;
    if (k.x < h[mid].x) 
      upper = mid;
    else
      lower = mid;
  }
  
  //test between mid and mid+1
  double slope = double(h[mid+1].y - h[mid].y)/(h[mid+1].x - h[mid].x);
  double yintersect = h[mid].y + (k.x-h[mid].x)*slope;
  
  bool ans = (sign == 1 ? k.y >= yintersect-EPS : k.y <= yintersect + EPS);

  return ans;
}

int main() {
  vector<Point> large, small;
  int n,m;
  scanf("%d", &n);
  int x,y;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    large.push_back(Point(x,y));
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    small.push_back(Point(x,y));
  }
  
  vector<Point> hull;
  int midpoint = convexHull(large, hull);

  int llimit = midpoint-1;
  while (hull[llimit-1].x == hull[llimit].x) llimit--;
  vector<Point> lower(hull.begin(), hull.begin() + llimit + 1);

  int ulimit = midpoint-1;
  while (hull[ulimit].x == hull[ulimit+1].x) ulimit++;

  int uend = hull.size()-1;
  while (hull[uend].x == hull[uend-1].x) uend--;

  vector<Point> upper(hull.begin()+ulimit, hull.begin()+uend+1);
  reverse(upper.begin(), upper.end());

  /*
  puts("Lower:");
  for (size_t i = 0; i < lower.size(); i++)
    printf("%lld %lld\n", lower[i].x, lower[i].y);

  puts("Upper:");
  for (size_t i = 0; i < upper.size(); i++)
    printf("%lld %lld\n", upper[i].x, upper[i].y);
  */

  int cnt = 0;
  for (int i = 0; i < m; i++) {
    bool lres = above(1, small[i], lower), ures = above(-1, small[i], upper);
    if (lres && ures) cnt++;
    //    printf("%d - (%lld, %lld) %s %d %d\n", i, small[i].x, small[i].y, (lres && ures ? "PASSED" : "FAILED"), lres, ures);
  }
  printf("%d\n", cnt);
  return 0;
}
