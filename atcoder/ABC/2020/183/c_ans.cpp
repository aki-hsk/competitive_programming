#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int n, k;
    cin >> n >> k;
    int t[8][8];
    rep(i, n) rep(j, n) cin >> t[i][j];
    vector<int> p;
    for(int i=1; i<n; i++) p.push_back(i);  // 1~n-1の値をpにいれる, t[i][j]の添字に合わせている

    int ans = 0;
    do {
        int tot = t[0][p[0]]; // 0~最初の地点
        // pの要素数はn-1
        // p[0]~p[n-2]までがpの要素全て
        rep(i, n-2) tot += t[p[i]][p[i+1]];
        tot += t[p.back()][0];//最後の地点から0まで
        if(tot == k) ans++;
    } while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}