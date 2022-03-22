#include<iostream>
#include<vector>
using namespace std;

// 上限はスター型のグラフ
// 下限は完全グラフ

int main() {
    int n, k;
    cin >> n >> k;
    int mx = (n-1) * (n-2) / 2;
    if(mx < k) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> ans;
    // 頂点nを中心にする
    for(int i=0; i<n-1; i++) {
        ans.push_back({i+1, n});
    }
    int add = mx - k;
    vector<pair<int, int>> edge;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n-1; j++) {
            edge.push_back({i+1, j+1});
        }
    }
    for(int i=0; i<add; i++) ans.push_back(edge[i]);
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}