#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int a = stoi(s.substr(0,2));
    int b = stoi(s.substr(2,2));

    bool x = false, y = false;

    if(a > 0 && a <= 12) x = true;
    if(b > 0 && b <= 12) y = true;
    if(x && y) cout << "AMBIGUOUS" << endl;
    else if(x) cout << "MMYY" << endl;
    else if(y) cout << "YYMM" << endl;
    else cout << "NA" << endl;

    return 0;


}

