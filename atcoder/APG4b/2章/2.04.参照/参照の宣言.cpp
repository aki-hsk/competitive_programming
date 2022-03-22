#include<bits/stdc++.h>
using namespace std;

int main() {
    int a = 123;
    int &b = a; //int型変数aへの参照

    string s = "apg4b";
    string &t = s; //string型変数sへの参照

    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> &w = v; //vector型変数vへの参照

    int &c; //参照先がないためコンパイルエラー
            //error: 'c' declared as reference but not initialized


}