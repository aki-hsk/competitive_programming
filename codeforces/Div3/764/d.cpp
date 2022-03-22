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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ex = 0, p = 0;
    vector<int> v(26);
    rep(i, n) v[s[i]-'a']++;
    rep(i, 26) {
        p += v[i] / 2;
        ex += v[i] % 2;
    }
    cout << p / k * 2 + min(1, (p % k * 2 + ex) / k) << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}
