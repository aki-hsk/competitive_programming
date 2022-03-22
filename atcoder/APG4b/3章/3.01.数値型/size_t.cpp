#include<bits/stdc++.h>
using namespace std;

//size()で返ってくる要素数の値はsize_tという符号なしの整数型

int main() {
    vector<int> data(0);
    cout << data.size() - 1 << endl;
    //ループ回数のdata.size() - 1がオーバーフローしてしまう
    for(int i=0; i<data.size()-1; i++) {
        cout << i << endl;
    }

    //キャストする必要があるよ！！
    for(int i=0; i<(int)data.size()-1; i++) {
    }
}