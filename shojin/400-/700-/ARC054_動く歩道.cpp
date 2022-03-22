#include <bits/stdc++.h>
using namespace std;

int main() {
    // L:周長, X: 床が１秒間に進む, Y: 歩く速度, S: 初期位置, D: 出口の位置
    double L, X, Y, S, D;
    cin >> L >> X >> Y >> S >> D;

    if(S <= D) {
        double t1 = (D-S)/(X+Y);
        if(Y > X) chmin(t1, (L-D+S)/(Y-X));
        printf("%10.10f\n", t1);
    }
    else {
        double t1 = (L-S+D)/(X+Y);
        if(Y > X) chmin(t1, (S-D)/(Y-X));
        printf("%10.10f\n", t1);
    }
}