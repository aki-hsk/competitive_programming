#include<bits/stdc++.h>
using namespace std;

//deque デックと読むよ
// キューの操作とスタックの操作を同時に行えるデータ構造

int main() {
    deque<int> d;
    d.push_back(10);
    d.push_back(1);
    d.push_back(3);

    // d = {10, 1, 3}

    cout << d.front() << endl;  // 先頭の値へアクセス -> 10
    d.pop_front();              // 先頭を削除

    // d = {1, 3}
    cout << d.back() << endl;   // 末尾の値へアクセス -> 3
    d.pop_back();               // 末尾を削除

    // d = {1}
    d.push_front(5);            // 先頭への値の追加
    d.push_back(2);             // 末尾への値の追加

    // {5, 1, 3}
    cout << d.at(1) << endl;
}