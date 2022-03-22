#include<iostream>
#include<vector>
using namespace std;

int h, w;
vector<string> s;
int a[2005][2005];
int dp[2005][2005]; // dp[i][j] = (i, j)からスタートしたとき自分-相手の最大値
bool visited[2005][2005];

int f(int i, int j) {
    if(i == h-1 && j == w-1) return 0;
    if(visited[i][j]) return dp[i][j];
    visited[i][j] = true;
    int res = -(1<<30);
    if(j+1 < w) res = max(res, a[i][j+1]-f(i, j+1));
    if(i+1 < h) res = max(res, a[i+1][j]-f(i+1, j));
    return dp[i][j] = res;
}

int main() {
    cin >> h >> w;
    s.resize(h);
    for(int i=0; i<h; i++) cin >> s[i];
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) {
        a[i][j] = s[i][j] == '+' ? 1:-1;
    }
    int score = f(0, 0);
    if(score == 0) cout << "Draw" << endl;
    else if(score < 0) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
    return 0;
}