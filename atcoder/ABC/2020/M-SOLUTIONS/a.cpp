#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int X;
    cin >> X;

    if(X < 600) cout << 8 <<endl;
    else if(X < 800) cout << 7 << endl;
    else if(X < 1000) cout << 6 << endl;
    else if(X < 1200) cout << 5 << endl;
    else if(X < 1400) cout << 4 << endl;
    else if(X < 1600) cout << 3 << endl;
    else if(X < 1800) cout << 2 << endl;
    else if(X < 2000) cout << 1 << endl;
}