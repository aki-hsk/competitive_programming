#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    if(a[n-2] > a[n-1]) {
        cout << -1 << endl;
    }
    else {
        if(a[n-1] < 0) {
            if(is_sorted(a.begin(), a.end())) {
                cout << 0 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            cout << n-2 << endl;
            for(int i=1; i<=n-2; i++) {
                printf("%d %d %d\n", i, n-1, n);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}
