#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {3, 1, 5, 6, 7, 2, 4};

    auto itr1 = a.begin();    //aの先頭を指すイテレータ
    itr1 = itr1 + 2;         //a[2]を指すイテレータ
    auto itr2 = itr1 + 4;    //末端の要素a[6]を指すイテレータ

    cout << *itr1 << endl;   //a[2]へアクセス
    cout << *itr2 << endl;   //itr2が指す要素a[6]へアクセス

    //for文を用いて順番にアクセス
    cout << "for文を用いて順番にアクセス" << endl;
    for(auto it = a.begin(); it != a.end(); it++) {
        cout << *it << endl;
    }
}