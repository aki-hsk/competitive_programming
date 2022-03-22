#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const int SINF = 1LL << 29;

int main() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    const int M = 10005;
    vector<int> dp(M, SINF);
    dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<h; j++) {
            int nj = min(j+a[i], h);
            dp[nj] = min(dp[nj], dp[j] + b[i]);
        }
    }
    cout << dp[h] << endl;
    return 0;
}