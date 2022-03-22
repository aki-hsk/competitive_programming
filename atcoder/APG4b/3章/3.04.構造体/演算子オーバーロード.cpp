#include<bits/stdc++.h>
using namespace std;

struct MyPair {
    int x;
    string y;

    // 別のMyPair型のオブジェクトをとってx,yにそれぞれ+したものを返す
    // +演算子をオーバーロード
    //返り値の型 operator演算子(引数の型 引数)
    MyPair operator+(const MyPair &other) {
        MyPair ret;
        ret.x = x + other.x; //intの+演算子が呼ばれる
        ret.y = y + " "+ other.y; //string型の+演算子が呼ばれる
        return ret;
    }
};

int main() {
    MyPair a = {123, "hello"};
    MyPair b = {456, "world"};

    MyPair c = a + b;
    cout << c.x << endl;
    cout << c.y << endl;

}