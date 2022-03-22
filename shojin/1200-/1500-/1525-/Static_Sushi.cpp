#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    long long C;
    cin >> n >> C;
    vector<long long> x(n+2), v(n+2), a(n+2), b(n+2);
    for(int i=1; i<=n; i++) cin >> x[i] >> v[i];

    // 時計回り
    for(int i=1; i<=n; i++) {
        a[i] = a[i-1] + v[i] - (x[i] - x[i-1]);
    }
    x[n+1] = C;
    // 反時計回り
    for(int i=n; i>=1; i--) {
        b[i] = b[i+1] + v[i] - (x[i+1] - x[i]);
    }
    for(int i=2; i<=n; i++) a[i] = max(a[i-1], a[i]);
    for(int i=n-1; i>=1; i--) b[i] = max(b[i], b[i+1]);

    long long ans = 0;
    for(int i=1; i<=n; i++) {
        ans = max(ans, a[i] - x[i] + b[i+1]);           // 時計回り -> 反時計回り
        ans = max(ans, b[i] - (C - x[i]) + a[i-1]);     // 反時計回り -> 時計回り
        ans = max(ans, a[i]);
        ans = max(ans, b[i]);
    }
    printf("%lld\n", ans);
    return 0;
}