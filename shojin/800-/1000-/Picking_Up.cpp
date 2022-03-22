#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    sort(all(vp));
    map<pair<int, int>, int> mp;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int nx = vp[j].first - vp[i].first;
            int ny = vp[j].second - vp[i].second;
            mp[{nx, ny}]++;
        }
    }

    int ans = n, cnt = 0;
    for(auto m:mp) chmax(cnt, m.second);
    cout << ans - cnt << endl;
}