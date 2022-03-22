#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace atcoder;
using namespace std;

const int MAX_A = 300005;

// https://youtu.be/D0Op33UL_cA?t=2149
// https://youtu.be/D0Op33UL_cA?t=3956

// オペレータ 二項演算　今回は最大を取るのでmax
int op(int a, int b) {return max(a, b);}
// 単位元
int e() { return 0; }

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    segtree<int, op, e> dp(MAX_A);
    for(int i=0; i<n; i++) {
        int x = a[i];
        int l = x-k, r = x+k+1;
        l = max(l, 0);
        r = min(r, MAX_A);
        int now = dp.prod(l, r) + 1;
        dp.set(x, max(dp.get(x), now));
    }
    int ans = dp.prod(0, MAX_A);
    cout << ans << endl;
    return 0;
}