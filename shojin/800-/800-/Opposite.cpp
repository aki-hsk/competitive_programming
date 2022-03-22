#include<iostream>
#include<cmath>
using namespace std;

// cx, cyを中心として x, yをrad回転する
pair<double, double> rot(double cx, double cy, double x, double y, double rad) {
    // 原点にずらしてから計算をした後に元の座標(cx, cy)分を足す
    double rx = (x-cx)*cos(rad)-(y-cy)*sin(rad) + cx;
    double ry = (x-cx)*sin(rad)+(y-cy)*cos(rad) + cy;
    return make_pair(rx, ry);
}

int main() {
    int n;
    double x, y, X, Y, pi = 3.14159265358979323846;
    cin >> n >> x >> y >> X >> Y;
    double cx = (x + X)/2, cy = (y + Y)/2;
    pair<double, double> C = rot(cx, cy, x, y, 2*pi/n);
    printf("%.20f %.20f\n", C.first, C.second);
}