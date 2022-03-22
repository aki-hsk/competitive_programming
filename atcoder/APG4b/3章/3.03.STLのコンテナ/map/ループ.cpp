#include<bits/stdc++.h>
using namespace std;

int main() {
     //<key, value>
    map<string , int> score;        //名前->成績
    score["Alice"] = 100;
    score["Bob"] = 89;
    score["Charlie"] = 95;

    //Keyの値が小さい順にループ
    for(pair<string, int> p : score) {
        string key = p.first;
        int value = p.second;
        cout << key << " " << value << endl;
        /*----keyの小さい順に出力----
            Alice 100
            Bob 89
            Charlie 95
                        */
    }

    //autoを使う
    for(auto s:score) {
        auto k = s.first;
        auto v = s.second;
        cout << k << " => " << v << endl;
    }
}