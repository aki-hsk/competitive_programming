#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)


// max(min())
// 最小値の最大化 → 二分探索
int main() {
    int n;
    cin >> n;
    int m = 5;
    vector<vector<int>> a(n, vector<int> (m));
    rep(i, n) rep(j, m) cin >> a[i][j];
    int l = 0, r = 1001001001;
    while(r-l > 1) {
        int mid = (l+r)/2;
        vector<int> s;
        rep(i, n) {
            int x = 0;
            rep(j, m) {
                if(a[i][j] >= mid) x |= 1<<j;
            }
            s.push_back(x);
        }
        sort(s.begin(), s.end());
        // unique
        // 123334 → 1234●●
        // ゴミが入っている ゴミの先頭のイテレータを返す
        s.erase(unique(s.begin(), s.end()), s.end());
        // k < j < i
        bool ok = false;
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                for(int k=j; k<s.size(); k++) {
                    // 全て1111...であるかの判定
                    if((s[i]|s[j]|s[k]) == (1<<m)-1) ok = true;
                }
            }
        }
        if(ok) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}