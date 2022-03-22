#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    vector<ll> a(100005, 0), b(n), c(100005, 0);
    rep(i, n) {
        int x;
        cin >> x;
        a[x]++;
    }
    rep(i, n) cin >> b[i];
    rep(i, n) {
        int x;
        cin >> x;
        c[x]++;
    }

    ll res = 0;
    for(int i=0; i<n; i++) {
        res += a[b[i]] * c[i+1];
    }
    cout << res << endl;
}