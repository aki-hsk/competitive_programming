#include<bits/stdc++.h>
using namespace std;

//配列の先頭100要素の合計を計算
int sum100(vector<int> &a) {
    int result = 0;
    for(int i=0; i<100; i++) {
        result += a[i];
    }
    return result;
}

int main() {
    vector<int> vec(10000000, 1);

    for(int i=0; i<500; i++) {
        cout << sum100(vec) << endl;
    }
}