#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    int count = 0;

    for(int i=0; i<s.size(); i++) {
        count += (int)(s[i]-48);
        count %= 9;
    }
    if (count % 9 == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    else {
        cout << "No" << endl;
    }
}