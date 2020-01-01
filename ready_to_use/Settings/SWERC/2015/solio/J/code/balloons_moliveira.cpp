// SWERC 2015 - St John Festival
// Approach: Find the convex hull of the large balloons. Then, for each point p,
//           binary search to find the candidate triangle that would contain p. 
//           O(N log N + M log N)
// Author: Miguel Oliveira
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
  long long x, y;
  Point(long long xx = 0, long long yy = 0) : x(xx), y(yy)  { }
  Point operator - (const Point & a) const      { return Point(x - a.x , y - a.y); }
  long long operator * (const Point & a) const  { return x * a.x + y * a.y; }
  long long operator ^ (const Point & a) const  { return x * a.y - y * a.x;        }
  bool operator < (const Point & p) const {
    return x < p.x || (x == p.x && y < p.y); 
  }
};

long long Cross(const Point& A, const Point& B, const Point& C) { return (B-A) ^ (C-A); }

void ConvexHull(vector<Point>& P, vector<Point>& H) {
  int i, t, k = 0, n = P.size();
  H.resize(2*n);
  sort(P.begin(), P.end()); 
  for (i = 0; i < n; i++) {
    while (k > 1 && Cross(H[k-2], H[k-1], P[i]) <= 0) 
      k--;
    H[k++] = P[i];
  }
  for (i = n-2, t = k; i >= 0; i--) {
    while (k > t && Cross(H[k-2], H[k-1], P[i]) <= 0) 
      k--;
    H[k++] = P[i];
  }
  H.resize(k);
}
// This actually returns 2x the area, but it is ok for our needs - InTriangle().
long long TriangleArea(const Point& a, const Point& b, const Point& c) {
  return (-b.y*c.x + a.y*(-b.x + c.x) + a.x*(b.y - c.y) + b.x*c.y);
}

bool InIntSegment(const Point& c, const Point&a, const Point& b) {
  if (Cross(a, b, c) != 0)
    return false;
  long long dotproduct = (c-a) * (b-a), squared_length = (b-a) * (b-a);
  if (dotproduct < 0 || dotproduct > squared_length)
    return false;
  return true;
}

bool InTriangle(const Point& p, const Point& a, const Point& b, const Point& c) {
  if (InIntSegment(p, a, b) || InIntSegment(p, b, c) || InIntSegment(p, a, c))
    return true;

  long long area = TriangleArea(a, b, c);
  if (area == 0)
    return false;
  double s = static_cast<double>(a.y*c.x - a.x*c.y + (c.y - a.y)*p.x + (a.x - c.x)*p.y) / area;
  if (s <= 0) {
    return false;
  }
  double t = static_cast<double>(a.x*b.y - a.y*b.x + (a.y - b.y)*p.x + (b.x - a.x)*p.y) / area;
  return t > 0 && 1-s-t > 0;
}

int InPolygon(Point& p, const vector<Point>& hull) { 
  int left = 1, right = hull.size()-3; // -1 due to mid+1, -1 due last point == hull[0]
  while (left <= right) {
    int mid = (left + right) / 2;
    long long cross1 = Cross(hull[0], hull[mid], p);
    long long cross2 = Cross(hull[0], p, hull[mid+1]);
    if (cross1 >= 0 && cross2 >= 0 && InTriangle(p, hull[0], hull[mid], hull[mid+1])) {
      return 1;
    } else if (cross1 < 0) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return 0;
}

void ReadPoints(int& size, vector<Point>& points) {
  cin >> size;
  points.resize(size);
  for (int i = 0; i < size; ++i)
    cin >> points[i].x >> points[i].y;
}

int main() {
  int N, M, answer = 0;
  vector<Point> large, small, hull;
  ReadPoints(N, large);
  ReadPoints(M, small);
  ConvexHull(large, hull);
  for (auto p : small) {
    answer += InPolygon(p, hull);
  }
  cout << answer << endl;     
  return 0;
}
