#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Point{
    double x,y;
    Point(){}
    Point(double x,double y) :x(x),y(y){}
    Point operator + (Point p) {return Point(x+p.x,y+p.y);}
    Point operator - (Point p) {return Point(x-p.x,y-p.y);}
    Point operator * (double k) {return Point(x*k,y*k);}
    Point operator / (double k) {return Point(x/k,y/k);}
    double norm(){return x*x+y*y;}
    double abs(){return sqrt(norm());}

    bool operator < (const Point &p) const{
        return x!=p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const{
        return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};
typedef Point Vector;
typedef vector<Point> Polygon;

struct Segment{
    Point p1,p2;
    Segment(){}
    Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

struct Circle{
    Point c;
    double r;
    Circle(Point c,double r):c(c),r(r){}
};

double norm(Vector a){
    return a.x*a.x+a.y*a.y;
}
double abs(Vector a){
    return sqrt(norm(a));
}
double dot(Vector a,Vector b){
    return a.x*b.x+a.y*b.y;
}
double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

bool isOrthogonal(Vector a,Vector b){
    return equals(dot(a,b),0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
    return isOrthogonal(a1-a2,b1-b2);
}

bool isOrthogonal(Segment s1,Segment s2){
    return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

bool isParallel(Vector a,Vector b){
    return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
    return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2){
    return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

Point project(Segment s,Point p){
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}

Point reflect(Segment s,Point p){
    return p+(project(s,p)-p)*2.0;
}

int ccw(Point p0,Point p1,Point p2){
    Vector a = p1-p0;
    Vector b = p2-p0;
    if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a,b) < -EPS) return CLOCKWISE;
    if(dot(a,b) < -EPS) return ONLINE_BACK;
    if(a.norm()<b.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
    return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 &&
	    ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
}

bool intersect(Segment s1,Segment s2){
    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

double getDistanceLP(Line l,Point p){
    return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
    if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
    return getDistanceLP(s,p);
}

double getDistance(Segment s1,Segment s2){
    if(intersect(s1,s2)) return 0.0;
    return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
            min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

double getDistance(Point p0,Point p1,Point p2,Point p3){
    return getDistance(Segment(p0,p1),Segment(p2,p3));
}

Point getCrossPoint(Segment s1,Segment s2){
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}

Point getCrossPoint(Point p0,Point p1,Point p2,Point p3){
    return getCrossPoint(Segment(p0,p1),Segment(p2,p3));
}

pair<Point,Point> getCrossPoints(Circle c,Line l){
    Vector pr=project(l,c.c);
    Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    return make_pair(pr+e*base,pr-e*base);
}


double arg(Vector p){
    return atan2(p.y,p.x);
}

Vector polar(double a,double r){
    return Point(cos(r)*a,sin(r)*a);
}

pair<Point,Point> getCrossPoints(Circle c1,Circle c2){
    double d=abs(c1.c-c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t=arg(c2.c-c1.c);
    return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}


int main() {
    double ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int n;
    cin >> n;
    vector<pair<double, double>> v(n);
    Segment s0(Point(ax, ay), Point(bx, by));
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    vector<Segment> vs;
    for(int i=0; i<n; i++) {
        if(i != n-1) vs.push_back(Segment(Point(v[i].first, v[i].second), Point(v[i+1].first, v[i+1].second)));
        else vs.push_back(Segment(Point(v[i].first, v[i].second), Point(v[0].first, v[0].second)));
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(intersect(s0, vs[i])) cnt++;
    }
    cout << cnt/2 + 1 << endl;
}