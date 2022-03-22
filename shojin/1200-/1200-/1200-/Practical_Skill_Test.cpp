#include<iostream>
#include<vector>
#include<map>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    map<int, pair<int, int>> mp;
    rep(i, h) {
        rep(j, w) {
            int a;
            cin >> a;
            mp[a] = {i, j};
        }
    }

    vector<int> cost(h*w+1);
    for(int i=d+1; i<=h*w; i++) {
        cost[i] = cost[i-d]+abs(mp[i].first-mp[i-d].first) + abs(mp[i].second-mp[i-d].second);
    }

    int q;
    cin >> q;
    rep(k, q) {
        int l, r;
        cin >> l >> r;
        cout << cost[r]-cost[l] << endl;
    }
}