#include<bits/stdc++.h>
using namespace std;

// priority_queue
// それまでに追加した要素のうち、最も大きいものを取り出す

int main() {
    priority_queue<int> pq;
    pq.push(10);
    pq.push(3);
    pq.push(6);
    pq.push(1);

    //空で無い間繰り返す
    while(!pq.empty()) {
        cout << pq.top() << endl;   // 最大の値を出力
        pq.pop();                   // 最大の値を削除
    }
}