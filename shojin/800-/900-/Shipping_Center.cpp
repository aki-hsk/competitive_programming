#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    // 荷物の重さと価値
    vector<pair<int, int>> vp(n);
    for(int i=0; i<n; i++) {
        int w, v;
        cin >> w >> v;
        vp[i] = make_pair(v, w);
    }

    // valueを降順にソート
    sort(vp.rbegin(), vp.rend());

    // 箱
    vector<int> x(m);
    for(int i=0; i<m; i++) cin >> x[i];

    for(int i=0; i<q; i++) {
        int r, l;
        cin >> l >> r;
        r--; l--;

        int ans = 0;
        vector<int> y;
        for(int v=0; v<m; v++) {
            if(v >= l && v <= r) continue;
            y.push_back(x[v]);
        }
        sort(y.begin(), y.end());
        // 荷物
        for(int j=0; j<n; j++) {
            // 箱
            for(int k=0; k<y.size(); k++) {
                if(y[k] >= vp[j].second) {
                    ans += vp[j].first;
                    y[k] = -1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}