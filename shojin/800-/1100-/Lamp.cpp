#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int num1[2005][2005];
int num2[2005][2005];
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    rep(i, h) cin >> board[i];

    int cnt = 0, pre = 0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] == '.') cnt++;
            if(board[i][j] == '#') {
                for(int k=pre; k<j; k++) num1[i][k] = cnt;
                cnt = 0;
                pre = j+1;
            }
        }
        for(int k=pre; k<w; k++) num1[i][k] = cnt;
        cnt = pre = 0;
    }

    for(int j=0; j<w; j++) {
        for(int i=0; i<h; i++) {
            if(board[i][j] == '.') cnt++;
            if(board[i][j] == '#') {
                for(int k=pre; k<i; k++) num2[k][j] = cnt;
                cnt = 0;
                pre = i+1;
            }
        }
        for(int k=pre; k<h; k++) num2[k][j] += cnt;
        cnt = pre = 0;
    }

    int res = 0;
    rep(i, h) rep(j, w) chmax(res, num1[i][j] + num2[i][j] - 1);
    cout << res << endl;
}