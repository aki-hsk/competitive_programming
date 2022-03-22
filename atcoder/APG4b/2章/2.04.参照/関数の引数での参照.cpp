#include<bits/stdc++.h>
using namespace std;

int f(int &x) {
    x = x * 2; //xを2倍(参照によって呼び出す側の変数が変更される)
    return x;
}

int main() {
    int a = 3; //関数を呼び出すがわの変数
    int b = f(a); //参照がaになる
    cout << a << endl;
    cout << b << endl;

/*---output------
    a: 6
    b: 6
-----output-----*/

}