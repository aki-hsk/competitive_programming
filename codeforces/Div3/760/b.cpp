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
    vector<string> v(n-2);
    rep(i, n-2) cin >> v[i];

    string res;
    res += v[0][0];

    bool ok = false;
    rep(i, n-3) {
        if(v[i].back() == v[i+1].front()) res.push_back(v[i].back());
        else {
            ok = true;
            res.push_back(v[i].back());
            res.push_back(v[i+1].front());
        }
    }
    res.push_back(v.back().back());
    if(!ok) res.push_back('a');
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}