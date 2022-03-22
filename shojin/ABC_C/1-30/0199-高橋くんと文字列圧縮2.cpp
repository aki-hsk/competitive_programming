#include <bits/stdc++.h>
using namespace std;

// 文字列圧縮
int main() {
    string s; cin >> s;
    int cnt = 1;
    for(int i=0; i<s.size(); i++) {
        cout << s[i];
        // s[i+1]は\0を返す
        while (s[i] == s[i+1]) {
            i++;
            cnt++;
        }
        cout << cnt;
        cnt = 1;
    }
    cout << endl;
}