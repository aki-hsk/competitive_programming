#include<bits/stdc++.h>
using namespace std;

//構造体の定義
struct MyPair {
    //型 変数名;
    int x;
    string y;

    //メンバ関数
    void print() {
        //直接x, yにアクセスできる
        cout << "call print method!!" << endl;
        cout << "x= " << x << endl;
        cout << "y= " << y << endl;
    }
};

int main() {
    //構造体名 オブジェクト名 = {メンバ変数1の値, メンバ変数2の値};
    MyPair p = {12345, "hello"};
    //アクセス
    cout << "p.x = " << p.x << endl;
    cout << "p.y = " << p.y << endl;
    //関数の呼び出し
    p.print();
}