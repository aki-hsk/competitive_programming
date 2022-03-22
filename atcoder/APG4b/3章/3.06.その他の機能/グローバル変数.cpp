#include<bits/stdc++.h>
using namespace std;

//グローバル変数
//同じ名前のグローバル変数は複数宣言できない
int number = 10;

void change() {
    number = 5;
}

int main() {
    cout << number << endl;

    change();

    cout << number << endl;
}