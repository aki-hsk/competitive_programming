#include<bits/stdc++.h>
using namespace std;

int main() {
     //<key, value>
    map<string , int> score;        //名前->成績
    score["Alice"] = 100;
    score["Bob"] = 89;
    score["Charlie"] = 95;

    cout << score.at("Alice") << endl;
    cout << score.at("Bob") << endl;

    //値の削除
    score.erase("Bob");
    cout << score.at("Bob") << endl;
}