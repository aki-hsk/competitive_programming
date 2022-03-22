#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool flg = false;
    // (k + B)A%B = (kA + BA)%B = kA%B
    // 周期Bで繰り返すのでi:1~Bで全探索する
    for(int i=1; i<=B; i++) {
        if(i * A % B == C) flg = true;
    }
    cout << (flg ? "YES" : "NO") << endl;
}