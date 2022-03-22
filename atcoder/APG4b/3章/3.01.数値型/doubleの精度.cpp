#include<bits/stdc++.h>
using namespace std;

int main() {
    double x = 1000000000;  //10^9
    double y = 0.000000001; //10-^9

    double z = x + y;
    cout << fixed << setprecision(16);
    cout << x << endl;
    cout << y << endl;
    cout << "z:" << z << endl;
    /// z:1000000000.0000000000000000となって桁落ちする
}