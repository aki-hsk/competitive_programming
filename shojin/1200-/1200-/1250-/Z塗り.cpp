#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> board(n);
    for(int i=0; i<n; i++) cin >> board[i];

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=n-1; j>=0; j--) {
            if(board[i][j] == '.') {
                ans++;
                for(int x=0; x<=j; x++) board[i][x] = 'o';
                if(i+1 < n) for(int x=j; x<n; x++) board[i+1][x] = 'o';
            }
        }
    }
    cout << ans << endl;
    return 0;
}