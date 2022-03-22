#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int g[15][15];

int main() {
    int N;
    cin >> N;
    rep(i, N) rep(j, N) g[i][j] = -1;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            x--;
            g[i][x] = y;
        }
    }

    int ans = 0;
    for(int bit=0; bit<(1<<N); bit++) {
        vector<int> d(N, 0);
        bool flg = true;
        for(int i=0; i<N; i++) {
            if((bit>>i)&1) {
                d[i] = 1;
            }
        }
        for(int i=0; i<N; i++) {
            if(d[i]) {
                for(int j=0; j<N; j++) {
                    if(g[i][j] == -1) continue;
                    if(g[i][j] != d[j]) {
                        flg = false;
                        break;
                    }
                }
            }
        }
        // __builtin_popcount() 1の数を調べる
        if(flg) chmax(ans, __builtin_popcount(bit));
    }
    cout << ans << endl;
}
