#include<bits/stdc++.h>
using namespace std;

int main() {
    //イテレータ->メンバ変数
    //イテレータ->メンバ関数()

    vector<pair<int, int>> a = {{1, 4}, {2, 5}, {3, 6}};
    auto itr = a.begin() + 1;
    cout << (itr->first) << ", " << (itr->second) << endl;
}