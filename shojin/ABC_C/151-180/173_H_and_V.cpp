#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int H, W, K;
    cin >> H >> W >> K;
    string board[H], t;

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 0;

    for(int is=0; is<1<<H; is++) {
        for(int js=0; js<1<<W; js++) {
            int count=0;
            for(int i=0; i<H; i++) {
                for(int j=0; j<W; j++) {
                    if(is>>i&1) continue;
                    if(js>>j&1) continue;
                    if(board[i][j] == '#') count++;
                }
            }
            if(count == K) ans++;
        }
    }
    cout << ans << endl;
}