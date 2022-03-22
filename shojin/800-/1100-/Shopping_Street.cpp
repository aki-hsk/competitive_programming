#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 店が空いているかどうか
    long long f[n][10];
    for(int i=0; i<n; i++) {
        for(int j=0; j<10; j++) {
            cin >> f[i][j];
        }
    }
    // 利益
    long long p[n][11];
    for(int i=0; i<n; i++) {
        for(int j=0; j<11; j++) {
            cin >> p[i][j];
        }
    }

    long long ans = -(1LL<<60);
    for(int bit=1; bit<(1<<10); bit++) {
        // joisinoが店を開く営業時間
        long long res = 0;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<10; j++) {
                if((bit>>j&1) && f[i][j]) cnt++;
            }
            res += p[i][cnt];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}