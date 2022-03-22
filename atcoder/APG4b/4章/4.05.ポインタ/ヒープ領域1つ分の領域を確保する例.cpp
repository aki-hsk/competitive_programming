#include<bits/stdc++.h>
using namespace std;

int main() {
    int *p;
    // int型の変数の分だけヒープ領域からメモリを確保
    p = new int;

    // ポインタを介して使う
    *p = 123;
    cout << *p << endl;

    // メモリを開放
    delete p;
}