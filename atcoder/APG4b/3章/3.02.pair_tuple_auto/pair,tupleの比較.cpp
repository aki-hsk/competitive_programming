#include<bits/stdc++.h>
using namespace std;

// pair<int,int>を比較する場合
//1つめの値を基準に評価して等しい場合は2つめの値を基準に比較する
int main() {
    pair<int, int> a(3, 1);
    pair<int, int> b(2, 10);
    // 3 > 2なのでa < bはfalse
    if(a < b) {
        cout << "a < b" << endl;
    } else {
        cout << "a > b" << endl;
    }

    pair<int, int> c(5, 1);
    pair<int ,int> d(5, 10);
    // 5 == 5, 1 < 10なので c < d
    if(c < d) {
        cout << "c < d" << endl;
    }
    else {
        cout << "c > d" << endl;
    }

}