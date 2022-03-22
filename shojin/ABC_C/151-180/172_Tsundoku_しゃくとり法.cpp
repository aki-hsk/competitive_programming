#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    // n:Aの冊数, m:Bの冊数, k:所要時間の上限
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    ll t = 0;
    rep(i, m) t += b[i];
    int j = m;

    int ans = 0;

    rep(i, n+1) {
        while(j > 0 && t > k) {
            --j;
            t -= b[j];
        }
        if(t > k) break;
        chmax(ans, i+j);
        if(i == n) break;
        t += a[i];
    }
    cout << ans << endl;
    return 0;
}