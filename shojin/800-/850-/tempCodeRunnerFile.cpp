#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using mint = modint998244353;

// dp[i][j] := i番目まででC[i]がjの時の選び方の場合の数
mint dp[3005][3005];
const int M = 3003;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    dp[0][0] = 1;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<M; j++) dp[i][j+1] += dp[i][j];
        if(i != n) {
            for(int j=a[i]; j<=b[i]; j++) dp[i+1][j] += dp[i][j];
        }
    }
    cout << dp[n][M].val() << endl;
}