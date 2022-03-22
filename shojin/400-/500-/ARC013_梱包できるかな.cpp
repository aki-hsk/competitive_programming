#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    vector<int> a(3), b(3);
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];
    sort(all(b));
    ll ans = 0;
    do {
        ll v = 1;
        rep(i, 3) v *= a[i]/b[i];
        chmax(ans, v);
    } while(next_permutation(all(b)));

    cout << ans << endl;
}
