#include <bits/stdc++.h>
using namespace std;

// 戻り値に答えをいれる
int solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 && y1 == y2) return 0;
    if(x1 + y1 == x2 + y2) return 1;
    if(x1 - y1 == x2 - y2) return 1;
    if(abs(x1-x2) + abs(y1-y2) <= 3) return 1;
    if((x1 + y1) % 2 == (x2 + y2) % 2) return 2;
    if(abs(x1-x2) + abs(y1-y2) <= 6) return 2;
    // 斜め移動した後にマンハッタン
    if(abs((x1+y1) - (x2+y2)) <= 3) return 2;
    if(abs((x1-y1) - (x2-y2)) <= 3) return 2;
    return 3;
}

int main() {
    cout << solve() << endl;
    return 0;
}