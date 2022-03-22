#include<bits/stdc++.h>
using namespace std;

int main() {
    int number = 100;
    //to_string 数値->文字
    string s = to_string(number);
    cout << s + "yen" << endl;

    //stoi 文字列 -> int
    string t = "100";
    int n = stoi(t);
    cout << n << endl;
}