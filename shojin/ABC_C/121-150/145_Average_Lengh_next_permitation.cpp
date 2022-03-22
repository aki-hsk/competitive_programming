#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int N;
    cin >> N;
    vector<double> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    vector<int> t(N);
    rep(i, N) t[i] = i;
    double ans = 0;
    int cnt = 0;
    do {
        rep(i, N-1) ans += pow(pow(x[t[i]]-x[t[i+1]], 2) + pow(y[t[i]]-y[t[i+1]], 2), 0.5);
        cnt++;
    } while(next_permutation(t.begin(), t.end()));
 
    printf("%.10f\n", ans/cnt);
    return 0;
}