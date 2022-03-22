#include<bits/stdc++.h>
using namespace std;

int main() {
    int *p;

    // int型の変数10個分だけヒープ領域からメモリを確保
    p = new int(10);

    // ポインタを介して使う
    int *tmp = p; // アドレス値のコピー
    for(int i=0; i<10; i++) {
        *tmp = i; // i番目にiを書き込む
        tmp++; // 次の要素を指すように変更
    }

    tmp = p; // tmpのアドレスをpの位置に戻す
    for(int i=0; i<10; i++) {
        cout << *tmp << endl;
        tmp++;
    }
    // メモリを開放する(10個分を連続で確保したのでdelete[]を使う)
    delete[] p;
}