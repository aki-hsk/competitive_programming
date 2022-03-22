#include<bits/stdc++.h>
using namespace std;

int main() {
     //<key, value>
    map<string , int> score;        //名前->成績
    score["Alice"] = 100;
    score["Bob"] = 89;
    score["Charlie"] = 95;

    if(score.count("Alice")) {
        cout << "Alice: " << score.at("Alice") << endl;
    }
    if(score.count("Jiro")) { //存在しない
        cout << "Jiro: " << score.at("Jiro") << endl;
    }
}