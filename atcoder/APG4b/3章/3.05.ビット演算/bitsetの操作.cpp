#include<bits/stdc++.h>
using namespace std;

int main() {
    bitset<4> S;
    S.set(0, 1);  //0番目のビットを1にする
    cout << S << endl;

    //特定のbitが1かどうかを調べる　変数.test(index);
    if(S.test(3)) {
        cout << "4th bit si 1" << endl;
    } else {
        cout << "4th bit is 0" << endl;
    }
}