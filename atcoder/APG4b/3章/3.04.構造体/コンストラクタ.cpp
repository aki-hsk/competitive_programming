#include<bits/stdc++.h>
using namespace std;

struct MyPair {
    int x;
    string y;
    //コンストラクタ
    MyPair() {
        cout << "this is constructer" << endl;
    }
};

int main() {
    MyPair p;
    p.x = 12345;
    p.y = "hello";
    cout << "p.x = " << p.x << endl;
    cout << "p.y = " << p.y << endl;
}