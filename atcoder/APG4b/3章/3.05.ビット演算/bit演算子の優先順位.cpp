#include<bits/stdc++.h>
using namespace std;

//ビット演算をするときは（）でくくる！！！

int main() {
    int x = 5;  //0101
    int y = 10; //1010

    // if(x & y > 0) { // &演算子よりも>演算子の方が優先度が高い x & (y>0)となってしまう
    // x&y == 0000
    if((x&y) > 0) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}