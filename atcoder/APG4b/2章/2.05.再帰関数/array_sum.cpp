#include<bits/stdc++.h>
using namespace std;

//(補助関数)
//dataのi番目以降の要素の総和を計算する
int array_sum_from_i(vector<int> &data, int i) {
    //ベースケース
    if(i == data.size()) return 0; //対象の要素がないので総和は0

    //再帰ステップ
    return data.at(i) + array_sum_from_i(data, i+1);
}

//dataの全ての要素の総和を計算する
int array_sum(vector<int> &data) {
    return array_sum_from_i(data, 0);
}

int main() {
    vector<int> a = {0, 3, 9, 1, 5};
    cout << array_sum(a) << endl;
}