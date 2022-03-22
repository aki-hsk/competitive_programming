#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    int ans = 0;
    rep(i,h) cin >> s[i];
    // 1<<3 = 1000 = 2の3乗
    //isには行のどれを選ぶか, jsには列のどれを選ぶかの情報が入っている。
    //このループはどこを赤い色に染めたか
    rep(is, 1 << h)rep(js, 1 << w) {
        int cnt = 0;
        rep(i, h)rep(j, w) {
            //2進数のiケタ目を取り出す
            //行が消されているならcontinue
            if(is>>i&1) continue;
            //列が消されているならcontinue
            if(js>>j&1) continue;
            //黒マスならばカウントを増やす
            if(s[i][j] == '#') cnt++;
        }
        if(cnt ==k) ans++;
    }
    cout << ans << endl;
    return 0;
}