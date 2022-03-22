#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> s(r);
    rep(i, r) cin >> s[i];

    vector<vector<int>> up(r, vector<int>(c));
    vector<vector<int>> down(r, vector<int>(c));

    for(int j=0; j<c; j++) {
        int cnt = 0;
        for(int i=0; i<r; i++) {
            if(s[i][j] == 'o') cnt++;
            else cnt = 0;
            up[i][j] = cnt;
        }
        cnt = 0;
        for(int i=r-1; i>=0; i--) {
            if(s[i][j] == 'o') cnt++;
            else cnt = 0;
            down[i][j] = cnt;
        }
    }

    int ans = 0;
    for(int i=k-1; i<=r-k; i++) {
        for(int j=k-1; j<=c-k; j++) {
            bool ok = true;
            for(int x=-(k-1); x<=k-1; x++) {
                if(up[i][j+x] < k-abs(x)) ok = false;
                if(down[i][j+x] < k-abs(x)) ok = false;
            }
            if(ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}