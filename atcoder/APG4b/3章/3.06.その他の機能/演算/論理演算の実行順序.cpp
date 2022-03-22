#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "abc";
    // エラーにならない
    //始めの時点でfalse
    if(s.size() > 10 && s.at(10) == 'x') {
        cout << "ok" << endl;
    }

    //エラー
    //始めにエラーが出るから
    if(s.at(10) == 'x' && s.size() > 10) {
        cout << "ng" << endl;
    }
}