#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    //小さい方を出力
    int ans = a < b ? a : b;
    cout << ans << endl;

    cout << (a < b ? a : b) << endl; //()で囲う
}