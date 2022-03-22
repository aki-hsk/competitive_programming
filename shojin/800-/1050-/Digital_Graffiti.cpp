#include<iostream>
#include<vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    for(int i=0; i<h; i++) cin >> board[i];

    int ans = 0;
    for(int i=0; i<h-1; i++) {
        for(int j=0; j<w-1; j++) {
            int cnt = 0;
            for(int dx=0; dx<2; dx++) {
                for(int dy=0; dy<2; dy++) {
                    if(board[i+dy][j+dx] == '#') cnt++;
                }
            }
            if(cnt == 1 || cnt == 3) ans++;
        }
    }
    cout << ans << endl;
}