#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {2, 3, 1};

    // 大きい順にソートさせる比較関数
    auto comp = [](int a, int b) { return a > b;};
    sort(v.begin(), v.end(), comp);
    cout << v[0] << endl; // 3, 2, 1

    vector<int> z = {1, 10, 3};
    sort(z.begin(), z.end(), [](int a, int b) {return a > b;});
    cout << z[0] << endl;
}