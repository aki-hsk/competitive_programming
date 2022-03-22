#include<bits/stdc++.h>
using namespace std;

int main() {
    pair<string ,int> p("abc", 3);
    cout <<p.first << endl;     // abc

    p.first = "hello";
    cout << p.first << endl;    // hello
    cout << p.second << endl;   // 3

    //pairの生成
    p = make_pair("*" , 1);

    string s;
    int a;

    //pairの分解
    tie(s, a) = p;
    cout << s << endl; // *
    cout << a << endl; // 1
}