#include<iostream>
#include<cmath>
using namespace std;
const double pi = 3.14159265358979323846;

double dist(double x, double y) {
  return pow(x*x + y*y, 0.5);
}

int main() {
  double t, l, x, y;
  cin >> t >> l >> x >> y;
  int q;
  cin >> q;
  for(int qi=0; qi<q; qi++) {
    int e;
    cin >> e;
    double py = -(l/2) * sin(2*e*pi/t);
    double pz = l/2 - (l/2)*cos(2*e*pi/t);
    double bottom = dist(x, abs(py-y));
    double height = pz;
    double ans = atan(height/bottom) * 180 / pi;
    printf("%.20f\n", ans);
  }
}