#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using mint = modint998244353;

mint dp[3005][3005];

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    dp[0][0] = 1;
}