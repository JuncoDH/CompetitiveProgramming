// SWERC 2015 - St John Festival
// Approach: Find the convex hull of the large balloons. Then, for each point p,
//           binary search to find the candidate triangle that would contain p. 
//           O(N log N + M log N)
// Author: Miguel Oliveira
import java.io.*;
import java.util.*;

class Balloons {
  static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

  static ArrayList<Point> readPoints() throws IOException {
    ArrayList<Point> points = new ArrayList<Point>();
    int n = Integer.parseInt(reader.readLine());
    for (int i = 0; i < n; i++) {
      String[] tokens = reader.readLine().split(" ");
      points.add(new Point(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]))); 
    }
    return points;
  }
  public static void main( String[] args ) throws IOException {
    List<Point> large = readPoints();
    List<Point> hull = convexHull(large);
    int answer = 0;
    for (Point p : readPoints()) {
      answer += inPolygon(p, hull);
    }
    System.out.println(answer);       
  }

  static class Point implements Comparable<Point> {
    long x, y;
    Point(long xx, long yy) { x = xx; y = yy; }
    Point minus(Point a)    { return new Point(x - a.x , y - a.y);  }
    long dot(Point a)       { return x * a.x + y * a.y;             }
    long cross(Point a)     { return x * a.y - y * a.x;             }

    @Override
    public int compareTo(Point p) {
      int d = Long.compare(x, p.x);
      if (d != 0)   
        return d;
      return Long.compare(y, p.y);
    }
  }

  static long cross(Point A, Point B, Point C) { return B.minus(A).cross(C.minus(A)); }

  static List<Point> convexHull(List<Point> P) {
    int i, t, k = 0, n = P.size();
    ArrayList<Point> H = new ArrayList<Point>(2*n);
    Collections.sort(P);
    for (i = 0; i < n; i++) {
      while (k > 1 && cross(H.get(k-2), H.get(k-1), P.get(i)) <= 0) 
        k--;
      if (H.size() > k)
        H.set(k, P.get(i));
      else
        H.add(P.get(i));
      k++;
    }
    for (i = n-2, t = k; i >= 0; i--) {
      while (k > t && cross(H.get(k-2), H.get(k-1), P.get(i)) <= 0) 
        k--;
      if (H.size() > k)
        H.set(k, P.get(i));
      else
        H.add(P.get(i));
      k++;
    }
    return H.subList(0, k);
  }
  static int inPolygon(Point p, List<Point> hull) { 
    int left = 1, right = hull.size()-3; // -1 due to mid+1, -1 due last point == hull[0]
    Point first = hull.get(0);
    while (left <= right) {
      final int mid = (left + right) / 2;
      long cross1 = cross(first, hull.get(mid), p);
      long cross2 = cross(first, p, hull.get(mid+1));
      if (cross1 >= 0 && cross2 >= 0 && inTriangle(p, first, hull.get(mid), hull.get(mid+1))) {
        return 1;
      } else if (cross1 < 0) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return 0;
  }

  // This actually returns 2x the area, but it is ok for our needs - InTriangle().
  static long triangleArea(Point a, Point b, Point c) {
    return (-b.y*c.x + a.y*(-b.x + c.x) + a.x*(b.y - c.y) + b.x*c.y);
  }

  static boolean inIntSegment(Point c, Point a, Point b) {
    if (cross(a, b, c) != 0)
      return false;
    Point tmp = b.minus(a);
    long dotproduct = c.minus(a).dot(tmp);
    long squared_length = tmp.dot(tmp);
    if (dotproduct < 0 || dotproduct > squared_length)
      return false;
    return true;
  }

  static boolean inTriangle(Point p, Point a, Point b, Point c) {
    if (inIntSegment(p, a, b) || inIntSegment(p, b, c) || inIntSegment(p, a, c))
      return true;

    long area = triangleArea(a, b, c);
    if (area == 0)
      return false;
    double s = (double)(a.y*c.x - a.x*c.y + (c.y - a.y)*p.x + (a.x - c.x)*p.y) / area;
    if (s <= 0) {
      return false;
    }
    double t = (double)(a.x*b.y - a.y*b.x + (a.y - b.y)*p.x + (b.x - a.x)*p.y) / area;
    return t > 0 && 1-s-t > 0;
  }
}
