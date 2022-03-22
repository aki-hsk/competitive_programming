#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// O(mlogm)


int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> hs(h), ws(w);
    map<pair<int, int>, bool> mp;
    for(int i=0; i<n; i++) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        hs[r]++;
        ws[c]++;
        mp[{r, c}] = true;
    }

    int mh = *max_element(hs.begin(), hs.end());
    int mw = *max_element(ws.begin(), ws.end());
    vector<int> is, js;
    for(int i=0; i<h; i++) if(mh == hs[i]) is.push_back(i);
    for(int j=0; j<w; j++) if(mw == ws[j]) js.push_back(j);
    int ans = mh+mw;
    // continueとなる回数はm回以下
    // mpのサイズは最大でもm個のため。
    for(int i:is) for(int j:js) {
        if(mp[{i, j}]) continue;
        cout << ans << endl;
        return 0;
    }
    cout << ans-1 << endl;
    return 0;
}