#include<bits/stdc++.h>
using namespace std;

int main() {
    //宣言
    stack<int> s;
    s.push(10);
    s.push(1);
    s.push(3);

    cout << s.top() << endl;    // -> 3
    s.pop();                    //値の削除
    cout << s.top() << endl;    // -> 1
}