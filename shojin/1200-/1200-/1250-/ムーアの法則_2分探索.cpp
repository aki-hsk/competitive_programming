#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double p;
    cin >> p;
    double left = 0, right = 100.0;
    // mid年経った状態でスタートしてP年以内に終わるか？
    while(right - left > 1e-10) {
        // Δx右にずれた時に増加しているor減少している
        double mid = (right + left) / 2.0;
        double t = mid + p / pow(2, mid/1.5);
        double rmid = mid + 1e-10;
        double rt = rmid + p / pow(2, rmid/ 1.5);

        if(rt <= t) left = mid;
        else right = mid;
    }
    double ans = left + p / pow(2, left/1.5);
    printf("%.20f\n", ans);
    return 0;
}