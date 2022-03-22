#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // nが負の値でも一度実行される
    do {
        cout << n << endl;
        n--;
    } while(n >= 0);
}