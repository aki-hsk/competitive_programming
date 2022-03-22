#include<bits/stdc++.h>
using namespace std;


// tupleはpairを一般化したもので、複数個の組を表す
int main() {
    //宣言
    tuple<int, string, bool> data(1, "hello", true);
    //アクセス
    // get<K>(tuple型の変数) K番目にアクセス
    // Kは定数で0index
    get<2>(data) = false;
    cout << get<1>(data) << endl; //hello

    //tuple型の生成
    data = make_tuple(2, "WORLD", true);

    int a;
    string s;
    bool f;
    //tupleの分解
    tie(a, s, f) = data;
    cout << a << " " << s << " " << f << endl;
}