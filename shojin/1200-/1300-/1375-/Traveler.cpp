#include<iostream>
#include<vector>
using namespace std;
const int SINF = (1<<30);
const long long INF = (1LL<<60);

int main() {
    int n;
    cin >> n;
    vector<int> l(n, SINF), r(n, -SINF);
    for(int i=0; i<n; i++) {
        int x, c;
        cin >> x >> c;
        --c;
        l[c] = min(l[c], x);
        r[c] = max(r[c], x);
    }
    vector<pair<int, int>> d;
    d.push_back({0, 0});
    for(int i=0; i<n; i++) {
        if(l[i] != SINF) d.push_back({l[i], r[i]});
    }
    d.push_back({0, 0});
    // dp[j] := 左端or右端で終わるか
    vector<long long> dp(2);
    for(int i=1; i<d.size(); i++) {
        // p:dp[i]
        // dp:dp[i+1]
        vector<long long> p(2, INF);
        swap(p, dp);
        int lx = d[i].first, rx = d[i].second;
        for(int j=0; j<2; j++) {
            // 一つ前のdpが終わった時点でいる座標
            int x = j ? d[i-1].second : d[i-1].first;
            dp[0] = min(dp[0], p[j] + abs(x-rx) + (rx-lx));
            dp[1] = min(dp[1], p[j] + abs(x-lx) + (rx-lx));
        }
    }
    cout << dp[0] << endl;
    return 0;
}