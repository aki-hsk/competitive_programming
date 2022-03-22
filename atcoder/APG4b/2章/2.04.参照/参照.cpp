#include<bits/stdc++.h>
using namespace std;
int main() {
    int a = 3;
    int &b = a; //bは変数aの参照

    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

    b = 4; //参照先の値を変更 a = 4となる

    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

    return 0;

/*出力----------
    a: 3
    b: 3
    a: 4
    b: 4
---------------*/
}