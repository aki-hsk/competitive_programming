#include<iostream>
using namespace std;

int x[505][505], cnt[505][505];
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        x[l][r]++;
    }
    for(int i=0; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            // 横方向の累積和
            cnt[i][j] = cnt[i][j-1] + x[i][j];
        }
    }

    for(int k=0; k<q; k++) {
        int p, q;
        cin >> p >> q;
        long long ans = 0;
        for(int i=p; i<=q; i++) {
            // 横方向の累積和をy軸に沿って足し合わせる
            ans += cnt[i][q] - cnt[i][p-1];
        }
        cout << ans << endl;
    }
}