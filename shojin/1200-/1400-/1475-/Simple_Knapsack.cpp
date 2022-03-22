#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, W;
vector<vector<long long>> a;
int dp[101][101][101][101];

long long rec(int i0, int i1, int i2, int i3, long long weight, int& w0) {
    if(i0==a[0].size() && i1==a[1].size() && i2==a[2].size() && i3==a[3].size()) return 0;
    if(dp[i0][i1][i2][i3]) return dp[i0][i1][i2][i3];

    long long res = 0;
    if(i0 < a[0].size() && weight + w0 <= W) res = max(res, rec(i0+1, i1, i2, i3, weight + 0 + w0, w0) + a[0][i0]);
    if(i1 < a[1].size() && weight + w0 + 1 <= W) res = max(res, rec(i0, i1+1, i2, i3, weight + 1 + w0, w0) + a[1][i1]);
    if(i2 < a[2].size() && weight + w0 + 2 <= W) res = max(res, rec(i0, i1, i2+1, i3, weight + 2 + w0, w0) + a[2][i2]);
    if(i3 < a[3].size() && weight + w0 + 3 <= W) res = max(res, rec(i0, i1, i2, i3+1, weight + 3 + w0, w0) + a[3][i3]);
    return dp[i0][i1][i2][i3] = res;
}

int main() {
    cin >> n >> W;
    vector<long long> w(n), v(n);
    for(int i=0; i<n; i++) cin >> w[i] >> v[i];

    int w0 = w[0];
    a.resize(4);
    for(int i=0; i<n; i++) {
        a[w[i]-w0].push_back(v[i]);
    }
    for(int i=0; i<4; i++) {
        sort(a[i].rbegin(), a[i].rend());
    }
    cout << rec(0, 0, 0, 0, 0, w0) << endl;
    return 0;
}