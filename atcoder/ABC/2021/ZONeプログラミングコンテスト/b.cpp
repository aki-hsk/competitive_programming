#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    double N, D, H;
    cin >> N >> D >> H;
    double y = 0;
    rep(i, N) {
        int d, h;
        cin >> d >> h;
        double dy = (D*h-d*H) / (D-d);
        chmax(y, dy);
    }
    printf("%.10f\n", y);
}