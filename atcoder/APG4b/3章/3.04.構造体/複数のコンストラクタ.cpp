#include<bits/stdc++.h>
using namespace std;

struct MyPair{
    int x;
    string y;
   //コンストラクタ1
    MyPair() {
        cout << "初期化なし" << endl;
    }
    MyPair(int x_) {
        cout << "xのみ初期化" << endl;
        x = x_;
    }
    MyPair(int x_, string y_) {
        cout << "x,yを初期化" << endl;
        x = x_;
        y = y_;
    }
};


int main() {
    MyPair p; //コンストラクタ1
    cout << "p.x = " << p.x << endl;
    cout << "p.y = " << p.y << endl;

    MyPair q(6789); //コンストラクタ2
    cout << "q.x = " << q.x << endl;
    cout << "q.y = " << q.y << endl;

    MyPair r(11111, "good bye"); //コンストラクタ3
    cout << "r.x = " << r.x << endl;
    cout << "r.y = " << r.y << endl;

}