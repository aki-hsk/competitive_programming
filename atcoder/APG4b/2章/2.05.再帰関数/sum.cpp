#include<bits/stdc++.h>
using namespace std;

int sum(int n) {

    // ベースケース
    // 再帰呼び出しを行わずに完了できる処理
    if(n == 0) {
        return 0;
    }

    //再帰ステップ
    //再帰呼び出しを行い、その結果を用いて行う処理
    int s = sum(n-1);
    return s + n;
}

int main() {
    cout << sum(2) << endl;
    cout << sum(3) << endl;
    cout << sum(10) << endl;
}

