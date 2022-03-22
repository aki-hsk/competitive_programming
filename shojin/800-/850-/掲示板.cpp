#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define aint(v) v.begin(), v.end()

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp;
    rep(i, n) vp.push_back({0, i+1});
    rep(i, m) {
        int a;
        cin >> a;
        a--;
        vp[a].first = (i+1);
    }

    // pairのソート
    // firstは降順, secondは昇順
    sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) { if(a.first != b.first) { return a.first > b.first;} return a.second < b.second;});
    rep(i, n) cout << vp[i].second << endl;
    return 0;
}