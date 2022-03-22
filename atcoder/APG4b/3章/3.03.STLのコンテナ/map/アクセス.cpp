#include<bits/stdc++.h>
using namespace std;

int main() {
     //<key, value>
    map<string , int> score;        //名前->成績
    score["Alice"] = 100;
    score["Bob"] = 89;
    score["Charlie"] = 95;

    // 変数.at(key) keyに対応するvalueが無い場合はerror
    // 変数[key] keyに対応するvalueが無い場合はvalueの初期値が代入

    cout << score["aaa"] << endl;       //score["aaa"]に0が代入
    cout << score.at("aki") << endl;    //errorが発生
}