#include<iostream>
#include<vector>
using namespace std;

// DAG (Directed Acyclic Graph, 閉路を含まない有向グラフ)
// DAGとDPは相性が良いよ!!
// https://www.youtube.com/watch?v=HolLfo49Pow

// dp[v] := どこかで買って1本以上辿って今vにいる時の支出の最小

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    vector<vector<int>> to(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }

    const long long INF = (1LL<<60);
    vector<long long> dp(n, INF);
    long long ans = -INF;

    for(int i=0; i<n; i++) {
        ans = max(ans, x[i]-dp[i]);
        for(int j : to[i]) {
            dp[j] = min(dp[j], dp[i]);
            dp[j] = min(dp[j], x[i]);
        }
    }
    cout << ans << endl;
    return 0;
}