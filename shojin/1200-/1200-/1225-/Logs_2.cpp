#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // 長さx以下にできるか？
    int l = 0, r = 1e9;
    while(r - l > 1) {
        int m = (l+r)/2;
        ll cnt = 0;
        // m以下の長さにするために何回切る必要があるか
        for(int i=0; i<n; i++) {
            cnt += (a[i]-1)/m;
        }
        if(cnt > k) l = m;
        else r = m;
    }
    cout << r << endl;
}