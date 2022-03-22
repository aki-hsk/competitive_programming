#include<bits/stdc++.h>
using namespace std;

int main() {
    // &変数で変数のアドレスを得る
    // 型 *ポインタでポインタを定義
    // *ポインタでポインタの指すメモリ領域へのアクセス

    int x = 1;
    int *p; // ポインタを定義
    p = &x; // xのアドレスをpに代入
    *p = 2; // ポインタpの指す値を2にする
    cout << x << endl;

    int y
    y = *p; // yの値をポインタpが指す値にする
    cout << y << endl;
}