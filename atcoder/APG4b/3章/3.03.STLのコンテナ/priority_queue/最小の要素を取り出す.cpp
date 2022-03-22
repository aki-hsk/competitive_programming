#include<bits/stdc++.h>
using namespace std;

int main() {
    //小さい順に取り出される優先度付きキュー
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(3);
    pq.push(6);
    pq.push(1);

    // 空で無い間繰り返す
    while(!pq.empty()) {
        cout << pq.top() << endl;   // 最小の値を出力
        pq.pop();                   // 最小の値を削除
    }
}