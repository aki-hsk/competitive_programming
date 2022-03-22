#include <bits/stdc++.h>
using namespace std;

// 戻り値に答えをいれる
int solve(int x, int y) {
    if(x == 0 && y == 0) return 0;
    if(x + y == 0) return 1;
    if(x - y == 0) return 1;
    if(abs(x) + abs(y) <= 3) return 1;
    if((x+y)%2 == 0) return 2;
    if(abs(x) + abs(y) <= 6) return 2;
    // 斜め移動した後にマンハッタン
    if(abs(x+y) <= 3) return 2;
    if(abs(x-y) <= 3) return 2;
    return 3;
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // x1, y1を原点に持っていく
    cout << solve(x2-x1, y2-y1) << endl;
    return 0;
}