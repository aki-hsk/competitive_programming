#include<bits/stdc++.h>
using namespace std;

// i ~ N-1の範囲にNの約数が存在するか
bool has_divisor(int N, int i) {
    //ベースケース2
    //そもそも対象となる整数がないのでfalse
    if(i == N) return false;

    //ベースケース
    if(N % i == 0) {
        return true;
    }

    //再帰ステップ
    //i+1 ~ N-1の範囲の結果がi ~ N-1の範囲の結果になる
    // ベースケース2によってiがNの約数の場合は取り除かれてるので、あとはi+1 ~ N-1の範囲を調べる
    return has_divisor(N, i+1);
}

bool is_prime(int N) {
    if(N == 1) return false;
    else if(N == 2) return true;
    else {
        return !has_divisor(N, 2);
    }
}

int main() {
    cout << is_prime(1) << endl;
    cout << is_prime(2) << endl;
    cout << is_prime(13) << endl;
    cout << is_prime(12) << endl;
    cout << is_prime(57) << endl;
}