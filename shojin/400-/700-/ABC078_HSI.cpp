#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=avazOGG7OfY

int main() {
    int N, M;
    cin >> N >> M;
    // 確率 p で成功するミッションを成功するまでトライし続けたとき、トライすることになる回数の期待値は 1/p である
    // x = 1900m + 100(n-m)
    // ans = x + (1-p)*ans
    cout << (1900 * M + (N-M) * 100) * pow(2, M) << endl;
}