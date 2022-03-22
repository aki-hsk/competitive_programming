#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

class Point {
    public:
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) {return Point(x+p.x, y+p.y);}
    Point operator - (Point p) {return Point(x-p.x, y-p.y);}
    Point operator * (double a) {return Point(a*x, a*y);}
    Point operator / (double a) {return Point(x/a, y/a);}

    double abs() {return sqrt(norm());}
    double norm() {return x*x+y*y;}

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

typedef Point Vector;
struct Segment{
    Point p1,p2;
    Segment(){}
    Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

double norm(Vector a){
    return a.x*a.x+a.y*a.y;
}
double abs(Vector a){
    return sqrt(norm(a));
}

// ベクトルの内積
double dot(Vector a, Vector b) {
    return a.x*b.x + a.y*b.y;
}

// ベクトルの外積
double cross(Vector a, Vector b) {
    return a.x*b.y - a.y*b.x;
}

// 直行判定
bool isOrthogonal(Vector a, Vector b) {
    return equals(dot(a, b), 0.0);
}

// 並行判定
bool isParallel(Vector a, Vector b) {
    return equals(cross(a, b), 0.0);
}

// 線分sに対する点pの射影
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base)/norm(base);
    return s.p1 + base*r;
}

// 反射
Point reflect(Segment s, Point p) {
    return p + (project(s, p)-p) * 2.0;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<Segment> h; // 横線

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            Point p1(x[i], y[i]);
            Point p2(x[j], y[j]);
            if(y[i] == y[j]) h.push_back({p1, p2});
        }
    }

    int ans = 0;
    for(int i=0; i<h.size(); i++) {
        for(int j=i+1; j<h.size(); j++) {
            if(h[i].p1.x == h[j].p1.x && h[i].p2.x == h[j].p2.x) ans++;
            else if(h[i].p1.x == h[j].p2.x && h[i].p2.x == h[j].p1.x) ans++;
        }
    }
    cout << ans << endl;

}