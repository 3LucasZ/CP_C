#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end()

template <typename T>
struct point {
    T x, y;
    point() {}
    point(T x, T y): x(x), y(y) {}
    point& operator+=(const point &other) {
        x += other.x; y += other.y;
        return *this;
    }
    point& operator-=(const point &other) {
        x -= other.x; y -= other.y;
        return *this;
    }
    point& operator*=(T other) {
        x *= other; y *= other;
        return *this;
    }
    point& operator/=(T other) {
        x /= other; y /= other;
        return *this;
    }
    point operator+(const point &other) const {
        return point(*this) += other;
    }
    point operator-(const point &other) const {
        return point(*this) -= other;
    }
    point operator*(T other) const {
        return point(*this) *= other;
    }
    point operator/(T other) const {
        return point(*this) /= other;
    }
};
template <typename T>
string to_string(point<T> p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}
template <typename T>
point<T> operator*(T a, point<T> b) {
    return b * a;
}
template <typename T>
T dot(point<T> a, point<T> b) {
    return a.x * b.x + a.y * b.y;
}
template <typename T>
T norm(point<T> a) {
    return dot(a, a);
}
template <typename T>
T cross(point<T> a, point<T> b) {
    return a.x * b.y - a.y * b.x;
}
template <typename T>
int orientation(point<T> p1, point<T> p2, point<T> p3) {
    T det = cross(p2 - p1, p3 - p2);
    return (det > 0) - (det < 0);
}
template <typename T>
bool onSegment(point<T> p, point<T> q, point<T> r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}
template <typename T>
bool intersecting(point<T> p1, point<T> q1, point<T> p2, point<T> q2) {
    int o1 = orientation(p1, q1, p2); int o2 = orientation(p1, q1, q2); int o3 = orientation(p2, q2, p1); int o4 = orientation(p2, q2, q1);
    dbg(o1,o2,o3,o4);
    if ((o1 == 0 && onSegment(p1, p2, q1)) || (o2 == 0 && onSegment(p1, q2, q1)) || (o3 == 0 && onSegment(p2, p1, q2)) || (o4 == 0 && onSegment(p2, q1, q2))) return true; 
    return o1 != o2 && o3 != o4;
}
template <typename T>
point<T> intersection(point<T> a1, point<T> d1, point<T> a2, point<T> d2) {
    d1 -= a1; d2 -= a2;
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
template <typename T>
T area2(vector<point<T>> points) {
    T ret = 0;
    for (int i=0;i<points.size();i++) ret += cross(points[i],points[(i+1)%points.size()]);
    return abs(ret);
}

int N;
vector<point<ld>> points;

void solve() {
    int N; cin >> N;
    points.clear();
    for (int i=0;i<N;i++){
        ld x, y; cin >> x >> y;
        points.push_back({x,y});
    }
    //total area
    double totalArea = area2(points);
    dbg(totalArea);
    //re-index the polygon: 1 ... N
    points.push_back({points[0].x, points[0].y});
    //shift the polygon so the camera is at 0,0
    point shift = (points[0]+points[1])/2;
    for (int i=1;i<=N;i++){
        points[i] = points[i] - shift;
    }
    dbg(points);
    
    //excluded area
    ld excludedArea = 0;
    for (int flip=0;flip<2;flip++){
        dbg("RUN");
        point camr = {points[1].x - points[1].y, points[1].x + points[1].y}; //infinitely long camera right ray
        camr *= 50000;
        dbg(camr);
        for (int i=1;i<N;i++){
            dbg("check:",i,i+1,points[i],points[i+1]);
            if (intersecting({0,0},camr,points[i],points[i+1])) {
                point inter = intersection({0,0},camr,points[i],points[i+1]);
                excludedArea += cross(points[i], inter);
                dbg("intersection", inter);
                dbg(excludedArea);
                break;
            }
            excludedArea += cross(points[i], points[i+1]);
            dbg(excludedArea);
        }
        //change the order of the points
        for (int i=1;i<=N/2;i++) {
            int j = N+1-i;
            point tmp = points[i];
            points[i] = points[j];
            points[j] = tmp;
        }
        //flip the points across y
        for (int i=1;i<=N;i++){
            points[i].y*=-1;
        }
    }

    cout << (totalArea-excludedArea)/totalArea << nl;
}

int main() {
    int T; cin >> T;
    for (int i=0;i<T;i++){
        dbg("CASE",i);
        solve();
    }
}