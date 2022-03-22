#include<bits/stdc++.h>
using namespace std;

int main() {
    //arrayの要素数の指定などもconstである必要がある
    //vectorは大丈夫
    const int a = 10;
    cout << a + 5 << endl;

    a = 5; //error: assignment of read-only variable 'a'
}