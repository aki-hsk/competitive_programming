#include<bits/stdc++.h>
using namespace std;

int main() {
  //queue<型> 変数名;
    queue<int> q;
  //変数.push(値): 要素を追加
    q.push(10);
    q.push(3);
    q.push(6);
    q.push(1);

    //空で無い間繰り返す
    //q.empty(): queueが空であるか調べる
    while(!q.empty()) {
        cout << q.front() << endl;  // 先頭の値を出力 変数.front()
        q.pop();                    // 先頭の値を削除 変数.pop()
    }
}