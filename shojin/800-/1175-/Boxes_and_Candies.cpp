#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

// 先にkまで減らしてあとは貪欲
// a[i]とa[i+1]を見てa[i+1]を減らしていく

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll res = 0;
    rep(i, n) {
        cin >> a[i];
        if(a[i] > k) {
            res += a[i]-k;
            a[i] = k;
        }
    }

    rep(i, n-1) {
        if(a[i]+a[i+1] > k) {
            res += a[i]+a[i+1]-k;
            a[i+1] -= a[i]+a[i+1]-k;
        }
    }
    cout << res << endl;
}