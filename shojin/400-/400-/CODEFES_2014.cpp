#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    n %= 40;
    if(n < 21) cout << n << endl;
    else cout << 41 - n << endl;
}