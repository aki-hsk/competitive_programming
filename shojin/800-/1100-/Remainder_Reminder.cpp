#include<iostream>
using namespace std;

// https://www.youtube.com/watch?v=QOsiad2iFdw

int main() {
    int n, k;
    cin >> n >> k;
    long long ans = 0;

    // bを固定して考える
    // a%bは以下のように周期的になる
    // 0,1, .. b-1, 0, 1, .. b-1, 0, 1, .. r
    // n/b個のsection             | n%b個
    for(int b=1; b<=n; b++) {
        int p = n/b;
        int r = n%b;
        ans += p * max(0, b-k) + max(0, r-k+1);
    }
    if(k == 0) ans -= n;
    cout << ans << endl;
}