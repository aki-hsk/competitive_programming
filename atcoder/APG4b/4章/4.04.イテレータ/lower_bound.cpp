#include<bits/stdc++.h>
using namespace std;

// lower_bound: イテレータの範囲内から指定した値以上の最小の要素を探して、
// その要素を指すイテレータを返す

// lower_boundのイテレータから先頭のイテレータを引く => あるkeyより小さい要素の個数
// 末尾のイテレータからlower_boundのイテレータを引く => あるkey以上の要素の個数

// upper_bound: イテレータの範囲内から指定した値より大きい最小の要素を探して、
// その要素を指すイテレータを返す

// upper_boundのイテレータから先頭のイテレータを引く => あるkey以下の要素の個数
// 末尾のイテレータからlower_boundのイテレータを引く => あるkeyより大きい要素の個数

// オブジェクト.lower_bound(イテレータ1, イテレータ2, 値)
// 見つからなかった場合はイテレータ2を返す

int main() {
    vector<int> a = {8, 4, 3};
    sort(a.begin(), a.end());

    //5以上の最小の要素を指すイテレータ
    auto itr = lower_bound(a.begin(), a.end(), 5);
    if(itr == a.end()) {
        cout << "not found" << endl;
    } else {
        cout << "index:" << distance(a.begin(), itr) << " " << *itr << endl;
    }

    //10以上の最小の要素を返すイテレータ
    itr = lower_bound(a.begin(), a.end(), 10);
    if(itr == a.end()) {
        cout << "not found" << endl;
    } else {
        cout << distance(a.begin(), itr) << " "<< *itr << endl;
    }
}