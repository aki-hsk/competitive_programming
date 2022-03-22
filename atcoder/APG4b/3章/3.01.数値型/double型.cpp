#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << 3.14159265358979 << endl;
    //桁の途中までを表示
    cout << fixed << setprecision(10);
    cout << 3.14159265358979 << endl;


    //明示的な数値型の変換
    cout << fixed << setprecision(5);
    int a = 5;
    //int -> double
    cout << (double)a << endl;
    double b = 3.141592;
    //double -> int
    cout << (int)b << endl;
}