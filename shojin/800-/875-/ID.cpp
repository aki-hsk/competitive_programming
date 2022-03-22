#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    vector<pair<int, int>> vp(m);
    rep(i, m) {
        int p, y;
        cin >> p >> y;
        p--;
        v[p].push_back(y);
        vp[i] = make_pair(p, y);
    }
    rep(i, n) sort(v[i].begin(), v[i].end());
    rep(i, m) {
        int P = vp[i].first + 1;
        int Y = lower_bound(v[vp[i].first].begin(), v[vp[i].first].end(), vp[i].second) - v[vp[i].first].begin() + 1;
        printf("%06d%06d\n", P, Y);
    }
}