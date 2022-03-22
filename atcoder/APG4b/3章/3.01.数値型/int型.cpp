#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

//intは20億くらい(2 * 10^9)

int main() {
    int a = 2000000000;
    int b = a * 2;                  //オーバーフロー
    cout << b << endl;
    int c = (a * 10 + 100) / 100;   //計算途中でオーバーフロー
    cout << c << endl;
}