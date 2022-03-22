#include<bits/stdc++.h>
using namespace std;

int main() {
    //宣言
    set<int> S;

    //値を追加
    S.insert(3);
    S.insert(7);
    S.insert(8);
    S.insert(10);

    //最小値へのアクセス(イテレータ) -> 10
    cout << *begin(S) << endl;
    //最大値へのアクセス(イテレータ) -> 3
    cout << *rbegin(S) << endl;

    for(auto value:S) {
        cout << value << endl;
    }
}