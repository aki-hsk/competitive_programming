#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    double ans = 0;
    // 連結していない頂点に行く確率 (n-i)/n
    // 期待値はその逆数を足し合わせる
    for(int i=1; i<n; i++) {
        ans += (double)n/(n-i);
    }
    printf("%.20f", ans);
}