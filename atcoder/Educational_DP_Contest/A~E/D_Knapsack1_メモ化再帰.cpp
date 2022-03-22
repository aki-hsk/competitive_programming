#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[105][100005];
int n, W;
vector<int> w, v;

ll rec(int m, int x) {
    if(m == 0) return 0;
    if(dp[m][x]) return dp[m][x];
    ll res = 0;
    chmax(res, rec(m-1, x));
    if(x-w[m-1] >= 0) chmax(res, rec(m-1, x-w[m-1]) + v[m-1]);
    return dp[m][x] = res;
}

int main() {
    cin >> n >> W;
    w.resize(n);
    v.resize(n);
    rep(i, n) cin >> w[i] >> v[i];
    cout << rec(n, W) << endl;
}