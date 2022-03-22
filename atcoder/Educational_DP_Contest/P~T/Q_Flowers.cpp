#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

// 解説: https://qiita.com/drken/items/68b8503ad4ffb469624c#4-lis-%E3%81%AE%E8%A7%A3%E6%B3%952-%E3%82%BB%E3%82%B0%E6%9C%A8-ver

long long op(long long x, long long y) { return max(x, y); }
long long e() { return 0; }

int main() {
    int n;
    cin >> n;
    vector<long long> h(n), a(n);
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n; i++) cin >> a[i];

    segtree<long long, op, e> dp(n+1);

    long long res = 0;
    for(int i=0; i<n; i++) {
        long long A = dp.prod(0, h[i]);

        if(dp.prod(h[i], h[i]+1) < A + a[i]) {
            dp.set(h[i], A + a[i]);
            res = max(res, A + a[i]);
        }
    }
    cout << res << endl;
}