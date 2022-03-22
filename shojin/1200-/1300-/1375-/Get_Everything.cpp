#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[1<<13];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> co(m), t(m);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        co[i] = a;
        int x = 0;
        rep(j, b) {
            int y;
            cin >> y;
            y--;
            x |= (1<<y);
        }
        t[i] = x;
    }

    int n2 = (1<<n);
    rep(i, n2+1) dp[i] = (1<<30);
    dp[0] = 0;

    for(int bit=0; bit<n2; bit++) {
        for(int i=0; i<m; i++) {
            chmin(dp[bit|t[i]], dp[bit] + co[i]);
        }
    }
    int ans = dp[n2-1];
    if(ans == (1<<30)) ans = -1;
    cout << ans << endl;
    return 0;
}