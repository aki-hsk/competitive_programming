#include<bits/stdc++.h>
using namespace std;

// a~bの総和を計算する(a <= b)

int sum_range(int a, int b) {
    //ベースステップ
    if (a == b) return a;

    //再帰ステップ
    return sum_range(a, b-1) + b;
}

int main() {
    cout << sum_range(1, 4) << endl;
    cout << sum_range(5, 8) << endl;
}