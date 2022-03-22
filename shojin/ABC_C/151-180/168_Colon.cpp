#include <bits/stdc++.h>
using namespace std;

int main() {
    const double PI=3.14159265358979323846;
    double A, B, H, M;
    cin >> A >> B >> H >> M;
    double m = M / 60;
    double h = H / 12 + M / 720;
    double rad = (m - h) * 2 * PI;
    printf("%.20f\n",pow(A * A + B * B - 2 * A * B * cos(rad), 0.5));
}