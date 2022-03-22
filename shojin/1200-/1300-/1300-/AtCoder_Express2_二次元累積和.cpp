#include<iostream>
using namespace std;


// アルゴリズムビジュアル大辞典
// https://qiita.com/drken/items/56a6b68edef8fc605821#4-%E4%BA%8C%E6%AC%A1%E5%85%83%E7%B4%AF%E7%A9%8D%E5%92%8C
// https://www.youtube.com/watch?v=OdJH-io-sVw

int cnt[505][505];
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l][r]++;
    }
    // 横方向のスキャン
    for(int i=0; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cnt[i][j] += cnt[i][j-1];
        }
    }
    // 縦方向のスキャン
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            cnt[i][j] += cnt[i-1][j];
        }
    }

    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<=n; j++) {
    //         cout << cnt[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 二次元平面上の累積和(q, q)の値のみが欲しい
    for(int k=0; k<q; k++) {
        int p, q;
        cin >> p >> q;
        cout << cnt[q][q] + cnt[p-1][p-1] - cnt[p-1][q] - cnt[q][p-1] << endl;
    }
}