#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int N;
int x[10], y[10];

double dist(int i, int j) {
    double dx = x[i]-x[j];
    double dy = y[i]-y[j];
    return pow(dx * dx + dy * dy, 0.5);
}

int main() {
    cin >> N;
    rep(i, N) {
        cin >> x[i] >> y[i];
    }

    double ans = 0.0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            ans += dist(i, j) * 2 / N;
        }
    }
    printf("%.10f\n", ans);
}
