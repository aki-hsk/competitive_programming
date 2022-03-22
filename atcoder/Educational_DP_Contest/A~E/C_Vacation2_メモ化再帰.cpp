#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int n;
int dp[4][100005];
vector<int> a, b, c;

int rec(int act, int d) {
    if(d == 0) return 0;
    if(dp[act][d] != 0) return dp[act][d];
    int res = 0;
    rep(x, 3) {
        if(act == x) continue;
        if(x == 0) chmax(res, rec(0, d-1) + a[d-1]);
        if(x == 1) chmax(res, rec(1, d-1) + b[d-1]);
        if(x == 2) chmax(res, rec(2, d-1) + c[d-1]);
    }
    return dp[act][d] = res;
}

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    cout << rec(3, n) << endl;
}