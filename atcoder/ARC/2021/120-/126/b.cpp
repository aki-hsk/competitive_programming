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

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> used_a(n+1), used_b(n+1);
    vector<pair<int, int>> vp(m);
    rep(i, m) {
        cin >> vp[i].first >> vp[i].second;
    }
    sort(all(vp));
    ll ans = 0;
    ll cnt = 0;
    int right = -1;
    rep(i, m) {
        if(vp[i].first > vp[i].second) continue;
        if(vp[i].second <= right) continue;
        else {
            right = vp[i].second;
            cnt++;
        }
    }

    int left = n+1;
    rep(i, m) {
        if(left <= right) break;
        if(vp[i].first < vp[i].second) continue;
        if(vp[i].second <= right) continue;
        if(vp[i].second >= left) continue;
        else {
            left = vp[i].second;
            cnt++;
        }
    }
    cout << cnt << endl;
}