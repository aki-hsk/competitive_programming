#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {0, 10, 13, 14, 20};

    //lower_bound: 昇順にソートされた配列においてx以上の最小の要素を求める

    // aにおいて,12以上の最小の要素は13
    cout << *lower_bound(a.begin(), a.end(), 12) << endl; // -> 13
    cout << lower_bound(a.begin(), a.end(), 10) - a.begin() << endl; // -> 1
    // 14以上の最小の要素は14
    cout << *lower_bound(a.begin(), a.end(), 14) << endl; // -> 14
    cout << upper_bound(a.begin(), a.end(), -1) - a.begin() << endl; // -> 2

    // upper_bound: 昇順にソートされた配列においてxを超える最小の要素を求める
    cout << *upper_bound(a.begin(), a.end(), 10) << endl; // -> 13
}