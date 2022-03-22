#include<bits/stdc++.h>
using namespace std;

int main() {
    for(int i=0; i<= ('Z' - 'A'); i++) {
        cout << (char)('A' + i);
    }


    cout << (char)('x' + ('A' - 'a')); //'X' 小文字->大文字
    cout << (char)('X' - ('A' - 'a')); //'x' 小文字->大文字

    cout << (char)toupper('x'); // 'X'
    cout << (char)tolower('X'); // 'x'
}