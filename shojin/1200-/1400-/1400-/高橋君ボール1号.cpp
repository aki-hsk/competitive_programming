#include<iostream>
#include<cmath>
using namespace std;
const double pi = 3.14159265358979323846;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double lt = 0.0, rt = 200.0;
    while(rt - lt >= 1e-12) {
        double mid = (rt + lt)/2.0;
        double ft = a * mid + b * sin(c * mid * pi);
        if(ft > 100.0) rt = mid;
        else lt = mid;
    }
    printf("%.20f\n", lt);
    return 0;
}