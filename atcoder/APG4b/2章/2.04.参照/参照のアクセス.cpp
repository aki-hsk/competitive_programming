#include<bits/stdc++.h>
using namespace std;

int main() {
    int a = 0;
    int &b = a;
    b = b + 1; //a = a + 1と同じ結果

    cout << a << endl; //"1"が出力

    string s = "apg4b";
    string &t = s;

    t[0] = 'A';
    t[1] = 'P';
    t[2] = 'G';

    cout << s << endl;
    cout << t << endl;
}