#include<bits/stdc++.h>
using namespace std;

//型エイリアスのusingとusing namespaceのusingは別物だよ！！

int main() {
    using pii = pair<int, int>;
    //これ以降piiという型名はpair<int, int>と同じ意味

    pii p;
    p = make_pair(1, 2);
    cout << p.first << ", " << p.second << endl;
    p = pii(3, 4);  //別のpairを作って代入
    cout << p.first << ", " << p.second << endl;

    //多次元配列の型を簡単に表現
    using vi = vector<int>; //intの1次元の型にviという別名をつける
    using vii = vector<vi>; //intの2次元の型にviという別名をつける

    int N = 10, M = 20;
    vvi data(N, vi(M));     //N * Mの2次元配列
}