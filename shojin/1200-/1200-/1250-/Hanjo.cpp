#include<iostream>
#include<vector>
using namespace std;

int h, w;
bool used[16][16];

int dfs(int i, int j, int a, int b) {
    if(a < 0 || b < 0) return 0;
    if(j == w) j = 0, i++;
    if(i == h) return 1;
    // ここは returnで呼ぶ　returnでないと単に戻り値がここに返ってきて終わるだけ。
    if(used[i][j]) return dfs(i, j+1, a, b);
    used[i][j] = true;
    int res = 0;
    // 1✖️1のマスを使う
    res += dfs(i, j+1, a, b-1);

    // 横に並べる
    if(j+1 < w && !used[i][j+1]) {
        used[i][j+1] = true;
        res += dfs(i, j+1, a-1, b);
        used[i][j+1] = false;
    }

    // 縦に並べる
    if(i+1 < h && !used[i+1][j]) {
        used[i+1][j] = true;
        res += dfs(i, j+1, a-1, b);
        used[i+1][j] = false;
    }
    used[i][j] = false;
    return res;
}

int main() {
    cin >> h >> w;
    int a, b;
    cin >> a >> b;
    // 今どのますにいるかと畳の枚数
    cout << dfs(0, 0, a, b) << endl;
    return 0;
}