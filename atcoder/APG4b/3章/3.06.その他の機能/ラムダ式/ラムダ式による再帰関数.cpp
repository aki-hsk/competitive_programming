#include<bits/stdc++.h>
using namespace std;

int main() {
    // 再帰関数の定義
    // autoではなくfunctionを型とする
    // function<返り値の型(引数の型1, 引数の型2,...) 関数名 = [&](引数の型1 引数名1,...)
    function<int(int)> sum = [&](int n) {
        if(n == 0) {
            return 0;
        }
        int s = sum(n - 1);
        return s + n;
    };
    cout << sum(1000) << endl;
}