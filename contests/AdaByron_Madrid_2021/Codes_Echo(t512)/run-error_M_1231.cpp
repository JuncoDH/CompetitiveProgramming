#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <set>

#define pb push_back
#define fi first
#define se second
using namespace std;

using vi = vector<int>;
using ll = unsigned long long;
using pi = pair<int,int>;
template<typename T>
class Point{
public:
    static const int LEFT_TURN =1;
    static const int RIGHT_TURN = -1;
    T x=0, y=0;
    Point()=default;
    Point(T _x, T _y){
        x=_x;
        y=_y;
    }
    bool operator == (const Point<T> other) const{
        return x == other.x && y == other.y;
    }
    bool operator < (const Point<T> other)const{
        if(y!= other.y)return y<other.y;
        return x<other.x;
    }
    T euclidean_distance (Point<T> other){
        T dx = x -other.x;
        T dy = y- other.y;
        return sqrt(dx*dx+ dy*dy);
    }
    T euclidean_distance_squared(Point<T> other){
        T dx = x-other.x;
        T dy = y-other.y;
        return dx*dx +dy*dy;
    }
    int get_quadrant(){
        if(x>0 && y >=0) return 1;
        if(x<=0 && y >0) return 2;
        if(x<0 && y <=0) return 3;
        if(x>=0 && y <0) return 4;
        return 0;
    }
    int get_relative_quadrant(Point<T> other){
        Point <T> p(other.x -y, other.y-y);
        return p.get_quadrant();
    }
    int get_orientation (Point<T> a, Point<T> b){
        T prod = (a.x -x)*(b.y-a.y)-(a.y<y)*(b.x-a.x);
        if(prod==0){
            return 0;
        }
        return prod>0? LEFT_TURN: RIGHT_TURN;
    }

    bool angle_cmp(Point<T> a, Point<T> b){
        if(get_relative_quadrant(a)!= get_relative_quadrant(b)){
            return get_relative_quadrant(a)<get_relative_quadrant(b);
        }
        int ori = get_orientation(a,b);
        if(ori == 0)return euclidean_distance_squared(a)<euclidean_distance_squared(b);
        return ori == LEFT_TURN;
    }
    void polar_sort(vector<Point<T>> & v){
        sort(v.begin(),v.end(), [&](Point<T> a, Point<T> b){
            return angle_cmp(a,b);
        });
    }
    static void convert_convex_hull(vector<Point<T>> &v){
        if(v.size()<3)return;
        Point<T> bottom_left = v[0],p2;
        for(auto p:v) bottom_left=min(bottom_left,p);
        bottom_left.polar_sort(v);
        vector<Point<T>> v_input = v; v.clear();
        for(auto p: v_input){
            while(v.size()>=2){
                p2 = v.back(); v.pop_back();
                if(v.back().get_orientation(p2,p)==LEFT_TURN){
                    v.pb(p2);
                    break;
                }
            }
            v.pb(p);
        }
    }
};

int main() {
    int t;
    cin>>t;
    int z=0;
    while(t--){
        int n;
        cin>>n;
        vector<Point<int>> list;
        int a,b;
        double d,dd;
        for(int i=0;i<n;++i){
            cin>>d>>dd;
            a=d*100;
            b=dd*100;
            list.pb(Point<int>(a,b));
        }
        auto rem = list;
        int iter=0;
        while(!rem.empty()){
            auto rem2=rem;
            Point<int>::convert_convex_hull(rem2);
            set<Point<int>> points;
            for(auto a:rem){
                points.insert(a);
            }
            for(auto a:rem2){
                points.erase(a);
            }
            rem.clear();
            for(auto a:points){
                rem.pb(a);
            }
            iter++;
        }
        cout<<"Caso #"<<++z<<": "<<iter-2<<"\n";

    }

    return 0;
}
