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
    ll n, k;
    cin >> n >> k;
    int odd = 1, even = 2;
    vector<vector<ll>> ans(n, vector<ll>(k));
    bool ok = true;
    rep(i, n) {
        rep(j, k) {
            if(i % 2 == 0) {
                if(odd > n*k) ok = false;
                ans[i][j] = odd;
                odd += 2;
            }
            else {
                if(even > n*k) ok = false;
                ans[i][j] = even;
                even += 2;
            }
        }
    }
    if(!ok) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    rep(i, n) {
        rep(j, k) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}