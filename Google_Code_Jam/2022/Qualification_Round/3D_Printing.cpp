#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(int num) {
    vector<vector<int>> c(3);
    rep(i, 3) {
        rep(j, 4) {
            int x;
            cin >> x;
            c[i].push_back(x);
        }
    }
    vector<int> ans(4, SINF);
    for(int j=0; j<4; j++) {
        rep(i, 3) {
            chmin(ans[j], c[i][j]);
        }
    }
    int sum = accumulate(ans.begin(), ans.end(), 0);
    cout << "Case #" << num << ": ";
    if(sum < 1000000) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int tot = 0;
    rep(j, 4) {
        if(tot + ans[j] <= 1000000) cout << ans[j];
        else cout << 1000000 - tot;
        cout << (j == 3 ? "\n" : " ");
        tot += min(1000000 - tot, ans[j]);
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve(i+1);
}