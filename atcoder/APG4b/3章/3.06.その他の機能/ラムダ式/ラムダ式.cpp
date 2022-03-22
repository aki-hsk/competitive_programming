#include<bits/stdc++.h>
using namespace std;

int main() {
    // my_min関数をラムダ式で定義
    // auto 関数名 = [](引数の型1 引数名1, 引数の型2 引数名2, ...) {関数の処理};
    auto my_min = [](int a, int b) {
        if(a < b) {
            return a;
        } else {
            return b;
        }
    };

    cout << my_min(5, 10) << endl;
}