#include<bits/stdc++.h>
using namespace std;

int main() {
    // 3ビットのビット列全てを列挙
    // 1 << k : 2のk乗
    for(int tmp = 0; tmp < (1 << 3); tmp++) {
        // tmpをビット列として解釈してsを初期化
        bitset<3> s(tmp);
        cout << s << endl;
    }
}